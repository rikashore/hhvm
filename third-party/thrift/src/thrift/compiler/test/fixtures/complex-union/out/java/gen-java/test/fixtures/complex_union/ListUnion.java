/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.complex_union;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftUnion("ListUnion")
public final class ListUnion implements com.facebook.thrift.payload.ThriftSerializable {
    
    private static final boolean allowNullFieldValues =
        System.getProperty("thrift.union.allow-null-field-values", "false").equalsIgnoreCase("true");

    private static final TStruct STRUCT_DESC = new TStruct("ListUnion");
    private static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    private static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();
    private static final ListUnion _DEFAULT = new ListUnion();

    public static final int _INTLISTVALUE = 2;
    private static final TField INT_LIST_VALUE_FIELD_DESC = new TField("intListValue", TType.LIST, (short)2);
    public static final int _STRINGLISTVALUE = 3;
    private static final TField STRING_LIST_VALUE_FIELD_DESC = new TField("stringListValue", TType.LIST, (short)3);

    static {
      NAMES_TO_IDS.put("intListValue", 2);
      THRIFT_NAMES_TO_IDS.put("intListValue", 2);
      FIELD_METADATA.put(2, INT_LIST_VALUE_FIELD_DESC);
      NAMES_TO_IDS.put("stringListValue", 3);
      THRIFT_NAMES_TO_IDS.put("stringListValue", 3);
      FIELD_METADATA.put(3, STRING_LIST_VALUE_FIELD_DESC);
    }

    private java.lang.Object value;
    private short id;

    public enum Type {
      INT_LIST_VALUE,
      STRING_LIST_VALUE,
    }

    public static ListUnion from(int _id, java.lang.Object _field) {
        return from((short) _id, _field);
    }

    public static ListUnion from(short _id, java.lang.Object _field) {
        java.util.Objects.requireNonNull(_field);
        if (!FIELD_METADATA.containsKey(Integer.valueOf(_id))) {
            throw new java.lang.IllegalArgumentException("unknown field " + _id);
        }

        ListUnion _u = new  ListUnion();

        try {
            switch(_id) {
                case 2:
                    _u.id = _id;
                    _u.value = (List<Long>) _field;
                    return _u;
                case 3:
                    _u.id = _id;
                    _u.value = (List<String>) _field;
                    return _u;
                default:
                throw new IllegalArgumentException("invalid type " + _field.getClass().getName() + " for field " + _id);
            }
        } catch (java.lang.Exception t) {
            throw new IllegalArgumentException("invalid type " + _field.getClass().getName() + " for field " + _id);
        }
    }

    @ThriftConstructor
    public ListUnion() {
    }
    
    public static ListUnion fromIntListValue(final List<Long> intListValue) {
        ListUnion res = new ListUnion();
        if (!ListUnion.allowNullFieldValues && intListValue == null) {
            throw new TProtocolException("Cannot initialize Union field 'ListUnion.intListValue' with null value!");
        }
        res.value = intListValue;
        res.id = 2;
        return res;
    }
    
    public static ListUnion fromStringListValue(final List<String> stringListValue) {
        ListUnion res = new ListUnion();
        if (!ListUnion.allowNullFieldValues && stringListValue == null) {
            throw new TProtocolException("Cannot initialize Union field 'ListUnion.stringListValue' with null value!");
        }
        res.value = stringListValue;
        res.id = 3;
        return res;
    }
    
    @com.facebook.swift.codec.ThriftField
    @Deprecated
    public void setIntListValue(final List<Long> intListValue) {
        this.value = intListValue;
        this.id = 2;
    }
    @com.facebook.swift.codec.ThriftField
    @Deprecated
    public void setStringListValue(final List<String> stringListValue) {
        this.value = stringListValue;
        this.id = 3;
    }

    @com.facebook.swift.codec.ThriftField(value=2, name="intListValue", requiredness=Requiredness.NONE)
    public List<Long> getIntListValue() {
        if (this.id != 2) {
            throw new IllegalStateException("Not a intListValue element!");
        }
        return (List<Long>) value;
    }

