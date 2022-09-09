/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/stream/gen-cpp2/PubSubStreamingServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/stream/gen-cpp2/module_types.h"
#include <thrift/lib/cpp2/async/ServerStream.h>

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace cpp2 {
class PubSubStreamingService;
class PubSubStreamingServiceAsyncProcessor;

class PubSubStreamingServiceServiceInfoHolder : public apache::thrift::ServiceInfoHolder {
  public:
   apache::thrift::ServiceRequestInfoMap const& requestInfoMap() const override;
   static apache::thrift::ServiceRequestInfoMap staticRequestInfoMap();
};
} // cpp2

namespace apache::thrift {
template <>
class ServiceHandler<::cpp2::PubSubStreamingService> : public apache::thrift::ServerInterface {
 public:
  std::string_view getGeneratedName() const override { return "PubSubStreamingService"; }

  typedef ::cpp2::PubSubStreamingServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  CreateMethodMetadataResult createMethodMetadata() override;
 private:
  std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> getServiceRequestInfoMap() const;
 public:

  virtual ::apache::thrift::ServerStream<::std::int32_t> returnstream(::std::int32_t /*i32_from*/, ::std::int32_t /*i32_to*/);
  virtual folly::Future<::apache::thrift::ServerStream<::std::int32_t>> future_returnstream(::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual folly::SemiFuture<::apache::thrift::ServerStream<::std::int32_t>> semifuture_returnstream(::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<::apache::thrift::ServerStream<::std::int32_t>> co_returnstream(::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual folly::coro::Task<::apache::thrift::ServerStream<::std::int32_t>> co_returnstream(apache::thrift::RequestParams params, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
#endif
  virtual void async_tm_returnstream(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ServerStream<::std::int32_t>>> callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual ::apache::thrift::ServerStream<::std::int32_t> streamthrows(::std::int32_t /*foo*/);
  virtual folly::Future<::apache::thrift::ServerStream<::std::int32_t>> future_streamthrows(::std::int32_t p_foo);
  virtual folly::SemiFuture<::apache::thrift::ServerStream<::std::int32_t>> semifuture_streamthrows(::std::int32_t p_foo);
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<::apache::thrift::ServerStream<::std::int32_t>> co_streamthrows(::std::int32_t p_foo);
  virtual folly::coro::Task<::apache::thrift::ServerStream<::std::int32_t>> co_streamthrows(apache::thrift::RequestParams params, ::std::int32_t p_foo);
#endif
  virtual void async_tm_streamthrows(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ServerStream<::std::int32_t>>> callback, ::std::int32_t p_foo);
  virtual ::apache::thrift::ServerStream<::std::int32_t> servicethrows(::std::int32_t /*foo*/);
  virtual folly::Future<::apache::thrift::ServerStream<::std::int32_t>> future_servicethrows(::std::int32_t p_foo);
  virtual folly::SemiFuture<::apache::thrift::ServerStream<::std::int32_t>> semifuture_servicethrows(::std::int32_t p_foo);
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<::apache::thrift::ServerStream<::std::int32_t>> co_servicethrows(::std::int32_t p_foo);
  virtual folly::coro::Task<::apache::thrift::ServerStream<::std::int32_t>> co_servicethrows(apache::thrift::RequestParams params, ::std::int32_t p_foo);
#endif
  virtual void async_tm_servicethrows(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ServerStream<::std::int32_t>>> callback, ::std::int32_t p_foo);
  virtual ::apache::thrift::ServerStream<::std::int32_t> boththrows(::std::int32_t /*foo*/);
  virtual folly::Future<::apache::thrift::ServerStream<::std::int32_t>> future_boththrows(::std::int32_t p_foo);
  virtual folly::SemiFuture<::apache::thrift::ServerStream<::std::int32_t>> semifuture_boththrows(::std::int32_t p_foo);
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<::apache::thrift::ServerStream<::std::int32_t>> co_boththrows(::std::int32_t p_foo);
  virtual folly::coro::Task<::apache::thrift::ServerStream<::std::int32_t>> co_boththrows(apache::thrift::RequestParams params, ::std::int32_t p_foo);
#endif
  virtual void async_tm_boththrows(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ServerStream<::std::int32_t>>> callback, ::std::int32_t p_foo);
  virtual ::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t> responseandstreamstreamthrows(::std::int32_t /*foo*/);
  virtual folly::Future<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> future_responseandstreamstreamthrows(::std::int32_t p_foo);
  virtual folly::SemiFuture<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> semifuture_responseandstreamstreamthrows(::std::int32_t p_foo);
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> co_responseandstreamstreamthrows(::std::int32_t p_foo);
  virtual folly::coro::Task<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> co_responseandstreamstreamthrows(apache::thrift::RequestParams params, ::std::int32_t p_foo);
#endif
  virtual void async_tm_responseandstreamstreamthrows(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>>> callback, ::std::int32_t p_foo);
  virtual ::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t> responseandstreamservicethrows(::std::int32_t /*foo*/);
  virtual folly::Future<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> future_responseandstreamservicethrows(::std::int32_t p_foo);
  virtual folly::SemiFuture<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> semifuture_responseandstreamservicethrows(::std::int32_t p_foo);
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> co_responseandstreamservicethrows(::std::int32_t p_foo);
  virtual folly::coro::Task<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> co_responseandstreamservicethrows(apache::thrift::RequestParams params, ::std::int32_t p_foo);
#endif
  virtual void async_tm_responseandstreamservicethrows(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>>> callback, ::std::int32_t p_foo);
  virtual ::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t> responseandstreamboththrows(::std::int32_t /*foo*/);
  virtual folly::Future<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> future_responseandstreamboththrows(::std::int32_t p_foo);
  virtual folly::SemiFuture<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> semifuture_responseandstreamboththrows(::std::int32_t p_foo);
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> co_responseandstreamboththrows(::std::int32_t p_foo);
  virtual folly::coro::Task<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> co_responseandstreamboththrows(apache::thrift::RequestParams params, ::std::int32_t p_foo);
#endif
  virtual void async_tm_responseandstreamboththrows(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>>> callback, ::std::int32_t p_foo);
  virtual void async_eb_returnstreamFast(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ServerStream<::std::int32_t>>> callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
 private:
  static ::cpp2::PubSubStreamingServiceServiceInfoHolder __fbthrift_serviceInfoHolder;
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_returnstream{apache::thrift::detail::si::InvocationType::AsyncTm};
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_streamthrows{apache::thrift::detail::si::InvocationType::AsyncTm};
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_servicethrows{apache::thrift::detail::si::InvocationType::AsyncTm};
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_boththrows{apache::thrift::detail::si::InvocationType::AsyncTm};
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_responseandstreamstreamthrows{apache::thrift::detail::si::InvocationType::AsyncTm};
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_responseandstreamservicethrows{apache::thrift::detail::si::InvocationType::AsyncTm};
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_responseandstreamboththrows{apache::thrift::detail::si::InvocationType::AsyncTm};
};

} // namespace apache::thrift

namespace cpp2 {
using PubSubStreamingServiceSvIf [[deprecated("Use apache::thrift::ServiceHandler<PubSubStreamingService> instead")]] = ::apache::thrift::ServiceHandler<PubSubStreamingService>;
} // cpp2
namespace cpp2 {
class PubSubStreamingServiceSvNull : public ::apache::thrift::ServiceHandler<PubSubStreamingService> {
 public:
};

class PubSubStreamingServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessorBase {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  ::apache::thrift::ServiceHandler<::cpp2::PubSubStreamingService>* iface_;
 public:
  // This is implemented in case the corresponding AsyncProcessorFactory did not implement createMethodMetadata.
  // This can happen if the service is using a custom AsyncProcessorFactory but re-using the same AsyncProcessor.
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  // By default, this overload will be called for generated services
  void processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  void executeRequest(apache::thrift::ServerRequest&& serverRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) override;
 public:
  using ProcessFuncs = GeneratedAsyncProcessorBase::ProcessFuncs<PubSubStreamingServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessorBase::ProcessMap<ProcessFuncs>;
  static const PubSubStreamingServiceAsyncProcessor::ProcessMap& getOwnProcessMap();
 private:
  static const PubSubStreamingServiceAsyncProcessor::ProcessMap kOwnProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_returnstream(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_returnstream(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_returnstream(apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, ::apache::thrift::ServerStream<::std::int32_t>&& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_returnstream(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_streamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_streamthrows(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_streamthrows(apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, ::apache::thrift::ServerStream<::std::int32_t>&& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_streamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_servicethrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_servicethrows(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_servicethrows(apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, ::apache::thrift::ServerStream<::std::int32_t>&& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_servicethrows(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_boththrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_boththrows(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_boththrows(apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, ::apache::thrift::ServerStream<::std::int32_t>&& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_boththrows(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_responseandstreamstreamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_responseandstreamstreamthrows(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_responseandstreamstreamthrows(apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, ::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>&& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_responseandstreamstreamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_responseandstreamservicethrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_responseandstreamservicethrows(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_responseandstreamservicethrows(apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, ::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>&& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_responseandstreamservicethrows(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_responseandstreamboththrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_responseandstreamboththrows(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_responseandstreamboththrows(apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, ::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>&& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_responseandstreamboththrows(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_returnstreamFast(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_returnstreamFast(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_returnstreamFast(apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, ::apache::thrift::ServerStream<::std::int32_t>&& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_returnstreamFast(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  PubSubStreamingServiceAsyncProcessor(::apache::thrift::ServiceHandler<::cpp2::PubSubStreamingService>* iface) :
      iface_(iface) {}
  ~PubSubStreamingServiceAsyncProcessor() override {}
};

} // cpp2
