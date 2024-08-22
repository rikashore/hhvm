/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.annotation;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftUnion("Unfortunate_union")
public final class UnfortunateUnion implements com.facebook.thrift.payload.ThriftSerializable {
    
    private static final boolean allowNullFieldValues =
        System.getProperty("thrift.union.allow-null-field-values", "false").equalsIgnoreCase("true");

    private static final TStruct STRUCT_DESC = new TStruct("Unfortunate_union");
    private static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    private static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();
    private static final UnfortunateUnion _DEFAULT = new UnfortunateUnion();

    public static final int _AN_SNAKE_STRING = 1;
    private static final TField AN_SNAKE_STRING_FIELD_DESC = new TField("an_snake_string", TType.STRING, (short)1);
    public static final int _ACAMELI32 = 2;
    private static final TField A_CAMEL_I32_FIELD_DESC = new TField("aCamelI32", TType.I32, (short)2);

    static {
      NAMES_TO_IDS.put("anSnakeString", 1);
      THRIFT_NAMES_TO_IDS.put("an_snake_string", 1);
      FIELD_METADATA.put(1, AN_SNAKE_STRING_FIELD_DESC);
      NAMES_TO_IDS.put("aCamelI32", 2);
      THRIFT_NAMES_TO_IDS.put("aCamelI32", 2);
      FIELD_METADATA.put(2, A_CAMEL_I32_FIELD_DESC);
    }

    private java.lang.Object value;
    private short id;

    public enum Type {
      AN_SNAKE_STRING,
      A_CAMEL_I32,
    }

    public static UnfortunateUnion from(int _id, java.lang.Object _field) {
        return from((short) _id, _field);
    }

    public static UnfortunateUnion from(short _id, java.lang.Object _field) {
        java.util.Objects.requireNonNull(_field);
        if (!FIELD_METADATA.containsKey(Integer.valueOf(_id))) {
            throw new java.lang.IllegalArgumentException("unknown field " + _id);
        }

        UnfortunateUnion _u = new  UnfortunateUnion();

        try {
            switch(_id) {
                case 1:
                    _u.id = _id;
                    _u.value = (String) _field;
                    return _u;
                case 2:
                    _u.id = _id;
                    _u.value = (int) _field;
                    return _u;
                default:
                throw new IllegalArgumentException("invalid type " + _field.getClass().getName() + " for field " + _id);
            }
        } catch (java.lang.Exception t) {
            throw new IllegalArgumentException("invalid type " + _field.getClass().getName() + " for field " + _id);
        }
    }

    @ThriftConstructor
    public UnfortunateUnion() {
    }
    
    @ThriftConstructor
    @Deprecated
    public UnfortunateUnion(final String anSnakeString) {
        if (!UnfortunateUnion.allowNullFieldValues && anSnakeString == null) {
            throw new TProtocolException("Cannot initialize Union field 'UnfortunateUnion.anSnakeString' with null value!");
        }
        this.value = anSnakeString;
        this.id = 1;
    }
    
    @ThriftConstructor
    @Deprecated
    public UnfortunateUnion(final int aCamelI32) {
        this.value = aCamelI32;
        this.id = 2;
    }
    
    public static UnfortunateUnion fromAnSnakeString(final String anSnakeString) {
        UnfortunateUnion res = new UnfortunateUnion();
        if (!UnfortunateUnion.allowNullFieldValues && anSnakeString == null) {
            throw new TProtocolException("Cannot initialize Union field 'UnfortunateUnion.anSnakeString' with null value!");
        }
        res.value = anSnakeString;
        res.id = 1;
        return res;
    }
    
    public static UnfortunateUnion fromACamelI32(final int aCamelI32) {
        UnfortunateUnion res = new UnfortunateUnion();
        res.value = aCamelI32;
        res.id = 2;
        return res;
    }
    

    @com.facebook.swift.codec.ThriftField(value=1, name="an_snake_string", requiredness=Requiredness.NONE)
    public String getAnSnakeString() {
        if (this.id != 1) {
            throw new IllegalStateException("Not a an_snake_string element!");
        }
        return (String) value;
    }

    public boolean isSetAnSnakeString() {
        return this.id == 1;
    }

    @com.facebook.swift.codec.ThriftField(value=2, name="aCamelI32", requiredness=Requiredness.NONE)
    public int getACamelI32() {
        if (this.id != 2) {
            throw new IllegalStateException("Not a aCamelI32 element!");
        }
        return (int) value;
    }

