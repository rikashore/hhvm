#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations


# EXPERIMENTAL - DO NOT USE !!!
# See `experimental_generate_mutable_types` documentation in thrift compiler

#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations

import typing as _typing

import enum

import folly.iobuf as _fbthrift_iobuf
import thrift.python.types as _fbthrift_python_types
import thrift.python.mutable_types as _fbthrift_python_mutable_types
import thrift.python.mutable_exceptions as _fbthrift_python_mutable_exceptions

class _fbthrift_compatible_with_MyEnum:
    pass


class MyEnum(_fbthrift_python_types.Enum, int, _fbthrift_compatible_with_MyEnum):
    MyValue1: MyEnum = ...
    MyValue2: MyEnum = ...
    MyValue3: MyEnum = ...
    MyValue4: MyEnum = ...
    MyValue5: MyEnum = ...
    def _to_python(self) -> MyEnum: ...
    def _to_py3(self) -> "module.types.MyEnum": ...  # type: ignore
    def _to_py_deprecated(self) -> int: ...


class _fbthrift_compatible_with_MyStructFloatFieldThrowExp:
    pass


class MyStructFloatFieldThrowExp(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_compatible_with_MyStructFloatFieldThrowExp):
    myLongField: int = ...
    MyByteField: int = ...
    myStringField: str = ...
    myFloatField: float = ...
    def __init__(
        self, *,
        myLongField: _typing.Optional[int]=...,
        MyByteField: _typing.Optional[int]=...,
        myStringField: _typing.Optional[str]=...,
        myFloatField: _typing.Optional[float]=...
    ) -> None: ...

    def __call__(
        self, *,
        myLongField: _typing.Optional[int]=...,
        MyByteField: _typing.Optional[int]=...,
        myStringField: _typing.Optional[str]=...,
        myFloatField: _typing.Optional[float]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, int, str, float]]]: ...
    def _to_python(self) -> "module.thrift_types.MyStructFloatFieldThrowExp": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.MyStructFloatFieldThrowExp": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyStructFloatFieldThrowExp": ...  # type: ignore


class _fbthrift_compatible_with_MyStructMapFloatThrowExp:
    pass


class MyStructMapFloatThrowExp(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_compatible_with_MyStructMapFloatThrowExp):
    myLongField: int = ...
    mapListOfFloats: _typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[float]]] = ...
    def __init__(
        self, *,
        myLongField: _typing.Optional[int]=...,
        mapListOfFloats: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[float]]]]=...
    ) -> None: ...

    def __call__(
        self, *,
        myLongField: _typing.Optional[int]=...,
        mapListOfFloats: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[float]]]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, _typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[float]]]]]]: ...
    def _to_python(self) -> "module.thrift_types.MyStructMapFloatThrowExp": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.MyStructMapFloatThrowExp": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyStructMapFloatThrowExp": ...  # type: ignore


class _fbthrift_compatible_with_MyStruct:
    pass


