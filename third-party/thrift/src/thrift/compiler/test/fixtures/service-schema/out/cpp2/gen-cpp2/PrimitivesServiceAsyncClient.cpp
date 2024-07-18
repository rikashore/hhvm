/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/service-schema/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/service-schema/gen-cpp2/PrimitivesServiceAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::integral, ::std::int64_t*>, apache::thrift::FieldData<2, ::apache::thrift::type_class::integral, ::std::int64_t*>> PrimitivesService_init_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::integral, ::std::int64_t*>> PrimitivesService_init_presult;
typedef apache::thrift::ThriftPresult<false> PrimitivesService_method_that_throws_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::enumeration, ::cpp2::Result*>, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::CustomException>> PrimitivesService_method_that_throws_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::integral, ::std::int64_t*>> PrimitivesService_return_void_method_pargs;
typedef apache::thrift::ThriftPresult<true> PrimitivesService_return_void_method_presult;
} // namespace cpp2
template <typename Protocol_, typename RpcOptions>
void apache::thrift::Client<::cpp2::PrimitivesService>::initT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int64_t p_param0, ::std::int64_t p_param1) {

  ::cpp2::PrimitivesService_init_pargs args;
  args.get<0>().value = &p_param0;
  args.get<1>().value = &p_param1;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "init",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "PrimitivesService");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::forward<RpcOptions>(rpcOptions), std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);
}

template <typename Protocol_, typename RpcOptions>
void apache::thrift::Client<::cpp2::PrimitivesService>::method_that_throwsT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback) {

  ::cpp2::PrimitivesService_method_that_throws_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "method_that_throws",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "PrimitivesService");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::forward<RpcOptions>(rpcOptions), std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);
}

template <typename Protocol_, typename RpcOptions>
void apache::thrift::Client<::cpp2::PrimitivesService>::return_void_methodT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int64_t p_id) {

  ::cpp2::PrimitivesService_return_void_method_pargs args;
  args.get<0>().value = &p_id;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "return_void_method",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "PrimitivesService");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::forward<RpcOptions>(rpcOptions), std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);
}



void apache::thrift::Client<::cpp2::PrimitivesService>::init(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int64_t p_param0, ::std::int64_t p_param1) {
  ::apache::thrift::RpcOptions rpcOptions;
  init(rpcOptions, std::move(callback), p_param0, p_param1);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::init(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int64_t p_param0, ::std::int64_t p_param1) {
  auto [ctx, header] = initCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  initImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_param0, p_param1);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::initImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int64_t p_param0, ::std::int64_t p_param1, bool stealRpcOptions) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      if (stealRpcOptions) {
        initT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_param0, p_param1);
      } else {
        initT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_param0, p_param1);
      }
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      if (stealRpcOptions) {
        initT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_param0, p_param1);
      } else {
        initT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_param0, p_param1);
      }
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::cpp2::PrimitivesService>::initCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      nullptr, /* clientInterceptors */
      getServiceName(),
      "PrimitivesService.init",
      *header);

  return {std::move(ctx), std::move(header)};
}

::std::int64_t apache::thrift::Client<::cpp2::PrimitivesService>::sync_init(::std::int64_t p_param0, ::std::int64_t p_param1) {
  ::apache::thrift::RpcOptions rpcOptions;
  return sync_init(rpcOptions, p_param0, p_param1);
}

::std::int64_t apache::thrift::Client<::cpp2::PrimitivesService>::sync_init(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_param0, ::std::int64_t p_param1) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = initCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  callback.waitUntilDone(
    evb,
    [&] {
      initImpl(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback), p_param0, p_param1);
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
      return recv_init(returnState);
  });
}


folly::Future<::std::int64_t> apache::thrift::Client<::cpp2::PrimitivesService>::future_init(::std::int64_t p_param0, ::std::int64_t p_param1) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_init(rpcOptions, p_param0, p_param1);
}

folly::SemiFuture<::std::int64_t> apache::thrift::Client<::cpp2::PrimitivesService>::semifuture_init(::std::int64_t p_param0, ::std::int64_t p_param1) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_init(rpcOptions, p_param0, p_param1);
}

folly::Future<::std::int64_t> apache::thrift::Client<::cpp2::PrimitivesService>::future_init(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_param0, ::std::int64_t p_param1) {
  folly::Promise<::std::int64_t> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::std::int64_t>>(std::move(promise), recv_wrapped_init, channel_);
  init(rpcOptions, std::move(callback), p_param0, p_param1);
  return future;
}

