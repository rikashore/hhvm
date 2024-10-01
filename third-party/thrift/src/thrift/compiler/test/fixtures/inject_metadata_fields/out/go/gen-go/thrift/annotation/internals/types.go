// Autogenerated by Thrift for thrift/annotation/internal.thrift
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//  @generated

package internals

import (
    "fmt"
    "reflect"

    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift/types"
)

// (needed to ensure safety because of naive import list construction)
var _ = fmt.Printf
var _ = reflect.Ptr
var _ = thrift.ZERO

type InjectMetadataFields struct {
    Type string `thrift:"type,1" json:"type" db:"type"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*InjectMetadataFields)(nil)

func NewInjectMetadataFields() *InjectMetadataFields {
    return (&InjectMetadataFields{}).setDefaults()
}

func (x *InjectMetadataFields) GetType() string {
    return x.Type
}

func (x *InjectMetadataFields) SetTypeNonCompat(value string) *InjectMetadataFields {
    x.Type = value
    return x
}

func (x *InjectMetadataFields) SetType(value string) *InjectMetadataFields {
    x.Type = value
    return x
}

func (x *InjectMetadataFields) writeField1(p thrift.Encoder) error {  // Type
    if err := p.WriteFieldBegin("type", thrift.STRING, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Type
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *InjectMetadataFields) readField1(p thrift.Decoder) error {  // Type
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.Type = result
    return nil
}



func (x *InjectMetadataFields) Write(p thrift.Encoder) error {
    if err := p.WriteStructBegin("InjectMetadataFields"); err != nil {
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

func (x *InjectMetadataFields) Read(p thrift.Decoder) error {
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
        case (id == 1 && wireType == thrift.Type(thrift.STRING)):  // type
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

func (x *InjectMetadataFields) String() string {
    return thrift.StructToString(reflect.ValueOf(x))
}

func (x *InjectMetadataFields) setDefaults() *InjectMetadataFields {
    return x.
        SetTypeNonCompat("")
}



// RegisterTypes registers types found in this file that have a thrift_uri with the passed in registry.
func RegisterTypes(registry interface {
  RegisterType(name string, initializer func() any)
}) {
    registry.RegisterType("facebook.com/thrift/annotation/InjectMetadataFields", func() any { return NewInjectMetadataFields() })

}
