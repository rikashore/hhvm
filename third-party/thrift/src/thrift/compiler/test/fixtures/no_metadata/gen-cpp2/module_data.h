/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/no_metadata/gen-cpp2/module_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::cpp2::MyEnum> {
  using type = ::cpp2::MyEnum;
  static constexpr const std::size_t size = 2;
  static const std::array<type, size> values;
  static const std::array<folly::StringPiece, size> names;
};

template <> struct TEnumDataStorage<::cpp2::MyUnion::Type> {
  using type = ::cpp2::MyUnion::Type;
  static constexpr const std::size_t size = 3;
  static const std::array<type, size> values;
  static const std::array<folly::StringPiece, size> names;
};

template <> struct TStructDataStorage<::cpp2::MyDataItem> {
  static constexpr const std::size_t fields_size = 0;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;
};

template <> struct TStructDataStorage<::cpp2::MyStruct> {
  static constexpr const std::size_t fields_size = 4;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;
};

template <> struct TStructDataStorage<::cpp2::MyUnion> {
  static constexpr const std::size_t fields_size = 3;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;
};

}} // apache::thrift