folly::SemiFuture<::std::int64_t> apache::thrift::Client<::cpp2::PrimitivesService>::semifuture_init(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_param0, ::std::int64_t p_param1) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_init, channel_);
  auto callback = std::move(callbackAndFuture.first);
  init(rpcOptions, std::move(callback), p_param0, p_param1);
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<::std::int64_t, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::PrimitivesService>::header_future_init(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_param0, ::std::int64_t p_param1) {
  folly::Promise<std::pair<::std::int64_t, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<::std::int64_t>>(std::move(promise), recv_wrapped_init, channel_);
  init(rpcOptions, std::move(callback), p_param0, p_param1);
  return future;
}

folly::SemiFuture<std::pair<::std::int64_t, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::PrimitivesService>::header_semifuture_init(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_param0, ::std::int64_t p_param1) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_init, channel_);
  auto callback = std::move(callbackAndFuture.first);
  init(rpcOptions, std::move(callback), p_param0, p_param1);
  return std::move(callbackAndFuture.second);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::init(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, ::std::int64_t p_param0, ::std::int64_t p_param1) {
  init(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), p_param0, p_param1);
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::cpp2::PrimitivesService>::recv_wrapped_init(::std::int64_t& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::cpp2::PrimitivesService_init_presult;
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

::std::int64_t apache::thrift::Client<::cpp2::PrimitivesService>::recv_init(::apache::thrift::ClientReceiveState& state) {
  ::std::int64_t _return;
  auto ew = recv_wrapped_init(_return, state);
  if (ew) {
    ew.throw_exception();
  }
  return _return;
}

::std::int64_t apache::thrift::Client<::cpp2::PrimitivesService>::recv_instance_init(::apache::thrift::ClientReceiveState& state) {
  return recv_init(state);
}

folly::exception_wrapper apache::thrift::Client<::cpp2::PrimitivesService>::recv_instance_wrapped_init(::std::int64_t& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_init(_return, state);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::method_that_throws(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  method_that_throws(rpcOptions, std::move(callback));
}

void apache::thrift::Client<::cpp2::PrimitivesService>::method_that_throws(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto [ctx, header] = method_that_throwsCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  method_that_throwsImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback));
}

void apache::thrift::Client<::cpp2::PrimitivesService>::method_that_throwsImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, bool stealRpcOptions) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      if (stealRpcOptions) {
        method_that_throwsT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback));
      } else {
        method_that_throwsT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback));
      }
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      if (stealRpcOptions) {
        method_that_throwsT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback));
      } else {
        method_that_throwsT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback));
      }
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::cpp2::PrimitivesService>::method_that_throwsCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      nullptr, /* clientInterceptors */
      getServiceName(),
      "PrimitivesService.method_that_throws",
      *header);

  return {std::move(ctx), std::move(header)};
}

::cpp2::Result apache::thrift::Client<::cpp2::PrimitivesService>::sync_method_that_throws() {
  ::apache::thrift::RpcOptions rpcOptions;
  return sync_method_that_throws(rpcOptions);
}

::cpp2::Result apache::thrift::Client<::cpp2::PrimitivesService>::sync_method_that_throws(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = method_that_throwsCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  callback.waitUntilDone(
    evb,
    [&] {
      method_that_throwsImpl(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback));
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
      return recv_method_that_throws(returnState);
  });
}


folly::Future<::cpp2::Result> apache::thrift::Client<::cpp2::PrimitivesService>::future_method_that_throws() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_method_that_throws(rpcOptions);
}

folly::SemiFuture<::cpp2::Result> apache::thrift::Client<::cpp2::PrimitivesService>::semifuture_method_that_throws() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_method_that_throws(rpcOptions);
}

