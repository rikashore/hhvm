/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <vector>

#include <thrift/lib/cpp2/gen/module_metadata_h.h>
#include "thrift/compiler/test/fixtures/namespace_from_package_without_module_name/gen-cpp2/module_types.h"

namespace test {
namespace namespace_from_package_without_module_name {
class TestService;
}} // namespace test::namespace_from_package_without_module_name

namespace apache {
namespace thrift {
namespace detail {
namespace md {

template <>
class StructMetadata<::test::namespace_from_package_without_module_name::Foo> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class ServiceMetadata<::apache::thrift::ServiceHandler<::test::namespace_from_package_without_module_name::TestService>> {
 public:
  static void gen(ThriftServiceMetadataResponse& response);
 private:
  static const ThriftServiceContextRef* genRecurse(ThriftMetadata& metadata, std::vector<ThriftServiceContextRef>& services);

  template <typename T>
  friend class ServiceMetadata;

  static void gen_init(ThriftMetadata& metadata, ThriftService& context);
};
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
