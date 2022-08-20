// Autogenerated by Thrift Compiler (facebook)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
// @generated

package module

import (
	"bytes"
	"context"
	"sync"
	"fmt"
	thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
	hack0 "thrift/annotation/hack"

)

// (needed to ensure safety because of naive import list construction.)
var _ = thrift.ZERO
var _ = fmt.Printf
var _ = sync.Mutex{}
var _ = bytes.Equal
var _ = context.Background

var _ = hack0.GoUnusedProtection__
var GoUnusedProtection__ int;

type MyEnum int64
const (
  MyEnum_MyValue1 MyEnum = 0
  MyEnum_MyValue2 MyEnum = 1
)

var MyEnumToName = map[MyEnum]string {
  MyEnum_MyValue1: "MyValue1",
  MyEnum_MyValue2: "MyValue2",
}

var MyEnumToValue = map[string]MyEnum {
  "MyValue1": MyEnum_MyValue1,
  "MyValue2": MyEnum_MyValue2,
}

var MyEnumNames = []string {
  "MyValue1",
  "MyValue2",
}

var MyEnumValues = []MyEnum {
  MyEnum_MyValue1,
  MyEnum_MyValue2,
}

func (p MyEnum) String() string {
  if v, ok := MyEnumToName[p]; ok {
    return v
  }
  return "<UNSET>"
}

func MyEnumFromString(s string) (MyEnum, error) {
  if v, ok := MyEnumToValue[s]; ok {
    return v, nil
  }
  return MyEnum(0), fmt.Errorf("not a valid MyEnum string")
}

func MyEnumPtr(v MyEnum) *MyEnum { return &v }

type HackEnum int64
const (
  HackEnum_Value1 HackEnum = 0
  HackEnum_Value2 HackEnum = 1
)

var HackEnumToName = map[HackEnum]string {
  HackEnum_Value1: "Value1",
  HackEnum_Value2: "Value2",
}

var HackEnumToValue = map[string]HackEnum {
  "Value1": HackEnum_Value1,
  "Value2": HackEnum_Value2,
}

var HackEnumNames = []string {
  "Value1",
  "Value2",
}

var HackEnumValues = []HackEnum {
  HackEnum_Value1,
  HackEnum_Value2,
}

func (p HackEnum) String() string {
  if v, ok := HackEnumToName[p]; ok {
    return v
  }
  return "<UNSET>"
}

func HackEnumFromString(s string) (HackEnum, error) {
  if v, ok := HackEnumToValue[s]; ok {
    return v, nil
  }
  return HackEnum(0), fmt.Errorf("not a valid HackEnum string")
}

func HackEnumPtr(v HackEnum) *HackEnum { return &v }

// Attributes:
//  - MyIntField
//  - MyStringField
//  - MyDataField
//  - MyEnum
//  - Oneway
//  - Readonly
//  - Idempotent
//  - FloatSet
//  - NoHackCodegenField
type MyStruct struct {
  MyIntField int64 `thrift:"MyIntField,1" db:"MyIntField" json:"MyIntField"`
  MyStringField string `thrift:"MyStringField,2" db:"MyStringField" json:"MyStringField"`
  MyDataField *MyDataItem `thrift:"MyDataField,3" db:"MyDataField" json:"MyDataField"`
  MyEnum MyEnum `thrift:"myEnum,4" db:"myEnum" json:"myEnum"`
  Oneway bool `thrift:"oneway,5" db:"oneway" json:"oneway"`
  Readonly bool `thrift:"readonly,6" db:"readonly" json:"readonly"`
  Idempotent bool `thrift:"idempotent,7" db:"idempotent" json:"idempotent"`
  FloatSet []float32 `thrift:"floatSet,8" db:"floatSet" json:"floatSet"`
  NoHackCodegenField string `thrift:"no_hack_codegen_field,9" db:"no_hack_codegen_field" json:"no_hack_codegen_field"`
}

func NewMyStruct() *MyStruct {
  return &MyStruct{
    MyDataField: NewMyDataItem(),
  }
}


