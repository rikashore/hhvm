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
    uint32_t as cuint32_t,
)
from libcpp.string cimport string
from libcpp cimport bool as cbool, nullptr, nullptr_t
from cpython cimport bool as pbool
from libcpp.memory cimport shared_ptr, unique_ptr
from libcpp.utility cimport move as cmove
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap, pair as cpair
from thrift.py3.exceptions cimport cTException
cimport folly.iobuf as _fbthrift_iobuf
cimport thrift.py3.exceptions
cimport thrift.py3.types
from thrift.py3.types cimport (
    bstring,
    bytes_to_string,
    field_ref as __field_ref,
    optional_field_ref as __optional_field_ref,
    required_field_ref as __required_field_ref,
    terse_field_ref as __terse_field_ref,
    union_field_ref as __union_field_ref,
    get_union_field_value as __get_union_field_value,
)
from thrift.py3.common cimport (
    RpcOptions as __RpcOptions,
    Protocol as __Protocol,
    cThriftMetadata as __fbthrift_cThriftMetadata,
    MetadataBox as __MetadataBox,
)
from folly.optional cimport cOptional as __cOptional

cimport module.types_fields as _fbthrift_types_fields

cdef extern from "src/gen-py3/module/types.h":
  pass

cdef extern from *:
    ctypedef cint64_t Foo "Foo"
cdef extern from *:
    ctypedef double Bar "Bar"
cdef extern from *:
    ctypedef cint32_t Baz "Baz"

cdef extern from "src/gen-cpp2/module_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass EnumMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "src/gen-cpp2/module_types.h" namespace "::cpp2":
    cdef cppclass cMyEnumA "::cpp2::MyEnumA":
        pass





cdef class MyEnumA(thrift.py3.types.CompiledEnum):
    pass

cdef extern from "src/gen-cpp2/module_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass ExceptionMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "src/gen-cpp2/module_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass StructMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "src/gen-cpp2/module_types_custom_protocol.h" namespace "::cpp2":

    cdef cppclass cSmallStruct "::cpp2::SmallStruct":
        cSmallStruct() except +
        cSmallStruct(const cSmallStruct&) except +
        bint operator==(cSmallStruct&)
        bint operator!=(cSmallStruct&)
        bint operator<(cSmallStruct&)
        bint operator>(cSmallStruct&)
        bint operator<=(cSmallStruct&)
        bint operator>=(cSmallStruct&)
        __field_ref[cbool] small_A_ref "small_A_ref" ()
        __field_ref[cint32_t] small_B_ref "small_B_ref" ()


    cdef cppclass ccontainerStruct "::cpp2::containerStruct":
        ccontainerStruct() except +
        ccontainerStruct(const ccontainerStruct&) except +
        bint operator==(ccontainerStruct&)
        bint operator!=(ccontainerStruct&)
        bint operator<(ccontainerStruct&)
        bint operator>(ccontainerStruct&)
        bint operator<=(ccontainerStruct&)
        bint operator>=(ccontainerStruct&)
        __field_ref[cbool] fieldA_ref "fieldA_ref" ()
        __field_ref[cmap[string,cbool]] fieldB_ref "fieldB_ref" ()
        __field_ref[cset[cint32_t]] fieldC_ref "fieldC_ref" ()
        __field_ref[string] fieldD_ref "fieldD_ref" ()
        __field_ref[string] fieldE_ref "fieldE_ref" ()
        __field_ref[vector[vector[vector[cint32_t]]]] fieldF_ref "fieldF_ref" ()
        __field_ref[cmap[string,cmap[string,cmap[string,cint32_t]]]] fieldG_ref "fieldG_ref" ()
        __field_ref[vector[cset[cint32_t]]] fieldH_ref "fieldH_ref" ()
        __field_ref[cbool] fieldI_ref "fieldI_ref" ()
        __field_ref[cmap[string,vector[cint32_t]]] fieldJ_ref "fieldJ_ref" ()
        __field_ref[vector[vector[vector[vector[cint32_t]]]]] fieldK_ref "fieldK_ref" ()
        __field_ref[cset[cset[cset[cbool]]]] fieldL_ref "fieldL_ref" ()
        __field_ref[cmap[cset[vector[cint32_t]],cmap[vector[cset[string]],string]]] fieldM_ref "fieldM_ref" ()
        __field_ref[vector[Foo]] fieldN_ref "fieldN_ref" ()
        __field_ref[vector[Bar]] fieldO_ref "fieldO_ref" ()
        __field_ref[vector[Baz]] fieldP_ref "fieldP_ref" ()
        __field_ref[cMyEnumA] fieldQ_ref "fieldQ_ref" ()
        unique_ptr[cmap[string,cbool]] fieldR_ref "fieldR_ref" ()
        unique_ptr[cSmallStruct] fieldS_ref "fieldS_ref" ()
        shared_ptr[cSmallStruct] fieldT_ref "fieldT_ref" ()
        shared_ptr[const cSmallStruct] fieldU_ref "fieldU_ref" ()
        unique_ptr[cSmallStruct] fieldX_ref "fieldX_ref" ()




