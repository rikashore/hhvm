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

/**
 * An annotation that intercepts field access with C++ field interceptor.
 * Use with *caution* since this may introduce substantial performance overhead on each field access.
 * 
 * For example:
 * 
 *     struct Foo {
 *       @cpp.FieldInterceptor{name = "MyFieldInterceptor"}
 *       1: i64 id;
 *     }
 * 
 * The field interceptor `MyFieldInterceptor` will intercept with `interceptThriftFieldAccess`
 * when the field `id` is accessed.
 */
@SuppressWarnings({ "unused", "serial" })
public class FieldInterceptor implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("FieldInterceptor");
  private static final TField NAME_FIELD_DESC = new TField("name", TType.STRING, (short)1);
  private static final TField NOINLINE_FIELD_DESC = new TField("noinline", TType.BOOL, (short)2);

  /**
   * The name of a field interceptor.
   * 
   * The field interceptor provides the following API:
   * 
   *     struct ThriftFieldInterceptor {
   *       template <typename T, typename Struct, int16_t FieldId>
   *       static void interceptThriftFieldAccess(T&& field,
   *                                              apache::thrift::FieldContext<Struct, FieldId>&& ctx);
   *     };
   * 
   * The field interceptor intercepts with the field value and the field context.
   * It enforces an easily searchable function name `interceptThriftFieldAccess`.
   */
  public final String name;
  /**
   * Setting to true makes compiler not inline and erase function signature for
   * the intercepting field accessor.
   */
  public final Boolean noinline;
  public static final int NAME = 1;
  public static final int NOINLINE = 2;

  public FieldInterceptor(
      String name,
      Boolean noinline) {
    this.name = name;
    this.noinline = noinline;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public FieldInterceptor(FieldInterceptor other) {
    if (other.isSetName()) {
      this.name = TBaseHelper.deepCopy(other.name);
    } else {
      this.name = null;
    }
    if (other.isSetNoinline()) {
      this.noinline = TBaseHelper.deepCopy(other.noinline);
    } else {
      this.noinline = null;
    }
  }

  public FieldInterceptor deepCopy() {
    return new FieldInterceptor(this);
  }

  /**
   * The name of a field interceptor.
   * 
   * The field interceptor provides the following API:
   * 
   *     struct ThriftFieldInterceptor {
   *       template <typename T, typename Struct, int16_t FieldId>
   *       static void interceptThriftFieldAccess(T&& field,
   *                                              apache::thrift::FieldContext<Struct, FieldId>&& ctx);
   *     };
   * 
   * The field interceptor intercepts with the field value and the field context.
   * It enforces an easily searchable function name `interceptThriftFieldAccess`.
   */
  public String getName() {
    return this.name;
  }

  // Returns true if field name is set (has been assigned a value) and false otherwise
  public boolean isSetName() {
    return this.name != null;
  }

  /**
   * Setting to true makes compiler not inline and erase function signature for
   * the intercepting field accessor.
   */
  public Boolean isNoinline() {
    return this.noinline;
  }

  // Returns true if field noinline is set (has been assigned a value) and false otherwise
  public boolean isSetNoinline() {
    return this.noinline != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof FieldInterceptor))
      return false;
    FieldInterceptor that = (FieldInterceptor)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetName(), that.isSetName(), this.name, that.name)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetNoinline(), that.isSetNoinline(), this.noinline, that.noinline)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {name, noinline});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static FieldInterceptor deserialize(TProtocol iprot) throws TException {
    String tmp_name = null;
    Boolean tmp_noinline = null;
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
        case NAME:
          if (__field.type == TType.STRING) {
            tmp_name = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case NOINLINE:
          if (__field.type == TType.BOOL) {
            tmp_noinline = iprot.readBool();
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

    FieldInterceptor _that;
    _that = new FieldInterceptor(
      tmp_name
      ,tmp_noinline
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.name != null) {
      oprot.writeFieldBegin(NAME_FIELD_DESC);
      oprot.writeString(this.name);
      oprot.writeFieldEnd();
    }
    if (this.noinline != null) {
      oprot.writeFieldBegin(NOINLINE_FIELD_DESC);
      oprot.writeBool(this.noinline);
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

