#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
import typing as __T

from thrift import Thrift
from thrift.protocol.TProtocol import TProtocolBase

from test.fixtures.py_cpp_transport.ttypes import *


class Iface:  # MyService
    def ping(self) -> None: ...
    def echo(self, input: str) -> str: ...

class Client(Iface, __T.ContextManager[Client]):  # MyService
    def __init__(self, iprot: __T.Optional[TProtocolBase], oprot: __T.Optional[TProtocolBase] = None, cpp_transport: __T.Optional[__T.TypeVar("SyncClient")] = None) -> None: ...
    def set_persistent_header(self, key: str, value: str) -> None: ...
    def get_persistent_headers(self) -> __T.Mapping[str, str]: ...
    def clear_persistent_headers(self) -> None: ...
    def set_onetime_header(self, key: str, value: str) -> None: ...
    def get_last_response_headers(self) -> __T.Mapping[str, str]: ...
    def set_max_frame_size(self, size: int) -> None: ...
    def send_ping(self) -> None: ...
    def recv_ping(self) -> None: ...
    def send_echo(self, input: __T.Optional[str] = ...) -> None: ...
    def recv_echo(self) -> str: ...

class Processor(Iface, Thrift.TProcessor):  # MyService
    def __init__(self, handler: Iface) -> None:
        self._handler: Iface
        self._onewayMethods: __T.Sequence[__T.Callable]
        self._processMap: __T.Dict[str, __T.Callable]

    def process_ping(self, seqid: int, iprot: TProtocolBase, oprot: TProtocolBase, server_ctx: __T.Any = ...) -> None: ...
    def process_echo(self, seqid: int, iprot: TProtocolBase, oprot: TProtocolBase, server_ctx: __T.Any = ...) -> None: ...
    def process_main(self, iprot: TProtocolBase, oprot: TProtocolBase, server_ctx: __T.Any = ...) -> __T.Optional[bool]: ...
    def onewayMethods(self) -> __T.Tuple[__T.Callable]: ...

class ping_args:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self
    ) -> None:
        ...

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...

class ping_result:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(self, success: None = ...) -> None:
        self.success: None

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...

class echo_args:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self,
        input: __T.Optional[str] = ...
    ) -> None:
        self.input: __T.Optional[str]

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...

class echo_result:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(self, success: str = ...) -> None:
        self.success: str

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