cdef class SmallStruct(thrift.py3.types.Struct):
    cdef shared_ptr[cSmallStruct] _cpp_obj
    cdef _fbthrift_types_fields.__SmallStruct_FieldsSetter _fields_setter
    cdef inline object small_A_impl(self)
    cdef inline object small_B_impl(self)

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cSmallStruct])



cdef class containerStruct(thrift.py3.types.Struct):
    cdef shared_ptr[ccontainerStruct] _cpp_obj
    cdef _fbthrift_types_fields.__containerStruct_FieldsSetter _fields_setter
    cdef inline object fieldA_impl(self)
    cdef inline object fieldB_impl(self)
    cdef inline object fieldC_impl(self)
    cdef inline object fieldD_impl(self)
    cdef inline object fieldE_impl(self)
    cdef inline object fieldF_impl(self)
    cdef inline object fieldG_impl(self)
    cdef inline object fieldH_impl(self)
    cdef inline object fieldI_impl(self)
    cdef inline object fieldJ_impl(self)
    cdef inline object fieldK_impl(self)
    cdef inline object fieldL_impl(self)
    cdef inline object fieldM_impl(self)
    cdef inline object fieldN_impl(self)
    cdef inline object fieldO_impl(self)
    cdef inline object fieldP_impl(self)
    cdef inline object fieldQ_impl(self)
    cdef inline object fieldR_impl(self)
    cdef inline object fieldS_impl(self)
    cdef inline object fieldT_impl(self)
    cdef inline object fieldU_impl(self)
    cdef inline object fieldX_impl(self)
    cdef Map__string_bool __fbthrift_cached_fieldB
    cdef Set__i32 __fbthrift_cached_fieldC
    cdef List__List__List__i32 __fbthrift_cached_fieldF
    cdef Map__string_Map__string_Map__string_i32 __fbthrift_cached_fieldG
    cdef List__Set__i32 __fbthrift_cached_fieldH
    cdef Map__string_List__i32 __fbthrift_cached_fieldJ
    cdef List__List__List__List__i32 __fbthrift_cached_fieldK
    cdef Set__Set__Set__bool __fbthrift_cached_fieldL
    cdef Map__Set__List__i32_Map__List__Set__string_string __fbthrift_cached_fieldM
    cdef List__Foo__i64 __fbthrift_cached_fieldN
    cdef List__Bar__double __fbthrift_cached_fieldO
    cdef List__Baz__i32 __fbthrift_cached_fieldP
    cdef object __fbthrift_cached_fieldQ
    cdef Map__string_bool __fbthrift_cached_fieldR
    cdef SmallStruct __fbthrift_cached_fieldS
    cdef SmallStruct __fbthrift_cached_fieldT
    cdef SmallStruct __fbthrift_cached_fieldU
    cdef SmallStruct __fbthrift_cached_fieldX

    @staticmethod
    cdef _fbthrift_create(shared_ptr[ccontainerStruct])


cdef class Map__string_bool(thrift.py3.types.Map):
    cdef shared_ptr[cmap[string,cbool]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cmap[string,cbool]])
    @staticmethod
    cdef shared_ptr[cmap[string,cbool]] _make_instance(object items) except *

cdef class Set__i32(thrift.py3.types.Set):
    cdef shared_ptr[cset[cint32_t]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cset[cint32_t]])
    @staticmethod
    cdef shared_ptr[cset[cint32_t]] _make_instance(object items) except *

cdef class List__i32(thrift.py3.types.List):
    cdef shared_ptr[vector[cint32_t]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[cint32_t]])
    @staticmethod
    cdef shared_ptr[vector[cint32_t]] _make_instance(object items) except *

cdef class List__List__i32(thrift.py3.types.List):
    cdef shared_ptr[vector[vector[cint32_t]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[vector[cint32_t]]])
    @staticmethod
    cdef shared_ptr[vector[vector[cint32_t]]] _make_instance(object items) except *

cdef class List__List__List__i32(thrift.py3.types.List):
    cdef shared_ptr[vector[vector[vector[cint32_t]]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[vector[vector[cint32_t]]]])
    @staticmethod
    cdef shared_ptr[vector[vector[vector[cint32_t]]]] _make_instance(object items) except *

