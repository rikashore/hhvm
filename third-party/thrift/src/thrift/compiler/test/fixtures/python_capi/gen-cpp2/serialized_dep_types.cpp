/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/python_capi/src/serialized_dep.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/python_capi/gen-cpp2/serialized_dep_types.h"
#include "thrift/compiler/test/fixtures/python_capi/gen-cpp2/serialized_dep_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/python_capi/gen-cpp2/serialized_dep_data.h"


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::test::fixtures::python_capi::SerializedStruct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::test::fixtures::python_capi::SerializedStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace test { namespace fixtures { namespace python_capi {

const char* SerializedStruct::__fbthrift_thrift_uri() {
  return "test.dev/fixtures/python_capi/SerializedStruct";
}

const folly::StringPiece SerializedStruct::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<SerializedStruct>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece SerializedStruct::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<SerializedStruct>::name;
}

SerializedStruct::SerializedStruct(const SerializedStruct&) = default;
SerializedStruct& SerializedStruct::operator=(const SerializedStruct&) = default;
SerializedStruct::SerializedStruct() :
      __fbthrift_field_i() {
}


SerializedStruct::~SerializedStruct() {}

SerializedStruct::SerializedStruct(FOLLY_MAYBE_UNUSED SerializedStruct&& other) noexcept :
    __fbthrift_field_s(std::move(other.__fbthrift_field_s)),
    __fbthrift_field_i(std::move(other.__fbthrift_field_i)),
    __fbthrift_field_os(std::move(other.__fbthrift_field_os)),
    __fbthrift_field_rs(std::move(other.__fbthrift_field_rs)),
    __isset(other.__isset) {
}

SerializedStruct& SerializedStruct::operator=(FOLLY_MAYBE_UNUSED SerializedStruct&& other) noexcept {
    this->__fbthrift_field_s = std::move(other.__fbthrift_field_s);
    this->__fbthrift_field_i = std::move(other.__fbthrift_field_i);
    this->__fbthrift_field_os = std::move(other.__fbthrift_field_os);
    this->__fbthrift_field_rs = std::move(other.__fbthrift_field_rs);
    __isset = other.__isset;
    return *this;
}


SerializedStruct::SerializedStruct(apache::thrift::FragileConstructor, ::std::string s__arg, ::std::int32_t i__arg, ::std::string os__arg, ::std::string rs__arg) :
    __fbthrift_field_s(std::move(s__arg)),
    __fbthrift_field_i(std::move(i__arg)),
    __fbthrift_field_os(std::move(os__arg)),
    __fbthrift_field_rs(std::move(rs__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
  __isset.set(folly::index_constant<2>(), true);
}


void SerializedStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_s = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_i = ::std::int32_t();
  this->__fbthrift_field_os = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_rs = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  __isset = {};
}

void SerializedStruct::__fbthrift_clear_terse_fields() {
}

bool SerializedStruct::__fbthrift_is_empty() const {
  return false;
}

bool SerializedStruct::operator==(FOLLY_MAYBE_UNUSED const SerializedStruct& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool SerializedStruct::operator<(FOLLY_MAYBE_UNUSED const SerializedStruct& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap(FOLLY_MAYBE_UNUSED SerializedStruct& a, FOLLY_MAYBE_UNUSED SerializedStruct& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_s, b.__fbthrift_field_s);
  swap(a.__fbthrift_field_i, b.__fbthrift_field_i);
  swap(a.__fbthrift_field_os, b.__fbthrift_field_os);
  swap(a.__fbthrift_field_rs, b.__fbthrift_field_rs);
  swap(a.__isset, b.__isset);
}

template void SerializedStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t SerializedStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t SerializedStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SerializedStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void SerializedStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t SerializedStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t SerializedStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t SerializedStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


}}} // test::fixtures::python_capi

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::test::fixtures::python_capi::SerializedUnion>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::test::fixtures::python_capi::SerializedUnion>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

folly::Range<::test::fixtures::python_capi::SerializedUnion::Type const*> const TEnumTraits<::test::fixtures::python_capi::SerializedUnion::Type>::values = folly::range(TEnumDataStorage<::test::fixtures::python_capi::SerializedUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::test::fixtures::python_capi::SerializedUnion::Type>::names = folly::range(TEnumDataStorage<::test::fixtures::python_capi::SerializedUnion::Type>::names);

bool TEnumTraits<::test::fixtures::python_capi::SerializedUnion::Type>::findName(type value, folly::StringPiece* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value, out);
}

