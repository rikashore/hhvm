#
# Autogenerated by Thrift for includes.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cimport cython as __cython
from cpython.object cimport PyTypeObject
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr
from libcpp.optional cimport optional as __optional
from libcpp.string cimport string
from libcpp cimport bool as cbool
from libcpp.iterator cimport inserter as cinserter
from libcpp.utility cimport move as cmove
from cpython cimport bool as pbool
from cython.operator cimport dereference as deref, preincrement as inc, address as ptr_address
import thrift.py3.types
from thrift.py3.types import _IsSet as _fbthrift_IsSet
from thrift.py3.types cimport make_unique
cimport thrift.py3.types
cimport thrift.py3.exceptions
cimport thrift.python.exceptions
from thrift.python.std_libcpp cimport sv_to_str as __sv_to_str, string_view as __cstring_view
from thrift.py3.types cimport (
    cSetOp as __cSetOp,
    richcmp as __richcmp,
    list_getitem as __list_getitem,
    set_op as __set_op,
    setcmp as __setcmp,
    set_iter as __set_iter,
    map_iter as __map_iter,
    map_contains as __map_contains,
    map_getitem as __map_getitem,
    reference_shared_ptr as __reference_shared_ptr,
    get_field_name_by_index as __get_field_name_by_index,
    reset_field as __reset_field,
    translate_cpp_enum_to_python,
    SetMetaClass as __SetMetaClass,
    const_pointer_cast,
    make_const_shared,
    constant_shared_ptr,
    NOTSET as __NOTSET,
    EnumData as __EnumData,
    EnumFlagsData as __EnumFlagsData,
    UnionTypeEnumData as __UnionTypeEnumData,
    createEnumDataForUnionType as __createEnumDataForUnionType,
    BadEnum as __BadEnum,
)
cimport thrift.py3.serializer as serializer
from thrift.python.protocol cimport Protocol as __Protocol
import folly.iobuf as _fbthrift_iobuf
from folly.optional cimport cOptional
from folly.memory cimport to_shared_ptr as __to_shared_ptr
from folly.range cimport Range as __cRange

import sys
from collections.abc import Sequence, Set, Mapping, Iterable
import weakref as __weakref
import builtins as _builtins
import importlib
cimport transitive.types as _transitive_types
import transitive.types as _transitive_types





cdef object get_types_reflection():
    import importlib
    return importlib.import_module(
        "includes.types_reflection"
    )

@__cython.auto_pickle(False)
cdef class Included(thrift.py3.types.Struct):
    def __init__(Included self, **kwargs):
        self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE = make_shared[cIncluded]()
        self._fields_setter = _fbthrift_types_fields.__Included_FieldsSetter._fbthrift_create(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE.get())
        super().__init__(**kwargs)

    def __call__(Included self, **kwargs):
        if not kwargs:
            return self
        cdef Included __fbthrift_inst = Included.__new__(Included)
        __fbthrift_inst._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE = make_shared[cIncluded](deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))
        __fbthrift_inst._fields_setter = _fbthrift_types_fields.__Included_FieldsSetter._fbthrift_create(__fbthrift_inst._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE.get())
        for __fbthrift_name, _fbthrift_value in kwargs.items():
            __fbthrift_inst._fbthrift_set_field(__fbthrift_name, _fbthrift_value)
        return __fbthrift_inst

    cdef void _fbthrift_set_field(self, str name, object value) except *:
        self._fields_setter.set_field(name.encode("utf-8"), value)

    cdef object _fbthrift_isset(self):
        return _fbthrift_IsSet("Included", {
          "MyIntField": deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE).MyIntField_ref().has_value(),
          "MyTransitiveField": deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE).MyTransitiveField_ref().has_value(),
        })

    @staticmethod
    cdef _create_FBTHRIFT_ONLY_DO_NOT_USE(shared_ptr[cIncluded] cpp_obj):
        __fbthrift_inst = <Included>Included.__new__(Included)
        __fbthrift_inst._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE = cmove(cpp_obj)
        return __fbthrift_inst

    cdef inline MyIntField_impl(self):

        return deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE).MyIntField_ref().value()

    @property
    def MyIntField(self):
        return self.MyIntField_impl()

    cdef inline MyTransitiveField_impl(self):

        if self.__fbthrift_cached_MyTransitiveField is None:
            self.__fbthrift_cached_MyTransitiveField = _transitive_types.Foo._create_FBTHRIFT_ONLY_DO_NOT_USE(__reference_shared_ptr(deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE).MyTransitiveField_ref().ref(), self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))
        return self.__fbthrift_cached_MyTransitiveField

    @property
    def MyTransitiveField(self):
        return self.MyTransitiveField_impl()


    def __hash__(Included self):
        return super().__hash__()

    def __repr__(Included self):
        return super().__repr__()

    def __str__(Included self):
        return super().__str__()


    def __copy__(Included self):
        cdef shared_ptr[cIncluded] cpp_obj = make_shared[cIncluded](
            deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE)
        )
        return Included._create_FBTHRIFT_ONLY_DO_NOT_USE(cmove(cpp_obj))

    def __richcmp__(self, other, int op):
        r = self._fbthrift_cmp_sametype(other, op)
        return __richcmp[cIncluded](
            self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE,
            (<Included>other)._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE,
            op,
        ) if r is None else r

    @staticmethod
    def __get_reflection__():
        return get_types_reflection().get_reflection__Included()

    @staticmethod
    def __get_metadata__():
        cdef __fbthrift_cThriftMetadata meta
        StructMetadata[cIncluded].gen(meta)
        return __MetadataBox.box(cmove(meta))

    @staticmethod
    def __get_thrift_name__():
        return "includes.Included"

    @classmethod
    def _fbthrift_get_field_name_by_index(cls, idx):
        return __sv_to_str(__get_field_name_by_index[cIncluded](idx))

    @classmethod
    def _fbthrift_get_struct_size(cls):
        return 2

    cdef _fbthrift_iobuf.IOBuf _fbthrift_serialize(Included self, __Protocol proto):
        cdef unique_ptr[_fbthrift_iobuf.cIOBuf] data
        with nogil:
            data = cmove(serializer.cserialize[cIncluded](self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE.get(), proto))
        return _fbthrift_iobuf.from_unique_ptr(cmove(data))

    cdef cuint32_t _fbthrift_deserialize(Included self, const _fbthrift_iobuf.cIOBuf* buf, __Protocol proto) except? 0:
        cdef cuint32_t needed
        self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE = make_shared[cIncluded]()
        with nogil:
            needed = serializer.cdeserialize[cIncluded](buf, self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE.get(), proto)
        return needed


    def _to_python(self):
        import importlib
        import thrift.python.converter
        python_types = importlib.import_module(
            "includes.thrift_types"
        )
        return thrift.python.converter.to_python_struct(python_types.Included, self)

    def _to_py3(self):
        return self

    def _to_py_deprecated(self):
        import importlib
        import thrift.util.converter
        py_deprecated_types = importlib.import_module("includes.ttypes")
        return thrift.util.converter.to_py_struct(py_deprecated_types.Included, self)


ExampleIncluded = Included._create_FBTHRIFT_ONLY_DO_NOT_USE(constant_shared_ptr(cExampleIncluded()))
IncludedConstant = 42
IncludedInt64 = int
TransitiveFoo = _transitive_types.Foo