    public boolean isSetACamelI32() {
        return this.id == 2;
    }

    @ThriftUnionId
    public short getThriftId() {
        return this.id;
    }

    public Type getThriftType() {
      switch(this.id) {
        case 1:
          return Type.AN_SNAKE_STRING;
        case 2:
          return Type.A_CAMEL_I32;
        default:
          throw new IllegalStateException("unreachable");
      }
    }

    public String getThriftName() {
        TField tField = (TField) FIELD_METADATA.get((int) this.id);
        if (tField == null) {
            return "null";
        } else {
            return tField.name;
        }
    }

    public void accept(Visitor visitor) {
        if (isSetAnSnakeString()) {
            visitor.visitAnSnakeString(getAnSnakeString());
            return;
        }
        if (isSetACamelI32()) {
            visitor.visitACamelI32(getACamelI32());
            return;
        }
    }

    @java.lang.Override
    public String toString() {
        return toStringHelper(this)
            .add("value", value)
            .add("id", id)
            .add("name", getThriftName())
            .add("type", value == null ? "<null>" : value.getClass().getSimpleName())
            .toString();
    }

    @java.lang.Override
    public boolean equals(java.lang.Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        UnfortunateUnion other = (UnfortunateUnion)o;

        return Objects.equals(this.id, other.id)
                && Objects.deepEquals(this.value, other.value);
    }

    @java.lang.Override
    public int hashCode() {
        return Arrays.deepHashCode(new java.lang.Object[] {
            id,
            value,
        });
    }

    public interface Visitor {
        void visitAnSnakeString(String anSnakeString);
        void visitACamelI32(int aCamelI32);
    }

    public void write0(TProtocol oprot) throws TException {
      if (this.id != 0 && this.value == null ){
        if(allowNullFieldValues) {
          // Warning: this path will generate corrupt serialized data!
          return;
        } else {
          throw new TProtocolException("Cannot write a Union with marked-as-set but null value!");
        }
      }
      oprot.writeStructBegin(STRUCT_DESC);
      switch (this.id) {
      case _AN_SNAKE_STRING: {
        oprot.writeFieldBegin(AN_SNAKE_STRING_FIELD_DESC);
        String anSnakeString = (String)this.value;
        oprot.writeString(anSnakeString);
        oprot.writeFieldEnd();
        break;
      }
      case _ACAMELI32: {
        oprot.writeFieldBegin(A_CAMEL_I32_FIELD_DESC);
        int aCamelI32 = (int)this.value;
        oprot.writeI32(aCamelI32);
        oprot.writeFieldEnd();
        break;
      }
      default:
          // ignore unknown field
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
    
    public static com.facebook.thrift.payload.Reader<UnfortunateUnion> asReader() {
      return UnfortunateUnion::read0;
    }
    
    public static UnfortunateUnion read0(TProtocol oprot) throws TException {
      UnfortunateUnion res = new UnfortunateUnion();
      res.value = null;
      res.id = (short) 0;
      oprot.readStructBegin(UnfortunateUnion.NAMES_TO_IDS, UnfortunateUnion.THRIFT_NAMES_TO_IDS, UnfortunateUnion.FIELD_METADATA);
      TField __field = oprot.readFieldBegin();
      if (__field.type != TType.STOP) {
          switch (__field.id) {
          case _AN_SNAKE_STRING:
            if (__field.type == AN_SNAKE_STRING_FIELD_DESC.type) {
              String anSnakeString = oprot.readString();
              res.value = anSnakeString;
            }
            break;
          case _ACAMELI32:
            if (__field.type == A_CAMEL_I32_FIELD_DESC.type) {
              int aCamelI32 = oprot.readI32();
              res.value = aCamelI32;
            }
            break;
          default:
            TProtocolUtil.skip(oprot, __field.type);
          }
        if (res.value != null) {
          res.id = __field.id;
        }
        oprot.readFieldEnd();
        TField __stopField = oprot.readFieldBegin(); // Consume the STOP byte
        if (__stopField.type != TType.STOP) {
          throw new TProtocolException(TProtocolException.INVALID_DATA, "Union 'UnfortunateUnion' is missing a STOP byte");
        }
      }
      oprot.readStructEnd();
      return res;
    }
    public static UnfortunateUnion defaultInstance() {
        return _DEFAULT;
    }

}
