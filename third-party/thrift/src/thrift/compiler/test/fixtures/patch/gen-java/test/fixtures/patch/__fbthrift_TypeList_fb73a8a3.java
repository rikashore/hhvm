/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.patch;

import com.facebook.thrift.type.TypeList;
import java.util.ArrayList;
import java.util.List;

public class __fbthrift_TypeList_fb73a8a3 implements TypeList {

  private static List<TypeMapping> list = new ArrayList<>();

  static {
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyData", "test.fixtures.patch.MyData"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/InnerUnion", "test.fixtures.patch.InnerUnion"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyUnion", "test.fixtures.patch.MyUnion"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyStruct", "test.fixtures.patch.MyStruct"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyDataFieldPatch", "test.fixtures.patch.MyDataFieldPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyDataPatch", "test.fixtures.patch.MyDataPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/OptionalMyDataPatch", "test.fixtures.patch.OptionalMyDataPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/InnerUnionFieldPatch", "test.fixtures.patch.InnerUnionFieldPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/InnerUnionPatch", "test.fixtures.patch.InnerUnionPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/OptionalInnerUnionPatch", "test.fixtures.patch.OptionalInnerUnionPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyUnionFieldPatch", "test.fixtures.patch.MyUnionFieldPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyUnionPatch", "test.fixtures.patch.MyUnionPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/OptionalMyUnionPatch", "test.fixtures.patch.OptionalMyUnionPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyStructFieldPatch", "test.fixtures.patch.MyStructFieldPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyStructField21Patch", "test.fixtures.patch.MyStructField21Patch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/OptionalMyStructField21Patch", "test.fixtures.patch.OptionalMyStructField21Patch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyStructField22Patch", "test.fixtures.patch.MyStructField22Patch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/OptionalMyStructField22Patch", "test.fixtures.patch.OptionalMyStructField22Patch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyStructField23Patch", "test.fixtures.patch.MyStructField23Patch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/OptionalMyStructField23Patch", "test.fixtures.patch.OptionalMyStructField23Patch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/MyStructPatch", "test.fixtures.patch.MyStructPatch"));
    list.add(new TypeList.TypeMapping("test.dev/fixtures/patch/OptionalMyStructPatch", "test.fixtures.patch.OptionalMyStructPatch"));
  }

  @java.lang.Override
  public List<TypeList.TypeMapping> getTypes() {
    return list;
  }
}
