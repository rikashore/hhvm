#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from thrift.py3.reflection cimport (
  MethodSpec as __MethodSpec,
  ArgumentSpec as __ArgumentSpec,
  NumberType as __NumberType,
)

import folly.iobuf as _fbthrift_iobuf

cimport facebook.thrift.annotation.hack.types as _facebook_thrift_annotation_hack_types

cimport test.fixtures.basic.module.types as _test_fixtures_basic_module_types


cdef __InterfaceSpec get_reflection__FooService(bint for_clients):
    cdef __InterfaceSpec spec = __InterfaceSpec._fbthrift_create(
        name="FooService",
        annotations={
        },
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="simple_rpc",
            arguments=(
            ),
            result=None,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    return spec


cdef __InterfaceSpec get_reflection__FB303Service(bint for_clients):
    cdef __InterfaceSpec spec = __InterfaceSpec._fbthrift_create(
        name="FB303Service",
        annotations={
        },
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="simple_rpc",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="int_parameter",
                    type=int,
                    kind=__NumberType.I32,
                    annotations={
                    },
                ),
            ),
            result=_test_fixtures_basic_module_types.ReservedKeyword,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    return spec


cdef __InterfaceSpec get_reflection__MyService(bint for_clients):
    cdef __InterfaceSpec spec = __InterfaceSpec._fbthrift_create(
        name="MyService",
        annotations={
        },
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="ping",
            arguments=(
            ),
            result=None,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="getRandomData",
            arguments=(
            ),
            result=str,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="sink",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="sink",
                    type=int,
                    kind=__NumberType.I64,
                    annotations={
                    },
                ),
            ),
            result=None,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="putDataById",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="id",
                    type=int,
                    kind=__NumberType.I64,
                    annotations={
                    },
                ),
                __ArgumentSpec._fbthrift_create(
                    name="data",
                    type=str,
                    kind=__NumberType.NOT_A_NUMBER,
                    annotations={
                    },
                ),
            ),
            result=None,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="hasDataById",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="id",
                    type=int,
                    kind=__NumberType.I64,
                    annotations={
                    },
                ),
            ),
            result=bool,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="getDataById",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="id",
                    type=int,
                    kind=__NumberType.I64,
                    annotations={
                    },
                ),
            ),
            result=str,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="deleteDataById",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="id",
                    type=int,
                    kind=__NumberType.I64,
                    annotations={
                    },
                ),
            ),
            result=None,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="lobDataById",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="id",
                    type=int,
                    kind=__NumberType.I64,
                    annotations={
                    },
                ),
                __ArgumentSpec._fbthrift_create(
                    name="data",
                    type=str,
                    kind=__NumberType.NOT_A_NUMBER,
                    annotations={
                    },
                ),
            ),
            result=None,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="invalid_return_for_hack",
            arguments=(
            ),
            result=_test_fixtures_basic_module_types.Set__float,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="rpc_skipped_codegen",
            arguments=(
            ),
            result=None,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    return spec


cdef __InterfaceSpec get_reflection__DbMixedStackArguments(bint for_clients):
    cdef __InterfaceSpec spec = __InterfaceSpec._fbthrift_create(
        name="DbMixedStackArguments",
        annotations={
        },
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="getDataByKey0",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="key",
                    type=str,
                    kind=__NumberType.NOT_A_NUMBER,
                    annotations={
                    },
                ),
            ),
            result=bytes,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="getDataByKey1",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="key",
                    type=str,
                    kind=__NumberType.NOT_A_NUMBER,
                    annotations={
                    },
                ),
            ),
            result=bytes,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    return spec
