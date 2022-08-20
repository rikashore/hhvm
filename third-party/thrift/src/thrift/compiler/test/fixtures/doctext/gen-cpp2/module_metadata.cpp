/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/doctext/gen-cpp2/module_metadata.h"

// some of these functions can be so large that the compiler gives up optimizing
// them - and issues a warning which may be treated as an error!
//
// these functions are so rarely called that it is probably okay for them not to
// be optimized in practice
FOLLY_CLANG_DISABLE_WARNING("-Wignored-optimization-argument")

namespace apache {
namespace thrift {
namespace detail {
namespace md {
using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;
using ThriftService = ::apache::thrift::metadata::ThriftService;
using ThriftServiceContext = ::apache::thrift::metadata::ThriftServiceContext;
using ThriftFunctionGenerator = void (*)(ThriftMetadata&, ThriftService&);

void EnumMetadata<::cpp2::B>::gen(ThriftMetadata& metadata) {
  auto res = metadata.enums()->emplace("module.B", ::apache::thrift::metadata::ThriftEnum{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftEnum& enum_metadata = res.first->second;
  enum_metadata.name() = "module.B";
  using EnumTraits = TEnumTraits<::cpp2::B>;
  for (std::size_t i = 0; i != EnumTraits::size; ++i) {
    enum_metadata.elements()->emplace(static_cast<int32_t>(EnumTraits::values[i]), EnumTraits::names[i].str());
  }
}

const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::A>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs()->emplace("module.A", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_A = res.first->second;
  module_A.name() = "module.A";
  module_A.is_union() = false;
  static const auto* const
  module_A_fields = new std::array<EncodedThriftField, 1>{{
    {1, "useless_field", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE), std::vector<ThriftConstStruct>{}},
  }};
  for (const auto& f : *module_A_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id() = f.id;
    field.name() = f.name;
    field.is_optional() = f.is_optional;
    f.metadata_type_interface->writeAndGenType(*field.type(), metadata);
    field.structured_annotations() = f.structured_annotations;
    module_A.fields()->push_back(std::move(field));
  }
  return res.first->second;
}
const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::U>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs()->emplace("module.U", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_U = res.first->second;
  module_U.name() = "module.U";
  module_U.is_union() = true;
  static const auto* const
  module_U_fields = new std::array<EncodedThriftField, 2>{{
    {1, "i", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE), std::vector<ThriftConstStruct>{}},
    {2, "s", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::vector<ThriftConstStruct>{}},
  }};
  for (const auto& f : *module_U_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id() = f.id;
    field.name() = f.name;
    field.is_optional() = f.is_optional;
    f.metadata_type_interface->writeAndGenType(*field.type(), metadata);
    field.structured_annotations() = f.structured_annotations;
    module_U.fields()->push_back(std::move(field));
  }
  return res.first->second;
}
const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::Bang>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs()->emplace("module.Bang", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_Bang = res.first->second;
  module_Bang.name() = "module.Bang";
  module_Bang.is_union() = false;
  static const auto* const
  module_Bang_fields = new std::array<EncodedThriftField, 1>{{
    {1, "message", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::vector<ThriftConstStruct>{}},
  }};
  for (const auto& f : *module_Bang_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id() = f.id;
    field.name() = f.name;
    field.is_optional() = f.is_optional;
    f.metadata_type_interface->writeAndGenType(*field.type(), metadata);
    field.structured_annotations() = f.structured_annotations;
    module_Bang.fields()->push_back(std::move(field));
  }
  return res.first->second;
}

void ExceptionMetadata<::cpp2::Bang>::gen(ThriftMetadata& metadata) {
  auto res = metadata.exceptions()->emplace("module.Bang", ::apache::thrift::metadata::ThriftException{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftException& module_Bang = res.first->second;
  module_Bang.name() = "module.Bang";
  static const auto* const
  module_Bang_fields = new std::array<EncodedThriftField, 1>{{
    {1, "message", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::vector<ThriftConstStruct>{}},
  }};
  for (const auto& f : *module_Bang_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id() = f.id;
    field.name() = f.name;
    field.is_optional() = f.is_optional;
    f.metadata_type_interface->writeAndGenType(*field.type(), metadata);
    module_Bang.fields()->push_back(std::move(field));
  }
}
void ServiceMetadata<::apache::thrift::ServiceHandler<::cpp2::C>>::gen_f(FOLLY_MAYBE_UNUSED ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  func.name() = "f";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(*func.return_type(), metadata);
  func.is_oneway() = false;
  service.functions()->push_back(std::move(func));
}
void ServiceMetadata<::apache::thrift::ServiceHandler<::cpp2::C>>::gen_numbers(FOLLY_MAYBE_UNUSED ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  func.name() = "numbers";
  auto func_ret_type = std::make_unique<Stream>(std::make_unique<Typedef>("module.number", std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE), std::vector<ThriftConstStruct>{}));
  func_ret_type->writeAndGenType(*func.return_type(), metadata);
  func.is_oneway() = false;
  service.functions()->push_back(std::move(func));
}
void ServiceMetadata<::apache::thrift::ServiceHandler<::cpp2::C>>::gen_thing(FOLLY_MAYBE_UNUSED ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  func.name() = "thing";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE);
  func_ret_type->writeAndGenType(*func.return_type(), metadata);
  ::apache::thrift::metadata::ThriftField module_C_thing_a_1;
  module_C_thing_a_1.id() = 1;
  module_C_thing_a_1.name() = "a";
  module_C_thing_a_1.is_optional() = false;
  auto module_C_thing_a_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE);
  module_C_thing_a_1_type->writeAndGenType(*module_C_thing_a_1.type(), metadata);
  func.arguments()->push_back(std::move(module_C_thing_a_1));
  ::apache::thrift::metadata::ThriftField module_C_thing_b_2;
  module_C_thing_b_2.id() = 2;
  module_C_thing_b_2.name() = "b";
  module_C_thing_b_2.is_optional() = false;
  auto module_C_thing_b_2_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE);
  module_C_thing_b_2_type->writeAndGenType(*module_C_thing_b_2.type(), metadata);
  func.arguments()->push_back(std::move(module_C_thing_b_2));
  ::apache::thrift::metadata::ThriftField module_C_thing_c_3;
  module_C_thing_c_3.id() = 3;
  module_C_thing_c_3.name() = "c";
  module_C_thing_c_3.is_optional() = false;
  auto module_C_thing_c_3_type = std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE));
  module_C_thing_c_3_type->writeAndGenType(*module_C_thing_c_3.type(), metadata);
  func.arguments()->push_back(std::move(module_C_thing_c_3));
  ::apache::thrift::metadata::ThriftField module_C_thing_bang_1;
  module_C_thing_bang_1.id() = 1;
  module_C_thing_bang_1.name() = "bang";
  module_C_thing_bang_1.is_optional() = false;
  auto module_C_thing_bang_1_type = std::make_unique<Struct<::cpp2::Bang>>("module.Bang");
  module_C_thing_bang_1_type->writeAndGenType(*module_C_thing_bang_1.type(), metadata);
  func.exceptions()->push_back(std::move(module_C_thing_bang_1));
  ExceptionMetadata<::cpp2::Bang>::gen(metadata);
  func.is_oneway() = false;
  service.functions()->push_back(std::move(func));
}