folly::Future<::cpp2::Result> apache::thrift::Client<::cpp2::PrimitivesService>::future_method_that_throws(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<::cpp2::Result> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::cpp2::Result>>(std::move(promise), recv_wrapped_method_that_throws, channel_);
  method_that_throws(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<::cpp2::Result> apache::thrift::Client<::cpp2::PrimitivesService>::semifuture_method_that_throws(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_method_that_throws, channel_);
  auto callback = std::move(callbackAndFuture.first);
  method_that_throws(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<::cpp2::Result, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::PrimitivesService>::header_future_method_that_throws(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<::cpp2::Result, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<::cpp2::Result>>(std::move(promise), recv_wrapped_method_that_throws, channel_);
  method_that_throws(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<std::pair<::cpp2::Result, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::PrimitivesService>::header_semifuture_method_that_throws(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_method_that_throws, channel_);
  auto callback = std::move(callbackAndFuture.first);
  method_that_throws(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::method_that_throws(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  method_that_throws(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::cpp2::PrimitivesService>::recv_wrapped_method_that_throws(::cpp2::Result& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::cpp2::PrimitivesService_method_that_throws_presult;
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

::cpp2::Result apache::thrift::Client<::cpp2::PrimitivesService>::recv_method_that_throws(::apache::thrift::ClientReceiveState& state) {
  ::cpp2::Result _return;
  auto ew = recv_wrapped_method_that_throws(_return, state);
  if (ew) {
    ew.throw_exception();
  }
  return _return;
}

::cpp2::Result apache::thrift::Client<::cpp2::PrimitivesService>::recv_instance_method_that_throws(::apache::thrift::ClientReceiveState& state) {
  return recv_method_that_throws(state);
}

folly::exception_wrapper apache::thrift::Client<::cpp2::PrimitivesService>::recv_instance_wrapped_method_that_throws(::cpp2::Result& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_method_that_throws(_return, state);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::return_void_method(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int64_t p_id) {
  ::apache::thrift::RpcOptions rpcOptions;
  return_void_method(rpcOptions, std::move(callback), p_id);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::return_void_method(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int64_t p_id) {
  auto [ctx, header] = return_void_methodCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  return_void_methodImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_id);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::return_void_methodImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int64_t p_id, bool stealRpcOptions) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      if (stealRpcOptions) {
        return_void_methodT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_id);
      } else {
        return_void_methodT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_id);
      }
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      if (stealRpcOptions) {
        return_void_methodT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_id);
      } else {
        return_void_methodT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_id);
      }
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::cpp2::PrimitivesService>::return_void_methodCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      nullptr, /* clientInterceptors */
      getServiceName(),
      "PrimitivesService.return_void_method",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::cpp2::PrimitivesService>::sync_return_void_method(::std::int64_t p_id) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_return_void_method(rpcOptions, p_id);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::sync_return_void_method(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_id) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = return_void_methodCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  callback.waitUntilDone(
    evb,
    [&] {
      return_void_methodImpl(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback), p_id);
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
      recv_return_void_method(returnState);
  });
}


folly::Future<folly::Unit> apache::thrift::Client<::cpp2::PrimitivesService>::future_return_void_method(::std::int64_t p_id) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_return_void_method(rpcOptions, p_id);
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::PrimitivesService>::semifuture_return_void_method(::std::int64_t p_id) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_return_void_method(rpcOptions, p_id);
}

folly::Future<folly::Unit> apache::thrift::Client<::cpp2::PrimitivesService>::future_return_void_method(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_id) {
  folly::Promise<folly::Unit> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_return_void_method, channel_);
  return_void_method(rpcOptions, std::move(callback), p_id);
  return future;
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::PrimitivesService>::semifuture_return_void_method(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_id) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_return_void_method, channel_);
  auto callback = std::move(callbackAndFuture.first);
  return_void_method(rpcOptions, std::move(callback), p_id);
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::PrimitivesService>::header_future_return_void_method(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_id) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_return_void_method, channel_);
  return_void_method(rpcOptions, std::move(callback), p_id);
  return future;
}

folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::PrimitivesService>::header_semifuture_return_void_method(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_id) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_return_void_method, channel_);
  auto callback = std::move(callbackAndFuture.first);
  return_void_method(rpcOptions, std::move(callback), p_id);
  return std::move(callbackAndFuture.second);
}

void apache::thrift::Client<::cpp2::PrimitivesService>::return_void_method(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, ::std::int64_t p_id) {
  return_void_method(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), p_id);
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::cpp2::PrimitivesService>::recv_wrapped_return_void_method(::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::cpp2::PrimitivesService_return_void_method_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void apache::thrift::Client<::cpp2::PrimitivesService>::recv_return_void_method(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_return_void_method(state);
  if (ew) {
    ew.throw_exception();
  }
}

void apache::thrift::Client<::cpp2::PrimitivesService>::recv_instance_return_void_method(::apache::thrift::ClientReceiveState& state) {
  recv_return_void_method(state);
}

folly::exception_wrapper apache::thrift::Client<::cpp2::PrimitivesService>::recv_instance_wrapped_return_void_method(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_return_void_method(state);
}