class MyStruct(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_compatible_with_MyStruct):
    MyIntField: int = ...
    MyStringField: str = ...
    MyDataField: MyDataItem = ...
    myEnum: MyEnum = ...
    MyBoolField: bool = ...
    MyByteField: int = ...
    MyShortField: int = ...
    MyLongField: int = ...
    MyDoubleField: float = ...
    lDouble: _typing.MutableSequence[float] = ...
    lShort: _typing.MutableSequence[int] = ...
    lInteger: _typing.MutableSequence[int] = ...
    lLong: _typing.MutableSequence[int] = ...
    lString: _typing.MutableSequence[str] = ...
    lBool: _typing.MutableSequence[bool] = ...
    lByte: _typing.MutableSequence[int] = ...
    mShortString: _typing.MutableMapping[int, str] = ...
    mIntegerString: _typing.MutableMapping[int, str] = ...
    mStringMyStruct: _typing.MutableMapping[str, MyStruct] = ...
    mStringBool: _typing.MutableMapping[str, bool] = ...
    mIntegerInteger: _typing.MutableMapping[int, int] = ...
    mIntegerBool: _typing.MutableMapping[int, bool] = ...
    sShort: _typing.MutableSet[int] = ...
    sMyStruct: _typing.MutableSet[MyStruct] = ...
    sLong: _typing.MutableSet[int] = ...
    sString: _typing.MutableSet[str] = ...
    sByte: _typing.MutableSet[int] = ...
    mListList: _typing.MutableMapping[_typing.MutableSequence[int], _typing.MutableSequence[int]] = ...
    def __init__(
        self, *,
        MyIntField: _typing.Optional[int]=...,
        MyStringField: _typing.Optional[str]=...,
        MyDataField: _typing.Optional[_fbthrift_compatible_with_MyDataItem]=...,
        myEnum: _typing.Optional[_fbthrift_compatible_with_MyEnum]=...,
        MyBoolField: _typing.Optional[bool]=...,
        MyByteField: _typing.Optional[int]=...,
        MyShortField: _typing.Optional[int]=...,
        MyLongField: _typing.Optional[int]=...,
        MyDoubleField: _typing.Optional[float]=...,
        lDouble: _typing.Optional[_typing.MutableSequence[float]]=...,
        lShort: _typing.Optional[_typing.MutableSequence[int]]=...,
        lInteger: _typing.Optional[_typing.MutableSequence[int]]=...,
        lLong: _typing.Optional[_typing.MutableSequence[int]]=...,
        lString: _typing.Optional[_typing.MutableSequence[str]]=...,
        lBool: _typing.Optional[_typing.MutableSequence[bool]]=...,
        lByte: _typing.Optional[_typing.MutableSequence[int]]=...,
        mShortString: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        mIntegerString: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        mStringMyStruct: _typing.Optional[_typing.MutableMapping[str, _fbthrift_compatible_with_MyStruct]]=...,
        mStringBool: _typing.Optional[_typing.MutableMapping[str, bool]]=...,
        mIntegerInteger: _typing.Optional[_typing.MutableMapping[int, int]]=...,
        mIntegerBool: _typing.Optional[_typing.MutableMapping[int, bool]]=...,
        sShort: _typing.Optional[_typing.MutableSet[int]]=...,
        sMyStruct: _typing.Optional[_typing.MutableSet[_fbthrift_compatible_with_MyStruct]]=...,
        sLong: _typing.Optional[_typing.MutableSet[int]]=...,
        sString: _typing.Optional[_typing.MutableSet[str]]=...,
        sByte: _typing.Optional[_typing.MutableSet[int]]=...,
        mListList: _typing.Optional[_typing.MutableMapping[_typing.MutableSequence[int], _typing.MutableSequence[int]]]=...
    ) -> None: ...

    def __call__(
        self, *,
        MyIntField: _typing.Optional[int]=...,
        MyStringField: _typing.Optional[str]=...,
        MyDataField: _typing.Optional[_fbthrift_compatible_with_MyDataItem]=...,
        myEnum: _typing.Optional[_fbthrift_compatible_with_MyEnum]=...,
        MyBoolField: _typing.Optional[bool]=...,
        MyByteField: _typing.Optional[int]=...,
        MyShortField: _typing.Optional[int]=...,
        MyLongField: _typing.Optional[int]=...,
        MyDoubleField: _typing.Optional[float]=...,
        lDouble: _typing.Optional[_typing.MutableSequence[float]]=...,
        lShort: _typing.Optional[_typing.MutableSequence[int]]=...,
        lInteger: _typing.Optional[_typing.MutableSequence[int]]=...,
        lLong: _typing.Optional[_typing.MutableSequence[int]]=...,
        lString: _typing.Optional[_typing.MutableSequence[str]]=...,
        lBool: _typing.Optional[_typing.MutableSequence[bool]]=...,
        lByte: _typing.Optional[_typing.MutableSequence[int]]=...,
        mShortString: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        mIntegerString: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        mStringMyStruct: _typing.Optional[_typing.MutableMapping[str, _fbthrift_compatible_with_MyStruct]]=...,
        mStringBool: _typing.Optional[_typing.MutableMapping[str, bool]]=...,
        mIntegerInteger: _typing.Optional[_typing.MutableMapping[int, int]]=...,
        mIntegerBool: _typing.Optional[_typing.MutableMapping[int, bool]]=...,
        sShort: _typing.Optional[_typing.MutableSet[int]]=...,
        sMyStruct: _typing.Optional[_typing.MutableSet[_fbthrift_compatible_with_MyStruct]]=...,
        sLong: _typing.Optional[_typing.MutableSet[int]]=...,
        sString: _typing.Optional[_typing.MutableSet[str]]=...,
        sByte: _typing.Optional[_typing.MutableSet[int]]=...,
        mListList: _typing.Optional[_typing.MutableMapping[_typing.MutableSequence[int], _typing.MutableSequence[int]]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, str, MyDataItem, MyEnum, bool, int, int, int, float, _typing.MutableSequence[float], _typing.MutableSequence[int], _typing.MutableSequence[int], _typing.MutableSequence[int], _typing.MutableSequence[str], _typing.MutableSequence[bool], _typing.MutableSequence[int], _typing.MutableMapping[int, str], _typing.MutableMapping[int, str], _typing.MutableMapping[str, MyStruct], _typing.MutableMapping[str, bool], _typing.MutableMapping[int, int], _typing.MutableMapping[int, bool], _typing.MutableSet[int], _typing.MutableSet[MyStruct], _typing.MutableSet[int], _typing.MutableSet[str], _typing.MutableSet[int], _typing.MutableMapping[_typing.MutableSequence[int], _typing.MutableSequence[int]]]]]: ...
    def _to_python(self) -> "module.thrift_types.MyStruct": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.MyStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyStruct": ...  # type: ignore