void ServiceMetadata<::apache::thrift::ServiceHandler<::cpp2::C>>::gen(::apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  const ::apache::thrift::metadata::ThriftServiceContextRef* self = genRecurse(*response.metadata(), *response.services());
  DCHECK(self != nullptr);
  // TODO(praihan): Remove ThriftServiceContext from response. But in the meantime, we need to fill the field with the result of looking up in ThriftMetadata.
  ::apache::thrift::metadata::ThriftServiceContext context;
  context.module() = *self->module();
  context.service_info() = response.metadata()->services()->at(*self->service_name());
  response.context() = std::move(context);
}

const ThriftServiceContextRef* ServiceMetadata<::apache::thrift::ServiceHandler<::cpp2::C>>::genRecurse(FOLLY_MAYBE_UNUSED ThriftMetadata& metadata, std::vector<ThriftServiceContextRef>& services) {
  ::apache::thrift::metadata::ThriftService module_C;
  module_C.name() = "module.C";
  static const ThriftFunctionGenerator functions[] = {
    ServiceMetadata<::apache::thrift::ServiceHandler<::cpp2::C>>::gen_f,
    ServiceMetadata<::apache::thrift::ServiceHandler<::cpp2::C>>::gen_numbers,
    ServiceMetadata<::apache::thrift::ServiceHandler<::cpp2::C>>::gen_thing,
  };
  for (auto& function_gen : functions) {
    function_gen(metadata, module_C);
  }
  // We need to keep the index around because a reference or iterator could be invalidated.
  auto selfIndex = services.size();
  services.emplace_back();
  ThriftServiceContextRef& context = services[selfIndex];
  metadata.services()->emplace("module.C", std::move(module_C));
  context.service_name() = "module.C";
  ::apache::thrift::metadata::ThriftModuleContext module;
  module.name() = "module";
  context.module() = std::move(module);
  return &context;
}
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
