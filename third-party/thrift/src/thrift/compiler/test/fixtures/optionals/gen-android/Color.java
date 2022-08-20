/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
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
public class Color implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("Color");
  private static final TField RED_FIELD_DESC = new TField("red", TType.DOUBLE, (short)1);
  private static final TField GREEN_FIELD_DESC = new TField("green", TType.DOUBLE, (short)2);
  private static final TField BLUE_FIELD_DESC = new TField("blue", TType.DOUBLE, (short)3);
  private static final TField ALPHA_FIELD_DESC = new TField("alpha", TType.DOUBLE, (short)4);

  public final Double red;
  public final Double green;
  public final Double blue;
  public final Double alpha;
  public static final int RED = 1;
  public static final int GREEN = 2;
  public static final int BLUE = 3;
  public static final int ALPHA = 4;

  public Color(
      Double red,
      Double green,
      Double blue,
      Double alpha) {
    this.red = red;
    this.green = green;
    this.blue = blue;
    this.alpha = alpha;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public Color(Color other) {
    if (other.isSetRed()) {
      this.red = TBaseHelper.deepCopy(other.red);
    } else {
      this.red = null;
    }
    if (other.isSetGreen()) {
      this.green = TBaseHelper.deepCopy(other.green);
    } else {
      this.green = null;
    }
    if (other.isSetBlue()) {
      this.blue = TBaseHelper.deepCopy(other.blue);
    } else {
      this.blue = null;
    }
    if (other.isSetAlpha()) {
      this.alpha = TBaseHelper.deepCopy(other.alpha);
    } else {
      this.alpha = null;
    }
  }

  public Color deepCopy() {
    return new Color(this);
  }

  public Double getRed() {
    return this.red;
  }

  // Returns true if field red is set (has been assigned a value) and false otherwise
  public boolean isSetRed() {
    return this.red != null;
  }

  public Double getGreen() {
    return this.green;
  }

  // Returns true if field green is set (has been assigned a value) and false otherwise
  public boolean isSetGreen() {
    return this.green != null;
  }

  public Double getBlue() {
    return this.blue;
  }

  // Returns true if field blue is set (has been assigned a value) and false otherwise
  public boolean isSetBlue() {
    return this.blue != null;
  }

  public Double getAlpha() {
    return this.alpha;
  }

  // Returns true if field alpha is set (has been assigned a value) and false otherwise
  public boolean isSetAlpha() {
    return this.alpha != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof Color))
      return false;
    Color that = (Color)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetRed(), that.isSetRed(), this.red, that.red)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetGreen(), that.isSetGreen(), this.green, that.green)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetBlue(), that.isSetBlue(), this.blue, that.blue)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAlpha(), that.isSetAlpha(), this.alpha, that.alpha)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {red, green, blue, alpha});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static Color deserialize(TProtocol iprot) throws TException {
    Double tmp_red = null;
    Double tmp_green = null;
    Double tmp_blue = null;
    Double tmp_alpha = null;
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
        case RED:
          if (__field.type == TType.DOUBLE) {
            tmp_red = iprot.readDouble();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case GREEN:
          if (__field.type == TType.DOUBLE) {
            tmp_green = iprot.readDouble();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case BLUE:
          if (__field.type == TType.DOUBLE) {
            tmp_blue = iprot.readDouble();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ALPHA:
          if (__field.type == TType.DOUBLE) {
            tmp_alpha = iprot.readDouble();
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

    Color _that;
    _that = new Color(
      tmp_red
      ,tmp_green
      ,tmp_blue
      ,tmp_alpha
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.red != null) {
      oprot.writeFieldBegin(RED_FIELD_DESC);
      oprot.writeDouble(this.red);
      oprot.writeFieldEnd();
    }
    if (this.green != null) {
      oprot.writeFieldBegin(GREEN_FIELD_DESC);
      oprot.writeDouble(this.green);
      oprot.writeFieldEnd();
    }
    if (this.blue != null) {
      oprot.writeFieldBegin(BLUE_FIELD_DESC);
      oprot.writeDouble(this.blue);
      oprot.writeFieldEnd();
    }
    if (this.alpha != null) {
      oprot.writeFieldBegin(ALPHA_FIELD_DESC);
      oprot.writeDouble(this.alpha);
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