class _fbthrift_compatible_with_SimpleStruct:
    pass


class SimpleStruct(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_compatible_with_SimpleStruct):
    age: int = ...
    name: str = ...
    def __init__(
        self, *,
        age: _typing.Optional[int]=...,
        name: _typing.Optional[str]=...
    ) -> None: ...

    def __call__(
        self, *,
        age: _typing.Optional[int]=...,
        name: _typing.Optional[str]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, str]]]: ...
    def _to_python(self) -> "module.thrift_types.SimpleStruct": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.SimpleStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.SimpleStruct": ...  # type: ignore


class _fbthrift_compatible_with_defaultStruct:
    pass


class defaultStruct(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_compatible_with_defaultStruct):
    myLongDFset: int = ...
    myLongDF: int = ...
    portDFset: int = ...
    portNum: int = ...
    myBinaryDFset: bytes = ...
    myBinary: bytes = ...
    myByteDFSet: int = ...
    myByte: int = ...
    myDoubleDFset: float = ...
    myDoubleDFZero: float = ...
    myDouble: float = ...
    field3: _typing.MutableMapping[int, str] = ...
    myList: _typing.MutableSequence[MyEnum] = ...
    mySet: _typing.MutableSet[str] = ...
    simpleStruct: SimpleStruct = ...
    listStructDFset: _typing.MutableSequence[SimpleStruct] = ...
    myUnion: MyUnion = ...
    listUnionDFset: _typing.MutableSequence[MyUnion] = ...
    mapNestlistStructDfSet: _typing.MutableMapping[int, _typing.MutableSequence[SimpleStruct]] = ...
    mapJavaTypeDFset: _typing.MutableMapping[int, str] = ...
    emptyMap: _typing.MutableMapping[int, int] = ...
    enumMapDFset: _typing.MutableMapping[str, _typing.MutableMapping[int, MyEnum]] = ...
    def __init__(
        self, *,
        myLongDFset: _typing.Optional[int]=...,
        myLongDF: _typing.Optional[int]=...,
        portDFset: _typing.Optional[int]=...,
        portNum: _typing.Optional[int]=...,
        myBinaryDFset: _typing.Optional[bytes]=...,
        myBinary: _typing.Optional[bytes]=...,
        myByteDFSet: _typing.Optional[int]=...,
        myByte: _typing.Optional[int]=...,
        myDoubleDFset: _typing.Optional[float]=...,
        myDoubleDFZero: _typing.Optional[float]=...,
        myDouble: _typing.Optional[float]=...,
        field3: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        myList: _typing.Optional[_typing.MutableSequence[_fbthrift_compatible_with_MyEnum]]=...,
        mySet: _typing.Optional[_typing.MutableSet[str]]=...,
        simpleStruct: _typing.Optional[_fbthrift_compatible_with_SimpleStruct]=...,
        listStructDFset: _typing.Optional[_typing.MutableSequence[_fbthrift_compatible_with_SimpleStruct]]=...,
        myUnion: _typing.Optional[_fbthrift_compatible_with_MyUnion]=...,
        listUnionDFset: _typing.Optional[_typing.MutableSequence[_fbthrift_compatible_with_MyUnion]]=...,
        mapNestlistStructDfSet: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_fbthrift_compatible_with_SimpleStruct]]]=...,
        mapJavaTypeDFset: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        emptyMap: _typing.Optional[_typing.MutableMapping[int, int]]=...,
        enumMapDFset: _typing.Optional[_typing.MutableMapping[str, _typing.MutableMapping[int, _fbthrift_compatible_with_MyEnum]]]=...
    ) -> None: ...

    def __call__(
        self, *,
        myLongDFset: _typing.Optional[int]=...,
        myLongDF: _typing.Optional[int]=...,
        portDFset: _typing.Optional[int]=...,
        portNum: _typing.Optional[int]=...,
        myBinaryDFset: _typing.Optional[bytes]=...,
        myBinary: _typing.Optional[bytes]=...,
        myByteDFSet: _typing.Optional[int]=...,
        myByte: _typing.Optional[int]=...,
        myDoubleDFset: _typing.Optional[float]=...,
        myDoubleDFZero: _typing.Optional[float]=...,
        myDouble: _typing.Optional[float]=...,
        field3: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        myList: _typing.Optional[_typing.MutableSequence[_fbthrift_compatible_with_MyEnum]]=...,
        mySet: _typing.Optional[_typing.MutableSet[str]]=...,
        simpleStruct: _typing.Optional[_fbthrift_compatible_with_SimpleStruct]=...,
        listStructDFset: _typing.Optional[_typing.MutableSequence[_fbthrift_compatible_with_SimpleStruct]]=...,
        myUnion: _typing.Optional[_fbthrift_compatible_with_MyUnion]=...,
        listUnionDFset: _typing.Optional[_typing.MutableSequence[_fbthrift_compatible_with_MyUnion]]=...,
        mapNestlistStructDfSet: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_fbthrift_compatible_with_SimpleStruct]]]=...,
        mapJavaTypeDFset: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        emptyMap: _typing.Optional[_typing.MutableMapping[int, int]]=...,
        enumMapDFset: _typing.Optional[_typing.MutableMapping[str, _typing.MutableMapping[int, _fbthrift_compatible_with_MyEnum]]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, int, int, int, bytes, bytes, int, int, float, float, float, _typing.MutableMapping[int, str], _typing.MutableSequence[MyEnum], _typing.MutableSet[str], SimpleStruct, _typing.MutableSequence[SimpleStruct], MyUnion, _typing.MutableSequence[MyUnion], _typing.MutableMapping[int, _typing.MutableSequence[SimpleStruct]], _typing.MutableMapping[int, str], _typing.MutableMapping[int, int], _typing.MutableMapping[str, _typing.MutableMapping[int, MyEnum]]]]]: ...
    def _to_python(self) -> "module.thrift_types.defaultStruct": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.defaultStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.defaultStruct": ...  # type: ignore


