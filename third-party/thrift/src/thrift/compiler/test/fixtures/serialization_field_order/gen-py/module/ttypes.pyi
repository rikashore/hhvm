#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

# pyre-unsafe

import typing as __T  # sometimes `t` is used as a field name

from thrift import Thrift
from thrift.protocol.TProtocol import TProtocolBase

__property__ = property  # sometimes `property` is used as a field name

import thrift.annotation.thrift.ttypes

UTF8STRINGS: bool


class Foo:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self,
        field1: __T.Optional[int] = ...,
        field2: __T.Optional[int] = ...,
        field3: __T.Optional[int] = ...
    ) -> None:
        ...

    @__property__
    def field1(self) -> int: ...
    @field1.setter
    def field1(self, value: __T.Optional[int]) -> None: ...
    @__property__
    def field2(self) -> int: ...
    @field2.setter
    def field2(self, value: __T.Optional[int]) -> None: ...
    @__property__
    def field3(self) -> int: ...
    @field3.setter
    def field3(self, value: __T.Optional[int]) -> None: ...


    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    @__T.overload
    def readFromJson(self, json: __T.Dict[str, __T.Any], is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    @__T.overload
    def readFromJson(self, json: str, is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
    def __dir__(self) -> __T.Sequence[str]: ...
    def _to_python(self) -> "module.thrift_types.Foo": ...   # type: ignore
    def _to_py3(self) -> "module.types.Foo": ...   # type: ignore
    def _to_py_deprecated(self) -> Foo: ...


class Foo2:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self,
        field1: __T.Optional[int] = ...,
        field2: __T.Optional[int] = ...,
        field3: __T.Optional[int] = ...
    ) -> None:
        ...

    @__property__
    def field1(self) -> int: ...
    @field1.setter
    def field1(self, value: __T.Optional[int]) -> None: ...
    @__property__
    def field2(self) -> int: ...
    @field2.setter
    def field2(self, value: __T.Optional[int]) -> None: ...
    @__property__
    def field3(self) -> int: ...
    @field3.setter
    def field3(self, value: __T.Optional[int]) -> None: ...


    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    @__T.overload
    def readFromJson(self, json: __T.Dict[str, __T.Any], is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    @__T.overload
    def readFromJson(self, json: str, is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
    def __dir__(self) -> __T.Sequence[str]: ...
    def _to_python(self) -> "module.thrift_types.Foo2": ...   # type: ignore
    def _to_py3(self) -> "module.types.Foo2": ...   # type: ignore
    def _to_py_deprecated(self) -> Foo2: ...


