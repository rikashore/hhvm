/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/reflection_dep_B_types.h"
#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/reflection_dep_C_types.h"
#include "thrift/test/fatal_custom_types.h"

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace test_cpp2 { namespace cpp_reflection {
class service2;
}} // test_cpp2::cpp_reflection
namespace apache::thrift {

template <>
class Client<::test_cpp2::cpp_reflection::service2> : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "service2";
  }


  virtual void methodA(std::unique_ptr<apache::thrift::RequestCallback> callback);
  virtual void methodA(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 protected:
  void methodAImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, bool stealRpcOptions = false);
 public:

  virtual void sync_methodA();
  virtual void sync_methodA(apache::thrift::RpcOptions& rpcOptions);

  virtual folly::Future<folly::Unit> future_methodA();
  virtual folly::SemiFuture<folly::Unit> semifuture_methodA();
  virtual folly::Future<folly::Unit> future_methodA(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<folly::Unit> semifuture_methodA(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_methodA(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_methodA(apache::thrift::RpcOptions& rpcOptions);

#if FOLLY_HAS_COROUTINES
#if __clang__
  template <int = 0>
  folly::coro::Task<void> co_methodA() {
    return co_methodA<false>(nullptr);
  }
  template <int = 0>
  folly::coro::Task<void> co_methodA(apache::thrift::RpcOptions& rpcOptions) {
    return co_methodA<true>(&rpcOptions);
  }
#else
  folly::coro::Task<void> co_methodA() {
    co_await folly::coro::detachOnCancel(semifuture_methodA());
  }
  folly::coro::Task<void> co_methodA(apache::thrift::RpcOptions& rpcOptions) {
    co_await folly::coro::detachOnCancel(semifuture_methodA(rpcOptions));
  }
#endif
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<void> co_methodA(apache::thrift::RpcOptions* rpcOptions) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientCoroCallback<false> callback(&returnState, co_await folly::coro::co_current_executor);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = methodACtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if constexpr (hasRpcOptions) {
      methodAImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    } else {
      methodAImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    if (auto ew = recv_wrapped_methodA(returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  virtual void methodA(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);


  static folly::exception_wrapper recv_wrapped_methodA(::apache::thrift::ClientReceiveState& state);
  static void recv_methodA(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_methodA(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_methodA(::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_, typename RpcOptions>
  void methodAT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> methodACtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void methodB(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);
  virtual void methodB(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);
 protected:
  void methodBImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z, bool stealRpcOptions = false);
 public:

  virtual void sync_methodB(::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);
  virtual void sync_methodB(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);

  virtual folly::Future<folly::Unit> future_methodB(::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);
  virtual folly::SemiFuture<folly::Unit> semifuture_methodB(::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);
  virtual folly::Future<folly::Unit> future_methodB(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);
  virtual folly::SemiFuture<folly::Unit> semifuture_methodB(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);
  virtual folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_methodB(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);
  virtual folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_methodB(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);

#if FOLLY_HAS_COROUTINES
#if __clang__
  template <int = 0>
  folly::coro::Task<void> co_methodB(::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z) {
    return co_methodB<false>(nullptr, p_x, p_y, p_z);
  }
  template <int = 0>
  folly::coro::Task<void> co_methodB(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z) {
    return co_methodB<true>(&rpcOptions, p_x, p_y, p_z);
  }
#else
  folly::coro::Task<void> co_methodB(::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z) {
    co_await folly::coro::detachOnCancel(semifuture_methodB(p_x, p_y, p_z));
  }
  folly::coro::Task<void> co_methodB(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z) {
    co_await folly::coro::detachOnCancel(semifuture_methodB(rpcOptions, p_x, p_y, p_z));
  }
#endif
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<void> co_methodB(apache::thrift::RpcOptions* rpcOptions, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientCoroCallback<false> callback(&returnState, co_await folly::coro::co_current_executor);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = methodBCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if constexpr (hasRpcOptions) {
      methodBImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_x, p_y, p_z);
    } else {
      methodBImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_x, p_y, p_z);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    if (auto ew = recv_wrapped_methodB(returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  virtual void methodB(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);


  static folly::exception_wrapper recv_wrapped_methodB(::apache::thrift::ClientReceiveState& state);
  static void recv_methodB(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_methodB(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_methodB(::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_, typename RpcOptions>
  void methodBT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int32_t p_x, const ::test_cpp2::cpp_reflection::struct1& p_y, double p_z);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> methodBCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void methodC(std::unique_ptr<apache::thrift::RequestCallback> callback);
  virtual void methodC(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 protected:
  void methodCImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, bool stealRpcOptions = false);
 public:

  virtual ::std::int32_t sync_methodC();
  virtual ::std::int32_t sync_methodC(apache::thrift::RpcOptions& rpcOptions);

  virtual folly::Future<::std::int32_t> future_methodC();
  virtual folly::SemiFuture<::std::int32_t> semifuture_methodC();
  virtual folly::Future<::std::int32_t> future_methodC(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<::std::int32_t> semifuture_methodC(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<std::pair<::std::int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_methodC(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<std::pair<::std::int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_methodC(apache::thrift::RpcOptions& rpcOptions);

#if FOLLY_HAS_COROUTINES
#if __clang__
  template <int = 0>
  folly::coro::Task<::std::int32_t> co_methodC() {
    return co_methodC<false>(nullptr);
  }
  template <int = 0>
  folly::coro::Task<::std::int32_t> co_methodC(apache::thrift::RpcOptions& rpcOptions) {
    return co_methodC<true>(&rpcOptions);
  }
#else
  folly::coro::Task<::std::int32_t> co_methodC() {
    co_return co_await folly::coro::detachOnCancel(semifuture_methodC());
  }
  folly::coro::Task<::std::int32_t> co_methodC(apache::thrift::RpcOptions& rpcOptions) {
    co_return co_await folly::coro::detachOnCancel(semifuture_methodC(rpcOptions));
  }
#endif
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<::std::int32_t> co_methodC(apache::thrift::RpcOptions* rpcOptions) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientCoroCallback<false> callback(&returnState, co_await folly::coro::co_current_executor);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = methodCCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if constexpr (hasRpcOptions) {
      methodCImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    } else {
      methodCImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    ::std::int32_t _return;
    if (auto ew = recv_wrapped_methodC(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  virtual void methodC(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);


  static folly::exception_wrapper recv_wrapped_methodC(::std::int32_t& _return, ::apache::thrift::ClientReceiveState& state);
  static ::std::int32_t recv_methodC(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual ::std::int32_t recv_instance_methodC(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_methodC(::std::int32_t& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_, typename RpcOptions>
  void methodCT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> methodCCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void methodD(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);
  virtual void methodD(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);
 protected:
  void methodDImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k, bool stealRpcOptions = false);
 public:

  virtual ::std::int32_t sync_methodD(::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);
  virtual ::std::int32_t sync_methodD(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);

  virtual folly::Future<::std::int32_t> future_methodD(::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);
  virtual folly::SemiFuture<::std::int32_t> semifuture_methodD(::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);
  virtual folly::Future<::std::int32_t> future_methodD(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);
  virtual folly::SemiFuture<::std::int32_t> semifuture_methodD(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);
  virtual folly::Future<std::pair<::std::int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_methodD(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);
  virtual folly::SemiFuture<std::pair<::std::int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_methodD(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);

#if FOLLY_HAS_COROUTINES
#if __clang__
  template <int = 0>
  folly::coro::Task<::std::int32_t> co_methodD(::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k) {
    return co_methodD<false>(nullptr, p_i, p_j, p_k);
  }
  template <int = 0>
  folly::coro::Task<::std::int32_t> co_methodD(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k) {
    return co_methodD<true>(&rpcOptions, p_i, p_j, p_k);
  }
#else
  folly::coro::Task<::std::int32_t> co_methodD(::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k) {
    co_return co_await folly::coro::detachOnCancel(semifuture_methodD(p_i, p_j, p_k));
  }
  folly::coro::Task<::std::int32_t> co_methodD(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k) {
    co_return co_await folly::coro::detachOnCancel(semifuture_methodD(rpcOptions, p_i, p_j, p_k));
  }
#endif
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<::std::int32_t> co_methodD(apache::thrift::RpcOptions* rpcOptions, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientCoroCallback<false> callback(&returnState, co_await folly::coro::co_current_executor);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = methodDCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if constexpr (hasRpcOptions) {
      methodDImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_i, p_j, p_k);
    } else {
      methodDImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_i, p_j, p_k);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    ::std::int32_t _return;
    if (auto ew = recv_wrapped_methodD(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  virtual void methodD(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);


  static folly::exception_wrapper recv_wrapped_methodD(::std::int32_t& _return, ::apache::thrift::ClientReceiveState& state);
  static ::std::int32_t recv_methodD(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual ::std::int32_t recv_instance_methodD(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_methodD(::std::int32_t& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_, typename RpcOptions>
  void methodDT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int32_t p_i, const ::test_cpp2::cpp_reflection::struct1& p_j, double p_k);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> methodDCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void methodE(std::unique_ptr<apache::thrift::RequestCallback> callback);
  virtual void methodE(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 protected:
  void methodEImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, bool stealRpcOptions = false);
 public:

  virtual void sync_methodE(::test_cpp2::cpp_reflection::struct2& _return);
  virtual void sync_methodE(apache::thrift::RpcOptions& rpcOptions, ::test_cpp2::cpp_reflection::struct2& _return);

  virtual folly::Future<::test_cpp2::cpp_reflection::struct2> future_methodE();
  virtual folly::SemiFuture<::test_cpp2::cpp_reflection::struct2> semifuture_methodE();
  virtual folly::Future<::test_cpp2::cpp_reflection::struct2> future_methodE(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<::test_cpp2::cpp_reflection::struct2> semifuture_methodE(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<std::pair<::test_cpp2::cpp_reflection::struct2, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_methodE(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<std::pair<::test_cpp2::cpp_reflection::struct2, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_methodE(apache::thrift::RpcOptions& rpcOptions);

#if FOLLY_HAS_COROUTINES
#if __clang__
  template <int = 0>
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodE() {
    return co_methodE<false>(nullptr);
  }
  template <int = 0>
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodE(apache::thrift::RpcOptions& rpcOptions) {
    return co_methodE<true>(&rpcOptions);
  }
#else
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodE() {
    co_return co_await folly::coro::detachOnCancel(semifuture_methodE());
  }
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodE(apache::thrift::RpcOptions& rpcOptions) {
    co_return co_await folly::coro::detachOnCancel(semifuture_methodE(rpcOptions));
  }
#endif
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodE(apache::thrift::RpcOptions* rpcOptions) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientCoroCallback<false> callback(&returnState, co_await folly::coro::co_current_executor);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = methodECtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if constexpr (hasRpcOptions) {
      methodEImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    } else {
      methodEImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    ::test_cpp2::cpp_reflection::struct2 _return;
    if (auto ew = recv_wrapped_methodE(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  virtual void methodE(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);


  static folly::exception_wrapper recv_wrapped_methodE(::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_methodE(::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_methodE(::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_methodE(::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_, typename RpcOptions>
  void methodET(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> methodECtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void methodF(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);
  virtual void methodF(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);
 protected:
  void methodFImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n, bool stealRpcOptions = false);
 public:

  virtual void sync_methodF(::test_cpp2::cpp_reflection::struct2& _return, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);
  virtual void sync_methodF(apache::thrift::RpcOptions& rpcOptions, ::test_cpp2::cpp_reflection::struct2& _return, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);

  virtual folly::Future<::test_cpp2::cpp_reflection::struct2> future_methodF(::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);
  virtual folly::SemiFuture<::test_cpp2::cpp_reflection::struct2> semifuture_methodF(::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);
  virtual folly::Future<::test_cpp2::cpp_reflection::struct2> future_methodF(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);
  virtual folly::SemiFuture<::test_cpp2::cpp_reflection::struct2> semifuture_methodF(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);
  virtual folly::Future<std::pair<::test_cpp2::cpp_reflection::struct2, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_methodF(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);
  virtual folly::SemiFuture<std::pair<::test_cpp2::cpp_reflection::struct2, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_methodF(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);

#if FOLLY_HAS_COROUTINES
#if __clang__
  template <int = 0>
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodF(::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n) {
    return co_methodF<false>(nullptr, p_l, p_m, p_n);
  }
  template <int = 0>
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodF(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n) {
    return co_methodF<true>(&rpcOptions, p_l, p_m, p_n);
  }
#else
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodF(::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n) {
    co_return co_await folly::coro::detachOnCancel(semifuture_methodF(p_l, p_m, p_n));
  }
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodF(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n) {
    co_return co_await folly::coro::detachOnCancel(semifuture_methodF(rpcOptions, p_l, p_m, p_n));
  }
#endif
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<::test_cpp2::cpp_reflection::struct2> co_methodF(apache::thrift::RpcOptions* rpcOptions, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientCoroCallback<false> callback(&returnState, co_await folly::coro::co_current_executor);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = methodFCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if constexpr (hasRpcOptions) {
      methodFImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_l, p_m, p_n);
    } else {
      methodFImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_l, p_m, p_n);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    ::test_cpp2::cpp_reflection::struct2 _return;
    if (auto ew = recv_wrapped_methodF(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  virtual void methodF(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);


  static folly::exception_wrapper recv_wrapped_methodF(::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_methodF(::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_methodF(::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_methodF(::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_, typename RpcOptions>
  void methodFT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int32_t p_l, const ::test_cpp2::cpp_reflection::struct1& p_m, double p_n);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> methodFCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
};

} // namespace apache::thrift

namespace test_cpp2 { namespace cpp_reflection {
using service2AsyncClient [[deprecated("Use apache::thrift::Client<service2> instead")]] = ::apache::thrift::Client<service2>;
}} // test_cpp2::cpp_reflection