func (p *MyStruct) GetMyIntField() int64 {
  return p.MyIntField
}

func (p *MyStruct) GetMyStringField() string {
  return p.MyStringField
}
var MyStruct_MyDataField_DEFAULT *MyDataItem
func (p *MyStruct) GetMyDataField() *MyDataItem {
  if !p.IsSetMyDataField() {
    return MyStruct_MyDataField_DEFAULT
  }
return p.MyDataField
}

func (p *MyStruct) GetMyEnum() MyEnum {
  return p.MyEnum
}

func (p *MyStruct) GetOneway() bool {
  return p.Oneway
}

func (p *MyStruct) GetReadonly() bool {
  return p.Readonly
}

func (p *MyStruct) GetIdempotent() bool {
  return p.Idempotent
}

func (p *MyStruct) GetFloatSet() []float32 {
  return p.FloatSet
}

func (p *MyStruct) GetNoHackCodegenField() string {
  return p.NoHackCodegenField
}
func (p *MyStruct) IsSetMyDataField() bool {
  return p != nil && p.MyDataField != nil
}

type MyStructBuilder struct {
  obj *MyStruct
}

func NewMyStructBuilder() *MyStructBuilder{
  return &MyStructBuilder{
    obj: NewMyStruct(),
  }
}

func (p MyStructBuilder) Emit() *MyStruct{
  return &MyStruct{
    MyIntField: p.obj.MyIntField,
    MyStringField: p.obj.MyStringField,
    MyDataField: p.obj.MyDataField,
    MyEnum: p.obj.MyEnum,
    Oneway: p.obj.Oneway,
    Readonly: p.obj.Readonly,
    Idempotent: p.obj.Idempotent,
    FloatSet: p.obj.FloatSet,
    NoHackCodegenField: p.obj.NoHackCodegenField,
  }
}

func (m *MyStructBuilder) MyIntField(myIntField int64) *MyStructBuilder {
  m.obj.MyIntField = myIntField
  return m
}

func (m *MyStructBuilder) MyStringField(myStringField string) *MyStructBuilder {
  m.obj.MyStringField = myStringField
  return m
}

func (m *MyStructBuilder) MyDataField(myDataField *MyDataItem) *MyStructBuilder {
  m.obj.MyDataField = myDataField
  return m
}

func (m *MyStructBuilder) MyEnum(myEnum MyEnum) *MyStructBuilder {
  m.obj.MyEnum = myEnum
  return m
}

func (m *MyStructBuilder) Oneway(oneway bool) *MyStructBuilder {
  m.obj.Oneway = oneway
  return m
}

func (m *MyStructBuilder) Readonly(readonly bool) *MyStructBuilder {
  m.obj.Readonly = readonly
  return m
}

func (m *MyStructBuilder) Idempotent(idempotent bool) *MyStructBuilder {
  m.obj.Idempotent = idempotent
  return m
}

func (m *MyStructBuilder) FloatSet(floatSet []float32) *MyStructBuilder {
  m.obj.FloatSet = floatSet
  return m
}

func (m *MyStructBuilder) NoHackCodegenField(noHackCodegenField string) *MyStructBuilder {
  m.obj.NoHackCodegenField = noHackCodegenField
  return m
}

func (m *MyStruct) SetMyIntField(myIntField int64) *MyStruct {
  m.MyIntField = myIntField
  return m
}

func (m *MyStruct) SetMyStringField(myStringField string) *MyStruct {
  m.MyStringField = myStringField
  return m
}

func (m *MyStruct) SetMyDataField(myDataField *MyDataItem) *MyStruct {
  m.MyDataField = myDataField
  return m
}

func (m *MyStruct) SetMyEnum(myEnum MyEnum) *MyStruct {
  m.MyEnum = myEnum
  return m
}

func (m *MyStruct) SetOneway(oneway bool) *MyStruct {
  m.Oneway = oneway
  return m
}

func (m *MyStruct) SetReadonly(readonly bool) *MyStruct {
  m.Readonly = readonly
  return m
}

