/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.adapter;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import com.google.common.collect.*;
import java.util.*;
import javax.annotation.Nullable;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@com.facebook.swift.codec.ThriftStruct(value="StructWithFieldAdapter", builder=StructWithFieldAdapter.Builder.class)
public final class StructWithFieldAdapter implements com.facebook.thrift.payload.ThriftSerializable {

    @ThriftConstructor
    public StructWithFieldAdapter(
        @com.facebook.swift.codec.ThriftField(value=1, name="field", requiredness=Requiredness.NONE) final int field,
        @com.facebook.swift.codec.ThriftField(value=2, name="shared_field", requiredness=Requiredness.NONE) final int sharedField,
        @com.facebook.swift.codec.ThriftField(value=3, name="opt_shared_field", requiredness=Requiredness.OPTIONAL) final Integer optSharedField,
        @com.facebook.swift.codec.ThriftField(value=4, name="opt_boxed_field", requiredness=Requiredness.OPTIONAL) final Integer optBoxedField
    ) {
        this.field = field;
        this.sharedField = sharedField;
        this.optSharedField = optSharedField;
        this.optBoxedField = optBoxedField;
    }
    
    @ThriftConstructor
    protected StructWithFieldAdapter() {
      this.field = 0;
      this.sharedField = 0;
      this.optSharedField = null;
      this.optBoxedField = null;
    }
    
    public static class Builder {
    
        private int field = 0;
        private int sharedField = 0;
        private Integer optSharedField = null;
        private Integer optBoxedField = null;
    
        @com.facebook.swift.codec.ThriftField(value=1, name="field", requiredness=Requiredness.NONE)
        public Builder setField(int field) {
            this.field = field;
            return this;
        }
    
        public int getField() { return field; }
    
            @com.facebook.swift.codec.ThriftField(value=2, name="shared_field", requiredness=Requiredness.NONE)
        public Builder setSharedField(int sharedField) {
            this.sharedField = sharedField;
            return this;
        }
    
        public int getSharedField() { return sharedField; }
    
            @com.facebook.swift.codec.ThriftField(value=3, name="opt_shared_field", requiredness=Requiredness.OPTIONAL)
        public Builder setOptSharedField(Integer optSharedField) {
            this.optSharedField = optSharedField;
            return this;
        }
    
        public Integer getOptSharedField() { return optSharedField; }
    
            @com.facebook.swift.codec.ThriftField(value=4, name="opt_boxed_field", requiredness=Requiredness.OPTIONAL)
        public Builder setOptBoxedField(Integer optBoxedField) {
            this.optBoxedField = optBoxedField;
            return this;
        }
    
        public Integer getOptBoxedField() { return optBoxedField; }
    
        public Builder() { }
        public Builder(StructWithFieldAdapter other) {
            this.field = other.field;
            this.sharedField = other.sharedField;
            this.optSharedField = other.optSharedField;
            this.optBoxedField = other.optBoxedField;
        }
    
        @ThriftConstructor
        public StructWithFieldAdapter build() {
            StructWithFieldAdapter result = new StructWithFieldAdapter (
                this.field,
                this.sharedField,
                this.optSharedField,
                this.optBoxedField
            );
            return result;
        }
    }
                    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("StructWithFieldAdapter");
    private final int field;
    public static final int _FIELD = 1;
    private static final TField FIELD_FIELD_DESC = new TField("field", TType.I32, (short)1);
        private final int sharedField;
    public static final int _SHARED_FIELD = 2;
    private static final TField SHARED_FIELD_FIELD_DESC = new TField("shared_field", TType.I32, (short)2);
        private final Integer optSharedField;
    public static final int _OPT_SHARED_FIELD = 3;
    private static final TField OPT_SHARED_FIELD_FIELD_DESC = new TField("opt_shared_field", TType.I32, (short)3);
        private final Integer optBoxedField;
    public static final int _OPT_BOXED_FIELD = 4;
    private static final TField OPT_BOXED_FIELD_FIELD_DESC = new TField("opt_boxed_field", TType.I32, (short)4);
    static {
      NAMES_TO_IDS.put("field", 1);
      THRIFT_NAMES_TO_IDS.put("field", 1);
      FIELD_METADATA.put(1, FIELD_FIELD_DESC);
      NAMES_TO_IDS.put("sharedField", 2);
      THRIFT_NAMES_TO_IDS.put("shared_field", 2);
      FIELD_METADATA.put(2, SHARED_FIELD_FIELD_DESC);
      NAMES_TO_IDS.put("optSharedField", 3);
      THRIFT_NAMES_TO_IDS.put("opt_shared_field", 3);
      FIELD_METADATA.put(3, OPT_SHARED_FIELD_FIELD_DESC);
      NAMES_TO_IDS.put("optBoxedField", 4);
      THRIFT_NAMES_TO_IDS.put("opt_boxed_field", 4);
      FIELD_METADATA.put(4, OPT_BOXED_FIELD_FIELD_DESC);
      com.facebook.thrift.type.TypeRegistry.add(new com.facebook.thrift.type.Type(
        new com.facebook.thrift.type.UniversalName("facebook.com/thrift/test/StructWithFieldAdapter"), 
        StructWithFieldAdapter.class, StructWithFieldAdapter::read0));
    }
    
    
    @com.facebook.swift.codec.ThriftField(value=1, name="field", requiredness=Requiredness.NONE)
    public int getField() { return field; }
    
    
    
