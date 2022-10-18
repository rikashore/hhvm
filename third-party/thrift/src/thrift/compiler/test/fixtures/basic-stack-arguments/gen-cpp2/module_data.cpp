/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/basic-stack-arguments/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/basic-stack-arguments/gen-cpp2/module_data.h"

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

THRIFT_DATA_SECTION const std::array<::cpp2::MyEnum, 2> TEnumDataStorage<::cpp2::MyEnum>::values = {{
  type::MyValue1,
  type::MyValue2,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TEnumDataStorage<::cpp2::MyEnum>::names = {{
  "MyValue1",
  "MyValue2",
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TStructDataStorage<::cpp2::MyStruct>::fields_names = {{
  "MyIntField",
  "MyStringField",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 2> TStructDataStorage<::cpp2::MyStruct>::fields_ids = {{
  1,
  2,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 2> TStructDataStorage<::cpp2::MyStruct>::fields_types = {{
  TType::T_I64,
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TStructDataStorage<::cpp2::MyStruct>::storage_names = {{
  "__fbthrift_field_MyIntField",
  "__fbthrift_field_MyStringField",
}};
THRIFT_DATA_SECTION const std::array<int, 2> TStructDataStorage<::cpp2::MyStruct>::isset_indexes = {{
  0,
  1,
}};

} // namespace thrift
} // namespace apache
