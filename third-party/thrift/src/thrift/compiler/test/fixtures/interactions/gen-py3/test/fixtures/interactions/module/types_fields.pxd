#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from libc.stdint cimport (
    int8_t as cint8_t,
    int16_t as cint16_t,
    int32_t as cint32_t,
    int64_t as cint64_t,
    uint16_t as cuint16_t,
    uint32_t as cuint32_t,
)
from libcpp.string cimport string
from libcpp cimport bool as cbool, nullptr, nullptr_t
from cpython cimport bool as pbool
from libcpp.memory cimport shared_ptr, unique_ptr
from libcpp.utility cimport move as cmove
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap
from libcpp.unordered_map cimport unordered_map as cumap
from thrift.py3.exceptions cimport cTException
cimport folly.iobuf as _fbthrift_iobuf
cimport thrift.py3.exceptions
cimport thrift.py3.types
from thrift.py3.common cimport Protocol as __Protocol
from thrift.py3.std_libcpp cimport string_view as __cstring_view
from thrift.py3.types cimport (
    bstring,
    bytes_to_string,
    field_ref as __field_ref,
    optional_field_ref as __optional_field_ref,
    required_field_ref as __required_field_ref,
    terse_field_ref as __terse_field_ref,
    StructFieldsSetter as __StructFieldsSetter
)
from folly.optional cimport cOptional as __cOptional


cimport test.fixtures.interactions.module.types as _test_fixtures_interactions_module_types



ctypedef void (*__CustomException_FieldsSetterFunc)(__CustomException_FieldsSetter, object) except *

cdef class __CustomException_FieldsSetter(__StructFieldsSetter):
    cdef _test_fixtures_interactions_module_types.cCustomException* _struct_cpp_obj
    cdef cumap[__cstring_view, __CustomException_FieldsSetterFunc] _setters

    @staticmethod
    cdef __CustomException_FieldsSetter _fbthrift_create(_test_fixtures_interactions_module_types.cCustomException* struct_cpp_obj)
    cdef void _set_field_0(self, _fbthrift_value) except *

