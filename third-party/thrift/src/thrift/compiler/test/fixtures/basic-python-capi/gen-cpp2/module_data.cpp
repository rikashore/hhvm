/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/basic-python-capi/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/basic-python-capi/gen-cpp2/module_data.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

FOLLY_CLANG_DISABLE_WARNING("-Wunused-macros")

#if defined(__GNUC__) && defined(__linux__) && !FOLLY_MOBILE
// These attributes are applied to the static data members to ensure that they
// are not stripped from the compiled binary, in order to keep them available
// for use by debuggers at runtime.
//
// The "used" attribute is required to ensure the compiler always emits unused
// data.
//
// The "section" attribute is required to stop the linker from stripping used
// data. It works by forcing all of the data members (both used and unused ones)
// into the same section. As the linker strips data on a per-section basis, it
// is then unable to remove unused data without also removing used data.
// This has a similar effect to the "retain" attribute, but works with older
// toolchains.
#define THRIFT_DATA_MEMBER [[gnu::used]] [[gnu::section(".rodata.thrift.data")]]
#else
#define THRIFT_DATA_MEMBER
#endif

namespace apache {
namespace thrift {

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyStruct>::name = "MyStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStruct>::fields_names = {{
  "inty",
  "stringy",
  "myItemy",
  "myEnumy",
  "booly",
  "floatListy",
  "strMappy",
  "intSetty",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStruct>::fields_types = {{
  TType::T_I64,
  TType::T_STRING,
  TType::T_STRUCT,
  TType::T_I32,
  TType::T_BOOL,
  TType::T_LIST,
  TType::T_MAP,
  TType::T_SET,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStruct>::storage_names = {{
  "__fbthrift_field_inty",
  "__fbthrift_field_stringy",
  "__fbthrift_field_myItemy",
  "__fbthrift_field_myEnumy",
  "__fbthrift_field_boulet",
  "__fbthrift_field_floatListy",
  "__fbthrift_field_strMappy",
  "__fbthrift_field_intSetty",
}};
THRIFT_DATA_MEMBER const std::array<int, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStruct>::isset_indexes = {{
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItem>::name = "MyDataItem";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItem>::fields_names = {{
  "s",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItem>::fields_ids = {{
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItem>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItem>::storage_names = {{
  "__fbthrift_field_s",
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItem>::isset_indexes = {{
  0,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::TransitiveDoubler>::name = "TransitiveDoubler";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 0> TStructDataStorage<::test::fixtures::basic-python-capi::TransitiveDoubler>::fields_names = {{
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 0> TStructDataStorage<::test::fixtures::basic-python-capi::TransitiveDoubler>::fields_ids = {{
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 0> TStructDataStorage<::test::fixtures::basic-python-capi::TransitiveDoubler>::fields_types = {{
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 0> TStructDataStorage<::test::fixtures::basic-python-capi::TransitiveDoubler>::storage_names = {{
}};
THRIFT_DATA_MEMBER const std::array<int, 0> TStructDataStorage<::test::fixtures::basic-python-capi::TransitiveDoubler>::isset_indexes = {{
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::detail::DoubledPair>::name = "DoubledPair";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 2> TStructDataStorage<::test::fixtures::basic-python-capi::detail::DoubledPair>::fields_names = {{
  "s",
  "x",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 2> TStructDataStorage<::test::fixtures::basic-python-capi::detail::DoubledPair>::fields_ids = {{
  1,
  2,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 2> TStructDataStorage<::test::fixtures::basic-python-capi::detail::DoubledPair>::fields_types = {{
  TType::T_STRING,
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 2> TStructDataStorage<::test::fixtures::basic-python-capi::detail::DoubledPair>::storage_names = {{
  "__fbthrift_field_s",
  "__fbthrift_field_x",
}};
THRIFT_DATA_MEMBER const std::array<int, 2> TStructDataStorage<::test::fixtures::basic-python-capi::detail::DoubledPair>::isset_indexes = {{
  0,
  1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::StringPair>::name = "StringPair";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 2> TStructDataStorage<::test::fixtures::basic-python-capi::StringPair>::fields_names = {{
  "normal",
  "doubled",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 2> TStructDataStorage<::test::fixtures::basic-python-capi::StringPair>::fields_ids = {{
  1,
  2,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 2> TStructDataStorage<::test::fixtures::basic-python-capi::StringPair>::fields_types = {{
  TType::T_STRING,
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 2> TStructDataStorage<::test::fixtures::basic-python-capi::StringPair>::storage_names = {{
  "__fbthrift_field_normal",
  "__fbthrift_field_doubled",
}};
THRIFT_DATA_MEMBER const std::array<int, 2> TStructDataStorage<::test::fixtures::basic-python-capi::StringPair>::isset_indexes = {{
  0,
  1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::VapidStruct>::name = "EmptyStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 0> TStructDataStorage<::test::fixtures::basic-python-capi::VapidStruct>::fields_names = {{
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 0> TStructDataStorage<::test::fixtures::basic-python-capi::VapidStruct>::fields_ids = {{
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 0> TStructDataStorage<::test::fixtures::basic-python-capi::VapidStruct>::fields_types = {{
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 0> TStructDataStorage<::test::fixtures::basic-python-capi::VapidStruct>::storage_names = {{
}};
THRIFT_DATA_MEMBER const std::array<int, 0> TStructDataStorage<::test::fixtures::basic-python-capi::VapidStruct>::isset_indexes = {{
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::PrimitiveStruct>::name = "PrimitiveStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 16> TStructDataStorage<::test::fixtures::basic-python-capi::PrimitiveStruct>::fields_names = {{
  "booly",
  "charry",
  "shorty",
  "inty",
  "longy",
  "floaty",
  "dubby",
  "stringy",
  "bytey",
  "buffy",
  "pointbuffy",
  "patched_struct",
  "empty_struct",
  "fbstring",
  "managed_string_view",
  "some_error",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 16> TStructDataStorage<::test::fixtures::basic-python-capi::PrimitiveStruct>::fields_ids = {{
  1,
  2,
  3,
  5,
  7,
  8,
  9,
  12,
  13,
  14,
  15,
  18,
  19,
  20,
  21,
  22,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 16> TStructDataStorage<::test::fixtures::basic-python-capi::PrimitiveStruct>::fields_types = {{
  TType::T_BOOL,
  TType::T_BYTE,
  TType::T_I16,
  TType::T_I32,
  TType::T_I64,
  TType::T_FLOAT,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRUCT,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 16> TStructDataStorage<::test::fixtures::basic-python-capi::PrimitiveStruct>::storage_names = {{
  "__fbthrift_field_booly",
  "__fbthrift_field_charry",
  "__fbthrift_field_shortay",
  "__fbthrift_field_inty",
  "__fbthrift_field_longy",
  "__fbthrift_field_floaty",
  "__fbthrift_field_dubby",
  "__fbthrift_field_stringy",
  "__fbthrift_field_bytey",
  "__fbthrift_field_buffy",
  "__fbthrift_field_pointbuffy",
  "__fbthrift_field_patched_struct",
  "__fbthrift_field_empty_struct",
  "__fbthrift_field_fbstring",
  "__fbthrift_field_managed_string_view",
  "__fbthrift_field_some_error",
}};
THRIFT_DATA_MEMBER const std::array<int, 16> TStructDataStorage<::test::fixtures::basic-python-capi::PrimitiveStruct>::isset_indexes = {{
  0,
  1,
  2,
  3,
  4,
  5,
  -1,
  -1,
  -1,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::AdaptedFields>::name = "AdaptedFields";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 4> TStructDataStorage<::test::fixtures::basic-python-capi::AdaptedFields>::fields_names = {{
  "adapted_int",
  "list_adapted_int",
  "set_adapted_int",
  "inline_adapted_int",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 4> TStructDataStorage<::test::fixtures::basic-python-capi::AdaptedFields>::fields_ids = {{
  1,
  2,
  3,
  4,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 4> TStructDataStorage<::test::fixtures::basic-python-capi::AdaptedFields>::fields_types = {{
  TType::T_I64,
  TType::T_LIST,
  TType::T_SET,
  TType::T_I64,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 4> TStructDataStorage<::test::fixtures::basic-python-capi::AdaptedFields>::storage_names = {{
  "__fbthrift_field_adapted_int",
  "__fbthrift_field_list_adapted_int",
  "__fbthrift_field_set_adapted_int",
  "__fbthrift_field_inline_adapted_int",
}};
THRIFT_DATA_MEMBER const std::array<int, 4> TStructDataStorage<::test::fixtures::basic-python-capi::AdaptedFields>::isset_indexes = {{
  0,
  1,
  2,
  3,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::ListStruct>::name = "ListStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 9> TStructDataStorage<::test::fixtures::basic-python-capi::ListStruct>::fields_names = {{
  "boolz",
  "intz",
  "stringz",
  "encoded",
  "uidz",
  "matrix",
  "ucharz",
  "voxels",
  "buf_ptrs",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 9> TStructDataStorage<::test::fixtures::basic-python-capi::ListStruct>::fields_ids = {{
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
THRIFT_DATA_MEMBER const std::array<protocol::TType, 9> TStructDataStorage<::test::fixtures::basic-python-capi::ListStruct>::fields_types = {{
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 9> TStructDataStorage<::test::fixtures::basic-python-capi::ListStruct>::storage_names = {{
  "__fbthrift_field_boolz",
  "__fbthrift_field_intz",
  "__fbthrift_field_stringz",
  "__fbthrift_field_encoded",
  "__fbthrift_field_uidz",
  "__fbthrift_field_matrix",
  "__fbthrift_field_ucharz",
  "__fbthrift_field_voxels",
  "__fbthrift_field_buf_ptrs",
}};
THRIFT_DATA_MEMBER const std::array<int, 9> TStructDataStorage<::test::fixtures::basic-python-capi::ListStruct>::isset_indexes = {{
  0,
  1,
  -1,
  2,
  3,
  4,
  5,
  6,
  7,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::SetStruct>::name = "SetStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 7> TStructDataStorage<::test::fixtures::basic-python-capi::SetStruct>::fields_names = {{
  "enumz",
  "intz",
  "binnaz",
  "encoded",
  "uidz",
  "charz",
  "setz",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 7> TStructDataStorage<::test::fixtures::basic-python-capi::SetStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 7> TStructDataStorage<::test::fixtures::basic-python-capi::SetStruct>::fields_types = {{
  TType::T_SET,
  TType::T_SET,
  TType::T_SET,
  TType::T_SET,
  TType::T_SET,
  TType::T_SET,
  TType::T_LIST,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 7> TStructDataStorage<::test::fixtures::basic-python-capi::SetStruct>::storage_names = {{
  "__fbthrift_field_enumz",
  "__fbthrift_field_intz",
  "__fbthrift_field_binnaz",
  "__fbthrift_field_encoded",
  "__fbthrift_field_uidz",
  "__fbthrift_field_charz",
  "__fbthrift_field_setz",
}};
THRIFT_DATA_MEMBER const std::array<int, 7> TStructDataStorage<::test::fixtures::basic-python-capi::SetStruct>::isset_indexes = {{
  0,
  1,
  -1,
  2,
  3,
  4,
  5,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MapStruct>::name = "MapStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 10> TStructDataStorage<::test::fixtures::basic-python-capi::MapStruct>::fields_names = {{
  "enumz",
  "intz",
  "binnaz",
  "encoded",
  "flotz",
  "map_list",
  "list_map",
  "fast_list_map",
  "buf_map",
  "unsigned_list_map",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 10> TStructDataStorage<::test::fixtures::basic-python-capi::MapStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 10> TStructDataStorage<::test::fixtures::basic-python-capi::MapStruct>::fields_types = {{
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_LIST,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 10> TStructDataStorage<::test::fixtures::basic-python-capi::MapStruct>::storage_names = {{
  "__fbthrift_field_enumz",
  "__fbthrift_field_intz",
  "__fbthrift_field_binnaz",
  "__fbthrift_field_encoded",
  "__fbthrift_field_flotz",
  "__fbthrift_field_map_list",
  "__fbthrift_field_list_map",
  "__fbthrift_field_fast_list_map",
  "__fbthrift_field_buf_map",
  "__fbthrift_field_unsigned_list_map",
}};
THRIFT_DATA_MEMBER const std::array<int, 10> TStructDataStorage<::test::fixtures::basic-python-capi::MapStruct>::isset_indexes = {{
  0,
  1,
  -1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::ComposeStruct>::name = "ComposeStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 10> TStructDataStorage<::test::fixtures::basic-python-capi::ComposeStruct>::fields_names = {{
  "enum_",
  "renamed_",
  "primitive",
  "aliased",
  "xenum",
  "xstruct",
  "friends",
  "serial_struct",
  "serial_union",
  "serial_error",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 10> TStructDataStorage<::test::fixtures::basic-python-capi::ComposeStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 10> TStructDataStorage<::test::fixtures::basic-python-capi::ComposeStruct>::fields_types = {{
  TType::T_I32,
  TType::T_I32,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_I32,
  TType::T_STRUCT,
  TType::T_LIST,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 10> TStructDataStorage<::test::fixtures::basic-python-capi::ComposeStruct>::storage_names = {{
  "__fbthrift_field_enum_",
  "__fbthrift_field_renamed_",
  "__fbthrift_field_primitive",
  "__fbthrift_field_aliased",
  "__fbthrift_field_xenum",
  "__fbthrift_field_xstruct",
  "__fbthrift_field_friends",
  "__fbthrift_field_serial_struct",
  "__fbthrift_field_serial_union",
  "__fbthrift_field_serial_error",
}};
THRIFT_DATA_MEMBER const std::array<int, 10> TStructDataStorage<::test::fixtures::basic-python-capi::ComposeStruct>::isset_indexes = {{
  0,
  1,
  2,
  -1,
  3,
  4,
  5,
  6,
  7,
  8,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::Shallot>::name = "Onion";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 7> TStructDataStorage<::test::fixtures::basic-python-capi::Shallot>::fields_names = {{
  "myEnum",
  "myStruct",
  "myString",
  "intSet",
  "doubleList",
  "strMap",
  "adaptedInt",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 7> TStructDataStorage<::test::fixtures::basic-python-capi::Shallot>::fields_ids = {{
  1,
  2,
  4,
  6,
  8,
  9,
  10,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 7> TStructDataStorage<::test::fixtures::basic-python-capi::Shallot>::fields_types = {{
  TType::T_I32,
  TType::T_STRUCT,
  TType::T_STRING,
  TType::T_SET,
  TType::T_LIST,
  TType::T_MAP,
  TType::T_I64,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 7> TStructDataStorage<::test::fixtures::basic-python-capi::Shallot>::storage_names = {{
  "myEnum",
  "myStruct",
  "myString",
  "intSet",
  "doubleList",
  "strMap",
  "adaptedInt",
}};
THRIFT_DATA_MEMBER const std::array<int, 7> TStructDataStorage<::test::fixtures::basic-python-capi::Shallot>::isset_indexes = {{
  0,
  1,
  2,
  3,
  4,
  5,
  6,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyStructPatchStruct>::name = "MyStructPatch";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructPatchStruct>::fields_names = {{
  "assign",
  "clear",
  "patchPrior",
  "ensure",
  "patch",
  "remove",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructPatchStruct>::fields_ids = {{
  1,
  2,
  3,
  5,
  6,
  7,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructPatchStruct>::fields_types = {{
  TType::T_STRUCT,
  TType::T_BOOL,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_LIST,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructPatchStruct>::storage_names = {{
  "__fbthrift_field_assign",
  "__fbthrift_field_clear",
  "__fbthrift_field_patchPrior",
  "__fbthrift_field_ensure",
  "__fbthrift_field_patch",
  "__fbthrift_field_remove",
}};
THRIFT_DATA_MEMBER const std::array<int, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructPatchStruct>::isset_indexes = {{
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField4PatchStruct>::name = "MyStructField4Patch";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 2> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField4PatchStruct>::fields_names = {{
  "assign",
  "clear",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 2> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField4PatchStruct>::fields_ids = {{
  1,
  2,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 2> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField4PatchStruct>::fields_types = {{
  TType::T_I32,
  TType::T_BOOL,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 2> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField4PatchStruct>::storage_names = {{
  "__fbthrift_field_assign",
  "__fbthrift_field_clear",
}};
THRIFT_DATA_MEMBER const std::array<int, 2> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField4PatchStruct>::isset_indexes = {{
  0,
  -1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField6PatchStruct>::name = "MyStructField6Patch";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField6PatchStruct>::fields_names = {{
  "assign",
  "clear",
  "prepend",
  "append",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField6PatchStruct>::fields_ids = {{
  1,
  2,
  8,
  9,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField6PatchStruct>::fields_types = {{
  TType::T_LIST,
  TType::T_BOOL,
  TType::T_LIST,
  TType::T_LIST,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField6PatchStruct>::storage_names = {{
  "__fbthrift_field_assign",
  "__fbthrift_field_clear",
  "__fbthrift_field_prepend",
  "__fbthrift_field_append",
}};
THRIFT_DATA_MEMBER const std::array<int, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField6PatchStruct>::isset_indexes = {{
  0,
  -1,
  -1,
  -1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField7PatchStruct>::name = "MyStructField7Patch";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 7> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField7PatchStruct>::fields_names = {{
  "assign",
  "clear",
  "patchPrior",
  "add",
  "patch",
  "remove",
  "put",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 7> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField7PatchStruct>::fields_ids = {{
  1,
  2,
  3,
  5,
  6,
  7,
  9,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 7> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField7PatchStruct>::fields_types = {{
  TType::T_MAP,
  TType::T_BOOL,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_SET,
  TType::T_MAP,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 7> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField7PatchStruct>::storage_names = {{
  "__fbthrift_field_assign",
  "__fbthrift_field_clear",
  "__fbthrift_field_patchPrior",
  "__fbthrift_field_add",
  "__fbthrift_field_patch",
  "__fbthrift_field_remove",
  "__fbthrift_field_put",
}};
THRIFT_DATA_MEMBER const std::array<int, 7> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField7PatchStruct>::isset_indexes = {{
  0,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField8PatchStruct>::name = "MyStructField8Patch";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField8PatchStruct>::fields_names = {{
  "assign",
  "clear",
  "remove",
  "add",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField8PatchStruct>::fields_ids = {{
  1,
  2,
  7,
  8,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField8PatchStruct>::fields_types = {{
  TType::T_SET,
  TType::T_BOOL,
  TType::T_SET,
  TType::T_SET,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField8PatchStruct>::storage_names = {{
  "__fbthrift_field_assign",
  "__fbthrift_field_clear",
  "__fbthrift_field_remove",
  "__fbthrift_field_add",
}};
THRIFT_DATA_MEMBER const std::array<int, 4> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructField8PatchStruct>::isset_indexes = {{
  0,
  -1,
  -1,
  -1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyStructFieldPatchStruct>::name = "MyStructFieldPatch";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructFieldPatchStruct>::fields_names = {{
  "inty",
  "stringy",
  "myItemy",
  "myEnumy",
  "booly",
  "floatListy",
  "strMappy",
  "intSetty",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructFieldPatchStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructFieldPatchStruct>::fields_types = {{
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructFieldPatchStruct>::storage_names = {{
  "__fbthrift_field_inty",
  "__fbthrift_field_stringy",
  "__fbthrift_field_myItemy",
  "__fbthrift_field_myEnumy",
  "__fbthrift_field_booly",
  "__fbthrift_field_floatListy",
  "__fbthrift_field_strMappy",
  "__fbthrift_field_intSetty",
}};
THRIFT_DATA_MEMBER const std::array<int, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructFieldPatchStruct>::isset_indexes = {{
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyStructEnsureStruct>::name = "MyStructEnsureStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructEnsureStruct>::fields_names = {{
  "inty",
  "stringy",
  "myItemy",
  "myEnumy",
  "booly",
  "floatListy",
  "strMappy",
  "intSetty",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructEnsureStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructEnsureStruct>::fields_types = {{
  TType::T_I64,
  TType::T_STRING,
  TType::T_STRUCT,
  TType::T_I32,
  TType::T_BOOL,
  TType::T_LIST,
  TType::T_MAP,
  TType::T_SET,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructEnsureStruct>::storage_names = {{
  "__fbthrift_field_inty",
  "__fbthrift_field_stringy",
  "__fbthrift_field_myItemy",
  "__fbthrift_field_myEnumy",
  "__fbthrift_field_booly",
  "__fbthrift_field_floatListy",
  "__fbthrift_field_strMappy",
  "__fbthrift_field_intSetty",
}};
THRIFT_DATA_MEMBER const std::array<int, 8> TStructDataStorage<::test::fixtures::basic-python-capi::MyStructEnsureStruct>::isset_indexes = {{
  0,
  1,
  -1,
  2,
  3,
  4,
  5,
  6,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemPatchStruct>::name = "MyDataItemPatch";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemPatchStruct>::fields_names = {{
  "assign",
  "clear",
  "patchPrior",
  "ensure",
  "patch",
  "remove",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemPatchStruct>::fields_ids = {{
  1,
  2,
  3,
  5,
  6,
  7,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemPatchStruct>::fields_types = {{
  TType::T_STRUCT,
  TType::T_BOOL,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_LIST,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemPatchStruct>::storage_names = {{
  "__fbthrift_field_assign",
  "__fbthrift_field_clear",
  "__fbthrift_field_patchPrior",
  "__fbthrift_field_ensure",
  "__fbthrift_field_patch",
  "__fbthrift_field_remove",
}};
THRIFT_DATA_MEMBER const std::array<int, 6> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemPatchStruct>::isset_indexes = {{
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemFieldPatchStruct>::name = "MyDataItemFieldPatch";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemFieldPatchStruct>::fields_names = {{
  "s",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemFieldPatchStruct>::fields_ids = {{
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemFieldPatchStruct>::fields_types = {{
  TType::T_STRUCT,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemFieldPatchStruct>::storage_names = {{
  "__fbthrift_field_s",
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemFieldPatchStruct>::isset_indexes = {{
  -1,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemEnsureStruct>::name = "MyDataItemEnsureStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemEnsureStruct>::fields_names = {{
  "s",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemEnsureStruct>::fields_ids = {{
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemEnsureStruct>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemEnsureStruct>::storage_names = {{
  "__fbthrift_field_s",
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItemEnsureStruct>::isset_indexes = {{
  0,
}};

} // namespace thrift
} // namespace apache
