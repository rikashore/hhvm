/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.adapter;

import com.facebook.thrift.type.TypeList;
import java.util.ArrayList;
import java.util.List;

public class __fbthrift_TypeList_635eac44 implements TypeList {

  private static List<TypeMapping> list = new ArrayList<>();

  static {
    list.add(new TypeList.TypeMapping("facebook.com/thrift/compiler/test/fixtures/adapter/src/module/Foo", "test.fixtures.adapter.Foo"));
    list.add(new TypeList.TypeMapping("facebook.com/thrift/test/Baz", "test.fixtures.adapter.Baz"));
    list.add(new TypeList.TypeMapping("facebook.com/thrift/test/Bar", "test.fixtures.adapter.Bar"));
    list.add(new TypeList.TypeMapping("facebook.com/thrift/test/DirectlyAdapted", "test.fixtures.adapter.DirectlyAdapted"));
    list.add(new TypeList.TypeMapping("facebook.com/thrift/test/StructWithFieldAdapter", "test.fixtures.adapter.StructWithFieldAdapter"));
    list.add(new TypeList.TypeMapping("facebook.com/thrift/test/TerseAdaptedFields", "test.fixtures.adapter.TerseAdaptedFields"));
    list.add(new TypeList.TypeMapping("facebook.com/thrift/test/B", "test.fixtures.adapter.B"));
    list.add(new TypeList.TypeMapping("facebook.com/thrift/test/A", "test.fixtures.adapter.A"));
    list.add(new TypeList.TypeMapping("facebook.com/thrift/test/Config", "test.fixtures.adapter.Config"));
    list.add(new TypeList.TypeMapping("facebook.com/thrift/test/MyStruct", "test.fixtures.adapter.MyStruct"));
  }

  @java.lang.Override
  public List<TypeList.TypeMapping> getTypes() {
    return list;
  }
}
