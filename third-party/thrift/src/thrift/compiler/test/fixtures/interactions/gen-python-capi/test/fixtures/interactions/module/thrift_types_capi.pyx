
#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from cpython.ref cimport PyObject
from libcpp.utility cimport move as __move
from folly.iobuf cimport (
    from_unique_ptr as __IOBuf_from_unique_ptr,
    IOBuf as __IOBuf,
)
from thrift.python.serializer import (
    deserialize as __deserialize,
    Protocol as __Protocol,
    serialize_iobuf as __serialize_iobuf,
)
import test.fixtures.interactions.module.thrift_types as __thrift_types

cdef api int can_extract__test__fixtures__interactions__module__CustomException(object __obj) except -1:
    return 1 if isinstance(__obj, __thrift_types.CustomException) else 0


cdef api object init__test__fixtures__interactions__module__CustomException(object data):
    return __thrift_types.CustomException._fbthrift_create(data)