bool TEnumTraits<::test::fixtures::python_capi::SerializedUnion::Type>::findValue(folly::StringPiece name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}
}} // apache::thrift
namespace test { namespace fixtures { namespace python_capi {

const char* SerializedUnion::__fbthrift_thrift_uri() {
  return "test.dev/fixtures/python_capi/SerializedUnion";
}

const folly::StringPiece SerializedUnion::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<SerializedUnion>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece SerializedUnion::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<SerializedUnion>::name;
}

void SerializedUnion::__fbthrift_destruct() {
  switch(getType()) {
    case Type::__EMPTY__:
      break;
    case Type::s:
      ::std::destroy_at(::std::addressof(value_.s));
      break;
    case Type::i:
      ::std::destroy_at(::std::addressof(value_.i));
      break;
    default:
      assert(false);
      break;
  }
}

void SerializedUnion::__fbthrift_clear() {
  __fbthrift_destruct();
  type_ = folly::to_underlying(Type::__EMPTY__);
}

  SerializedUnion::~SerializedUnion() {
    __fbthrift_destruct();
  }

bool SerializedUnion::__fbthrift_is_empty() const {
  return getType() == Type::__EMPTY__;
}

bool SerializedUnion::operator==(const SerializedUnion& rhs) const {
  return ::apache::thrift::op::detail::UnionEquality{}(*this, rhs);
}

bool SerializedUnion::operator<(FOLLY_MAYBE_UNUSED const SerializedUnion& rhs) const {
  return ::apache::thrift::op::detail::UnionLessThan{}(*this, rhs);
}

void swap(SerializedUnion& a, SerializedUnion& b) {
  SerializedUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void SerializedUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t SerializedUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t SerializedUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SerializedUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void SerializedUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t SerializedUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t SerializedUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t SerializedUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


}}} // test::fixtures::python_capi

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::test::fixtures::python_capi::SerializedError>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::test::fixtures::python_capi::SerializedError>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace test { namespace fixtures { namespace python_capi {

const char* SerializedError::__fbthrift_thrift_uri() {
  return "test.dev/fixtures/python_capi/SerializedError";
}

const folly::StringPiece SerializedError::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<SerializedError>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece SerializedError::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<SerializedError>::name;
}

SerializedError::SerializedError(const SerializedError&) = default;
SerializedError& SerializedError::operator=(const SerializedError&) = default;
SerializedError::SerializedError() {
}


SerializedError::~SerializedError() {}

SerializedError::SerializedError(FOLLY_MAYBE_UNUSED SerializedError&& other) noexcept :
    __fbthrift_field_msg(std::move(other.__fbthrift_field_msg)),
    __fbthrift_field_os(std::move(other.__fbthrift_field_os)),
    __fbthrift_field_rs(std::move(other.__fbthrift_field_rs)),
    __isset(other.__isset) {
}

SerializedError& SerializedError::operator=(FOLLY_MAYBE_UNUSED SerializedError&& other) noexcept {
    this->__fbthrift_field_msg = std::move(other.__fbthrift_field_msg);
    this->__fbthrift_field_os = std::move(other.__fbthrift_field_os);
    this->__fbthrift_field_rs = std::move(other.__fbthrift_field_rs);
    __isset = other.__isset;
    return *this;
}


SerializedError::SerializedError(apache::thrift::FragileConstructor, ::std::string msg__arg, ::std::string os__arg, ::std::string rs__arg) :
    __fbthrift_field_msg(std::move(msg__arg)),
    __fbthrift_field_os(std::move(os__arg)),
    __fbthrift_field_rs(std::move(rs__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
}


void SerializedError::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_msg = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_os = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_rs = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  __isset = {};
}

void SerializedError::__fbthrift_clear_terse_fields() {
}

bool SerializedError::__fbthrift_is_empty() const {
  return false;
}

bool SerializedError::operator==(FOLLY_MAYBE_UNUSED const SerializedError& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool SerializedError::operator<(FOLLY_MAYBE_UNUSED const SerializedError& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap(FOLLY_MAYBE_UNUSED SerializedError& a, FOLLY_MAYBE_UNUSED SerializedError& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_msg, b.__fbthrift_field_msg);
  swap(a.__fbthrift_field_os, b.__fbthrift_field_os);
  swap(a.__fbthrift_field_rs, b.__fbthrift_field_rs);
  swap(a.__isset, b.__isset);
}

template void SerializedError::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t SerializedError::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t SerializedError::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SerializedError::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void SerializedError::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t SerializedError::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t SerializedError::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t SerializedError::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


}}} // test::fixtures::python_capi

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::test::fixtures::python_capi::MarshalStruct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::test::fixtures::python_capi::MarshalStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace test { namespace fixtures { namespace python_capi {

const char* MarshalStruct::__fbthrift_thrift_uri() {
  return "test.dev/fixtures/python_capi/MarshalStruct";
}

const folly::StringPiece MarshalStruct::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<MarshalStruct>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece MarshalStruct::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<MarshalStruct>::name;
}

MarshalStruct::MarshalStruct(const MarshalStruct&) = default;
MarshalStruct& MarshalStruct::operator=(const MarshalStruct&) = default;
MarshalStruct::MarshalStruct() :
      __fbthrift_field_i() {
}


MarshalStruct::~MarshalStruct() {}

MarshalStruct::MarshalStruct(FOLLY_MAYBE_UNUSED MarshalStruct&& other) noexcept :
    __fbthrift_field_s(std::move(other.__fbthrift_field_s)),
    __fbthrift_field_i(std::move(other.__fbthrift_field_i)),
    __fbthrift_field_os(std::move(other.__fbthrift_field_os)),
    __fbthrift_field_rs(std::move(other.__fbthrift_field_rs)),
    __isset(other.__isset) {
}

MarshalStruct& MarshalStruct::operator=(FOLLY_MAYBE_UNUSED MarshalStruct&& other) noexcept {
    this->__fbthrift_field_s = std::move(other.__fbthrift_field_s);
    this->__fbthrift_field_i = std::move(other.__fbthrift_field_i);
    this->__fbthrift_field_os = std::move(other.__fbthrift_field_os);
    this->__fbthrift_field_rs = std::move(other.__fbthrift_field_rs);
    __isset = other.__isset;
    return *this;
}


MarshalStruct::MarshalStruct(apache::thrift::FragileConstructor, ::std::string s__arg, ::std::int32_t i__arg, ::std::string os__arg, ::std::string rs__arg) :
    __fbthrift_field_s(std::move(s__arg)),
    __fbthrift_field_i(std::move(i__arg)),
    __fbthrift_field_os(std::move(os__arg)),
    __fbthrift_field_rs(std::move(rs__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
  __isset.set(folly::index_constant<2>(), true);
}


void MarshalStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_s = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_i = ::std::int32_t();
  this->__fbthrift_field_os = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_rs = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  __isset = {};
}

void MarshalStruct::__fbthrift_clear_terse_fields() {
}

bool MarshalStruct::__fbthrift_is_empty() const {
  return false;
}

bool MarshalStruct::operator==(FOLLY_MAYBE_UNUSED const MarshalStruct& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool MarshalStruct::operator<(FOLLY_MAYBE_UNUSED const MarshalStruct& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap(FOLLY_MAYBE_UNUSED MarshalStruct& a, FOLLY_MAYBE_UNUSED MarshalStruct& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_s, b.__fbthrift_field_s);
  swap(a.__fbthrift_field_i, b.__fbthrift_field_i);
  swap(a.__fbthrift_field_os, b.__fbthrift_field_os);
  swap(a.__fbthrift_field_rs, b.__fbthrift_field_rs);
  swap(a.__isset, b.__isset);
}

template void MarshalStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MarshalStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MarshalStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MarshalStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MarshalStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MarshalStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MarshalStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MarshalStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


}}} // test::fixtures::python_capi

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::test::fixtures::python_capi::MarshalUnion>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::test::fixtures::python_capi::MarshalUnion>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

