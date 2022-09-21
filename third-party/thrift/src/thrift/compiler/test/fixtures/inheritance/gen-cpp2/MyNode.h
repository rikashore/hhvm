/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyNodeAsyncClient.h"
#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/module_types.h"
#if __has_include("thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyRoot.h")
#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyRoot.h"
#else
#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/module_handlers.h"
#endif

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
class MyNode;
class MyNodeAsyncProcessor;

class MyNodeServiceInfoHolder : public apache::thrift::ServiceInfoHolder {
  public:
   apache::thrift::ServiceRequestInfoMap const& requestInfoMap() const override;
   static apache::thrift::ServiceRequestInfoMap staticRequestInfoMap();
};
} // cpp2

namespace apache::thrift {
template <>
class ServiceHandler<::cpp2::MyNode> : virtual public ::cpp2::MyRootSvIf {
 public:
  std::string_view getGeneratedName() const override { return "MyNode"; }

  typedef ::cpp2::MyNodeAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  CreateMethodMetadataResult createMethodMetadata() override;
 private:
  std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> getServiceRequestInfoMap() const;
 public:

  virtual void sync_do_mid();
  [[deprecated("Use sync_do_mid instead")]] virtual void do_mid();
  virtual folly::Future<folly::Unit> future_do_mid();
  virtual folly::SemiFuture<folly::Unit> semifuture_do_mid();
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<void> co_do_mid();
  virtual folly::coro::Task<void> co_do_mid(apache::thrift::RequestParams params);
#endif
  virtual void async_tm_do_mid(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback);
 private:
  static ::cpp2::MyNodeServiceInfoHolder __fbthrift_serviceInfoHolder;
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_do_mid{apache::thrift::detail::si::InvocationType::AsyncTm};
};

} // namespace apache::thrift

namespace cpp2 {
using MyNodeSvIf [[deprecated("Use apache::thrift::ServiceHandler<MyNode> instead")]] = ::apache::thrift::ServiceHandler<MyNode>;
} // cpp2
namespace cpp2 {
class MyNodeSvNull : public ::apache::thrift::ServiceHandler<MyNode>, virtual public ::apache::thrift::ServiceHandler<::cpp2::MyRoot> {
 public:
  void do_mid() override;
};

class MyNodeAsyncProcessor : public ::cpp2::MyRootAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = ::cpp2::MyRootAsyncProcessor;
 protected:
  ::apache::thrift::ServiceHandler<::cpp2::MyNode>* iface_;
 public:
  // This is implemented in case the corresponding AsyncProcessorFactory did not implement createMethodMetadata.
  // This can happen if the service is using a custom AsyncProcessorFactory but re-using the same AsyncProcessor.
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  // By default, this overload will be called for generated services
  void processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  void executeRequest(apache::thrift::ServerRequest&& serverRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) override;
 public:
  using ProcessFuncs = GeneratedAsyncProcessorBase::ProcessFuncs<MyNodeAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessorBase::ProcessMap<ProcessFuncs>;
  static const MyNodeAsyncProcessor::ProcessMap& getOwnProcessMap();
 private:
  static const MyNodeAsyncProcessor::ProcessMap kOwnProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_do_mid(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_do_mid(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::SerializedResponse return_do_mid(apache::thrift::ContextStack* ctx);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_do_mid(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  MyNodeAsyncProcessor(::apache::thrift::ServiceHandler<::cpp2::MyNode>* iface) :
      ::cpp2::MyRootAsyncProcessor(iface),
      iface_(iface) {}
  ~MyNodeAsyncProcessor() override {}
};

} // cpp2
