#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from thrift.py3.server cimport ServiceInterface


cdef class MyServiceInterface(ServiceInterface):
    # these are to avoid weird Cython multiple inheritance issue
    cdef bint _for_cython_ping
    cdef bint _for_cython_getRandomData
    cdef bint _for_cython_hasDataById
    cdef bint _for_cython_getDataById
    cdef bint _for_cython_putDataById
    cdef bint _for_cython_lobDataById
    cdef bint _for_cython_doNothing
    pass

cdef class MyServicePrioParentInterface(ServiceInterface):
    # these are to avoid weird Cython multiple inheritance issue
    cdef bint _for_cython_ping
    cdef bint _for_cython_pong
    pass

cdef class MyServicePrioChildInterface(MyServicePrioParentInterface):
    # these are to avoid weird Cython multiple inheritance issue
    cdef bint _for_cython_pang
    pass

cdef class BadServiceInterface(ServiceInterface):
    # these are to avoid weird Cython multiple inheritance issue
    cdef bint _for_cython_bar
    pass