folly::Range<::test::fixtures::python_capi::MarshalUnion::Type const*> const TEnumTraits<::test::fixtures::python_capi::MarshalUnion::Type>::values = folly::range(TEnumDataStorage<::test::fixtures::python_capi::MarshalUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::test::fixtures::python_capi::MarshalUnion::Type>::names = folly::range(TEnumDataStorage<::test::fixtures::python_capi::MarshalUnion::Type>::names);

bool TEnumTraits<::test::fixtures::python_capi::MarshalUnion::Type>::findName(type value, folly::StringPiece* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value, out);
}

bool TEnumTraits<::test::fixtures::python_capi::MarshalUnion::Type>::findValue(folly::StringPiece name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}
}} // apache::thrift
namespace test { namespace fixtures { namespace python_capi {

const char* MarshalUnion::__fbthrift_thrift_uri() {
  return "test.dev/fixtures/python_capi/MarshalUnion";
}

const folly::StringPiece MarshalUnion::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<MarshalUnion>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece MarshalUnion::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<MarshalUnion>::name;
}

void MarshalUnion::__fbthrift_destruct() {
  switch(getType()) {
    case Type::__EMPTY__:
      break;
    case Type::s:
      ::std::destroy_at(::std::addressof(value_.s));
      break;
    case Type::i:
      ::std::destroy_at(::std::addressof(value_.i));
      break;
    default:
      assert(false);
      break;
  }
}

void MarshalUnion::__fbthrift_clear() {
  __fbthrift_destruct();
  type_ = folly::to_underlying(Type::__EMPTY__);
}

