/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

//
// Operation objects are the handles users of AsyncMysqlClient use to
// interact with connections and queries.  Every action a user
// initiates returns an Operation to track the status of the action,
// report errors, etc.  Operations also offer a way to set callbacks
// for completion.
//
// In general, operations are held in shared_ptr's as ownership is
// unclear.  This allows the construction of Operations, callbacks to
// be set, and the Operation itself be cleaned up by AsyncMysqlClient.
// Conversely, if callbacks aren't being used, the Operation can
// simply be wait()'d upon for completion.
//
// See README for examples.
//
// Implementation detail; Operations straddle the caller's thread and
// the thread managed by the AsyncMysqlClient.  They also are
// responsible for execution of the actual libmysqlclient functions
// and most interactions with libevent.
//
// As mentioned above, an Operation's lifetime is determined by both
// AsyncMysqlClient and the calling point that created an Operation.
// It is permissible to immediately discard an Operation or to hold
// onto it (via a shared_ptr).  However, all calls to methods such as
// result() etc must occur either in the callback or after wait() has
// returned.

#pragma once

#include <folly/Function.h>
#include <folly/concurrency/AtomicSharedPtr.h>
#include <folly/futures/Future.h>
#include <folly/stop_watch.h>
#include <functional>
#include <memory>
#include <string>
#include <variant>

#include "squangle/mysql_client/DbResult.h"

