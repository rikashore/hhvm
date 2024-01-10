/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package test.fixtures.patch;

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
public class RefFieldsFieldPatch implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("RefFieldsFieldPatch");
  private static final TField UNIQUE_FIELD_DESC = new TField("unique", TType.STRUCT, (short)1);
  private static final TField SHARED_MUSTABLE_FIELD_DESC = new TField("shared_mustable", TType.STRUCT, (short)3);
  private static final TField OPT_UNIQUE_FIELD_DESC = new TField("opt_unique", TType.STRUCT, (short)4);
  private static final TField OPT_SHARED_MUSTABLE_FIELD_DESC = new TField("opt_shared_mustable", TType.STRUCT, (short)6);
  private static final TField OPT_BOX_FIELD_DESC = new TField("opt_box", TType.STRUCT, (short)7);

  public final RefFieldsField1Patch unique;
  public final RefFieldsField3Patch shared_mustable;
  public final RefFieldsField4Patch opt_unique;
  public final RefFieldsField6Patch opt_shared_mustable;
  public final RefFieldsField7Patch opt_box;
  public static final int UNIQUE = 1;
  public static final int SHARED_MUSTABLE = 3;
  public static final int OPT_UNIQUE = 4;
  public static final int OPT_SHARED_MUSTABLE = 6;
  public static final int OPT_BOX = 7;

  public RefFieldsFieldPatch(
      RefFieldsField1Patch unique,
      RefFieldsField3Patch shared_mustable,
      RefFieldsField4Patch opt_unique,
      RefFieldsField6Patch opt_shared_mustable,
      RefFieldsField7Patch opt_box) {
    this.unique = unique;
    this.shared_mustable = shared_mustable;
    this.opt_unique = opt_unique;
    this.opt_shared_mustable = opt_shared_mustable;
    this.opt_box = opt_box;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public RefFieldsFieldPatch(RefFieldsFieldPatch other) {
    if (other.isSetUnique()) {
      this.unique = TBaseHelper.deepCopy(other.unique);
    } else {
      this.unique = null;
    }
    if (other.isSetShared_mustable()) {
      this.shared_mustable = TBaseHelper.deepCopy(other.shared_mustable);
    } else {
      this.shared_mustable = null;
    }
    if (other.isSetOpt_unique()) {
      this.opt_unique = TBaseHelper.deepCopy(other.opt_unique);
    } else {
      this.opt_unique = null;
    }
    if (other.isSetOpt_shared_mustable()) {
      this.opt_shared_mustable = TBaseHelper.deepCopy(other.opt_shared_mustable);
    } else {
      this.opt_shared_mustable = null;
    }
    if (other.isSetOpt_box()) {
      this.opt_box = TBaseHelper.deepCopy(other.opt_box);
    } else {
      this.opt_box = null;
    }
  }

  public RefFieldsFieldPatch deepCopy() {
    return new RefFieldsFieldPatch(this);
  }

  public RefFieldsField1Patch getUnique() {
    return this.unique;
  }

  // Returns true if field unique is set (has been assigned a value) and false otherwise
  public boolean isSetUnique() {
    return this.unique != null;
  }

  public RefFieldsField3Patch getShared_mustable() {
    return this.shared_mustable;
  }

  // Returns true if field shared_mustable is set (has been assigned a value) and false otherwise
  public boolean isSetShared_mustable() {
    return this.shared_mustable != null;
  }

  public RefFieldsField4Patch getOpt_unique() {
    return this.opt_unique;
  }

  // Returns true if field opt_unique is set (has been assigned a value) and false otherwise
  public boolean isSetOpt_unique() {
    return this.opt_unique != null;
  }

  public RefFieldsField6Patch getOpt_shared_mustable() {
    return this.opt_shared_mustable;
  }

  // Returns true if field opt_shared_mustable is set (has been assigned a value) and false otherwise
  public boolean isSetOpt_shared_mustable() {
    return this.opt_shared_mustable != null;
  }

  public RefFieldsField7Patch getOpt_box() {
    return this.opt_box;
  }

  // Returns true if field opt_box is set (has been assigned a value) and false otherwise
  public boolean isSetOpt_box() {
    return this.opt_box != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof RefFieldsFieldPatch))
      return false;
    RefFieldsFieldPatch that = (RefFieldsFieldPatch)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetUnique(), that.isSetUnique(), this.unique, that.unique)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetShared_mustable(), that.isSetShared_mustable(), this.shared_mustable, that.shared_mustable)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOpt_unique(), that.isSetOpt_unique(), this.opt_unique, that.opt_unique)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOpt_shared_mustable(), that.isSetOpt_shared_mustable(), this.opt_shared_mustable, that.opt_shared_mustable)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOpt_box(), that.isSetOpt_box(), this.opt_box, that.opt_box)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {unique, shared_mustable, opt_unique, opt_shared_mustable, opt_box});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static RefFieldsFieldPatch deserialize(TProtocol iprot) throws TException {
    RefFieldsField1Patch tmp_unique = null;
    RefFieldsField3Patch tmp_shared_mustable = null;
    RefFieldsField4Patch tmp_opt_unique = null;
    RefFieldsField6Patch tmp_opt_shared_mustable = null;
    RefFieldsField7Patch tmp_opt_box = null;
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
        case UNIQUE:
          if (__field.type == TType.STRUCT) {
            tmp_unique = RefFieldsField1Patch.deserialize(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case SHARED_MUSTABLE:
          if (__field.type == TType.STRUCT) {
            tmp_shared_mustable = RefFieldsField3Patch.deserialize(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPT_UNIQUE:
          if (__field.type == TType.STRUCT) {
            tmp_opt_unique = RefFieldsField4Patch.deserialize(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPT_SHARED_MUSTABLE:
          if (__field.type == TType.STRUCT) {
            tmp_opt_shared_mustable = RefFieldsField6Patch.deserialize(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPT_BOX:
          if (__field.type == TType.STRUCT) {
            tmp_opt_box = RefFieldsField7Patch.deserialize(iprot);
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

    RefFieldsFieldPatch _that;
    _that = new RefFieldsFieldPatch(
      tmp_unique
      ,tmp_shared_mustable
      ,tmp_opt_unique
      ,tmp_opt_shared_mustable
      ,tmp_opt_box
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.unique != null) {
      oprot.writeFieldBegin(UNIQUE_FIELD_DESC);
      this.unique.write(oprot);
      oprot.writeFieldEnd();
    }
    if (this.shared_mustable != null) {
      oprot.writeFieldBegin(SHARED_MUSTABLE_FIELD_DESC);
      this.shared_mustable.write(oprot);
      oprot.writeFieldEnd();
    }
    if (this.opt_unique != null) {
      oprot.writeFieldBegin(OPT_UNIQUE_FIELD_DESC);
      this.opt_unique.write(oprot);
      oprot.writeFieldEnd();
    }
    if (this.opt_shared_mustable != null) {
      oprot.writeFieldBegin(OPT_SHARED_MUSTABLE_FIELD_DESC);
      this.opt_shared_mustable.write(oprot);
      oprot.writeFieldEnd();
    }
    if (this.opt_box != null) {
      oprot.writeFieldBegin(OPT_BOX_FIELD_DESC);
      this.opt_box.write(oprot);
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