cdef class Map__string_i32(thrift.py3.types.Map):
    cdef shared_ptr[cmap[string,cint32_t]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cmap[string,cint32_t]])
    @staticmethod
    cdef shared_ptr[cmap[string,cint32_t]] _make_instance(object items) except *

cdef class Map__string_Map__string_i32(thrift.py3.types.Map):
    cdef shared_ptr[cmap[string,cmap[string,cint32_t]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cmap[string,cmap[string,cint32_t]]])
    @staticmethod
    cdef shared_ptr[cmap[string,cmap[string,cint32_t]]] _make_instance(object items) except *

cdef class Map__string_Map__string_Map__string_i32(thrift.py3.types.Map):
    cdef shared_ptr[cmap[string,cmap[string,cmap[string,cint32_t]]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cmap[string,cmap[string,cmap[string,cint32_t]]]])
    @staticmethod
    cdef shared_ptr[cmap[string,cmap[string,cmap[string,cint32_t]]]] _make_instance(object items) except *

cdef class List__Set__i32(thrift.py3.types.List):
    cdef shared_ptr[vector[cset[cint32_t]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[cset[cint32_t]]])
    @staticmethod
    cdef shared_ptr[vector[cset[cint32_t]]] _make_instance(object items) except *

cdef class Map__string_List__i32(thrift.py3.types.Map):
    cdef shared_ptr[cmap[string,vector[cint32_t]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cmap[string,vector[cint32_t]]])
    @staticmethod
    cdef shared_ptr[cmap[string,vector[cint32_t]]] _make_instance(object items) except *

cdef class List__List__List__List__i32(thrift.py3.types.List):
    cdef shared_ptr[vector[vector[vector[vector[cint32_t]]]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[vector[vector[vector[cint32_t]]]]])
    @staticmethod
    cdef shared_ptr[vector[vector[vector[vector[cint32_t]]]]] _make_instance(object items) except *

cdef class Set__bool(thrift.py3.types.Set):
    cdef shared_ptr[cset[cbool]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cset[cbool]])
    @staticmethod
    cdef shared_ptr[cset[cbool]] _make_instance(object items) except *

cdef class Set__Set__bool(thrift.py3.types.Set):
    cdef shared_ptr[cset[cset[cbool]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cset[cset[cbool]]])
    @staticmethod
    cdef shared_ptr[cset[cset[cbool]]] _make_instance(object items) except *

cdef class Set__Set__Set__bool(thrift.py3.types.Set):
    cdef shared_ptr[cset[cset[cset[cbool]]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cset[cset[cset[cbool]]]])
    @staticmethod
    cdef shared_ptr[cset[cset[cset[cbool]]]] _make_instance(object items) except *

cdef class Set__List__i32(thrift.py3.types.Set):
    cdef shared_ptr[cset[vector[cint32_t]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cset[vector[cint32_t]]])
    @staticmethod
    cdef shared_ptr[cset[vector[cint32_t]]] _make_instance(object items) except *

cdef class Set__string(thrift.py3.types.Set):
    cdef shared_ptr[cset[string]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cset[string]])
    @staticmethod
    cdef shared_ptr[cset[string]] _make_instance(object items) except *

cdef class List__Set__string(thrift.py3.types.List):
    cdef shared_ptr[vector[cset[string]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[cset[string]]])
    @staticmethod
    cdef shared_ptr[vector[cset[string]]] _make_instance(object items) except *

cdef class Map__List__Set__string_string(thrift.py3.types.Map):
    cdef shared_ptr[cmap[vector[cset[string]],string]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cmap[vector[cset[string]],string]])
    @staticmethod
    cdef shared_ptr[cmap[vector[cset[string]],string]] _make_instance(object items) except *

cdef class Map__Set__List__i32_Map__List__Set__string_string(thrift.py3.types.Map):
    cdef shared_ptr[cmap[cset[vector[cint32_t]],cmap[vector[cset[string]],string]]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cmap[cset[vector[cint32_t]],cmap[vector[cset[string]],string]]])
    @staticmethod
    cdef shared_ptr[cmap[cset[vector[cint32_t]],cmap[vector[cset[string]],string]]] _make_instance(object items) except *

cdef class List__Foo__i64(thrift.py3.types.List):
    cdef shared_ptr[vector[Foo]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[Foo]])
    @staticmethod
    cdef shared_ptr[vector[Foo]] _make_instance(object items) except *

cdef class List__Bar__double(thrift.py3.types.List):
    cdef shared_ptr[vector[Bar]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[Bar]])
    @staticmethod
    cdef shared_ptr[vector[Bar]] _make_instance(object items) except *

cdef class List__Baz__i32(thrift.py3.types.List):
    cdef shared_ptr[vector[Baz]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[Baz]])
    @staticmethod
    cdef shared_ptr[vector[Baz]] _make_instance(object items) except *


