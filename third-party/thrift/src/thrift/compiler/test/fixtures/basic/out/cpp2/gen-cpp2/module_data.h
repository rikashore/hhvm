/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/basic/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/basic/gen-cpp2/module_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::test::fixtures::basic::MyEnum> {
  using type = ::test::fixtures::basic::MyEnum;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = { {
      type::MyValue1,
      type::MyValue2,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "MyValue1"sv,
      "MyValue2"sv,
  }};
};

template <> struct TEnumDataStorage<::test::fixtures::basic::HackEnum> {
  using type = ::test::fixtures::basic::HackEnum;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = { {
      type::Value1,
      type::Value2,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "Value1"sv,
      "Value2"sv,
  }};
};

template <> struct TEnumDataStorage<::test::fixtures::basic::MyUnion::Type> {
  using type = ::test::fixtures::basic::MyUnion::Type;
  static constexpr const std::size_t size = 4;
  static constexpr std::array<type, size> values = { {
      type::myEnum,
      type::myStruct,
      type::myDataItem,
      type::floatSet,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "myEnum"sv,
      "myStruct"sv,
      "myDataItem"sv,
      "floatSet"sv,
  }};
};

template <> struct TEnumDataStorage<::test::fixtures::basic::UnionToBeRenamed::Type> {
  using type = ::test::fixtures::basic::UnionToBeRenamed::Type;
  static constexpr const std::size_t size = 1;
  static constexpr std::array<type, size> values = { {
      type::reserved_field,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "reserved_field"sv,
  }};
};

template <> struct TStructDataStorage<::test::fixtures::basic::MyStruct> {
  static constexpr const std::size_t fields_size = 9;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<std::string_view, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::basic::Containers> {
  static constexpr const std::size_t fields_size = 3;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<std::string_view, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::basic::MyDataItem> {
  static constexpr const std::size_t fields_size = 0;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<std::string_view, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::basic::MyUnion> {
  static constexpr const std::size_t fields_size = 4;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<std::string_view, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::basic::ReservedKeyword> {
  static constexpr const std::size_t fields_size = 1;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<std::string_view, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::basic::UnionToBeRenamed> {
  static constexpr const std::size_t fields_size = 1;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<std::string_view, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

}} // apache::thrift