func (m *MyStruct) SetIdempotent(idempotent bool) *MyStruct {
  m.Idempotent = idempotent
  return m
}

func (m *MyStruct) SetFloatSet(floatSet []float32) *MyStruct {
  m.FloatSet = floatSet
  return m
}

func (m *MyStruct) SetNoHackCodegenField(noHackCodegenField string) *MyStruct {
  m.NoHackCodegenField = noHackCodegenField
  return m
}

func (p *MyStruct) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    case 3:
      if err := p.ReadField3(iprot); err != nil {
        return err
      }
    case 4:
      if err := p.ReadField4(iprot); err != nil {
        return err
      }
    case 5:
      if err := p.ReadField5(iprot); err != nil {
        return err
      }
    case 6:
      if err := p.ReadField6(iprot); err != nil {
        return err
      }
    case 7:
      if err := p.ReadField7(iprot); err != nil {
        return err
      }
    case 8:
      if err := p.ReadField8(iprot); err != nil {
        return err
      }
    case 9:
      if err := p.ReadField9(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *MyStruct)  ReadField1(iprot thrift.Protocol) error {
  if v, err := iprot.ReadI64(); err != nil {
    return thrift.PrependError("error reading field 1: ", err)
  } else {
    p.MyIntField = v
  }
  return nil
}

func (p *MyStruct)  ReadField2(iprot thrift.Protocol) error {
  if v, err := iprot.ReadString(); err != nil {
    return thrift.PrependError("error reading field 2: ", err)
  } else {
    p.MyStringField = v
  }
  return nil
}

func (p *MyStruct)  ReadField3(iprot thrift.Protocol) error {
  p.MyDataField = NewMyDataItem()
  if err := p.MyDataField.Read(iprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", p.MyDataField), err)
  }
  return nil
}

func (p *MyStruct)  ReadField4(iprot thrift.Protocol) error {
  if v, err := iprot.ReadI32(); err != nil {
    return thrift.PrependError("error reading field 4: ", err)
  } else {
    temp := MyEnum(v)
    p.MyEnum = temp
  }
  return nil
}

func (p *MyStruct)  ReadField5(iprot thrift.Protocol) error {
  if v, err := iprot.ReadBool(); err != nil {
    return thrift.PrependError("error reading field 5: ", err)
  } else {
    p.Oneway = v
  }
  return nil
}

func (p *MyStruct)  ReadField6(iprot thrift.Protocol) error {
  if v, err := iprot.ReadBool(); err != nil {
    return thrift.PrependError("error reading field 6: ", err)
  } else {
    p.Readonly = v
  }
  return nil
}

func (p *MyStruct)  ReadField7(iprot thrift.Protocol) error {
  if v, err := iprot.ReadBool(); err != nil {
    return thrift.PrependError("error reading field 7: ", err)
  } else {
    p.Idempotent = v
  }
  return nil
}

func (p *MyStruct)  ReadField8(iprot thrift.Protocol) error {
  _, size, err := iprot.ReadSetBegin()
  if err != nil {
    return thrift.PrependError("error reading set begin: ", err)
  }
  tSet := make([]float32, 0, size)
  p.FloatSet =  tSet
  for i := 0; i < size; i ++ {
    var _elem1 float32
    if v, err := iprot.ReadFloat(); err != nil {
      return thrift.PrependError("error reading field 0: ", err)
    } else {
      _elem1 = v
    }
    p.FloatSet = append(p.FloatSet, _elem1)
  }
  if err := iprot.ReadSetEnd(); err != nil {
    return thrift.PrependError("error reading set end: ", err)
  }
  return nil
}

func (p *MyStruct)  ReadField9(iprot thrift.Protocol) error {
  if v, err := iprot.ReadString(); err != nil {
    return thrift.PrependError("error reading field 9: ", err)
  } else {
    p.NoHackCodegenField = v
  }
  return nil
}