class _fbthrift_compatible_with_MyStructTypeDef:
    pass


class MyStructTypeDef(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_compatible_with_MyStructTypeDef):
    myLongField: int = ...
    myLongTypeDef: int = ...
    myStringField: str = ...
    myStringTypedef: str = ...
    myMapField: _typing.MutableMapping[int, str] = ...
    myMapTypedef: _typing.MutableMapping[int, str] = ...
    myListField: _typing.MutableSequence[float] = ...
    myListTypedef: _typing.MutableSequence[float] = ...
    myMapListOfTypeDef: _typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[float]]] = ...
    def __init__(
        self, *,
        myLongField: _typing.Optional[int]=...,
        myLongTypeDef: _typing.Optional[int]=...,
        myStringField: _typing.Optional[str]=...,
        myStringTypedef: _typing.Optional[str]=...,
        myMapField: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        myMapTypedef: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        myListField: _typing.Optional[_typing.MutableSequence[float]]=...,
        myListTypedef: _typing.Optional[_typing.MutableSequence[float]]=...,
        myMapListOfTypeDef: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[float]]]]=...
    ) -> None: ...

    def __call__(
        self, *,
        myLongField: _typing.Optional[int]=...,
        myLongTypeDef: _typing.Optional[int]=...,
        myStringField: _typing.Optional[str]=...,
        myStringTypedef: _typing.Optional[str]=...,
        myMapField: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        myMapTypedef: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        myListField: _typing.Optional[_typing.MutableSequence[float]]=...,
        myListTypedef: _typing.Optional[_typing.MutableSequence[float]]=...,
        myMapListOfTypeDef: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[float]]]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, int, str, str, _typing.MutableMapping[int, str], _typing.MutableMapping[int, str], _typing.MutableSequence[float], _typing.MutableSequence[float], _typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[float]]]]]]: ...
    def _to_python(self) -> "module.thrift_types.MyStructTypeDef": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.MyStructTypeDef": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyStructTypeDef": ...  # type: ignore


class _fbthrift_compatible_with_MyDataItem:
    pass


class MyDataItem(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_compatible_with_MyDataItem):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> "module.thrift_types.MyDataItem": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.MyDataItem": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyDataItem": ...  # type: ignore


class _fbthrift_compatible_with_MyUnion:
    pass


