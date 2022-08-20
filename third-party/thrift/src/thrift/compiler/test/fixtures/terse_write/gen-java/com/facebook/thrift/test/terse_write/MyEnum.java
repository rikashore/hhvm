/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package com.facebook.thrift.test.terse_write;

import com.facebook.swift.codec.*;
import org.apache.thrift.TException;
import org.apache.thrift.protocol.TProtocol;

@SwiftGenerated
public enum MyEnum implements com.facebook.thrift.payload.ThriftSerializable {
    ME0(0),
    ME1(1);

    private final int value;

    MyEnum(int value) {
        this.value = value;
    }

    @ThriftEnumValue
    public int getValue() {
        return value;
    }

    public static MyEnum fromInteger(int n) {
        switch (n) {
        case 0:
            return ME0;
        case 1:
            return ME1;
        default:
            return null;
        }
    }

    public static com.facebook.thrift.payload.Reader<MyEnum> asReader() {
        return MyEnum::read0;
    }

    public static MyEnum read0(TProtocol iprot) throws TException {
        return MyEnum.fromInteger(iprot.readI32());
    }

    public void write0(TProtocol oprot) throws TException {
        oprot.writeI32(getValue());
    }


}
