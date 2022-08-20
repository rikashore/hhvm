/**
 * Autogenerated by Thrift for src/include1.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/frozen-struct/gen-cpp2/include1_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::some::ns::IncludedA> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).i32Field_ref()...);
    f(1, static_cast<T&&>(t).strField_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
