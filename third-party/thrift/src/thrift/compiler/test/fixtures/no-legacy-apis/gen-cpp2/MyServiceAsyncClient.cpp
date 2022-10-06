/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/no-legacy-apis/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/no-legacy-apis/gen-cpp2/MyServiceAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace test { namespace fixtures { namespace basic {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::variant, ::test::fixtures::basic::MyUnion*>> MyService_query_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::test::fixtures::basic::MyStruct*>> MyService_query_presult;
}}} // test::fixtures::basic
template <typename Protocol_, typename RpcOptions>
void apache::thrift::Client<::test::fixtures::basic::MyService>::queryT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::test::fixtures::basic::MyUnion& p_u) {

  ::test::fixtures::basic::MyService_query_pargs args;
  args.get<0>().value = const_cast<::test::fixtures::basic::MyUnion*>(&p_u);
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "query",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "test.dev/fixtures/no-legacy-apis/MyService");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::forward<RpcOptions>(rpcOptions), std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);
}




void apache::thrift::Client<::test::fixtures::basic::MyService>::query(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::test::fixtures::basic::MyUnion& p_u) {
  auto [ctx, header] = queryCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  queryImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_u);
}

void apache::thrift::Client<::test::fixtures::basic::MyService>::queryImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::test::fixtures::basic::MyUnion& p_u, bool stealRpcOptions) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      if (stealRpcOptions) {
        queryT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_u);
      } else {
        queryT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_u);
      }
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      if (stealRpcOptions) {
        queryT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_u);
      } else {
        queryT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_u);
      }
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::test::fixtures::basic::MyService>::queryCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      getServiceName(),
      "MyService.query",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::test::fixtures::basic::MyService>::sync_query(::test::fixtures::basic::MyStruct& _return, const ::test::fixtures::basic::MyUnion& p_u) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_query(rpcOptions, _return, p_u);
}

void apache::thrift::Client<::test::fixtures::basic::MyService>::sync_query(apache::thrift::RpcOptions& rpcOptions, ::test::fixtures::basic::MyStruct& _return, const ::test::fixtures::basic::MyUnion& p_u) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = queryCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  callback.waitUntilDone(
    evb,
    [&] {
      queryImpl(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback), p_u);
    });

  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::move(ctxAndHeader.first));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      recv_query(_return, returnState);
  });
}


folly::SemiFuture<::test::fixtures::basic::MyStruct> apache::thrift::Client<::test::fixtures::basic::MyService>::semifuture_query(const ::test::fixtures::basic::MyUnion& p_u) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_query(rpcOptions, p_u);
}

folly::SemiFuture<::test::fixtures::basic::MyStruct> apache::thrift::Client<::test::fixtures::basic::MyService>::semifuture_query(apache::thrift::RpcOptions& rpcOptions, const ::test::fixtures::basic::MyUnion& p_u) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_query, channel_);
  auto callback = std::move(callbackAndFuture.first);
  query(rpcOptions, std::move(callback), p_u);
  return std::move(callbackAndFuture.second);
}



#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::test::fixtures::basic::MyService>::recv_wrapped_query(::test::fixtures::basic::MyStruct& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::test::fixtures::basic::MyService_query_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void apache::thrift::Client<::test::fixtures::basic::MyService>::recv_query(::test::fixtures::basic::MyStruct& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_query(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}



