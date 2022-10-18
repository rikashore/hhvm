/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/basic-annotations/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/basic-annotations/gen-cpp2/module_data.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

#if defined(__GNUC__) && defined(__linux__) && !FOLLY_MOBILE
// This attribute is applied to the static data members to ensure that they are
// not stripped from the compiled binary, in order to keep them available for
// use by debuggers at runtime.
//
// The attribute works by forcing all of the data members (both used and unused
// ones) into the same section. This stops the linker from stripping the unused
// data, as it works on a per-section basis and only removes sections if they
// are entirely unused.
#define THRIFT_DATA_SECTION [[gnu::section(".rodata.thrift.data")]]
#else
#define THRIFT_DATA_SECTION
#endif

namespace apache {
namespace thrift {

THRIFT_DATA_SECTION const std::array<::cpp2::YourEnum, 3> TEnumDataStorage<::cpp2::YourEnum>::values = {{
  type::MyValue1,
  type::MyValue2,
  type::REALM,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 3> TEnumDataStorage<::cpp2::YourEnum>::names = {{
  "MyValue1",
  "MyValue2",
  "DOMAIN",
}};

THRIFT_DATA_SECTION const std::array<::cpp2::detail::YourUnion::Type, 0> TEnumDataStorage<::cpp2::detail::YourUnion::Type>::values = {{
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TEnumDataStorage<::cpp2::detail::YourUnion::Type>::names = {{
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::cpp2::MyStructNestedAnnotation>::fields_names = {{
  "name",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::cpp2::MyStructNestedAnnotation>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::cpp2::MyStructNestedAnnotation>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::cpp2::MyStructNestedAnnotation>::storage_names = {{
  "__fbthrift_field_name",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::cpp2::MyStructNestedAnnotation>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::cpp2::detail::YourUnion>::fields_names = {{
}};
THRIFT_DATA_SECTION const std::array<int16_t, 0> TStructDataStorage<::cpp2::detail::YourUnion>::fields_ids = {{
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 0> TStructDataStorage<::cpp2::detail::YourUnion>::fields_types = {{
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::cpp2::detail::YourUnion>::storage_names = {{
}};
THRIFT_DATA_SECTION const std::array<int, 0> TStructDataStorage<::cpp2::detail::YourUnion>::isset_indexes = {{
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::cpp2::detail::YourException>::fields_names = {{
}};
THRIFT_DATA_SECTION const std::array<int16_t, 0> TStructDataStorage<::cpp2::detail::YourException>::fields_ids = {{
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 0> TStructDataStorage<::cpp2::detail::YourException>::fields_types = {{
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::cpp2::detail::YourException>::storage_names = {{
}};
THRIFT_DATA_SECTION const std::array<int, 0> TStructDataStorage<::cpp2::detail::YourException>::isset_indexes = {{
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 10> TStructDataStorage<::cpp2::detail::YourStruct>::fields_names = {{
  "major",
  "package",
  "annotation_with_quote",
  "class_",
  "annotation_with_trailing_comma",
  "empty_annotations",
  "my_enum",
  "cpp_type_annotation",
  "my_union",
  "my_id",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 10> TStructDataStorage<::cpp2::detail::YourStruct>::fields_ids = {{
  2,
  1,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 10> TStructDataStorage<::cpp2::detail::YourStruct>::fields_types = {{
  TType::T_I64,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_I32,
  TType::T_LIST,
  TType::T_STRUCT,
  TType::T_I16,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 10> TStructDataStorage<::cpp2::detail::YourStruct>::storage_names = {{
  "__fbthrift_field_majorVer",
  "__fbthrift_field_package",
  "__fbthrift_field_annotation_with_quote",
  "__fbthrift_field_class_",
  "__fbthrift_field_annotation_with_trailing_comma",
  "__fbthrift_field_empty_annotations",
  "__fbthrift_field_my_enum",
  "__fbthrift_field_cpp_type_annotation",
  "__fbthrift_field_my_union",
  "__fbthrift_field_my_id",
}};
THRIFT_DATA_SECTION const std::array<int, 10> TStructDataStorage<::cpp2::detail::YourStruct>::isset_indexes = {{
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TStructDataStorage<::cpp2::SecretStruct>::fields_names = {{
  "id",
  "password",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 2> TStructDataStorage<::cpp2::SecretStruct>::fields_ids = {{
  1,
  2,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 2> TStructDataStorage<::cpp2::SecretStruct>::fields_types = {{
  TType::T_I64,
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TStructDataStorage<::cpp2::SecretStruct>::storage_names = {{
  "__fbthrift_field_id",
  "__fbthrift_field_password",
}};
THRIFT_DATA_SECTION const std::array<int, 2> TStructDataStorage<::cpp2::SecretStruct>::isset_indexes = {{
  0,
  1,
}};

} // namespace thrift
} // namespace apache
