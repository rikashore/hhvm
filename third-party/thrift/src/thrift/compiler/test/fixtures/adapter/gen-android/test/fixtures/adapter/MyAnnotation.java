/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package test.fixtures.adapter;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import com.facebook.thrift.*;
import com.facebook.thrift.annotations.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

@SuppressWarnings({ "unused", "serial" })
public class MyAnnotation implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("MyAnnotation");
  private static final TField SIGNATURE_FIELD_DESC = new TField("signature", TType.STRING, (short)1);
  private static final TField COLOR_FIELD_DESC = new TField("color", TType.I32, (short)2);

  public final String signature;
  /**
   * 
   * @see Color
   */
  public final Color color;
  public static final int SIGNATURE = 1;
  public static final int COLOR = 2;

  public MyAnnotation(
      String signature,
      Color color) {
    this.signature = signature;
    this.color = color;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public MyAnnotation(MyAnnotation other) {
    if (other.isSetSignature()) {
      this.signature = TBaseHelper.deepCopy(other.signature);
    } else {
      this.signature = null;
    }
    if (other.isSetColor()) {
      this.color = TBaseHelper.deepCopy(other.color);
    } else {
      this.color = null;
    }
  }

  public MyAnnotation deepCopy() {
    return new MyAnnotation(this);
  }

  public String getSignature() {
    return this.signature;
  }

  // Returns true if field signature is set (has been assigned a value) and false otherwise
  public boolean isSetSignature() {
    return this.signature != null;
  }

  /**
   * 
   * @see Color
   */
  public Color getColor() {
    return this.color;
  }

  // Returns true if field color is set (has been assigned a value) and false otherwise
  public boolean isSetColor() {
    return this.color != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof MyAnnotation))
      return false;
    MyAnnotation that = (MyAnnotation)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetSignature(), that.isSetSignature(), this.signature, that.signature)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetColor(), that.isSetColor(), this.color, that.color)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {signature, color});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static MyAnnotation deserialize(TProtocol iprot) throws TException {
    String tmp_signature = null;
    Color tmp_color = null;
    TField __field;
    iprot.readStructBegin();
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case SIGNATURE:
          if (__field.type == TType.STRING) {
            tmp_signature = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case COLOR:
          if (__field.type == TType.I32) {
            tmp_color = Color.findByValue(iprot.readI32());
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(iprot, __field.type);
          break;
      }
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();

    MyAnnotation _that;
    _that = new MyAnnotation(
      tmp_signature
      ,tmp_color
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.signature != null) {
      oprot.writeFieldBegin(SIGNATURE_FIELD_DESC);
      oprot.writeString(this.signature);
      oprot.writeFieldEnd();
    }
    if (this.color != null) {
      oprot.writeFieldBegin(COLOR_FIELD_DESC);
      oprot.writeI32(this.color == null ? 0 : this.color.getValue());
      oprot.writeFieldEnd();
    }
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    return toString(1, true);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    return TBaseHelper.toStringHelper(this, indent, prettyPrint);
  }

  public void validate() throws TException {
    // check for required fields
  }

}

