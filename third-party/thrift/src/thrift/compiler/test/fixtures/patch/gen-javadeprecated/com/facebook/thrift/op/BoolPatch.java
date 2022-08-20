/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.facebook.thrift.op;

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

/**
 * A patch for a boolean value.
 */
@SuppressWarnings({ "unused", "serial" })
public class BoolPatch implements TBase, java.io.Serializable, Cloneable, Comparable<BoolPatch> {
  private static final TStruct STRUCT_DESC = new TStruct("BoolPatch");
  private static final TField ASSIGN_FIELD_DESC = new TField("assign", TType.BOOL, (short)1);
  private static final TField INVERT_FIELD_DESC = new TField("invert", TType.BOOL, (short)9);

  /**
   * Assign to a given value.
   * 
   * If set, all other patch operations are ignored.
   */
  public boolean assign;
  /**
   * If the bool value should be inverted.
   */
  public boolean invert;
  public static final int ASSIGN = 1;
  public static final int INVERT = 9;

  // isset id assignments
  private static final int __ASSIGN_ISSET_ID = 0;
  private static final int __INVERT_ISSET_ID = 1;
  private BitSet __isset_bit_vector = new BitSet(2);

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(ASSIGN, new FieldMetaData("assign", TFieldRequirementType.OPTIONAL, 
        new FieldValueMetaData(TType.BOOL)));
    tmpMetaDataMap.put(INVERT, new FieldMetaData("invert", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.BOOL)));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(BoolPatch.class, metaDataMap);
  }

  public BoolPatch() {
  }

  public BoolPatch(
      boolean invert) {
    this();
    this.invert = invert;
    setInvertIsSet(true);
  }

  public BoolPatch(
      boolean assign,
      boolean invert) {
    this();
    this.assign = assign;
    setAssignIsSet(true);
    this.invert = invert;
    setInvertIsSet(true);
  }

  public static class Builder {
    private boolean assign;
    private boolean invert;

    BitSet __optional_isset = new BitSet(2);

    public Builder() {
    }

    public Builder setAssign(final boolean assign) {
      this.assign = assign;
      __optional_isset.set(__ASSIGN_ISSET_ID, true);
      return this;
    }

    public Builder setInvert(final boolean invert) {
      this.invert = invert;
      __optional_isset.set(__INVERT_ISSET_ID, true);
      return this;
    }

    public BoolPatch build() {
      BoolPatch result = new BoolPatch();
      if (__optional_isset.get(__ASSIGN_ISSET_ID)) {
        result.setAssign(this.assign);
      }
      if (__optional_isset.get(__INVERT_ISSET_ID)) {
        result.setInvert(this.invert);
      }
      return result;
    }
  }

  public static Builder builder() {
    return new Builder();
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public BoolPatch(BoolPatch other) {
    __isset_bit_vector.clear();
    __isset_bit_vector.or(other.__isset_bit_vector);
    this.assign = TBaseHelper.deepCopy(other.assign);
    this.invert = TBaseHelper.deepCopy(other.invert);
  }

  public BoolPatch deepCopy() {
    return new BoolPatch(this);
  }

  /**
   * Assign to a given value.
   * 
   * If set, all other patch operations are ignored.
   */
  public boolean isAssign() {
    return this.assign;
  }

  /**
   * Assign to a given value.
   * 
   * If set, all other patch operations are ignored.
   */
  public BoolPatch setAssign(boolean assign) {
    this.assign = assign;
    setAssignIsSet(true);
    return this;
  }

  public void unsetAssign() {
    __isset_bit_vector.clear(__ASSIGN_ISSET_ID);
  }

  // Returns true if field assign is set (has been assigned a value) and false otherwise
  public boolean isSetAssign() {
    return __isset_bit_vector.get(__ASSIGN_ISSET_ID);
  }

  public void setAssignIsSet(boolean __value) {
    __isset_bit_vector.set(__ASSIGN_ISSET_ID, __value);
  }

  /**
   * If the bool value should be inverted.
   */
  public boolean isInvert() {
    return this.invert;
  }

  /**
   * If the bool value should be inverted.
   */
  public BoolPatch setInvert(boolean invert) {
    this.invert = invert;
    setInvertIsSet(true);
    return this;
  }

  public void unsetInvert() {
    __isset_bit_vector.clear(__INVERT_ISSET_ID);
  }

  // Returns true if field invert is set (has been assigned a value) and false otherwise
  public boolean isSetInvert() {
    return __isset_bit_vector.get(__INVERT_ISSET_ID);
  }

  public void setInvertIsSet(boolean __value) {
    __isset_bit_vector.set(__INVERT_ISSET_ID, __value);
  }

  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    case ASSIGN:
      if (__value == null) {
        unsetAssign();
      } else {
        setAssign((Boolean)__value);
      }
      break;

    case INVERT:
      if (__value == null) {
        unsetInvert();
      } else {
        setInvert((Boolean)__value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case ASSIGN:
      return new Boolean(isAssign());

    case INVERT:
      return new Boolean(isInvert());

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof BoolPatch))
      return false;
    BoolPatch that = (BoolPatch)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetAssign(), that.isSetAssign(), this.assign, that.assign)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.invert, that.invert)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {assign, invert});
  }

  @Override
  public int compareTo(BoolPatch other) {
    if (other == null) {
      // See java.lang.Comparable docs
      throw new NullPointerException();
    }

    if (other == this) {
      return 0;
    }
    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetAssign()).compareTo(other.isSetAssign());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(assign, other.assign);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetInvert()).compareTo(other.isSetInvert());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(invert, other.invert);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    return 0;
  }

  public void read(TProtocol iprot) throws TException {
    TField __field;
    iprot.readStructBegin(metaDataMap);
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case ASSIGN:
          if (__field.type == TType.BOOL) {
            this.assign = iprot.readBool();
            setAssignIsSet(true);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case INVERT:
          if (__field.type == TType.BOOL) {
            this.invert = iprot.readBool();
            setInvertIsSet(true);
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


    // check for required fields of primitive type, which can't be checked in the validate method
    validate();
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (isSetAssign()) {
      oprot.writeFieldBegin(ASSIGN_FIELD_DESC);
      oprot.writeBool(this.assign);
      oprot.writeFieldEnd();
    }
    oprot.writeFieldBegin(INVERT_FIELD_DESC);
    oprot.writeBool(this.invert);
    oprot.writeFieldEnd();
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    return toString(1, true);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    String indentStr = prettyPrint ? TBaseHelper.getIndentedString(indent) : "";
    String newLine = prettyPrint ? "\n" : "";
    String space = prettyPrint ? " " : "";
    StringBuilder sb = new StringBuilder("BoolPatch");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    if (isSetAssign())
    {
      sb.append(indentStr);
      sb.append("assign");
      sb.append(space);
      sb.append(":").append(space);
      sb.append(TBaseHelper.toString(this.isAssign(), indent + 1, prettyPrint));
      first = false;
    }
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("invert");
    sb.append(space);
    sb.append(":").append(space);
    sb.append(TBaseHelper.toString(this.isInvert(), indent + 1, prettyPrint));
    first = false;
    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
  }

}

