/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/visitation/visit_by_thrift_field_metadata.h>
#include "thrift/compiler/test/fixtures/basic/gen-cpp2/module_metadata.h"

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitByFieldId<::test::fixtures::basic::MyDataItem> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    default:
      throwInvalidThriftId(fieldId, "::test::fixtures::basic::MyDataItem");
    }
  }
};

template <>
struct VisitByFieldId<::test::fixtures::basic::MyStruct> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).MyIntField_ref());
    case 2:
      return f(1, static_cast<T&&>(t).MyStringField_ref());
    case 3:
      return f(2, static_cast<T&&>(t).MyDataField_ref());
    case 4:
      return f(3, static_cast<T&&>(t).myEnum_ref());
    case 5:
      return f(4, static_cast<T&&>(t).oneway_ref());
    case 6:
      return f(5, static_cast<T&&>(t).readonly_ref());
    case 7:
      return f(6, static_cast<T&&>(t).idempotent_ref());
    case 8:
      return f(7, static_cast<T&&>(t).floatSet_ref());
    case 9:
      return f(8, static_cast<T&&>(t).no_hack_codegen_field_ref());
    default:
      throwInvalidThriftId(fieldId, "::test::fixtures::basic::MyStruct");
    }
  }
};

template <>
struct VisitByFieldId<::test::fixtures::basic::MyUnion> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).myEnum_ref());
    case 2:
      return f(1, static_cast<T&&>(t).myStruct_ref());
    case 3:
      return f(2, static_cast<T&&>(t).myDataItem_ref());
    case 4:
      return f(3, static_cast<T&&>(t).floatSet_ref());
    default:
      throwInvalidThriftId(fieldId, "::test::fixtures::basic::MyUnion");
    }
  }
};

template <>
struct VisitByFieldId<::test::fixtures::basic::ReservedKeyword> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).reserved_field_ref());
    default:
      throwInvalidThriftId(fieldId, "::test::fixtures::basic::ReservedKeyword");
    }
  }
};

template <>
struct VisitByFieldId<::test::fixtures::basic::UnionToBeRenamed> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).reserved_field_ref());
    default:
      throwInvalidThriftId(fieldId, "::test::fixtures::basic::UnionToBeRenamed");
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
