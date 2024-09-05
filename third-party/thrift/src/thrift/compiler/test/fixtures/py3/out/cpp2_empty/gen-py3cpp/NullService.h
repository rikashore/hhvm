/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/py3/src/empty.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/py3/gen-py3cpp/NullServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/py3/gen-py3cpp/empty_types.h"

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
class NullService;
class NullServiceAsyncProcessor;

class NullServiceServiceInfoHolder : public apache::thrift::ServiceInfoHolder {
  public:
   apache::thrift::ServiceRequestInfoMap const& requestInfoMap() const override;
   static apache::thrift::ServiceRequestInfoMap staticRequestInfoMap();
};
} // namespace cpp2

namespace apache::thrift {
template <>
class ServiceHandler<::cpp2::NullService> : public apache::thrift::ServerInterface {
 public:
  std::string_view getGeneratedName() const override { return "NullService"; }

  typedef ::cpp2::NullServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  CreateMethodMetadataResult createMethodMetadata() override;
  bool isThriftGenerated() const override final { return true; }
 private:
  std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> getServiceRequestInfoMap() const;
 public:

 private:
  static ::cpp2::NullServiceServiceInfoHolder __fbthrift_serviceInfoHolder;
};

} // namespace apache::thrift

namespace cpp2 {
using NullServiceSvIf [[deprecated("Use apache::thrift::ServiceHandler<NullService> instead")]] = ::apache::thrift::ServiceHandler<NullService>;
} // namespace cpp2

namespace cpp2 {
class NullServiceSvNull : public ::apache::thrift::ServiceHandler<NullService> {
 public:
};

class NullServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessorBase {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  ::apache::thrift::ServiceHandler<::cpp2::NullService>* iface_;
 public:
  void processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  void executeRequest(apache::thrift::ServerRequest&& serverRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) override;
 public:
  using ProcessFuncs = GeneratedAsyncProcessorBase::ProcessFuncs<NullServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessorBase::ProcessMap<ProcessFuncs>;
  static const NullServiceAsyncProcessor::ProcessMap& getOwnProcessMap();
 private:
  static const NullServiceAsyncProcessor::ProcessMap kOwnProcessMap_;
 private:
 public:
  NullServiceAsyncProcessor(::apache::thrift::ServiceHandler<::cpp2::NullService>* iface) :
      iface_(iface) {}
  ~NullServiceAsyncProcessor() override {}
};

} // namespace cpp2