    @com.facebook.swift.codec.ThriftField(value=2, name="shared_field", requiredness=Requiredness.NONE)
    public int getSharedField() { return sharedField; }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=3, name="opt_shared_field", requiredness=Requiredness.OPTIONAL)
    public Integer getOptSharedField() { return optSharedField; }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=4, name="opt_boxed_field", requiredness=Requiredness.OPTIONAL)
    public Integer getOptBoxedField() { return optBoxedField; }
    
    @java.lang.Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("field", field);
        helper.add("sharedField", sharedField);
        helper.add("optSharedField", optSharedField);
        helper.add("optBoxedField", optBoxedField);
        return helper.toString();
    }
    
    @java.lang.Override
    public boolean equals(java.lang.Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        StructWithFieldAdapter other = (StructWithFieldAdapter)o;
    
        return
            Objects.equals(field, other.field) &&
    Objects.equals(sharedField, other.sharedField) &&
    Objects.equals(optSharedField, other.optSharedField) &&
    Objects.equals(optBoxedField, other.optBoxedField) &&
            true;
    }
    
    @java.lang.Override
    public int hashCode() {
        return Arrays.deepHashCode(new java.lang.Object[] {
            field,
            sharedField,
            optSharedField,
            optBoxedField
        });
    }
    
    
    public static com.facebook.thrift.payload.Reader<StructWithFieldAdapter> asReader() {
      return StructWithFieldAdapter::read0;
    }
    
    public static StructWithFieldAdapter read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(StructWithFieldAdapter.NAMES_TO_IDS, StructWithFieldAdapter.THRIFT_NAMES_TO_IDS, StructWithFieldAdapter.FIELD_METADATA);
      StructWithFieldAdapter.Builder builder = new StructWithFieldAdapter.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _FIELD:
          if (__field.type == TType.I32) {
            int field = oprot.readI32();
            builder.setField(field);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _SHARED_FIELD:
          if (__field.type == TType.I32) {
            int sharedField = oprot.readI32();
            builder.setSharedField(sharedField);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _OPT_SHARED_FIELD:
          if (__field.type == TType.I32) {
            Integer optSharedField = oprot.readI32();
            builder.setOptSharedField(optSharedField);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _OPT_BOXED_FIELD:
          if (__field.type == TType.I32) {
            Integer optBoxedField = oprot.readI32();
            builder.setOptBoxedField(optBoxedField);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      oprot.writeFieldBegin(FIELD_FIELD_DESC);
      oprot.writeI32(this.field);
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(SHARED_FIELD_FIELD_DESC);
      oprot.writeI32(this.sharedField);
      oprot.writeFieldEnd();
      if (this.optSharedField != null) {
        oprot.writeFieldBegin(OPT_SHARED_FIELD_FIELD_DESC);
        oprot.writeI32(this.optSharedField);
        oprot.writeFieldEnd();
      }
      if (this.optBoxedField != null) {
        oprot.writeFieldBegin(OPT_BOXED_FIELD_FIELD_DESC);
        oprot.writeI32(this.optBoxedField);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
    private static class _StructWithFieldAdapterLazy {
        private static final StructWithFieldAdapter _DEFAULT = new StructWithFieldAdapter.Builder().build();
    }
    
    public static StructWithFieldAdapter defaultInstance() {
        return  _StructWithFieldAdapterLazy._DEFAULT;
    }
}
