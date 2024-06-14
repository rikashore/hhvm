/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/interactions/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include <thrift/compiler/test/fixtures/interactions/gen-py3/module/clients_wrapper.h>

namespace cpp2 {


folly::Future<folly::Unit>
MyServiceClientWrapper::foo(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<folly::Unit>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_foo, channel_);
  try {
    client->foo(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
MyServiceClientWrapper::interact(
    apache::thrift::RpcOptions& rpcOptions,
    int32_t arg_arg) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<folly::Unit>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_interact, channel_);
  try {
    client->interact(
      rpcOptions,
      std::move(callback),
      arg_arg
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<int32_t>
MyServiceClientWrapper::interactFast(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient*>(async_client_.get());
  folly::Promise<int32_t> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<int32_t>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_interactFast, channel_);
  try {
    client->interactFast(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<int32_t>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>>
MyServiceClientWrapper::serialize(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient*>(async_client_.get());
  folly::Promise<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_serialize, channel_);
  try {
    client->serialize(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}


folly::Future<std::unique_ptr<::thrift::py3::ClientWrapper>>
MyServiceClientWrapper::createMyInteraction() {
  return folly::via(
      channel_->getEventBase(),
      [=]() -> std::unique_ptr<::thrift::py3::ClientWrapper> {
        auto interaction_client = static_cast<std::unique_ptr<apache::thrift::GeneratedAsyncClient>>(std::make_unique<MyServiceAsyncClient::MyInteraction>(((MyServiceAsyncClient*)async_client_.get())->createMyInteraction()));
        return static_cast<std::unique_ptr<::thrift::py3::ClientWrapper>>(std::make_unique<MyInteractionInteractionWrapper>(std::move(interaction_client), channel_));
      }
  );
}


folly::Future<std::unique_ptr<::thrift::py3::ClientWrapper>>
MyServiceClientWrapper::createMyInteractionFast() {
  return folly::via(
      channel_->getEventBase(),
      [=]() -> std::unique_ptr<::thrift::py3::ClientWrapper> {
        auto interaction_client = static_cast<std::unique_ptr<apache::thrift::GeneratedAsyncClient>>(std::make_unique<MyServiceAsyncClient::MyInteractionFast>(((MyServiceAsyncClient*)async_client_.get())->createMyInteractionFast()));
        return static_cast<std::unique_ptr<::thrift::py3::ClientWrapper>>(std::make_unique<MyInteractionFastInteractionWrapper>(std::move(interaction_client), channel_));
      }
  );
}


folly::Future<std::unique_ptr<::thrift::py3::ClientWrapper>>
MyServiceClientWrapper::createSerialInteraction() {
  return folly::via(
      channel_->getEventBase(),
      [=]() -> std::unique_ptr<::thrift::py3::ClientWrapper> {
        auto interaction_client = static_cast<std::unique_ptr<apache::thrift::GeneratedAsyncClient>>(std::make_unique<MyServiceAsyncClient::SerialInteraction>(((MyServiceAsyncClient*)async_client_.get())->createSerialInteraction()));
        return static_cast<std::unique_ptr<::thrift::py3::ClientWrapper>>(std::make_unique<SerialInteractionInteractionWrapper>(std::move(interaction_client), channel_));
      }
  );
}

folly::Future<int32_t>
MyServiceClientWrapper::MyInteractionInteractionWrapper::frobnicate(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient::MyInteraction*>(async_client_.get());
  folly::Promise<int32_t> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<int32_t>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_frobnicate, channel_);
  try {
    client->frobnicate(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<int32_t>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
MyServiceClientWrapper::MyInteractionInteractionWrapper::ping(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient::MyInteraction*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::apache::thrift::OneWayFutureCallback>(
    std::move(_promise), channel_);
  try {
    client->ping(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<apache::thrift::ClientBufferedStream<bool>>
MyServiceClientWrapper::MyInteractionInteractionWrapper::truthify(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient::MyInteraction*>(async_client_.get());
  folly::Promise<apache::thrift::ClientBufferedStream<bool>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<apache::thrift::ClientBufferedStream<bool>>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_truthify, channel_);
  try {
    client->truthify(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<apache::thrift::ClientBufferedStream<bool>>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<int32_t>
MyServiceClientWrapper::MyInteractionFastInteractionWrapper::frobnicate(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient::MyInteractionFast*>(async_client_.get());
  folly::Promise<int32_t> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<int32_t>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_frobnicate, channel_);
  try {
    client->frobnicate(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<int32_t>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
MyServiceClientWrapper::MyInteractionFastInteractionWrapper::ping(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient::MyInteractionFast*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::apache::thrift::OneWayFutureCallback>(
    std::move(_promise), channel_);
  try {
    client->ping(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<apache::thrift::ClientBufferedStream<bool>>
MyServiceClientWrapper::MyInteractionFastInteractionWrapper::truthify(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient::MyInteractionFast*>(async_client_.get());
  folly::Promise<apache::thrift::ClientBufferedStream<bool>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<apache::thrift::ClientBufferedStream<bool>>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_truthify, channel_);
  try {
    client->truthify(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<apache::thrift::ClientBufferedStream<bool>>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
MyServiceClientWrapper::SerialInteractionInteractionWrapper::frobnicate(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::MyServiceAsyncClient::SerialInteraction*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<folly::Unit>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_frobnicate, channel_);
  try {
    client->frobnicate(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
FactoriesClientWrapper::foo(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::FactoriesAsyncClient*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<folly::Unit>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_foo, channel_);
  try {
    client->foo(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
FactoriesClientWrapper::interact(
    apache::thrift::RpcOptions& rpcOptions,
    int32_t arg_arg) {
  auto* client = static_cast<::cpp2::FactoriesAsyncClient*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<folly::Unit>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_interact, channel_);
  try {
    client->interact(
      rpcOptions,
      std::move(callback),
      arg_arg
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<int32_t>
FactoriesClientWrapper::interactFast(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::FactoriesAsyncClient*>(async_client_.get());
  folly::Promise<int32_t> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<int32_t>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_interactFast, channel_);
  try {
    client->interactFast(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<int32_t>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>>
FactoriesClientWrapper::serialize(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::FactoriesAsyncClient*>(async_client_.get());
  folly::Promise<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_serialize, channel_);
  try {
    client->serialize(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
PerformClientWrapper::foo(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::PerformAsyncClient*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<folly::Unit>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_foo, channel_);
  try {
    client->foo(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}


folly::Future<std::unique_ptr<::thrift::py3::ClientWrapper>>
PerformClientWrapper::createMyInteraction() {
  return folly::via(
      channel_->getEventBase(),
      [=]() -> std::unique_ptr<::thrift::py3::ClientWrapper> {
        auto interaction_client = static_cast<std::unique_ptr<apache::thrift::GeneratedAsyncClient>>(std::make_unique<PerformAsyncClient::MyInteraction>(((PerformAsyncClient*)async_client_.get())->createMyInteraction()));
        return static_cast<std::unique_ptr<::thrift::py3::ClientWrapper>>(std::make_unique<MyInteractionInteractionWrapper>(std::move(interaction_client), channel_));
      }
  );
}


folly::Future<std::unique_ptr<::thrift::py3::ClientWrapper>>
PerformClientWrapper::createMyInteractionFast() {
  return folly::via(
      channel_->getEventBase(),
      [=]() -> std::unique_ptr<::thrift::py3::ClientWrapper> {
        auto interaction_client = static_cast<std::unique_ptr<apache::thrift::GeneratedAsyncClient>>(std::make_unique<PerformAsyncClient::MyInteractionFast>(((PerformAsyncClient*)async_client_.get())->createMyInteractionFast()));
        return static_cast<std::unique_ptr<::thrift::py3::ClientWrapper>>(std::make_unique<MyInteractionFastInteractionWrapper>(std::move(interaction_client), channel_));
      }
  );
}


folly::Future<std::unique_ptr<::thrift::py3::ClientWrapper>>
PerformClientWrapper::createSerialInteraction() {
  return folly::via(
      channel_->getEventBase(),
      [=]() -> std::unique_ptr<::thrift::py3::ClientWrapper> {
        auto interaction_client = static_cast<std::unique_ptr<apache::thrift::GeneratedAsyncClient>>(std::make_unique<PerformAsyncClient::SerialInteraction>(((PerformAsyncClient*)async_client_.get())->createSerialInteraction()));
        return static_cast<std::unique_ptr<::thrift::py3::ClientWrapper>>(std::make_unique<SerialInteractionInteractionWrapper>(std::move(interaction_client), channel_));
      }
  );
}

folly::Future<int32_t>
PerformClientWrapper::MyInteractionInteractionWrapper::frobnicate(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::PerformAsyncClient::MyInteraction*>(async_client_.get());
  folly::Promise<int32_t> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<int32_t>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_frobnicate, channel_);
  try {
    client->frobnicate(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<int32_t>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
PerformClientWrapper::MyInteractionInteractionWrapper::ping(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::PerformAsyncClient::MyInteraction*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::apache::thrift::OneWayFutureCallback>(
    std::move(_promise), channel_);
  try {
    client->ping(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<apache::thrift::ClientBufferedStream<bool>>
PerformClientWrapper::MyInteractionInteractionWrapper::truthify(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::PerformAsyncClient::MyInteraction*>(async_client_.get());
  folly::Promise<apache::thrift::ClientBufferedStream<bool>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<apache::thrift::ClientBufferedStream<bool>>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_truthify, channel_);
  try {
    client->truthify(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<apache::thrift::ClientBufferedStream<bool>>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<int32_t>
PerformClientWrapper::MyInteractionFastInteractionWrapper::frobnicate(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::PerformAsyncClient::MyInteractionFast*>(async_client_.get());
  folly::Promise<int32_t> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<int32_t>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_frobnicate, channel_);
  try {
    client->frobnicate(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<int32_t>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
PerformClientWrapper::MyInteractionFastInteractionWrapper::ping(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::PerformAsyncClient::MyInteractionFast*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::apache::thrift::OneWayFutureCallback>(
    std::move(_promise), channel_);
  try {
    client->ping(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<apache::thrift::ClientBufferedStream<bool>>
PerformClientWrapper::MyInteractionFastInteractionWrapper::truthify(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::PerformAsyncClient::MyInteractionFast*>(async_client_.get());
  folly::Promise<apache::thrift::ClientBufferedStream<bool>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<apache::thrift::ClientBufferedStream<bool>>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_truthify, channel_);
  try {
    client->truthify(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<apache::thrift::ClientBufferedStream<bool>>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

folly::Future<folly::Unit>
PerformClientWrapper::SerialInteractionInteractionWrapper::frobnicate(
    apache::thrift::RpcOptions& rpcOptions) {
  auto* client = static_cast<::cpp2::PerformAsyncClient::SerialInteraction*>(async_client_.get());
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<::thrift::py3::FutureCallback<folly::Unit>>(
    std::move(_promise), rpcOptions, client->recv_wrapped_frobnicate, channel_);
  try {
    client->frobnicate(
      rpcOptions,
      std::move(callback)
    );
  } catch (...) {
    return folly::makeFuture<folly::Unit>(folly::exception_wrapper(
      std::current_exception()
    ));
  }
  return _future;
}

} // namespace cpp2