class MyUnion(_fbthrift_python_mutable_types.MutableUnion, _fbthrift_compatible_with_MyUnion):
    myEnum: MyEnum = ...
    myStruct: MyStruct = ...
    myDataItem: MyDataItem = ...
    complexNestedStruct: ComplexNestedStruct = ...
    longValue: int = ...
    intValue: int = ...
    def __init__(
        self, *,
        myEnum: _typing.Optional[_fbthrift_compatible_with_MyEnum]=...,
        myStruct: _typing.Optional[_fbthrift_compatible_with_MyStruct]=...,
        myDataItem: _typing.Optional[_fbthrift_compatible_with_MyDataItem]=...,
        complexNestedStruct: _typing.Optional[_fbthrift_compatible_with_ComplexNestedStruct]=...,
        longValue: _typing.Optional[int]=...,
        intValue: _typing.Optional[int]=...
    ) -> None: ...


    class Type(enum.Enum):
        FBTHRIFT_UNION_EMPTY: MyUnion.FbThriftUnionFieldEnum = ...
        myEnum: MyUnion.Type = ...
        myStruct: MyUnion.Type = ...
        myDataItem: MyUnion.Type = ...
        complexNestedStruct: MyUnion.Type = ...
        longValue: MyUnion.Type = ...
        intValue: MyUnion.Type = ...

    fbthrift_current_value: _typing.Final[_typing.Union[None, MyEnum, MyStruct, MyDataItem, ComplexNestedStruct, int, int]]
    fbthrift_current_field: FbThriftUnionFieldEnum
    def get_type(self) -> FbThriftUnionFieldEnum:...
    def _to_python(self) -> "module.thrift_types.MyUnion": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.MyUnion": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyUnion": ...  # type: ignore


class _fbthrift_compatible_with_MyUnionFloatFieldThrowExp:
    pass


class MyUnionFloatFieldThrowExp(_fbthrift_python_mutable_types.MutableUnion, _fbthrift_compatible_with_MyUnionFloatFieldThrowExp):
    myEnum: MyEnum = ...
    setFloat: _typing.MutableSequence[_typing.MutableSequence[float]] = ...
    myDataItem: MyDataItem = ...
    complexNestedStruct: ComplexNestedStruct = ...
    def __init__(
        self, *,
        myEnum: _typing.Optional[_fbthrift_compatible_with_MyEnum]=...,
        setFloat: _typing.Optional[_typing.MutableSequence[_typing.MutableSequence[float]]]=...,
        myDataItem: _typing.Optional[_fbthrift_compatible_with_MyDataItem]=...,
        complexNestedStruct: _typing.Optional[_fbthrift_compatible_with_ComplexNestedStruct]=...
    ) -> None: ...


    class Type(enum.Enum):
        FBTHRIFT_UNION_EMPTY: MyUnionFloatFieldThrowExp.FbThriftUnionFieldEnum = ...
        myEnum: MyUnionFloatFieldThrowExp.Type = ...
        setFloat: MyUnionFloatFieldThrowExp.Type = ...
        myDataItem: MyUnionFloatFieldThrowExp.Type = ...
        complexNestedStruct: MyUnionFloatFieldThrowExp.Type = ...

    fbthrift_current_value: _typing.Final[_typing.Union[None, MyEnum, _typing.MutableSequence[_typing.MutableSequence[float]], MyDataItem, ComplexNestedStruct]]
    fbthrift_current_field: FbThriftUnionFieldEnum
    def get_type(self) -> FbThriftUnionFieldEnum:...
    def _to_python(self) -> "module.thrift_types.MyUnionFloatFieldThrowExp": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.MyUnionFloatFieldThrowExp": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyUnionFloatFieldThrowExp": ...  # type: ignore


class _fbthrift_compatible_with_ComplexNestedStruct:
    pass


