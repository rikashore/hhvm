#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/basic-annotations/src/module.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#


from thrift.python.types import EnumMeta as __EnumMeta
import thrift.py3.types
import module.thrift_metadata




class MyEnum(
    thrift.py3.types.CompiledEnum,
    metaclass=__EnumMeta,
):
    MyValue1 = 0
    MyValue2 = 1
    DOMAIN = 2

    __slots__ = ()

    @staticmethod
    def __get_metadata__():
        return module.thrift_metadata.gen_metadata_enum_MyEnum()

    @staticmethod
    def __get_thrift_name__():
        return "module.MyEnum"

    def _to_python(self):
        import importlib
        python_types = importlib.import_module(
            "module.thrift_types"
        )
        return python_types.MyEnum(self.value)

    def _to_py3(self):
        return self

    def _to_py_deprecated(self):
        return self.value




