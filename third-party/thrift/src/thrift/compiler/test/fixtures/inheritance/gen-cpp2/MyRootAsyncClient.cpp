/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyRootAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> MyRoot_do_root_pargs;
typedef apache::thrift::ThriftPresult<true> MyRoot_do_root_presult;
} // cpp2
template <typename Protocol_, typename RpcOptions>
void apache::thrift::Client<::cpp2::MyRoot>::do_rootT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback) {

  ::cpp2::MyRoot_do_root_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "do_root",
                ::apache::thrift::FunctionQualifier::Unspecified);
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::forward<RpcOptions>(rpcOptions), std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);
}



void apache::thrift::Client<::cpp2::MyRoot>::do_root(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  do_root(rpcOptions, std::move(callback));
}

void apache::thrift::Client<::cpp2::MyRoot>::do_root(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto [ctx, header] = do_rootCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  do_rootImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback));
}

void apache::thrift::Client<::cpp2::MyRoot>::do_rootImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, bool stealRpcOptions) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      if (stealRpcOptions) {
        do_rootT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback));
      } else {
        do_rootT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback));
      }
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      if (stealRpcOptions) {
        do_rootT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback));
      } else {
        do_rootT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback));
      }
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::cpp2::MyRoot>::do_rootCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      getServiceName(),
      "MyRoot.do_root",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::cpp2::MyRoot>::sync_do_root() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_do_root(rpcOptions);
}

void apache::thrift::Client<::cpp2::MyRoot>::sync_do_root(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = do_rootCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  callback.waitUntilDone(
    evb,
    [&] {
      do_rootImpl(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback));
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
      recv_do_root(returnState);
  });
}


folly::Future<folly::Unit> apache::thrift::Client<::cpp2::MyRoot>::future_do_root() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_do_root(rpcOptions);
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::MyRoot>::semifuture_do_root() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_do_root(rpcOptions);
}

folly::Future<folly::Unit> apache::thrift::Client<::cpp2::MyRoot>::future_do_root(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<folly::Unit> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_do_root, channel_);
  do_root(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::MyRoot>::semifuture_do_root(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_do_root, channel_);
  auto callback = std::move(callbackAndFuture.first);
  do_root(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyRoot>::header_future_do_root(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_do_root, channel_);
  do_root(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyRoot>::header_semifuture_do_root(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_do_root, channel_);
  auto callback = std::move(callbackAndFuture.first);
  do_root(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

void apache::thrift::Client<::cpp2::MyRoot>::do_root(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  do_root(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::cpp2::MyRoot>::recv_wrapped_do_root(::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::cpp2::MyRoot_do_root_presult;
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

void apache::thrift::Client<::cpp2::MyRoot>::recv_do_root(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_do_root(state);
  if (ew) {
    ew.throw_exception();
  }
}

void apache::thrift::Client<::cpp2::MyRoot>::recv_instance_do_root(::apache::thrift::ClientReceiveState& state) {
  recv_do_root(state);
}

folly::exception_wrapper apache::thrift::Client<::cpp2::MyRoot>::recv_instance_wrapped_do_root(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_do_root(state);
}