class ComplexNestedStruct(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_compatible_with_ComplexNestedStruct):
    setOfSetOfInt: _typing.MutableSet[_typing.MutableSet[int]] = ...
    listofListOfListOfListOfEnum: _typing.MutableSequence[_typing.MutableSequence[_typing.MutableSequence[_typing.MutableSequence[MyEnum]]]] = ...
    listOfListOfMyStruct: _typing.MutableSequence[_typing.MutableSequence[MyStruct]] = ...
    setOfListOfListOfLong: _typing.MutableSet[_typing.MutableSequence[_typing.MutableSequence[int]]] = ...
    setOfSetOfsetOfLong: _typing.MutableSet[_typing.MutableSet[_typing.MutableSet[int]]] = ...
    mapStructListOfListOfLong: _typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[MyStruct]]] = ...
    mKeyStructValInt: _typing.MutableMapping[MyStruct, int] = ...
    listOfMapKeyIntValInt: _typing.MutableSequence[_typing.MutableMapping[int, int]] = ...
    listOfMapKeyStrValList: _typing.MutableSequence[_typing.MutableMapping[str, _typing.MutableSequence[MyStruct]]] = ...
    mapKeySetValLong: _typing.MutableMapping[_typing.MutableSet[int], int] = ...
    mapKeyListValLong: _typing.MutableMapping[_typing.MutableSequence[str], int] = ...
    mapKeyMapValMap: _typing.MutableMapping[_typing.MutableMapping[int, str], _typing.MutableMapping[int, str]] = ...
    mapKeySetValMap: _typing.MutableMapping[_typing.MutableSet[_typing.MutableSequence[int]], _typing.MutableMapping[_typing.MutableSequence[_typing.MutableSet[str]], str]] = ...
    NestedMaps: _typing.MutableMapping[_typing.MutableMapping[_typing.MutableMapping[int, str], str], _typing.MutableMapping[int, str]] = ...
    mapKeyIntValList: _typing.MutableMapping[int, _typing.MutableSequence[MyStruct]] = ...
    mapKeyIntValSet: _typing.MutableMapping[int, _typing.MutableSet[bool]] = ...
    mapKeySetValInt: _typing.MutableMapping[_typing.MutableSet[bool], MyEnum] = ...
    mapKeyListValSet: _typing.MutableMapping[_typing.MutableSequence[int], _typing.MutableSet[_typing.MutableMapping[float, str]]] = ...
    def __init__(
        self, *,
        setOfSetOfInt: _typing.Optional[_typing.MutableSet[_typing.MutableSet[int]]]=...,
        listofListOfListOfListOfEnum: _typing.Optional[_typing.MutableSequence[_typing.MutableSequence[_typing.MutableSequence[_typing.MutableSequence[_fbthrift_compatible_with_MyEnum]]]]]=...,
        listOfListOfMyStruct: _typing.Optional[_typing.MutableSequence[_typing.MutableSequence[_fbthrift_compatible_with_MyStruct]]]=...,
        setOfListOfListOfLong: _typing.Optional[_typing.MutableSet[_typing.MutableSequence[_typing.MutableSequence[int]]]]=...,
        setOfSetOfsetOfLong: _typing.Optional[_typing.MutableSet[_typing.MutableSet[_typing.MutableSet[int]]]]=...,
        mapStructListOfListOfLong: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[_fbthrift_compatible_with_MyStruct]]]]=...,
        mKeyStructValInt: _typing.Optional[_typing.MutableMapping[MyStruct, int]]=...,
        listOfMapKeyIntValInt: _typing.Optional[_typing.MutableSequence[_typing.MutableMapping[int, int]]]=...,
        listOfMapKeyStrValList: _typing.Optional[_typing.MutableSequence[_typing.MutableMapping[str, _typing.MutableSequence[_fbthrift_compatible_with_MyStruct]]]]=...,
        mapKeySetValLong: _typing.Optional[_typing.MutableMapping[_typing.MutableSet[int], int]]=...,
        mapKeyListValLong: _typing.Optional[_typing.MutableMapping[_typing.MutableSequence[str], int]]=...,
        mapKeyMapValMap: _typing.Optional[_typing.MutableMapping[_typing.MutableMapping[int, str], _typing.MutableMapping[int, str]]]=...,
        mapKeySetValMap: _typing.Optional[_typing.MutableMapping[_typing.MutableSet[_typing.MutableSequence[int]], _typing.MutableMapping[_typing.MutableSequence[_typing.MutableSet[str]], str]]]=...,
        NestedMaps: _typing.Optional[_typing.MutableMapping[_typing.MutableMapping[_typing.MutableMapping[int, str], str], _typing.MutableMapping[int, str]]]=...,
        mapKeyIntValList: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_fbthrift_compatible_with_MyStruct]]]=...,
        mapKeyIntValSet: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSet[bool]]]=...,
        mapKeySetValInt: _typing.Optional[_typing.MutableMapping[_typing.MutableSet[bool], _fbthrift_compatible_with_MyEnum]]=...,
        mapKeyListValSet: _typing.Optional[_typing.MutableMapping[_typing.MutableSequence[int], _typing.MutableSet[_typing.MutableMapping[float, str]]]]=...
    ) -> None: ...

    def __call__(
        self, *,
        setOfSetOfInt: _typing.Optional[_typing.MutableSet[_typing.MutableSet[int]]]=...,
        listofListOfListOfListOfEnum: _typing.Optional[_typing.MutableSequence[_typing.MutableSequence[_typing.MutableSequence[_typing.MutableSequence[_fbthrift_compatible_with_MyEnum]]]]]=...,
        listOfListOfMyStruct: _typing.Optional[_typing.MutableSequence[_typing.MutableSequence[_fbthrift_compatible_with_MyStruct]]]=...,
        setOfListOfListOfLong: _typing.Optional[_typing.MutableSet[_typing.MutableSequence[_typing.MutableSequence[int]]]]=...,
        setOfSetOfsetOfLong: _typing.Optional[_typing.MutableSet[_typing.MutableSet[_typing.MutableSet[int]]]]=...,
        mapStructListOfListOfLong: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[_fbthrift_compatible_with_MyStruct]]]]=...,
        mKeyStructValInt: _typing.Optional[_typing.MutableMapping[MyStruct, int]]=...,
        listOfMapKeyIntValInt: _typing.Optional[_typing.MutableSequence[_typing.MutableMapping[int, int]]]=...,
        listOfMapKeyStrValList: _typing.Optional[_typing.MutableSequence[_typing.MutableMapping[str, _typing.MutableSequence[_fbthrift_compatible_with_MyStruct]]]]=...,
        mapKeySetValLong: _typing.Optional[_typing.MutableMapping[_typing.MutableSet[int], int]]=...,
        mapKeyListValLong: _typing.Optional[_typing.MutableMapping[_typing.MutableSequence[str], int]]=...,
        mapKeyMapValMap: _typing.Optional[_typing.MutableMapping[_typing.MutableMapping[int, str], _typing.MutableMapping[int, str]]]=...,
        mapKeySetValMap: _typing.Optional[_typing.MutableMapping[_typing.MutableSet[_typing.MutableSequence[int]], _typing.MutableMapping[_typing.MutableSequence[_typing.MutableSet[str]], str]]]=...,
        NestedMaps: _typing.Optional[_typing.MutableMapping[_typing.MutableMapping[_typing.MutableMapping[int, str], str], _typing.MutableMapping[int, str]]]=...,
        mapKeyIntValList: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSequence[_fbthrift_compatible_with_MyStruct]]]=...,
        mapKeyIntValSet: _typing.Optional[_typing.MutableMapping[int, _typing.MutableSet[bool]]]=...,
        mapKeySetValInt: _typing.Optional[_typing.MutableMapping[_typing.MutableSet[bool], _fbthrift_compatible_with_MyEnum]]=...,
        mapKeyListValSet: _typing.Optional[_typing.MutableMapping[_typing.MutableSequence[int], _typing.MutableSet[_typing.MutableMapping[float, str]]]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.MutableSet[_typing.MutableSet[int]], _typing.MutableSequence[_typing.MutableSequence[_typing.MutableSequence[_typing.MutableSequence[MyEnum]]]], _typing.MutableSequence[_typing.MutableSequence[MyStruct]], _typing.MutableSet[_typing.MutableSequence[_typing.MutableSequence[int]]], _typing.MutableSet[_typing.MutableSet[_typing.MutableSet[int]]], _typing.MutableMapping[int, _typing.MutableSequence[_typing.MutableSequence[MyStruct]]], _typing.MutableMapping[MyStruct, int], _typing.MutableSequence[_typing.MutableMapping[int, int]], _typing.MutableSequence[_typing.MutableMapping[str, _typing.MutableSequence[MyStruct]]], _typing.MutableMapping[_typing.MutableSet[int], int], _typing.MutableMapping[_typing.MutableSequence[str], int], _typing.MutableMapping[_typing.MutableMapping[int, str], _typing.MutableMapping[int, str]], _typing.MutableMapping[_typing.MutableSet[_typing.MutableSequence[int]], _typing.MutableMapping[_typing.MutableSequence[_typing.MutableSet[str]], str]], _typing.MutableMapping[_typing.MutableMapping[_typing.MutableMapping[int, str], str], _typing.MutableMapping[int, str]], _typing.MutableMapping[int, _typing.MutableSequence[MyStruct]], _typing.MutableMapping[int, _typing.MutableSet[bool]], _typing.MutableMapping[_typing.MutableSet[bool], MyEnum], _typing.MutableMapping[_typing.MutableSequence[int], _typing.MutableSet[_typing.MutableMapping[float, str]]]]]]: ...
    def _to_python(self) -> "module.thrift_types.ComplexNestedStruct": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.ComplexNestedStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.ComplexNestedStruct": ...  # type: ignore


