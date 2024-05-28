/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#pragma once

#include <functional>
#include <folly/Range.h>

#include <thrift/lib/py3/enums.h>
#include "thrift/compiler/test/fixtures/int_limits/gen-cpp2/module_data.h"
#include "thrift/compiler/test/fixtures/int_limits/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/int_limits/gen-cpp2/module_metadata.h"
namespace thrift {
namespace py3 {



template<>
inline void reset_field<::cpp2::Limits>(
    ::cpp2::Limits& obj, uint16_t index) {
  switch (index) {
    case 0:
      obj.max_i64_field_ref().copy_from(default_inst<::cpp2::Limits>().max_i64_field_ref());
      return;
    case 1:
      obj.min_i64_field_ref().copy_from(default_inst<::cpp2::Limits>().min_i64_field_ref());
      return;
    case 2:
      obj.max_i32_field_ref().copy_from(default_inst<::cpp2::Limits>().max_i32_field_ref());
      return;
    case 3:
      obj.min_i32_field_ref().copy_from(default_inst<::cpp2::Limits>().min_i32_field_ref());
      return;
    case 4:
      obj.max_i16_field_ref().copy_from(default_inst<::cpp2::Limits>().max_i16_field_ref());
      return;
    case 5:
      obj.min_i16_field_ref().copy_from(default_inst<::cpp2::Limits>().min_i16_field_ref());
      return;
    case 6:
      obj.max_byte_field_ref().copy_from(default_inst<::cpp2::Limits>().max_byte_field_ref());
      return;
    case 7:
      obj.min_byte_field_ref().copy_from(default_inst<::cpp2::Limits>().min_byte_field_ref());
      return;
  }
}

template<>
inline const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::cpp2::Limits>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}
} // namespace py3
} // namespace thrift
