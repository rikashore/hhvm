#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations


import typing as _typing

import apache.thrift.metadata.thrift_types as _fbthrift_metadata
import folly.iobuf as _fbthrift_iobuf
from thrift.python.client import (
    AsyncClient as _fbthrift_python_AsyncClient,
    SyncClient as _fbthrift_python_SyncClient,
    Client as _fbthrift_python_Client,
)
import thrift.python.exceptions as _fbthrift_python_exceptions
import thrift.python.types as _fbthrift_python_types
import test.fixtures.interactions.module.thrift_types
import test.fixtures.interactions.module.thrift_metadata

class MyService(_fbthrift_python_Client["MyService.Async", "MyService.Sync"]):
    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.MyService"
    
    @staticmethod
    def __get_metadata__() -> _fbthrift_metadata.ThriftMetadata:
        return test.fixtures.interactions.module.thrift_metadata.gen_metadata_service_MyService()
    
    class Async(_fbthrift_python_AsyncClient):
        @staticmethod
        def __get_thrift_name__() -> str:
            return "module.MyService"
    
        @staticmethod
        def __get_metadata__() -> _fbthrift_metadata.ThriftMetadata:
            return test.fixtures.interactions.module.thrift_metadata.gen_metadata_service_MyService()
    
        async def foo(
            self
        ) -> None:
            _fbthrift_resp = await self._send_request(
                "MyService",
                "foo",
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_foo_args(),
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_foo_result,
            )
    
        async def interact(
            self,
            arg: int
        ) -> None:
            _fbthrift_resp = await self._send_request(
                "MyService",
                "interact",
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_interact_args(
                    arg=arg,),
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_interact_result,
            )
            # shortcut to success path for non-void returns
            if _fbthrift_resp.success is not None:
                return _fbthrift_resp.success
    
        async def interactFast(
            self
        ) -> int:
            _fbthrift_resp = await self._send_request(
                "MyService",
                "interactFast",
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_interactFast_args(),
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_interactFast_result,
            )
            # shortcut to success path for non-void returns
            if _fbthrift_resp.success is not None:
                return _fbthrift_resp.success
            raise _fbthrift_python_exceptions.ApplicationError(
                _fbthrift_python_exceptions.ApplicationErrorType.MISSING_RESULT,
                "Empty Response",
            )
    
        async def serialize(
            self
        ) -> _typing.Tuple[int, _typing.AsyncGenerator[int, None]]:
            _fbthrift_resp = await self._send_request(
                "MyService",
                "serialize",
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_serialize_args(),
                (test.fixtures.interactions.module.thrift_types._fbthrift_MyService_serialize_result, test.fixtures.interactions.module.thrift_types._fbthrift_MyService_serialize_result_stream),
            )
            _fbthrift_resp, _fbthrift_stream = _fbthrift_resp
            if _fbthrift_resp.success is not None:
                return _fbthrift_resp.success, _fbthrift_stream
            raise _fbthrift_python_exceptions.ApplicationError(
                _fbthrift_python_exceptions.ApplicationErrorType.MISSING_RESULT,
                "Empty Response",
            )
    
        def createMyInteraction(
            self #MyService
        ) -> MyService.Async:
            return self._create_interaction("MyInteraction", MyService.Async)  # type: ignore
    
        def createMyInteractionFast(
            self #MyService
        ) -> MyService.Async:
            return self._create_interaction("MyInteractionFast", MyService.Async)  # type: ignore
    
        def createSerialInteraction(
            self #MyService
        ) -> MyService.Async:
            return self._create_interaction("SerialInteraction", MyService.Async)  # type: ignore
    
    class Sync(_fbthrift_python_SyncClient):
        @staticmethod
        def __get_thrift_name__() -> str:
            return "module.MyService"
    
        @staticmethod
        def __get_metadata__() -> _fbthrift_metadata.ThriftMetadata:
            return test.fixtures.interactions.module.thrift_metadata.gen_metadata_service_MyService()
    
        def foo(
            self
        ) -> None:
            _fbthrift_resp = self._send_request(
                "MyService",
                "foo",
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_foo_args(),
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_foo_result,
            )
    
        def interact(
            self,
            arg: int
        ) -> None:
            _fbthrift_resp = self._send_request(
                "MyService",
                "interact",
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_interact_args(
                    arg=arg,),
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_interact_result,
            )
    
        def interactFast(
            self
        ) -> int:
            _fbthrift_resp = self._send_request(
                "MyService",
                "interactFast",
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_interactFast_args(),
                test.fixtures.interactions.module.thrift_types._fbthrift_MyService_interactFast_result,
            )
            # shortcut to success path for non-void returns
            if _fbthrift_resp.success is not None:
                return _fbthrift_resp.success
            raise _fbthrift_python_exceptions.ApplicationError(
                _fbthrift_python_exceptions.ApplicationErrorType.MISSING_RESULT,
                "Empty Response",
            )
    