  MarshalUnion::~MarshalUnion() {
    __fbthrift_destruct();
  }

bool MarshalUnion::__fbthrift_is_empty() const {
  return getType() == Type::__EMPTY__;
}

bool MarshalUnion::operator==(const MarshalUnion& rhs) const {
  return ::apache::thrift::op::detail::UnionEquality{}(*this, rhs);
}

bool MarshalUnion::operator<(FOLLY_MAYBE_UNUSED const MarshalUnion& rhs) const {
  return ::apache::thrift::op::detail::UnionLessThan{}(*this, rhs);
}

void swap(MarshalUnion& a, MarshalUnion& b) {
  MarshalUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void MarshalUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MarshalUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MarshalUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MarshalUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MarshalUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MarshalUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MarshalUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MarshalUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


}}} // test::fixtures::python_capi

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::test::fixtures::python_capi::MarshalError>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::test::fixtures::python_capi::MarshalError>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace test { namespace fixtures { namespace python_capi {

const char* MarshalError::__fbthrift_thrift_uri() {
  return "test.dev/fixtures/python_capi/MarshalError";
}

const folly::StringPiece MarshalError::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<MarshalError>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece MarshalError::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<MarshalError>::name;
}

MarshalError::MarshalError(const MarshalError&) = default;
MarshalError& MarshalError::operator=(const MarshalError&) = default;
MarshalError::MarshalError() {
}


MarshalError::~MarshalError() {}

MarshalError::MarshalError(FOLLY_MAYBE_UNUSED MarshalError&& other) noexcept :
    __fbthrift_field_msg(std::move(other.__fbthrift_field_msg)),
    __fbthrift_field_os(std::move(other.__fbthrift_field_os)),
    __fbthrift_field_rs(std::move(other.__fbthrift_field_rs)),
    __isset(other.__isset) {
}

MarshalError& MarshalError::operator=(FOLLY_MAYBE_UNUSED MarshalError&& other) noexcept {
    this->__fbthrift_field_msg = std::move(other.__fbthrift_field_msg);
    this->__fbthrift_field_os = std::move(other.__fbthrift_field_os);
    this->__fbthrift_field_rs = std::move(other.__fbthrift_field_rs);
    __isset = other.__isset;
    return *this;
}


MarshalError::MarshalError(apache::thrift::FragileConstructor, ::std::string msg__arg, ::std::string os__arg, ::std::string rs__arg) :
    __fbthrift_field_msg(std::move(msg__arg)),
    __fbthrift_field_os(std::move(os__arg)),
    __fbthrift_field_rs(std::move(rs__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
}


void MarshalError::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_msg = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_os = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_rs = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  __isset = {};
}

void MarshalError::__fbthrift_clear_terse_fields() {
}

bool MarshalError::__fbthrift_is_empty() const {
  return false;
}

bool MarshalError::operator==(FOLLY_MAYBE_UNUSED const MarshalError& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool MarshalError::operator<(FOLLY_MAYBE_UNUSED const MarshalError& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap(FOLLY_MAYBE_UNUSED MarshalError& a, FOLLY_MAYBE_UNUSED MarshalError& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_msg, b.__fbthrift_field_msg);
  swap(a.__fbthrift_field_os, b.__fbthrift_field_os);
  swap(a.__fbthrift_field_rs, b.__fbthrift_field_rs);
  swap(a.__isset, b.__isset);
}

template void MarshalError::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MarshalError::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MarshalError::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MarshalError::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MarshalError::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MarshalError::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MarshalError::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MarshalError::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


}}} // test::fixtures::python_capi

namespace test { namespace fixtures { namespace python_capi { namespace {
FOLLY_MAYBE_UNUSED FOLLY_ERASE void validateAdapters() {
}
}}}} // test::fixtures::python_capi
namespace apache::thrift::detail::annotation {
}
