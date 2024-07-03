#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/includes/src/matching_struct_names.thrift
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
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap, pair as cpair
from libcpp.unordered_map cimport unordered_map as cumap
cimport folly.iobuf as _fbthrift_iobuf
from thrift.python.exceptions cimport cTException
from thrift.py3.types cimport (
    bstring,
    field_ref as __field_ref,
    optional_field_ref as __optional_field_ref,
    required_field_ref as __required_field_ref,
    terse_field_ref as __terse_field_ref,
    union_field_ref as __union_field_ref,
    get_union_field_value as __get_union_field_value,
)
from thrift.python.common cimport cThriftMetadata as __fbthrift_cThriftMetadata
cimport module.types as _module_types
cimport thrift.py3.exceptions
cimport thrift.py3.types
from thrift.python.common cimport (
    RpcOptions as __RpcOptions,
    MetadataBox as __MetadataBox,
)
from folly.optional cimport cOptional as __cOptional

cimport matching_struct_names.types_fields as _fbthrift_types_fields

cdef extern from "thrift/compiler/test/fixtures/includes/gen-py3/matching_struct_names/types.h":
  pass





cdef extern from "thrift/compiler/test/fixtures/includes/gen-cpp2/matching_struct_names_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass ExceptionMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "thrift/compiler/test/fixtures/includes/gen-cpp2/matching_struct_names_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass StructMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "thrift/compiler/test/fixtures/includes/gen-cpp2/matching_struct_names_types_custom_protocol.h" namespace "::cpp2":

    cdef cppclass cMyStruct "::cpp2::MyStruct":
        cMyStruct() except +
        cMyStruct(const cMyStruct&) except +
        bint operator==(cMyStruct&)
        bint operator!=(cMyStruct&)
        bint operator<(cMyStruct&)
        bint operator>(cMyStruct&)
        bint operator<=(cMyStruct&)
        bint operator>=(cMyStruct&)
        __field_ref[string] field_ref "field_ref" ()


    cdef cppclass cCombo "::cpp2::Combo":
        cCombo() except +
        cCombo(const cCombo&) except +
        bint operator==(cCombo&)
        bint operator!=(cCombo&)
        bint operator<(cCombo&)
        bint operator>(cCombo&)
        bint operator<=(cCombo&)
        bint operator>=(cCombo&)
        __field_ref[vector[vector[cMyStruct]]] listOfOurMyStructLists_ref "listOfOurMyStructLists_ref" ()
        __field_ref[vector[_module_types.cMyStruct]] theirMyStructList_ref "theirMyStructList_ref" ()
        __field_ref[vector[cMyStruct]] ourMyStructList_ref "ourMyStructList_ref" ()
        __field_ref[vector[vector[_module_types.cMyStruct]]] listOfTheirMyStructList_ref "listOfTheirMyStructList_ref" ()




cdef class MyStruct(thrift.py3.types.Struct):
    cdef shared_ptr[cMyStruct] _cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE
    cdef _fbthrift_types_fields.__MyStruct_FieldsSetter _fields_setter
    cdef inline object field_impl(self)

    @staticmethod
    cdef _create_FBTHRIFT_ONLY_DO_NOT_USE(shared_ptr[cMyStruct])



cdef class Combo(thrift.py3.types.Struct):
    cdef shared_ptr[cCombo] _cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE
    cdef _fbthrift_types_fields.__Combo_FieldsSetter _fields_setter
    cdef inline object listOfOurMyStructLists_impl(self)
    cdef inline object theirMyStructList_impl(self)
    cdef inline object ourMyStructList_impl(self)
    cdef inline object listOfTheirMyStructList_impl(self)
    cdef object __fbthrift_cached_listOfOurMyStructLists
    cdef object __fbthrift_cached_theirMyStructList
    cdef object __fbthrift_cached_ourMyStructList
    cdef object __fbthrift_cached_listOfTheirMyStructList

    @staticmethod
    cdef _create_FBTHRIFT_ONLY_DO_NOT_USE(shared_ptr[cCombo])


cdef vector[cMyStruct] List__MyStruct__make_instance(object items) except *
cdef object List__MyStruct__from_cpp(const vector[cMyStruct]&) except *

cdef vector[vector[cMyStruct]] List__List__MyStruct__make_instance(object items) except *
cdef object List__List__MyStruct__from_cpp(const vector[vector[cMyStruct]]&) except *

cdef vector[_module_types.cMyStruct] List__module_MyStruct__make_instance(object items) except *
cdef object List__module_MyStruct__from_cpp(const vector[_module_types.cMyStruct]&) except *

cdef vector[vector[_module_types.cMyStruct]] List__List__module_MyStruct__make_instance(object items) except *
cdef object List__List__module_MyStruct__from_cpp(const vector[vector[_module_types.cMyStruct]]&) except *