namespace facebook::common::mysql_client {

class MysqlClientBase;
class ConnectOperation;
class QueryOperation;
class Operation;

enum class QueryCallbackReason;

// Simplify some std::chrono types.
using Clock = std::chrono::steady_clock;
using Timepoint = std::chrono::time_point<Clock>;

// Callbacks for connecting and querying, respectively.  A
// ConnectCallback is invoked when a connection succeeds or fails.  A
// QueryCallback is called for each row block (see Row.h) as well as
// when the query completes (either successfully or with an error).
using ConnectCallback = std::function<void(ConnectOperation&)>;
// Callback for observer. I will be called for a completed operation,
// after the callback for the specific operation is called, if one is defined.
using ObserverCallback = std::function<void(Operation&)>;
// Callback that is set on the ConnectOperation, and is then chained along all
// subsequent queries on that given connection.
using ChainedCallback = folly::Function<void(Operation&)>;
// Variant type allowing AsyncPostQueryCallback (below) to operate on either a
// Query or MultiQuery result.
using AsyncPostQueryResult = std::variant<DbQueryResult, DbMultiQueryResult>;
// Callbacks that are set on the ConnectOperation, and are then chained along
// all subsequent queries on that given connection. They execute asynchronously
// before/after query operations (if the async query APIs are used), and allow
// modification of the operation before or processing of results after a query.
using AsyncPreQueryCallback =
    std::function<folly::SemiFuture<folly::Unit>(FetchOperation&)>;
using AsyncPostQueryCallback =
    std::function<folly::SemiFuture<AsyncPostQueryResult>(
        AsyncPostQueryResult&&)>;

enum class SquangleErrno : uint16_t {
  SQ_ERRNO_CONN_TIMEOUT = 7000,
  SQ_ERRNO_CONN_TIMEOUT_LOOP_STALLED = 7001,
  SQ_ERRNO_QUERY_TIMEOUT = 7002,
  SQ_ERRNO_QUERY_TIMEOUT_LOOP_STALLED = 7003,
  SQ_ERRNO_POOL_CONN_TIMEOUT = 7004,
  SQ_ERRNO_FAILED_CONFIG_INIT = 7005,
  SQ_INVALID_API_USAGE = 7006,
  SQ_INITIALIZATION_FAILED = 7007,
};

// prefix to use in mysql errors generated by the client
constexpr auto kErrorPrefix = "MySQL Client";

// The state of the Operation.  In general, callers will see Unstarted
// (i.e., haven't yet called run()) or Completed (which may mean
// success or error; see OperationResult below).  Pending and
// Cancelling are not visible at times an outside caller might see
// them (since, once run() has been called, wait() must be called
// before inspecting other Operation attributes).
enum class OperationState {
  Unstarted,
  Pending,
  Cancelling,
  Completed,
};

// overload of operator<< for OperationState
std::ostream& operator<<(std::ostream& os, OperationState state);

// Once an operation is Completed, it has a result type, indicating
// what ultimately occurred.  These are self-explanatory.
enum class OperationResult {
  Unknown,
  Succeeded,
  Failed,
  Cancelled,
  TimedOut,
};

// overload of operator<< for OperationResult
std::ostream& operator<<(std::ostream& os, OperationResult result);

enum class StreamState { InitQuery, RowsReady, QueryEnded, Failure, Success };

// overload of operator<< for StreamState
std::ostream& operator<<(std::ostream& os, StreamState state);

// The abstract base for our available Operations.  Subclasses share
// intimate knowledge with the Operation class (most member variables
// are protected).
class Operation : public folly::EventHandler,
                  public folly::AsyncTimeout,
                  public std::enable_shared_from_this<Operation> {
 public:
  // No public constructor.
  virtual ~Operation() override;

  Operation& run();

  // Set a timeout; otherwise FLAGS_async_mysql_timeout_micros is
  // used.
  Operation& setTimeout(Duration timeout) {
    CHECK_THROW(
        state_ == OperationState::Unstarted, db::OperationStateException);
    timeout_ = timeout;
    return *this;
  }

  Duration getTimeout() {
    return timeout_;
  }

  Duration getMaxThreadBlockTime() {
    return max_thread_block_time_;
  }

  Duration getTotalThreadBlockTime() {
    return total_thread_block_time_;
  }

  void logThreadBlockTime(const folly::stop_watch<Duration> sw) {
    auto block_time = sw.elapsed();
    max_thread_block_time_ = std::max(max_thread_block_time_, block_time);
    total_thread_block_time_ += block_time;
  }

  // Did the operation succeed?
  bool ok() const {
    return done() && result_ == OperationResult::Succeeded;
  }

  // Is the operation complete (success or failure)?
  bool done() const {
    return state_ == OperationState::Completed;
  }

  // host and port we are connected to (or will be connected to).
  const std::string& host() const;
  int port() const;

  // Try to cancel a pending operation.  This is inherently racey with
  // callbacks; it is possible the callback is being invoked *during*
  // the cancel attempt, so a cancelled operation may still succeed.
  void cancel();

  // Wait for the Operation to complete.
  void wait() const;

  // Wait for an operation to complete.  Throw a
  // RequiredOperationFailedException if it fails. Mainly for testing.
  virtual void mustSucceed() = 0;

  // Information about why this operation failed.
  unsigned int mysql_errno() const {
    return mysql_errno_;
  }
  const std::string& mysql_error() const {
    return mysql_error_;
  }

  // Get the state and result, as well as readable string versions.
  OperationResult result() const {
    return result_;
  }

  folly::StringPiece resultString() const;

  OperationState state() const {
    return state_;
  }

  folly::StringPiece stateString() const;

  static folly::StringPiece toString(OperationState state);
  static folly::StringPiece toString(OperationResult result);
  static folly::StringPiece toString(StreamState state);

  static std::string connectStageString(connect_stage stage);

  Operation& setAttributes(const AttributeMap& attributes) {
    CHECK_THROW(
        state() == OperationState::Unstarted, db::OperationStateException);
    for (const auto& [key, value] : attributes) {
      attributes_[key] = value;
    }
    return *this;
  }

  Operation& setAttributes(AttributeMap&& attributes) {
    CHECK_THROW(
        state() == OperationState::Unstarted, db::OperationStateException);
    for (auto& [key, value] : attributes) {
      attributes_[key] = std::move(value);
    }
    return *this;
  }

  Operation& setAttribute(const std::string& key, const std::string& value) {
    CHECK_THROW(
        state() == OperationState::Unstarted, db::OperationStateException);
    attributes_[key] = value;
    return *this;
  }

  const AttributeMap& getAttributes() const {
    return attributes_;
  }

  // Connections are transferred across operations.  At any one time,
  // there is one unique owner of the connection.
  std::unique_ptr<Connection> releaseConnection();
  const Connection& connection() const {
    return conn_proxy_->get();
  }
  Connection& connection() {
    return conn_proxy_->get();
  }

  // Various accessors for our Operation's start, end, and total elapsed time.
  Timepoint startTime() const {
    return stopwatch_->getCheckpoint();
  }
  Timepoint endTime() const {
    CHECK_THROW(
        state_ == OperationState::Completed, db::OperationStateException);
    return startTime() + opDuration_;
  }

  Duration elapsed() const {
    CHECK_THROW(
        state_ == OperationState::Completed, db::OperationStateException);
    return opDuration_;
  }

  /**
   * Set various callbacks that are invoked during the operation's lifetime
   * The pre and post operations are chained, in that they are propagated to
   * operations that are scheduled on the connection following the current
   * operation. A couple notes:
   *
   * The PreOperationCallback will be invoked on a cancelled operation before
   * the cancellation takes effect
   *
   * The PostOperationCallback will be invoked on operations that have failed
   */
  void setObserverCallback(ObserverCallback obs_cb);
  void setPreOperationCallback(ChainedCallback obs_cb);
  void setPostOperationCallback(ChainedCallback obs_cb);

  /**
   * Set callbacks that are invoked asynchronously before/after query operations
   * (if using asynchronous query APIs). They do not execute on operations that
   * have failed, and if they fail the operation will fail too.
   *
   * PreQueryCallbacks execute after a query operation is initialized and before
   * it has been run. They are allowed to modify the operation by reference.
   *
   * PostQueryCallbacks execute after a query operation returns results. They
   * are allowed to do post-processing on the results received and returned via
   * rvalue reference.
   */
  void setPreQueryCallback(AsyncPreQueryCallback&& callback);
  void setPostQueryCallback(AsyncPostQueryCallback&& callback);

  // Retrieve the shared pointer that holds this instance.
  std::shared_ptr<Operation> getSharedPointer();

  MysqlClientBase& client() const;

  void setAsyncClientError(unsigned int mysql_errno, folly::StringPiece msg);

  virtual db::OperationType getOperationType() const = 0;

 protected:
  // Helper function to set chained callbacks
  ChainedCallback setCallback(
      ChainedCallback orgCallback,
      ChainedCallback newCallback);

  // Helper functions to set query callbacks
  static AsyncPreQueryCallback appendCallback(
      AsyncPreQueryCallback&& callback1,
      AsyncPreQueryCallback&& callback2);

  static AsyncPostQueryCallback appendCallback(
      AsyncPostQueryCallback&& callback1,
      AsyncPostQueryCallback&& callback2);

  static constexpr double kCallbackDelayStallThresholdUs = 50 * 1000;

  class ConnectionProxy;
  explicit Operation(std::unique_ptr<ConnectionProxy> conn);

  // These are duplicates of `connection()` below, but we don't want to have to
  // change all the callsites at this point so just point them to the other
  // versions.
  Connection& conn() {
    return connection();
  }
  const Connection& conn() const {
    return connection();
  }

  // Save any mysql errors that occurred (since we may hand off the
  // Connection before the user wants this information).
  void snapshotMysqlErrors();

  // Called when an Operation needs to wait for the socket to become
  // readable or writable (aka actionable).
  void waitForSocketActionable();

  // Overridden in child classes and invoked when the socket is
  // actionable.  This function should either completeOperation or
  // waitForSocketActionable.
  virtual void socketActionable() = 0;

  // EventHandler override
  void handlerReady(uint16_t /*events*/) noexcept override;

  // AsyncTimeout override
  void timeoutExpired() noexcept override {
    timeoutTriggered();
  }

  // Called by AsyncTimeout::timeoutExpired when the operation timed out
  void timeoutTriggered();

  // Our operation has completed.  During completeOperation,
  // specializedCompleteOperation is invoked for subclasses to perform
  // their own finalization (typically annotating errors and handling
  // timeouts).
  void completeOperation(OperationResult result);
  void completeOperationInner(OperationResult result);
  virtual Operation& specializedRun() = 0;
  virtual void specializedTimeoutTriggered() = 0;
  virtual void specializedCompleteOperation() = 0;

  class ConnectionProxy {
   public:
    virtual ~ConnectionProxy() = default;

    virtual Connection& get() = 0;
    virtual const Connection& get() const = 0;
    virtual std::unique_ptr<Connection> releaseConnection() {
      return nullptr;
    }
  };

  class OwnedConnection : public ConnectionProxy {
   public:
    explicit OwnedConnection(std::unique_ptr<Connection>&& conn);

    Connection& get() override;
    const Connection& get() const override;
    std::unique_ptr<Connection> releaseConnection() override;

   private:
    std::unique_ptr<Connection> conn_;
  };

  class ReferencedConnection : public ConnectionProxy {
   public:
    explicit ReferencedConnection(Connection& conn) : conn_(conn) {}

    Connection& get() override {
      return conn_;
    }
    const Connection& get() const override {
      return conn_;
    }

   private:
    Connection& conn_;
  };

  bool isInEventBaseThread() const;
  bool isEventBaseSet() const;

  std::string threadOverloadMessage(double cbDelayUs) const;
  std::string timeoutMessage(std::chrono::milliseconds delta) const;

  // Data members; subclasses freely interact with these.
  OperationState state_;
  OperationResult result_;

  // Our client is not owned by us. It must outlive all active Operations.
  Duration timeout_;
  using StopWatch = folly::stop_watch<Duration>;
  std::unique_ptr<StopWatch> stopwatch_;
  Duration opDuration_;

  // This will contain the max block time of the thread
  Duration max_thread_block_time_ = Duration(0);
  Duration total_thread_block_time_ = Duration(0);

  // Our Connection object.  Created by ConnectOperation and moved
  // into QueryOperations.
  std::unique_ptr<ConnectionProxy> conn_proxy_;

  // Errors that may have occurred.
  unsigned int mysql_errno_;
  std::string mysql_error_;

  // Connection or query attributes (depending on the Operation type)
  AttributeMap attributes_;

  struct Callbacks {
    Callbacks()
        : pre_operation_callback_(nullptr),
          post_operation_callback_(nullptr),
          pre_query_callback_(nullptr),
          post_query_callback_(nullptr) {}

    ChainedCallback pre_operation_callback_;
    ChainedCallback post_operation_callback_;

    AsyncPreQueryCallback pre_query_callback_;
    AsyncPostQueryCallback post_query_callback_;
  };

  Callbacks callbacks_;

  // Friends because they need to access the query callbacks on this class
  template <typename Operation>
  friend folly::SemiFuture<folly::Unit> handlePreQueryCallback(Operation& op);
  template <typename ReturnType, typename Operation, typename QueryResult>
  friend void handleQueryCompletion(
      Operation& op,
      QueryResult query_result,
      QueryCallbackReason reason,
      folly::Promise<std::pair<ReturnType, AsyncPostQueryCallback>>& promise);

 private:
  // Restore folly::RequestContext and also invoke socketActionable()
  void invokeSocketActionable();

  folly::atomic_shared_ptr<folly::RequestContext> request_context_;

  ObserverCallback observer_callback_;
  std::shared_ptr<db::ConnectionContextBase> connection_context_;

  MysqlClientBase& mysql_client_;

  folly::Synchronized<bool> cancel_on_run_{false};

  Operation() = delete;
  Operation(const Operation&) = delete;
  Operation& operator=(const Operation&) = delete;

  friend class Connection;
  friend class SyncConnection;
  friend class SyncConnectionPool;
};

// Helper function to build the result for a ConnectOperation in the sync
// mode. It will block the thread and return the acquired connection, in case
// of error, it will throw MysqlException as expected in the sync mode.
std::unique_ptr<Connection> blockingConnectHelper(
    std::shared_ptr<ConnectOperation> conn_op);

} // namespace facebook::common::mysql_client
