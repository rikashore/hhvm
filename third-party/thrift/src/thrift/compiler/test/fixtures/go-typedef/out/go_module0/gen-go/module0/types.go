// Autogenerated by Thrift for thrift/compiler/test/fixtures/go-typedef/src/module0.thrift
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//  @generated

package module0

import (
    "fmt"
    "reflect"

    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift/types"
)

// (needed to ensure safety because of naive import list construction)
var _ = fmt.Printf
var _ = reflect.Ptr
var _ = thrift.ZERO

type Accessory struct {
    InventoryId int32 `thrift:"InventoryId,1" json:"InventoryId" db:"InventoryId"`
    Name string `thrift:"Name,2" json:"Name" db:"Name"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*Accessory)(nil)

func NewAccessory() *Accessory {
    return (&Accessory{}).setDefaults()
}

func (x *Accessory) GetInventoryId() int32 {
    return x.InventoryId
}

func (x *Accessory) GetName() string {
    return x.Name
}

func (x *Accessory) SetInventoryIdNonCompat(value int32) *Accessory {
    x.InventoryId = value
    return x
}

func (x *Accessory) SetInventoryId(value int32) *Accessory {
    x.InventoryId = value
    return x
}

func (x *Accessory) SetNameNonCompat(value string) *Accessory {
    x.Name = value
    return x
}

func (x *Accessory) SetName(value string) *Accessory {
    x.Name = value
    return x
}

func (x *Accessory) writeField1(p thrift.Encoder) error {  // InventoryId
    if err := p.WriteFieldBegin("InventoryId", thrift.I32, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.InventoryId
    if err := p.WriteI32(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *Accessory) writeField2(p thrift.Encoder) error {  // Name
    if err := p.WriteFieldBegin("Name", thrift.STRING, 2); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Name
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *Accessory) readField1(p thrift.Decoder) error {  // InventoryId
    result, err := p.ReadI32()
if err != nil {
    return err
}

    x.InventoryId = result
    return nil
}

func (x *Accessory) readField2(p thrift.Decoder) error {  // Name
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.Name = result
    return nil
}



func (x *Accessory) Write(p thrift.Encoder) error {
    if err := p.WriteStructBegin("Accessory"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }
    if err := x.writeField2(p); err != nil {
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

func (x *Accessory) Read(p thrift.Decoder) error {
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
        case (id == 1 && wireType == thrift.Type(thrift.I32)):  // InventoryId
            fieldReadErr = x.readField1(p)
        case (id == 2 && wireType == thrift.Type(thrift.STRING)):  // Name
            fieldReadErr = x.readField2(p)
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

func (x *Accessory) String() string {
    return thrift.StructToString(reflect.ValueOf(x))
}

func (x *Accessory) setDefaults() *Accessory {
    return x.
        SetInventoryIdNonCompat(0).
        SetNameNonCompat("")
}

type PartName struct {
    InventoryId int32 `thrift:"InventoryId,1" json:"InventoryId" db:"InventoryId"`
    Name string `thrift:"Name,2" json:"Name" db:"Name"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*PartName)(nil)

func NewPartName() *PartName {
    return (&PartName{}).setDefaults()
}

func (x *PartName) GetInventoryId() int32 {
    return x.InventoryId
}

func (x *PartName) GetName() string {
    return x.Name
}

func (x *PartName) SetInventoryIdNonCompat(value int32) *PartName {
    x.InventoryId = value
    return x
}

func (x *PartName) SetInventoryId(value int32) *PartName {
    x.InventoryId = value
    return x
}

func (x *PartName) SetNameNonCompat(value string) *PartName {
    x.Name = value
    return x
}

func (x *PartName) SetName(value string) *PartName {
    x.Name = value
    return x
}

func (x *PartName) writeField1(p thrift.Encoder) error {  // InventoryId
    if err := p.WriteFieldBegin("InventoryId", thrift.I32, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.InventoryId
    if err := p.WriteI32(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *PartName) writeField2(p thrift.Encoder) error {  // Name
    if err := p.WriteFieldBegin("Name", thrift.STRING, 2); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Name
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *PartName) readField1(p thrift.Decoder) error {  // InventoryId
    result, err := p.ReadI32()
if err != nil {
    return err
}

    x.InventoryId = result
    return nil
}

func (x *PartName) readField2(p thrift.Decoder) error {  // Name
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.Name = result
    return nil
}



func (x *PartName) Write(p thrift.Encoder) error {
    if err := p.WriteStructBegin("PartName"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }
    if err := x.writeField2(p); err != nil {
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

func (x *PartName) Read(p thrift.Decoder) error {
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
        case (id == 1 && wireType == thrift.Type(thrift.I32)):  // InventoryId
            fieldReadErr = x.readField1(p)
        case (id == 2 && wireType == thrift.Type(thrift.STRING)):  // Name
            fieldReadErr = x.readField2(p)
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

func (x *PartName) String() string {
    return thrift.StructToString(reflect.ValueOf(x))
}

func (x *PartName) setDefaults() *PartName {
    return x.
        SetInventoryIdNonCompat(0).
        SetNameNonCompat("")
}



// RegisterTypes registers types found in this file that have a thrift_uri with the passed in registry.
func RegisterTypes(registry interface {
  RegisterType(name string, initializer func() any)
}) {

}