class _fbthrift_compatible_with_TypeRemapped:
    pass


class TypeRemapped(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_compatible_with_TypeRemapped):
    lsMap: _typing.MutableMapping[int, str] = ...
    ioMap: _typing.MutableMapping[int, _typing.MutableMapping[int, int]] = ...
    BigInteger: int = ...
    binaryTestBuffer: bytes = ...
    def __init__(
        self, *,
        lsMap: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        ioMap: _typing.Optional[_typing.MutableMapping[int, _typing.MutableMapping[int, int]]]=...,
        BigInteger: _typing.Optional[int]=...,
        binaryTestBuffer: _typing.Optional[bytes]=...
    ) -> None: ...

    def __call__(
        self, *,
        lsMap: _typing.Optional[_typing.MutableMapping[int, str]]=...,
        ioMap: _typing.Optional[_typing.MutableMapping[int, _typing.MutableMapping[int, int]]]=...,
        BigInteger: _typing.Optional[int]=...,
        binaryTestBuffer: _typing.Optional[bytes]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.MutableMapping[int, str], _typing.MutableMapping[int, _typing.MutableMapping[int, int]], int, bytes]]]: ...
    def _to_python(self) -> "module.thrift_types.TypeRemapped": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.TypeRemapped": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.TypeRemapped": ...  # type: ignore


