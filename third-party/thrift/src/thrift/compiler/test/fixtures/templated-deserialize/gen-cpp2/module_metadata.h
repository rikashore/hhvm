/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <vector>

#include <thrift/lib/cpp2/gen/module_metadata_h.h>
#include "thrift/compiler/test/fixtures/templated-deserialize/gen-cpp2/module_types.h"


namespace apache {
namespace thrift {
namespace detail {
namespace md {

template <>
class EnumMetadata<::cpp2::MyEnumA> {
 public:
  static void gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::cpp2::SmallStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::cpp2::containerStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