func (p *MyStruct) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("MyStruct"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := p.writeField3(oprot); err != nil { return err }
  if err := p.writeField4(oprot); err != nil { return err }
  if err := p.writeField5(oprot); err != nil { return err }
  if err := p.writeField6(oprot); err != nil { return err }
  if err := p.writeField7(oprot); err != nil { return err }
  if err := p.writeField8(oprot); err != nil { return err }
  if err := p.writeField9(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *MyStruct) writeField1(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("MyIntField", thrift.I64, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:MyIntField: ", p), err) }
  if err := oprot.WriteI64(int64(p.MyIntField)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.MyIntField (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:MyIntField: ", p), err) }
  return err
}

func (p *MyStruct) writeField2(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("MyStringField", thrift.STRING, 2); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:MyStringField: ", p), err) }
  if err := oprot.WriteString(string(p.MyStringField)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.MyStringField (2) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 2:MyStringField: ", p), err) }
  return err
}

func (p *MyStruct) writeField3(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("MyDataField", thrift.STRUCT, 3); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 3:MyDataField: ", p), err) }
  if err := p.MyDataField.Write(oprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", p.MyDataField), err)
  }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 3:MyDataField: ", p), err) }
  return err
}

func (p *MyStruct) writeField4(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("myEnum", thrift.I32, 4); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 4:myEnum: ", p), err) }
  if err := oprot.WriteI32(int32(p.MyEnum)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.myEnum (4) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 4:myEnum: ", p), err) }
  return err
}

func (p *MyStruct) writeField5(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("oneway", thrift.BOOL, 5); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 5:oneway: ", p), err) }
  if err := oprot.WriteBool(bool(p.Oneway)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.oneway (5) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 5:oneway: ", p), err) }
  return err
}

func (p *MyStruct) writeField6(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("readonly", thrift.BOOL, 6); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 6:readonly: ", p), err) }
  if err := oprot.WriteBool(bool(p.Readonly)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.readonly (6) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 6:readonly: ", p), err) }
  return err
}

func (p *MyStruct) writeField7(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("idempotent", thrift.BOOL, 7); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 7:idempotent: ", p), err) }
  if err := oprot.WriteBool(bool(p.Idempotent)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.idempotent (7) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 7:idempotent: ", p), err) }
  return err
}

func (p *MyStruct) writeField8(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("floatSet", thrift.SET, 8); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 8:floatSet: ", p), err) }
  if err := oprot.WriteSetBegin(thrift.FLOAT, len(p.FloatSet)); err != nil {
    return thrift.PrependError("error writing set begin: ", err)
  }
  set := make(map[float32]bool, len(p.FloatSet))
  for _, v := range p.FloatSet {
    if ok := set[v]; ok {
      return thrift.PrependError("", fmt.Errorf("%T error writing set field: slice is not unique", v))
    }
    set[v] = true
  }
  for _, v := range p.FloatSet {
    if err := oprot.WriteFloat(float32(v)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T. (0) field write error: ", p), err) }
  }
  if err := oprot.WriteSetEnd(); err != nil {
    return thrift.PrependError("error writing set end: ", err)
  }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 8:floatSet: ", p), err) }
  return err
}

func (p *MyStruct) writeField9(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("no_hack_codegen_field", thrift.STRING, 9); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 9:no_hack_codegen_field: ", p), err) }
  if err := oprot.WriteString(string(p.NoHackCodegenField)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.no_hack_codegen_field (9) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 9:no_hack_codegen_field: ", p), err) }
  return err
}

func (p *MyStruct) String() string {
  if p == nil {
    return "<nil>"
  }

  myIntFieldVal := fmt.Sprintf("%v", p.MyIntField)
  myStringFieldVal := fmt.Sprintf("%v", p.MyStringField)
  var myDataFieldVal string
  if p.MyDataField == nil {
    myDataFieldVal = "<nil>"
  } else {
    myDataFieldVal = fmt.Sprintf("%v", p.MyDataField)
  }
  myEnumVal := fmt.Sprintf("%v", p.MyEnum)
  onewayVal := fmt.Sprintf("%v", p.Oneway)
  readonlyVal := fmt.Sprintf("%v", p.Readonly)
  idempotentVal := fmt.Sprintf("%v", p.Idempotent)
  floatSetVal := fmt.Sprintf("%v", p.FloatSet)
  noHackCodegenFieldVal := fmt.Sprintf("%v", p.NoHackCodegenField)
  return fmt.Sprintf("MyStruct({MyIntField:%s MyStringField:%s MyDataField:%s MyEnum:%s Oneway:%s Readonly:%s Idempotent:%s FloatSet:%s NoHackCodegenField:%s})", myIntFieldVal, myStringFieldVal, myDataFieldVal, myEnumVal, onewayVal, readonlyVal, idempotentVal, floatSetVal, noHackCodegenFieldVal)
}

type MyDataItem struct {
}

func NewMyDataItem() *MyDataItem {
  return &MyDataItem{}
}

type MyDataItemBuilder struct {
  obj *MyDataItem
}

func NewMyDataItemBuilder() *MyDataItemBuilder{
  return &MyDataItemBuilder{
    obj: NewMyDataItem(),
  }
}

func (p MyDataItemBuilder) Emit() *MyDataItem{
  return &MyDataItem{
  }
}

func (p *MyDataItem) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    if err := iprot.Skip(fieldTypeId); err != nil {
      return err
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *MyDataItem) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("MyDataItem"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *MyDataItem) String() string {
  if p == nil {
    return "<nil>"
  }

  return fmt.Sprintf("MyDataItem({})")
}

// Attributes:
//  - MyEnum
//  - MyStruct
//  - MyDataItem
//  - FloatSet
type MyUnion struct {
  MyEnum *MyEnum `thrift:"myEnum,1,optional" db:"myEnum" json:"myEnum,omitempty"`
  MyStruct *MyStruct `thrift:"myStruct,2,optional" db:"myStruct" json:"myStruct,omitempty"`
  MyDataItem *MyDataItem `thrift:"myDataItem,3,optional" db:"myDataItem" json:"myDataItem,omitempty"`
  FloatSet []float32 `thrift:"floatSet,4,optional" db:"floatSet" json:"floatSet,omitempty"`
}

func NewMyUnion() *MyUnion {
  return &MyUnion{}
}

var MyUnion_MyEnum_DEFAULT MyEnum
func (p *MyUnion) GetMyEnum() MyEnum {
  if !p.IsSetMyEnum() {
    return MyUnion_MyEnum_DEFAULT
  }
return *p.MyEnum
}
var MyUnion_MyStruct_DEFAULT *MyStruct
func (p *MyUnion) GetMyStruct() *MyStruct {
  if !p.IsSetMyStruct() {
    return MyUnion_MyStruct_DEFAULT
  }
return p.MyStruct
}
var MyUnion_MyDataItem_DEFAULT *MyDataItem
func (p *MyUnion) GetMyDataItem() *MyDataItem {
  if !p.IsSetMyDataItem() {
    return MyUnion_MyDataItem_DEFAULT
  }
return p.MyDataItem
}
var MyUnion_FloatSet_DEFAULT []float32

func (p *MyUnion) GetFloatSet() []float32 {
  return p.FloatSet
}
func (p *MyUnion) CountSetFieldsMyUnion() int {
  count := 0
  if (p.IsSetMyEnum()) {
    count++
  }
  if (p.IsSetMyStruct()) {
    count++
  }
  if (p.IsSetMyDataItem()) {
    count++
  }
  if (p.IsSetFloatSet()) {
    count++
  }
  return count

}

func (p *MyUnion) IsSetMyEnum() bool {
  return p != nil && p.MyEnum != nil
}

func (p *MyUnion) IsSetMyStruct() bool {
  return p != nil && p.MyStruct != nil
}

func (p *MyUnion) IsSetMyDataItem() bool {
  return p != nil && p.MyDataItem != nil
}

func (p *MyUnion) IsSetFloatSet() bool {
  return p != nil && p.FloatSet != nil
}

type MyUnionBuilder struct {
  obj *MyUnion
}

func NewMyUnionBuilder() *MyUnionBuilder{
  return &MyUnionBuilder{
    obj: NewMyUnion(),
  }
}

func (p MyUnionBuilder) Emit() *MyUnion{
  return &MyUnion{
    MyEnum: p.obj.MyEnum,
    MyStruct: p.obj.MyStruct,
    MyDataItem: p.obj.MyDataItem,
    FloatSet: p.obj.FloatSet,
  }
}

func (m *MyUnionBuilder) MyEnum(myEnum *MyEnum) *MyUnionBuilder {
  m.obj.MyEnum = myEnum
  return m
}

func (m *MyUnionBuilder) MyStruct(myStruct *MyStruct) *MyUnionBuilder {
  m.obj.MyStruct = myStruct
  return m
}

func (m *MyUnionBuilder) MyDataItem(myDataItem *MyDataItem) *MyUnionBuilder {
  m.obj.MyDataItem = myDataItem
  return m
}

func (m *MyUnionBuilder) FloatSet(floatSet []float32) *MyUnionBuilder {
  m.obj.FloatSet = floatSet
  return m
}

func (m *MyUnion) SetMyEnum(myEnum *MyEnum) *MyUnion {
  m.MyEnum = myEnum
  return m
}

func (m *MyUnion) SetMyStruct(myStruct *MyStruct) *MyUnion {
  m.MyStruct = myStruct
  return m
}

func (m *MyUnion) SetMyDataItem(myDataItem *MyDataItem) *MyUnion {
  m.MyDataItem = myDataItem
  return m
}

func (m *MyUnion) SetFloatSet(floatSet []float32) *MyUnion {
  m.FloatSet = floatSet
  return m
}

func (p *MyUnion) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    case 3:
      if err := p.ReadField3(iprot); err != nil {
        return err
      }
    case 4:
      if err := p.ReadField4(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *MyUnion)  ReadField1(iprot thrift.Protocol) error {
  if v, err := iprot.ReadI32(); err != nil {
    return thrift.PrependError("error reading field 1: ", err)
  } else {
    temp := MyEnum(v)
    p.MyEnum = &temp
  }
  return nil
}

func (p *MyUnion)  ReadField2(iprot thrift.Protocol) error {
  p.MyStruct = NewMyStruct()
  if err := p.MyStruct.Read(iprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", p.MyStruct), err)
  }
  return nil
}

func (p *MyUnion)  ReadField3(iprot thrift.Protocol) error {
  p.MyDataItem = NewMyDataItem()
  if err := p.MyDataItem.Read(iprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", p.MyDataItem), err)
  }
  return nil
}

func (p *MyUnion)  ReadField4(iprot thrift.Protocol) error {
  _, size, err := iprot.ReadSetBegin()
  if err != nil {
    return thrift.PrependError("error reading set begin: ", err)
  }
  tSet := make([]float32, 0, size)
  p.FloatSet =  tSet
  for i := 0; i < size; i ++ {
    var _elem2 float32
    if v, err := iprot.ReadFloat(); err != nil {
      return thrift.PrependError("error reading field 0: ", err)
    } else {
      _elem2 = v
    }
    p.FloatSet = append(p.FloatSet, _elem2)
  }
  if err := iprot.ReadSetEnd(); err != nil {
    return thrift.PrependError("error reading set end: ", err)
  }
  return nil
}

func (p *MyUnion) Write(oprot thrift.Protocol) error {
  if c := p.CountSetFieldsMyUnion(); c > 1 {
    return fmt.Errorf("%T write union: no more than one field must be set (%d set).", p, c)
  }
  if err := oprot.WriteStructBegin("MyUnion"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := p.writeField3(oprot); err != nil { return err }
  if err := p.writeField4(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *MyUnion) writeField1(oprot thrift.Protocol) (err error) {
  if p.IsSetMyEnum() {
    if err := oprot.WriteFieldBegin("myEnum", thrift.I32, 1); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:myEnum: ", p), err) }
    if err := oprot.WriteI32(int32(*p.MyEnum)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.myEnum (1) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 1:myEnum: ", p), err) }
  }
  return err
}

func (p *MyUnion) writeField2(oprot thrift.Protocol) (err error) {
  if p.IsSetMyStruct() {
    if err := oprot.WriteFieldBegin("myStruct", thrift.STRUCT, 2); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:myStruct: ", p), err) }
    if err := p.MyStruct.Write(oprot); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", p.MyStruct), err)
    }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 2:myStruct: ", p), err) }
  }
  return err
}

func (p *MyUnion) writeField3(oprot thrift.Protocol) (err error) {
  if p.IsSetMyDataItem() {
    if err := oprot.WriteFieldBegin("myDataItem", thrift.STRUCT, 3); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 3:myDataItem: ", p), err) }
    if err := p.MyDataItem.Write(oprot); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", p.MyDataItem), err)
    }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 3:myDataItem: ", p), err) }
  }
  return err
}

func (p *MyUnion) writeField4(oprot thrift.Protocol) (err error) {
  if p.IsSetFloatSet() {
    if err := oprot.WriteFieldBegin("floatSet", thrift.SET, 4); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 4:floatSet: ", p), err) }
    if err := oprot.WriteSetBegin(thrift.FLOAT, len(p.FloatSet)); err != nil {
      return thrift.PrependError("error writing set begin: ", err)
    }
    set := make(map[float32]bool, len(p.FloatSet))
    for _, v := range p.FloatSet {
      if ok := set[v]; ok {
        return thrift.PrependError("", fmt.Errorf("%T error writing set field: slice is not unique", v))
      }
      set[v] = true
    }
    for _, v := range p.FloatSet {
      if err := oprot.WriteFloat(float32(v)); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T. (0) field write error: ", p), err) }
    }
    if err := oprot.WriteSetEnd(); err != nil {
      return thrift.PrependError("error writing set end: ", err)
    }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 4:floatSet: ", p), err) }
  }
  return err
}

func (p *MyUnion) String() string {
  if p == nil {
    return "<nil>"
  }

  var myEnumVal string
  if p.MyEnum == nil {
    myEnumVal = "<nil>"
  } else {
    myEnumVal = fmt.Sprintf("%v", *p.MyEnum)
  }
  var myStructVal string
  if p.MyStruct == nil {
    myStructVal = "<nil>"
  } else {
    myStructVal = fmt.Sprintf("%v", p.MyStruct)
  }
  var myDataItemVal string
  if p.MyDataItem == nil {
    myDataItemVal = "<nil>"
  } else {
    myDataItemVal = fmt.Sprintf("%v", p.MyDataItem)
  }
  floatSetVal := fmt.Sprintf("%v", p.FloatSet)
  return fmt.Sprintf("MyUnion({MyEnum:%s MyStruct:%s MyDataItem:%s FloatSet:%s})", myEnumVal, myStructVal, myDataItemVal, floatSetVal)
}

// Attributes:
//  - ReservedField
type ReservedKeyword struct {
  ReservedField int32 `thrift:"reserved_field,1" db:"reserved_field" json:"reserved_field"`
}

func NewReservedKeyword() *ReservedKeyword {
  return &ReservedKeyword{}
}


func (p *ReservedKeyword) GetReservedField() int32 {
  return p.ReservedField
}
type ReservedKeywordBuilder struct {
  obj *ReservedKeyword
}

func NewReservedKeywordBuilder() *ReservedKeywordBuilder{
  return &ReservedKeywordBuilder{
    obj: NewReservedKeyword(),
  }
}

func (p ReservedKeywordBuilder) Emit() *ReservedKeyword{
  return &ReservedKeyword{
    ReservedField: p.obj.ReservedField,
  }
}

func (r *ReservedKeywordBuilder) ReservedField(reservedField int32) *ReservedKeywordBuilder {
  r.obj.ReservedField = reservedField
  return r
}

func (r *ReservedKeyword) SetReservedField(reservedField int32) *ReservedKeyword {
  r.ReservedField = reservedField
  return r
}

func (p *ReservedKeyword) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *ReservedKeyword)  ReadField1(iprot thrift.Protocol) error {
  if v, err := iprot.ReadI32(); err != nil {
    return thrift.PrependError("error reading field 1: ", err)
  } else {
    p.ReservedField = v
  }
  return nil
}

func (p *ReservedKeyword) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("ReservedKeyword"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *ReservedKeyword) writeField1(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("reserved_field", thrift.I32, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:reserved_field: ", p), err) }
  if err := oprot.WriteI32(int32(p.ReservedField)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.reserved_field (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:reserved_field: ", p), err) }
  return err
}

func (p *ReservedKeyword) String() string {
  if p == nil {
    return "<nil>"
  }

  reservedFieldVal := fmt.Sprintf("%v", p.ReservedField)
  return fmt.Sprintf("ReservedKeyword({ReservedField:%s})", reservedFieldVal)
}

// Attributes:
//  - ReservedField
type UnionToBeRenamed struct {
  ReservedField *int32 `thrift:"reserved_field,1,optional" db:"reserved_field" json:"reserved_field,omitempty"`
}

func NewUnionToBeRenamed() *UnionToBeRenamed {
  return &UnionToBeRenamed{}
}

var UnionToBeRenamed_ReservedField_DEFAULT int32
func (p *UnionToBeRenamed) GetReservedField() int32 {
  if !p.IsSetReservedField() {
    return UnionToBeRenamed_ReservedField_DEFAULT
  }
return *p.ReservedField
}
func (p *UnionToBeRenamed) CountSetFieldsUnionToBeRenamed() int {
  count := 0
  if (p.IsSetReservedField()) {
    count++
  }
  return count

}

func (p *UnionToBeRenamed) IsSetReservedField() bool {
  return p != nil && p.ReservedField != nil
}

type UnionToBeRenamedBuilder struct {
  obj *UnionToBeRenamed
}

func NewUnionToBeRenamedBuilder() *UnionToBeRenamedBuilder{
  return &UnionToBeRenamedBuilder{
    obj: NewUnionToBeRenamed(),
  }
}

func (p UnionToBeRenamedBuilder) Emit() *UnionToBeRenamed{
  return &UnionToBeRenamed{
    ReservedField: p.obj.ReservedField,
  }
}

func (u *UnionToBeRenamedBuilder) ReservedField(reservedField *int32) *UnionToBeRenamedBuilder {
  u.obj.ReservedField = reservedField
  return u
}

func (u *UnionToBeRenamed) SetReservedField(reservedField *int32) *UnionToBeRenamed {
  u.ReservedField = reservedField
  return u
}

func (p *UnionToBeRenamed) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *UnionToBeRenamed)  ReadField1(iprot thrift.Protocol) error {
  if v, err := iprot.ReadI32(); err != nil {
    return thrift.PrependError("error reading field 1: ", err)
  } else {
    p.ReservedField = &v
  }
  return nil
}

func (p *UnionToBeRenamed) Write(oprot thrift.Protocol) error {
  if c := p.CountSetFieldsUnionToBeRenamed(); c > 1 {
    return fmt.Errorf("%T write union: no more than one field must be set (%d set).", p, c)
  }
  if err := oprot.WriteStructBegin("UnionToBeRenamed"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *UnionToBeRenamed) writeField1(oprot thrift.Protocol) (err error) {
  if p.IsSetReservedField() {
    if err := oprot.WriteFieldBegin("reserved_field", thrift.I32, 1); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:reserved_field: ", p), err) }
    if err := oprot.WriteI32(int32(*p.ReservedField)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.reserved_field (1) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 1:reserved_field: ", p), err) }
  }
  return err
}

func (p *UnionToBeRenamed) String() string {
  if p == nil {
    return "<nil>"
  }

  var reservedFieldVal string
  if p.ReservedField == nil {
    reservedFieldVal = "<nil>"
  } else {
    reservedFieldVal = fmt.Sprintf("%v", *p.ReservedField)
  }
  return fmt.Sprintf("UnionToBeRenamed({ReservedField:%s})", reservedFieldVal)
}