class _fbthrift_compatible_with_emptyXcep:
    pass


class emptyXcep(_fbthrift_python_mutable_exceptions.MutableGeneratedError, _fbthrift_compatible_with_emptyXcep):
    def __init__(
        self,
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> "module.thrift_types.emptyXcep": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.emptyXcep": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.emptyXcep": ...  # type: ignore


class _fbthrift_compatible_with_reqXcep:
    pass


class reqXcep(_fbthrift_python_mutable_exceptions.MutableGeneratedError, _fbthrift_compatible_with_reqXcep):
    message: str = ...
    errorCode: int = ...
    def __init__(
        self, *,
        message: _typing.Optional[str]=...,
        errorCode: _typing.Optional[int]=...
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, int]]]: ...
    def _to_python(self) -> "module.thrift_types.reqXcep": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.reqXcep": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.reqXcep": ...  # type: ignore


class _fbthrift_compatible_with_optXcep:
    pass


class optXcep(_fbthrift_python_mutable_exceptions.MutableGeneratedError, _fbthrift_compatible_with_optXcep):
    message: _typing.Optional[str] = ...
    errorCode: _typing.Optional[int] = ...
    def __init__(
        self, *,
        message: _typing.Optional[str]=...,
        errorCode: _typing.Optional[int]=...
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, int]]]: ...
    def _to_python(self) -> "module.thrift_types.optXcep": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.optXcep": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.optXcep": ...  # type: ignore


class _fbthrift_compatible_with_complexException:
    pass


class complexException(_fbthrift_python_mutable_exceptions.MutableGeneratedError, _fbthrift_compatible_with_complexException):
    message: str = ...
    listStrings: _typing.MutableSequence[str] = ...
    errorEnum: MyEnum = ...
    unionError: _typing.Optional[MyUnion] = ...
    structError: MyStruct = ...
    lsMap: _typing.MutableMapping[int, str] = ...
    def __init__(
        self, *,
        message: _typing.Optional[str]=...,
        listStrings: _typing.Optional[_typing.MutableSequence[str]]=...,
        errorEnum: _typing.Optional[_fbthrift_compatible_with_MyEnum]=...,
        unionError: _typing.Optional[_fbthrift_compatible_with_MyUnion]=...,
        structError: _typing.Optional[_fbthrift_compatible_with_MyStruct]=...,
        lsMap: _typing.Optional[_typing.MutableMapping[int, str]]=...
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, _typing.MutableSequence[str], MyEnum, MyUnion, MyStruct, _typing.MutableMapping[int, str]]]]: ...
    def _to_python(self) -> "module.thrift_types.complexException": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "module.types.complexException": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.complexException": ...  # type: ignore


DEFAULT_PORT_NUM: int = ...

constEnumUnion: MyUnion = ...

stringTypedef = str
longTypeDef = int
mapTypedef = _typing.Dict[int, str]
listTypedef = _typing.List[float]
floatTypedef = float
FMap = _typing.Dict[int, int]
binary_4918 = bytes
i32_1194 = int
map_i32_FMap_6797 = _typing.Dict[int, _typing.MutableMapping[int, int]]
map_i64_string_5732 = _typing.Dict[int, str]
