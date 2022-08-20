/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/visitation/visit_by_thrift_field_metadata.h>
#include "thrift/compiler/test/fixtures/basic-annotations/gen-cpp2/module_metadata.h"

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitByFieldId<::cpp2::MyStructNestedAnnotation> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).name_ref());
    default:
      throwInvalidThriftId(fieldId, "::cpp2::MyStructNestedAnnotation");
    }
  }
};

template <>
struct VisitByFieldId<::cpp2::detail::YourUnion> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    default:
      throwInvalidThriftId(fieldId, "::cpp2::detail::YourUnion");
    }
  }
};

template <>
struct VisitByFieldId<::cpp2::detail::YourException> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    default:
      throwInvalidThriftId(fieldId, "::cpp2::detail::YourException");
    }
  }
};

template <>
struct VisitByFieldId<::cpp2::detail::YourStruct> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    case 2:
      return f(0, static_cast<T&&>(t).majorVer_ref());
    case 1:
      return f(1, static_cast<T&&>(t).package_ref());
    case 3:
      return f(2, static_cast<T&&>(t).annotation_with_quote_ref());
    case 4:
      return f(3, static_cast<T&&>(t).class__ref());
    case 5:
      return f(4, static_cast<T&&>(t).annotation_with_trailing_comma_ref());
    case 6:
      return f(5, static_cast<T&&>(t).empty_annotations_ref());
    case 7:
      return f(6, static_cast<T&&>(t).my_enum_ref());
    case 8:
      return f(7, static_cast<T&&>(t).cpp_type_annotation_ref());
    case 9:
      return f(8, static_cast<T&&>(t).my_union_ref());
    case 10:
      return f(9, static_cast<T&&>(t).my_id_ref());
    default:
      throwInvalidThriftId(fieldId, "::cpp2::detail::YourStruct");
    }
  }
};

template <>
struct VisitByFieldId<::cpp2::SecretStruct> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, int32_t fieldId, FOLLY_MAYBE_UNUSED T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).id_ref());
    case 2:
      return f(1, static_cast<T&&>(t).password_ref());
    default:
      throwInvalidThriftId(fieldId, "::cpp2::SecretStruct");
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
