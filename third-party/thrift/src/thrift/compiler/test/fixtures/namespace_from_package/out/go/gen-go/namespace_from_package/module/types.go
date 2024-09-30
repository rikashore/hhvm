// Autogenerated by Thrift for thrift/compiler/test/fixtures/namespace_from_package/src/module.thrift
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//  @generated

package module

import (
    "fmt"
    "reflect"
    "strings"

    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift/types"
)

// (needed to ensure safety because of naive import list construction)
var _ = fmt.Printf
var _ = reflect.Ptr
var _ = strings.Split
var _ = thrift.ZERO

type Foo struct {
    MyInt int64 `thrift:"MyInt,1" json:"MyInt" db:"MyInt"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*Foo)(nil)

func NewFoo() *Foo {
    return (&Foo{}).setDefaults()
}

func (x *Foo) GetMyInt() int64 {
    return x.MyInt
}

func (x *Foo) SetMyIntNonCompat(value int64) *Foo {
    x.MyInt = value
    return x
}

func (x *Foo) SetMyInt(value int64) *Foo {
    x.MyInt = value
    return x
}

func (x *Foo) writeField1(p thrift.Encoder) error {  // MyInt
    if err := p.WriteFieldBegin("MyInt", thrift.I64, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.MyInt
    if err := p.WriteI64(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *Foo) readField1(p thrift.Decoder) error {  // MyInt
    result, err := p.ReadI64()
if err != nil {
    return err
}

    x.MyInt = result
    return nil
}

func (x *Foo) toString1() string {  // MyInt
    return fmt.Sprintf("%v", x.MyInt)
}



func (x *Foo) Write(p thrift.Encoder) error {
    if err := p.WriteStructBegin("Foo"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *Foo) Read(p thrift.Decoder) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        var fieldReadErr error
        switch {
        case (id == 1 && wireType == thrift.Type(thrift.I64)):  // MyInt
            fieldReadErr = x.readField1(p)
        default:
            fieldReadErr = p.Skip(wireType)
        }

        if fieldReadErr != nil {
            return fieldReadErr
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *Foo) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("Foo({")
    sb.WriteString(fmt.Sprintf("MyInt:%s", x.toString1()))
    sb.WriteString("})")

    return sb.String()
}
func (x *Foo) setDefaults() *Foo {
    return x.
        SetMyIntNonCompat(0)
}


// Service req/resp structs (below)
type reqTestServiceInit struct {
    Int1 int64 `thrift:"int1,1" json:"int1" db:"int1"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*reqTestServiceInit)(nil)

// Deprecated: TestServiceInitArgsDeprecated is deprecated, since it is supposed to be internal.
type TestServiceInitArgsDeprecated = reqTestServiceInit

func newReqTestServiceInit() *reqTestServiceInit {
    return (&reqTestServiceInit{}).setDefaults()
}

func (x *reqTestServiceInit) GetInt1() int64 {
    return x.Int1
}

func (x *reqTestServiceInit) SetInt1NonCompat(value int64) *reqTestServiceInit {
    x.Int1 = value
    return x
}

func (x *reqTestServiceInit) SetInt1(value int64) *reqTestServiceInit {
    x.Int1 = value
    return x
}

func (x *reqTestServiceInit) writeField1(p thrift.Encoder) error {  // Int1
    if err := p.WriteFieldBegin("int1", thrift.I64, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Int1
    if err := p.WriteI64(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *reqTestServiceInit) readField1(p thrift.Decoder) error {  // Int1
    result, err := p.ReadI64()
if err != nil {
    return err
}

    x.Int1 = result
    return nil
}

func (x *reqTestServiceInit) toString1() string {  // Int1
    return fmt.Sprintf("%v", x.Int1)
}



func (x *reqTestServiceInit) Write(p thrift.Encoder) error {
    if err := p.WriteStructBegin("reqTestServiceInit"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *reqTestServiceInit) Read(p thrift.Decoder) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        var fieldReadErr error
        switch {
        case (id == 1 && wireType == thrift.Type(thrift.I64)):  // int1
            fieldReadErr = x.readField1(p)
        default:
            fieldReadErr = p.Skip(wireType)
        }

        if fieldReadErr != nil {
            return fieldReadErr
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *reqTestServiceInit) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("reqTestServiceInit({")
    sb.WriteString(fmt.Sprintf("Int1:%s", x.toString1()))
    sb.WriteString("})")

    return sb.String()
}
func (x *reqTestServiceInit) setDefaults() *reqTestServiceInit {
    return x.
        SetInt1NonCompat(0)
}

type respTestServiceInit struct {
    Success *int64 `thrift:"success,0,optional" json:"success,omitempty" db:"success"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*respTestServiceInit)(nil)
var _ thrift.WritableResult = (*respTestServiceInit)(nil)

// Deprecated: TestServiceInitResultDeprecated is deprecated, since it is supposed to be internal.
type TestServiceInitResultDeprecated = respTestServiceInit

func newRespTestServiceInit() *respTestServiceInit {
    return (&respTestServiceInit{}).setDefaults()
}

func (x *respTestServiceInit) GetSuccess() int64 {
    if !x.IsSetSuccess() {
        return 0
    }
    return *x.Success
}

func (x *respTestServiceInit) SetSuccessNonCompat(value int64) *respTestServiceInit {
    x.Success = &value
    return x
}

func (x *respTestServiceInit) SetSuccess(value *int64) *respTestServiceInit {
    x.Success = value
    return x
}

func (x *respTestServiceInit) IsSetSuccess() bool {
    return x != nil && x.Success != nil
}

func (x *respTestServiceInit) writeField0(p thrift.Encoder) error {  // Success
    if !x.IsSetSuccess() {
        return nil
    }

    if err := p.WriteFieldBegin("success", thrift.I64, 0); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.Success
    if err := p.WriteI64(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *respTestServiceInit) readField0(p thrift.Decoder) error {  // Success
    result, err := p.ReadI64()
if err != nil {
    return err
}

    x.Success = &result
    return nil
}

func (x *respTestServiceInit) toString0() string {  // Success
    if x.IsSetSuccess() {
        return fmt.Sprintf("%v", *x.Success)
    }
    return fmt.Sprintf("%v", x.Success)
}




func (x *respTestServiceInit) Exception() thrift.WritableException {
    return nil
}

func (x *respTestServiceInit) Write(p thrift.Encoder) error {
    if err := p.WriteStructBegin("respTestServiceInit"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField0(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *respTestServiceInit) Read(p thrift.Decoder) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        var fieldReadErr error
        switch {
        case (id == 0 && wireType == thrift.Type(thrift.I64)):  // success
            fieldReadErr = x.readField0(p)
        default:
            fieldReadErr = p.Skip(wireType)
        }

        if fieldReadErr != nil {
            return fieldReadErr
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *respTestServiceInit) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("respTestServiceInit({")
    sb.WriteString(fmt.Sprintf("Success:%s", x.toString0()))
    sb.WriteString("})")

    return sb.String()
}
func (x *respTestServiceInit) setDefaults() *respTestServiceInit {
    return x
}


// RegisterTypes registers types found in this file that have a thrift_uri with the passed in registry.
func RegisterTypes(registry interface {
  RegisterType(name string, initializer func() any)
}) {
    registry.RegisterType("test.dev/namespace_from_package/module/Foo", func() any { return NewFoo() })

}
