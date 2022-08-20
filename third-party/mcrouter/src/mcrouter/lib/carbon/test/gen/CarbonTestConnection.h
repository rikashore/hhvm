/*
 *  Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <mcrouter/lib/CacheClientStats.h>
#include <mcrouter/lib/carbon/connection/ExternalCarbonConnectionImpl.h>
#include <mcrouter/lib/carbon/connection/InternalCarbonConnectionImpl.h>
#include <mcrouter/lib/carbon/connection/PooledCarbonConnectionImpl.h>

#include "mcrouter/lib/carbon/test/gen/CarbonTestMessages.h"
#include "mcrouter/lib/carbon/test/gen/CarbonTestRouterInfo.h"

namespace carbon {
namespace test {

class CarbonTestConnection {
 public:
  using RouterInfo = CarbonTestRouterInfo;

  virtual ~CarbonTestConnection() = default;

  virtual void sendRequestOne(
      const TestRequest&,
      carbon::RequestCb<TestRequest>) = 0;
  virtual void sendRequestOne(
      const TestRequestStringKey&,
      carbon::RequestCb<TestRequestStringKey>) = 0;

  virtual void sendRequestMulti(
      std::vector<std::reference_wrapper<const TestRequest>>&&,
      carbon::RequestCb<TestRequest>) = 0;
  virtual void sendRequestMulti(
      std::vector<std::reference_wrapper<const TestRequestStringKey>>&&,
      carbon::RequestCb<TestRequestStringKey>) = 0;

  virtual facebook::memcache::CacheClientCounters getStatCounters() const noexcept = 0;
  virtual std::unordered_map<std::string, std::string> getConfigOptions() = 0;
  virtual bool healthCheck() = 0;
  virtual std::unique_ptr<CarbonTestConnection> recreate() = 0;
};

template <class Impl>
class CarbonTestConnectionImpl : public CarbonTestConnection {
 public:
  template <class... Args>
  explicit CarbonTestConnectionImpl(Args&&... args)
      : impl_(std::forward<Args>(args)...) {}

  ~CarbonTestConnectionImpl() = default;

  facebook::memcache::CacheClientCounters getStatCounters() const noexcept {
    return impl_.getStatCounters();
  }

  std::unordered_map<std::string, std::string> getConfigOptions() {
    return impl_.getConfigOptions();
  }

  bool healthCheck() {
    return impl_.healthCheck();
  }

  std::unique_ptr<CarbonTestConnection> recreate() {
    return impl_.template recreate<CarbonTestConnectionImpl<Impl>>();
  }

  void sendRequestOne(
      const TestRequest& req,
      carbon::RequestCb<TestRequest> cb) {
    return impl_.sendRequestOne(req, std::move(cb));
  }
  void sendRequestOne(
      const TestRequestStringKey& req,
      carbon::RequestCb<TestRequestStringKey> cb) {
    return impl_.sendRequestOne(req, std::move(cb));
  }

  void sendRequestMulti(
      std::vector<std::reference_wrapper<const TestRequest>>&& reqs,
      carbon::RequestCb<TestRequest> cb) {
    return impl_.sendRequestMulti(std::move(reqs), std::move(cb));
  }
  void sendRequestMulti(
      std::vector<std::reference_wrapper<const TestRequestStringKey>>&& reqs,
      carbon::RequestCb<TestRequestStringKey> cb) {
    return impl_.sendRequestMulti(std::move(reqs), std::move(cb));
  }

 private:
  Impl impl_;
};

using CarbonTestPooledConnection =
    CarbonTestConnectionImpl<carbon::PooledCarbonConnectionImpl<CarbonTestConnection>>;
using CarbonTestInternalConnection =
    CarbonTestConnectionImpl<carbon::InternalCarbonConnectionImpl<CarbonTestConnection>>;
using CarbonTestExternalConnection =
    CarbonTestConnectionImpl<carbon::ExternalCarbonConnectionImpl<CarbonTestRouterInfo>>;
} // namespace test
} // namespace carbon