    public boolean isSetIntListValue() {
        return this.id == 2;
    }

    @com.facebook.swift.codec.ThriftField(value=3, name="stringListValue", requiredness=Requiredness.NONE)
    public List<String> getStringListValue() {
        if (this.id != 3) {
            throw new IllegalStateException("Not a stringListValue element!");
        }
        return (List<String>) value;
    }

    public boolean isSetStringListValue() {
        return this.id == 3;
    }

    @ThriftUnionId
    public short getThriftId() {
        return this.id;
    }

    public Type getThriftUnionType() {
      switch(this.id) {
        case 2:
          return Type.INT_LIST_VALUE;
        case 3:
          return Type.STRING_LIST_VALUE;
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
        if (isSetIntListValue()) {
            visitor.visitIntListValue(getIntListValue());
            return;
        }
        if (isSetStringListValue()) {
            visitor.visitStringListValue(getStringListValue());
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

        ListUnion other = (ListUnion)o;

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
        void visitIntListValue(List<Long> intListValue);
        void visitStringListValue(List<String> stringListValue);
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
      case _INTLISTVALUE: {
        oprot.writeFieldBegin(INT_LIST_VALUE_FIELD_DESC);
        List<Long> _iter0 = (List<Long>)this.value;
        oprot.writeListBegin(new TList(TType.I64, _iter0.size()));
        for (long _iter1 : _iter0) {
          oprot.writeI64(_iter1);
        }
        oprot.writeListEnd();
        oprot.writeFieldEnd();
        break;
      }
      case _STRINGLISTVALUE: {
        oprot.writeFieldBegin(STRING_LIST_VALUE_FIELD_DESC);
        List<String> _iter0 = (List<String>)this.value;
        oprot.writeListBegin(new TList(TType.STRING, _iter0.size()));
        for (String _iter1 : _iter0) {
          oprot.writeString(_iter1);
        }
        oprot.writeListEnd();
        oprot.writeFieldEnd();
        break;
      }
      default:
          // ignore unknown field
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
    
    public static com.facebook.thrift.payload.Reader<ListUnion> asReader() {
      return ListUnion::read0;
    }
    
    public static ListUnion read0(TProtocol oprot) throws TException {
      ListUnion res = new ListUnion();
      res.value = null;
      res.id = (short) 0;
      oprot.readStructBegin(ListUnion.NAMES_TO_IDS, ListUnion.THRIFT_NAMES_TO_IDS, ListUnion.FIELD_METADATA);
      TField __field = oprot.readFieldBegin();
      if (__field.type != TType.STOP) {
          switch (__field.id) {
          case _INTLISTVALUE:
            if (__field.type == INT_LIST_VALUE_FIELD_DESC.type) {
              List<Long> intListValue;
            {
            TList _list = oprot.readListBegin();
            intListValue = new ArrayList<Long>(Math.max(0, _list.size));
            for (int _i = 0; (_list.size < 0) ? oprot.peekList() : (_i < _list.size); _i++) {
                
                long _value1 = oprot.readI64();
                intListValue.add(_value1);
            }
            oprot.readListEnd();
            }
              res.value = intListValue;
            }
            break;
          case _STRINGLISTVALUE:
            if (__field.type == STRING_LIST_VALUE_FIELD_DESC.type) {
              List<String> stringListValue;
            {
            TList _list = oprot.readListBegin();
            stringListValue = new ArrayList<String>(Math.max(0, _list.size));
            for (int _i = 0; (_list.size < 0) ? oprot.peekList() : (_i < _list.size); _i++) {
                
                String _value1 = oprot.readString();
                stringListValue.add(_value1);
            }
            oprot.readListEnd();
            }
              res.value = stringListValue;
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
          throw new TProtocolException(TProtocolException.INVALID_DATA, "Union 'ListUnion' is missing a STOP byte");
        }
      }
      oprot.readStructEnd();
      return res;
    }
    public static ListUnion defaultInstance() {
        return _DEFAULT;
    }

}
