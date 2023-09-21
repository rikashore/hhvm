// @generated by Thrift for thrift/compiler/test/fixtures/basic/src/module.thrift
// This file is probably not the place you want to edit!


#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies, clippy::redundant_closure, clippy::type_complexity)]

#[allow(unused_imports)]
pub(crate) use crate as types;

#[derive(Clone, PartialEq)]
pub struct MyStruct {
    pub MyIntField: ::std::primitive::i64,
    pub MyStringField: ::std::string::String,
    pub MyDataField: crate::types::MyDataItem,
    pub myEnum: crate::types::MyEnum,
    pub oneway: ::std::primitive::bool,
    pub readonly: ::std::primitive::bool,
    pub idempotent: ::std::primitive::bool,
    pub floatSet: ::std::collections::BTreeSet<::fbthrift::export::OrderedFloat<::std::primitive::f32>>,
    pub no_hack_codegen_field: ::std::string::String,
    // This field forces `..Default::default()` when instantiating this
    // struct, to make code future-proof against new fields added later to
    // the definition in Thrift. If you don't want this, add the annotation
    // `(rust.exhaustive)` to the Thrift struct to eliminate this field.
    #[doc(hidden)]
    pub _dot_dot_Default_default: self::dot_dot::OtherFields,
}

#[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct MyDataItem {
    // This field forces `..Default::default()` when instantiating this
    // struct, to make code future-proof against new fields added later to
    // the definition in Thrift. If you don't want this, add the annotation
    // `(rust.exhaustive)` to the Thrift struct to eliminate this field.
    #[doc(hidden)]
    pub _dot_dot_Default_default: self::dot_dot::OtherFields,
}

#[derive(Clone, PartialEq, Debug)]
pub enum MyUnion {
    myEnum(crate::types::MyEnum),
    myStruct(crate::types::MyStruct),
    myDataItem(crate::types::MyDataItem),
    floatSet(::std::collections::BTreeSet<::fbthrift::export::OrderedFloat<::std::primitive::f32>>),
    UnknownField(::std::primitive::i32),
}

#[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct ReservedKeyword {
    pub reserved_field: ::std::primitive::i32,
    // This field forces `..Default::default()` when instantiating this
    // struct, to make code future-proof against new fields added later to
    // the definition in Thrift. If you don't want this, add the annotation
    // `(rust.exhaustive)` to the Thrift struct to eliminate this field.
    #[doc(hidden)]
    pub _dot_dot_Default_default: self::dot_dot::OtherFields,
}

#[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash, Debug)]
pub enum UnionToBeRenamed {
    reserved_field(::std::primitive::i32),
    UnknownField(::std::primitive::i32),
}

#[derive(Copy, Clone, Eq, PartialEq, Ord, PartialOrd, Hash)]
pub struct MyEnum(pub ::std::primitive::i32);

impl MyEnum {
    pub const MyValue1: Self = MyEnum(0i32);
    pub const MyValue2: Self = MyEnum(1i32);
}

impl ::fbthrift::ThriftEnum for MyEnum {
    fn enumerate() -> &'static [(Self, &'static str)] {
        &[
            (Self::MyValue1, "MyValue1"),
            (Self::MyValue2, "MyValue2"),
        ]
    }

    fn variants() -> &'static [&'static str] {
        &[
            "MyValue1",
            "MyValue2",
        ]
    }

    fn variant_values() -> &'static [Self] {
        &[
            Self::MyValue1,
            Self::MyValue2,
        ]
    }
}

#[allow(clippy::derivable_impls)]
impl ::std::default::Default for MyEnum {
    fn default() -> Self {
        Self(::std::primitive::i32::MIN)
    }
}

impl<'a> ::std::convert::From<&'a MyEnum> for ::std::primitive::i32 {
    #[inline]
    fn from(x: &'a MyEnum) -> Self {
        x.0
    }
}

impl ::std::convert::From<MyEnum> for ::std::primitive::i32 {
    #[inline]
    fn from(x: MyEnum) -> Self {
        x.0
    }
}

impl ::std::convert::From<::std::primitive::i32> for MyEnum {
    #[inline]
    fn from(x: ::std::primitive::i32) -> Self {
        Self(x)
    }
}

impl ::std::fmt::Display for MyEnum {
    fn fmt(&self, fmt: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        static VARIANTS_BY_NUMBER: &[(&::std::primitive::str, ::std::primitive::i32)] = &[
            ("MyValue1", 0),
            ("MyValue2", 1),
        ];
        ::fbthrift::help::enum_display(VARIANTS_BY_NUMBER, fmt, self.0)
    }
}

impl ::std::fmt::Debug for MyEnum {
    fn fmt(&self, fmt: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        write!(fmt, "MyEnum::{}", self)
    }
}

impl ::std::str::FromStr for MyEnum {
    type Err = ::anyhow::Error;

    fn from_str(string: &::std::primitive::str) -> ::std::result::Result<Self, Self::Err> {
        static VARIANTS_BY_NAME: &[(&::std::primitive::str, ::std::primitive::i32)] = &[
            ("MyValue1", 0),
            ("MyValue2", 1),
        ];
        ::fbthrift::help::enum_from_str(VARIANTS_BY_NAME, string, "MyEnum").map(Self)
    }
}

impl ::fbthrift::GetTType for MyEnum {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::I32;
}

impl ::fbthrift::GetUri for self::MyEnum {
    fn uri() -> &'static str {
        "test.dev/fixtures/basic/MyEnum"
    }
}

impl<P> ::fbthrift::Serialize<P> for MyEnum
where
    P: ::fbthrift::ProtocolWriter,
{
    #[inline]
    fn write(&self, p: &mut P) {
        p.write_i32(self.into())
    }
}

impl<P> ::fbthrift::Deserialize<P> for MyEnum
where
    P: ::fbthrift::ProtocolReader,
{
    #[inline]
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        ::std::result::Result::Ok(Self::from(p.read_i32()?))
    }
}

#[derive(Copy, Clone, Eq, PartialEq, Ord, PartialOrd, Hash)]
pub struct HackEnum(pub ::std::primitive::i32);

impl HackEnum {
    pub const Value1: Self = HackEnum(0i32);
    pub const Value2: Self = HackEnum(1i32);
}

impl ::fbthrift::ThriftEnum for HackEnum {
    fn enumerate() -> &'static [(Self, &'static str)] {
        &[
            (Self::Value1, "Value1"),
            (Self::Value2, "Value2"),
        ]
    }

    fn variants() -> &'static [&'static str] {
        &[
            "Value1",
            "Value2",
        ]
    }

    fn variant_values() -> &'static [Self] {
        &[
            Self::Value1,
            Self::Value2,
        ]
    }
}

#[allow(clippy::derivable_impls)]
impl ::std::default::Default for HackEnum {
    fn default() -> Self {
        Self(::std::primitive::i32::MIN)
    }
}

impl<'a> ::std::convert::From<&'a HackEnum> for ::std::primitive::i32 {
    #[inline]
    fn from(x: &'a HackEnum) -> Self {
        x.0
    }
}

impl ::std::convert::From<HackEnum> for ::std::primitive::i32 {
    #[inline]
    fn from(x: HackEnum) -> Self {
        x.0
    }
}

impl ::std::convert::From<::std::primitive::i32> for HackEnum {
    #[inline]
    fn from(x: ::std::primitive::i32) -> Self {
        Self(x)
    }
}

impl ::std::fmt::Display for HackEnum {
    fn fmt(&self, fmt: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        static VARIANTS_BY_NUMBER: &[(&::std::primitive::str, ::std::primitive::i32)] = &[
            ("Value1", 0),
            ("Value2", 1),
        ];
        ::fbthrift::help::enum_display(VARIANTS_BY_NUMBER, fmt, self.0)
    }
}

impl ::std::fmt::Debug for HackEnum {
    fn fmt(&self, fmt: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        write!(fmt, "HackEnum::{}", self)
    }
}

impl ::std::str::FromStr for HackEnum {
    type Err = ::anyhow::Error;

    fn from_str(string: &::std::primitive::str) -> ::std::result::Result<Self, Self::Err> {
        static VARIANTS_BY_NAME: &[(&::std::primitive::str, ::std::primitive::i32)] = &[
            ("Value1", 0),
            ("Value2", 1),
        ];
        ::fbthrift::help::enum_from_str(VARIANTS_BY_NAME, string, "HackEnum").map(Self)
    }
}

impl ::fbthrift::GetTType for HackEnum {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::I32;
}

impl ::fbthrift::GetUri for self::HackEnum {
    fn uri() -> &'static str {
        "test.dev/fixtures/basic/HackEnum"
    }
}

impl<P> ::fbthrift::Serialize<P> for HackEnum
where
    P: ::fbthrift::ProtocolWriter,
{
    #[inline]
    fn write(&self, p: &mut P) {
        p.write_i32(self.into())
    }
}

impl<P> ::fbthrift::Deserialize<P> for HackEnum
where
    P: ::fbthrift::ProtocolReader,
{
    #[inline]
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        ::std::result::Result::Ok(Self::from(p.read_i32()?))
    }
}

#[allow(clippy::derivable_impls)]
impl ::std::default::Default for self::MyStruct {
    fn default() -> Self {
        Self {
            MyIntField: ::std::default::Default::default(),
            MyStringField: ::std::default::Default::default(),
            MyDataField: ::std::default::Default::default(),
            myEnum: ::std::default::Default::default(),
            oneway: ::std::default::Default::default(),
            readonly: ::std::default::Default::default(),
            idempotent: ::std::default::Default::default(),
            floatSet: ::std::default::Default::default(),
            no_hack_codegen_field: ::std::default::Default::default(),
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        }
    }
}

impl ::std::fmt::Debug for self::MyStruct {
    fn fmt(&self, formatter: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        formatter
            .debug_struct("MyStruct")
            .field("MyIntField", &self.MyIntField)
            .field("MyStringField", &self.MyStringField)
            .field("MyDataField", &self.MyDataField)
            .field("myEnum", &self.myEnum)
            .field("oneway", &self.oneway)
            .field("readonly", &self.readonly)
            .field("idempotent", &self.idempotent)
            .field("floatSet", &self.floatSet)
            .field("no_hack_codegen_field", &self.no_hack_codegen_field)
            .finish()
    }
}

unsafe impl ::std::marker::Send for self::MyStruct {}
unsafe impl ::std::marker::Sync for self::MyStruct {}
impl ::std::marker::Unpin for self::MyStruct {}

impl ::fbthrift::GetTType for self::MyStruct {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
}

impl ::fbthrift::GetUri for self::MyStruct {
    fn uri() -> &'static str {
        "test.dev/fixtures/basic/MyStruct"
    }
}

impl<P> ::fbthrift::Serialize<P> for self::MyStruct
where
    P: ::fbthrift::ProtocolWriter,
{
    fn write(&self, p: &mut P) {
        p.write_struct_begin("MyStruct");
        p.write_field_begin("MyIntField", ::fbthrift::TType::I64, 1);
        ::fbthrift::Serialize::write(&self.MyIntField, p);
        p.write_field_end();
        p.write_field_begin("MyStringField", ::fbthrift::TType::String, 2);
        ::fbthrift::Serialize::write(&self.MyStringField, p);
        p.write_field_end();
        p.write_field_begin("MyDataField", ::fbthrift::TType::Struct, 3);
        ::fbthrift::Serialize::write(&self.MyDataField, p);
        p.write_field_end();
        p.write_field_begin("myEnum", ::fbthrift::TType::I32, 4);
        ::fbthrift::Serialize::write(&self.myEnum, p);
        p.write_field_end();
        p.write_field_begin("oneway", ::fbthrift::TType::Bool, 5);
        ::fbthrift::Serialize::write(&self.oneway, p);
        p.write_field_end();
        p.write_field_begin("readonly", ::fbthrift::TType::Bool, 6);
        ::fbthrift::Serialize::write(&self.readonly, p);
        p.write_field_end();
        p.write_field_begin("idempotent", ::fbthrift::TType::Bool, 7);
        ::fbthrift::Serialize::write(&self.idempotent, p);
        p.write_field_end();
        p.write_field_begin("floatSet", ::fbthrift::TType::Set, 8);
        ::fbthrift::Serialize::write(&self.floatSet, p);
        p.write_field_end();
        p.write_field_begin("no_hack_codegen_field", ::fbthrift::TType::String, 9);
        ::fbthrift::Serialize::write(&self.no_hack_codegen_field, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P> ::fbthrift::Deserialize<P> for self::MyStruct
where
    P: ::fbthrift::ProtocolReader,
{
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        static FIELDS: &[::fbthrift::Field] = &[
            ::fbthrift::Field::new("MyDataField", ::fbthrift::TType::Struct, 3),
            ::fbthrift::Field::new("MyIntField", ::fbthrift::TType::I64, 1),
            ::fbthrift::Field::new("MyStringField", ::fbthrift::TType::String, 2),
            ::fbthrift::Field::new("floatSet", ::fbthrift::TType::Set, 8),
            ::fbthrift::Field::new("idempotent", ::fbthrift::TType::Bool, 7),
            ::fbthrift::Field::new("myEnum", ::fbthrift::TType::I32, 4),
            ::fbthrift::Field::new("no_hack_codegen_field", ::fbthrift::TType::String, 9),
            ::fbthrift::Field::new("oneway", ::fbthrift::TType::Bool, 5),
            ::fbthrift::Field::new("readonly", ::fbthrift::TType::Bool, 6),
        ];
        let mut field_MyIntField = ::std::option::Option::None;
        let mut field_MyStringField = ::std::option::Option::None;
        let mut field_MyDataField = ::std::option::Option::None;
        let mut field_myEnum = ::std::option::Option::None;
        let mut field_oneway = ::std::option::Option::None;
        let mut field_readonly = ::std::option::Option::None;
        let mut field_idempotent = ::std::option::Option::None;
        let mut field_floatSet = ::std::option::Option::None;
        let mut field_no_hack_codegen_field = ::std::option::Option::None;
        let _ = p.read_struct_begin(|_| ())?;
        loop {
            let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
            match (fty, fid as ::std::primitive::i32) {
                (::fbthrift::TType::Stop, _) => break,
                (::fbthrift::TType::I64, 1) => field_MyIntField = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (::fbthrift::TType::String, 2) => field_MyStringField = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (::fbthrift::TType::Struct, 3) => field_MyDataField = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (::fbthrift::TType::I32, 4) => field_myEnum = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (::fbthrift::TType::Bool, 5) => field_oneway = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (::fbthrift::TType::Bool, 6) => field_readonly = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (::fbthrift::TType::Bool, 7) => field_idempotent = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (::fbthrift::TType::Set, 8) => field_floatSet = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (::fbthrift::TType::String, 9) => field_no_hack_codegen_field = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (fty, _) => p.skip(fty)?,
            }
            p.read_field_end()?;
        }
        p.read_struct_end()?;
        ::std::result::Result::Ok(Self {
            MyIntField: field_MyIntField.unwrap_or_default(),
            MyStringField: field_MyStringField.unwrap_or_default(),
            MyDataField: field_MyDataField.unwrap_or_default(),
            myEnum: field_myEnum.unwrap_or_default(),
            oneway: field_oneway.unwrap_or_default(),
            readonly: field_readonly.unwrap_or_default(),
            idempotent: field_idempotent.unwrap_or_default(),
            floatSet: field_floatSet.unwrap_or_default(),
            no_hack_codegen_field: field_no_hack_codegen_field.unwrap_or_default(),
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        })
    }
}


impl ::fbthrift::metadata::ThriftAnnotations for MyStruct {
    fn get_structured_annotation<T: Sized + 'static>() -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        None
    }

    fn get_field_structured_annotation<T: Sized + 'static>(field_id: i16) -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        #[allow(clippy::match_single_binding)]
        match field_id {
            1 => {
            },
            2 => {
            },
            3 => {
            },
            4 => {
            },
            5 => {
            },
            6 => {
            },
            7 => {
            },
            8 => {

                if type_id == ::std::any::TypeId::of::<hack::types::SkipCodegen>() {
                    let mut tmp = Some(hack::types::SkipCodegen {
                        reason: "Invalid key type".to_owned(),
                        ..::std::default::Default::default()
                    });
                    let r: &mut dyn ::std::any::Any = &mut tmp;
                    let r: &mut Option<T> = r.downcast_mut().unwrap();
                    return r.take();
                }
            },
            9 => {

                if type_id == ::std::any::TypeId::of::<hack::types::SkipCodegen>() {
                    let mut tmp = Some(hack::types::SkipCodegen {
                        reason: "skip field codegen for deprecation".to_owned(),
                        ..::std::default::Default::default()
                    });
                    let r: &mut dyn ::std::any::Any = &mut tmp;
                    let r: &mut Option<T> = r.downcast_mut().unwrap();
                    return r.take();
                }
            },
            _ => {}
        }

        None
    }
}


#[allow(clippy::derivable_impls)]
impl ::std::default::Default for self::MyDataItem {
    fn default() -> Self {
        Self {
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        }
    }
}

impl ::std::fmt::Debug for self::MyDataItem {
    fn fmt(&self, formatter: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        formatter
            .debug_struct("MyDataItem")
            .finish()
    }
}

unsafe impl ::std::marker::Send for self::MyDataItem {}
unsafe impl ::std::marker::Sync for self::MyDataItem {}
impl ::std::marker::Unpin for self::MyDataItem {}

impl ::fbthrift::GetTType for self::MyDataItem {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
}

impl ::fbthrift::GetUri for self::MyDataItem {
    fn uri() -> &'static str {
        "test.dev/fixtures/basic/MyDataItem"
    }
}

impl<P> ::fbthrift::Serialize<P> for self::MyDataItem
where
    P: ::fbthrift::ProtocolWriter,
{
    fn write(&self, p: &mut P) {
        p.write_struct_begin("MyDataItem");
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P> ::fbthrift::Deserialize<P> for self::MyDataItem
where
    P: ::fbthrift::ProtocolReader,
{
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        static FIELDS: &[::fbthrift::Field] = &[
        ];
        let _ = p.read_struct_begin(|_| ())?;
        loop {
            let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
            match (fty, fid as ::std::primitive::i32) {
                (::fbthrift::TType::Stop, _) => break,
                (fty, _) => p.skip(fty)?,
            }
            p.read_field_end()?;
        }
        p.read_struct_end()?;
        ::std::result::Result::Ok(Self {
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        })
    }
}


impl ::fbthrift::metadata::ThriftAnnotations for MyDataItem {
    fn get_structured_annotation<T: Sized + 'static>() -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        None
    }

    fn get_field_structured_annotation<T: Sized + 'static>(field_id: i16) -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        #[allow(clippy::match_single_binding)]
        match field_id {
            _ => {}
        }

        None
    }
}



impl ::std::default::Default for MyUnion {
    fn default() -> Self {
        Self::UnknownField(-1)
    }
}

impl ::fbthrift::GetTType for MyUnion {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
}

impl ::fbthrift::GetUri for self::MyUnion {
    fn uri() -> &'static str {
        "test.dev/fixtures/basic/MyUnion"
    }
}

impl<P> ::fbthrift::Serialize<P> for MyUnion
where
    P: ::fbthrift::ProtocolWriter,
{
    fn write(&self, p: &mut P) {
        p.write_struct_begin("MyUnion");
        match self {
            Self::myEnum(inner) => {
                p.write_field_begin("myEnum", ::fbthrift::TType::I32, 1);
                ::fbthrift::Serialize::write(inner, p);
                p.write_field_end();
            }
            Self::myStruct(inner) => {
                p.write_field_begin("myStruct", ::fbthrift::TType::Struct, 2);
                ::fbthrift::Serialize::write(inner, p);
                p.write_field_end();
            }
            Self::myDataItem(inner) => {
                p.write_field_begin("myDataItem", ::fbthrift::TType::Struct, 3);
                ::fbthrift::Serialize::write(inner, p);
                p.write_field_end();
            }
            Self::floatSet(inner) => {
                p.write_field_begin("floatSet", ::fbthrift::TType::Set, 4);
                ::fbthrift::Serialize::write(inner, p);
                p.write_field_end();
            }
            Self::UnknownField(_) => {}
        }
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P> ::fbthrift::Deserialize<P> for MyUnion
where
    P: ::fbthrift::ProtocolReader,
{
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        static FIELDS: &[::fbthrift::Field] = &[
            ::fbthrift::Field::new("floatSet", ::fbthrift::TType::Set, 4),
            ::fbthrift::Field::new("myDataItem", ::fbthrift::TType::Struct, 3),
            ::fbthrift::Field::new("myEnum", ::fbthrift::TType::I32, 1),
            ::fbthrift::Field::new("myStruct", ::fbthrift::TType::Struct, 2),
        ];
        let _ = p.read_struct_begin(|_| ())?;
        let mut once = false;
        let mut alt = ::std::option::Option::None;
        loop {
            let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
            match (fty, fid as ::std::primitive::i32, once) {
                (::fbthrift::TType::Stop, _, _) => break,
                (::fbthrift::TType::I32, 1, false) => {
                    once = true;
                    alt = ::std::option::Option::Some(Self::myEnum(::fbthrift::Deserialize::read(p)?));
                }
                (::fbthrift::TType::Struct, 2, false) => {
                    once = true;
                    alt = ::std::option::Option::Some(Self::myStruct(::fbthrift::Deserialize::read(p)?));
                }
                (::fbthrift::TType::Struct, 3, false) => {
                    once = true;
                    alt = ::std::option::Option::Some(Self::myDataItem(::fbthrift::Deserialize::read(p)?));
                }
                (::fbthrift::TType::Set, 4, false) => {
                    once = true;
                    alt = ::std::option::Option::Some(Self::floatSet(::fbthrift::Deserialize::read(p)?));
                }
                (fty, _, false) => p.skip(fty)?,
                (badty, badid, true) => return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ProtocolError::UnwantedExtraUnionField(
                    "MyUnion".to_string(),
                    badty,
                    badid,
                ))),
            }
            p.read_field_end()?;
        }
        p.read_struct_end()?;
        ::std::result::Result::Ok(alt.unwrap_or_default())
    }
}

impl MyUnion {
    /// Return current union variant name as a tuple of (Rust name, original name).
    pub fn variant_name(&self) -> Option<(&'static str, &'static str)> {
        match self {
            Self::myEnum(_) => Some(("myEnum", "myEnum")),
            Self::myStruct(_) => Some(("myStruct", "myStruct")),
            Self::myDataItem(_) => Some(("myDataItem", "myDataItem")),
            Self::floatSet(_) => Some(("floatSet", "floatSet")),
            Self::UnknownField(_) => None,
        }
    }
}

impl ::fbthrift::metadata::ThriftAnnotations for MyUnion {
    fn get_structured_annotation<T: Sized + 'static>() -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        None
    }

    fn get_field_structured_annotation<T: Sized + 'static>(field_id: i16) -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        #[allow(clippy::match_single_binding)]
        match field_id {
            1 => {
            },
            2 => {
            },
            3 => {
            },
            4 => {

                if type_id == ::std::any::TypeId::of::<hack::types::SkipCodegen>() {
                    let mut tmp = Some(hack::types::SkipCodegen {
                        reason: "Invalid key type".to_owned(),
                        ..::std::default::Default::default()
                    });
                    let r: &mut dyn ::std::any::Any = &mut tmp;
                    let r: &mut Option<T> = r.downcast_mut().unwrap();
                    return r.take();
                }
            },
            _ => {}
        }

        None
    }
}

#[allow(clippy::derivable_impls)]
impl ::std::default::Default for self::ReservedKeyword {
    fn default() -> Self {
        Self {
            reserved_field: ::std::default::Default::default(),
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        }
    }
}

impl ::std::fmt::Debug for self::ReservedKeyword {
    fn fmt(&self, formatter: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        formatter
            .debug_struct("ReservedKeyword")
            .field("reserved_field", &self.reserved_field)
            .finish()
    }
}

unsafe impl ::std::marker::Send for self::ReservedKeyword {}
unsafe impl ::std::marker::Sync for self::ReservedKeyword {}
impl ::std::marker::Unpin for self::ReservedKeyword {}

impl ::fbthrift::GetTType for self::ReservedKeyword {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
}

impl ::fbthrift::GetUri for self::ReservedKeyword {
    fn uri() -> &'static str {
        "test.dev/fixtures/basic/ReservedKeyword"
    }
}

impl<P> ::fbthrift::Serialize<P> for self::ReservedKeyword
where
    P: ::fbthrift::ProtocolWriter,
{
    fn write(&self, p: &mut P) {
        p.write_struct_begin("ReservedKeyword");
        p.write_field_begin("reserved_field", ::fbthrift::TType::I32, 1);
        ::fbthrift::Serialize::write(&self.reserved_field, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P> ::fbthrift::Deserialize<P> for self::ReservedKeyword
where
    P: ::fbthrift::ProtocolReader,
{
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        static FIELDS: &[::fbthrift::Field] = &[
            ::fbthrift::Field::new("reserved_field", ::fbthrift::TType::I32, 1),
        ];
        let mut field_reserved_field = ::std::option::Option::None;
        let _ = p.read_struct_begin(|_| ())?;
        loop {
            let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
            match (fty, fid as ::std::primitive::i32) {
                (::fbthrift::TType::Stop, _) => break,
                (::fbthrift::TType::I32, 1) => field_reserved_field = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (fty, _) => p.skip(fty)?,
            }
            p.read_field_end()?;
        }
        p.read_struct_end()?;
        ::std::result::Result::Ok(Self {
            reserved_field: field_reserved_field.unwrap_or_default(),
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        })
    }
}


impl ::fbthrift::metadata::ThriftAnnotations for ReservedKeyword {
    fn get_structured_annotation<T: Sized + 'static>() -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        if type_id == ::std::any::TypeId::of::<hack::types::Name>() {
            let mut tmp = Some(hack::types::Name {
                name: "MyRenamedStruct".to_owned(),
                reason: ::std::default::Default::default(),
                ..::std::default::Default::default()
            });
            let r: &mut dyn ::std::any::Any = &mut tmp;
            let r: &mut Option<T> = r.downcast_mut().unwrap();
            return r.take();
        }

        None
    }

    fn get_field_structured_annotation<T: Sized + 'static>(field_id: i16) -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        #[allow(clippy::match_single_binding)]
        match field_id {
            1 => {

                if type_id == ::std::any::TypeId::of::<hack::types::Name>() {
                    let mut tmp = Some(hack::types::Name {
                        name: "renamed_field".to_owned(),
                        reason: ::std::default::Default::default(),
                        ..::std::default::Default::default()
                    });
                    let r: &mut dyn ::std::any::Any = &mut tmp;
                    let r: &mut Option<T> = r.downcast_mut().unwrap();
                    return r.take();
                }
            },
            _ => {}
        }

        None
    }
}



impl ::std::default::Default for UnionToBeRenamed {
    fn default() -> Self {
        Self::UnknownField(-1)
    }
}

impl ::fbthrift::GetTType for UnionToBeRenamed {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
}

impl ::fbthrift::GetUri for self::UnionToBeRenamed {
    fn uri() -> &'static str {
        "test.dev/fixtures/basic/UnionToBeRenamed"
    }
}

impl<P> ::fbthrift::Serialize<P> for UnionToBeRenamed
where
    P: ::fbthrift::ProtocolWriter,
{
    fn write(&self, p: &mut P) {
        p.write_struct_begin("UnionToBeRenamed");
        match self {
            Self::reserved_field(inner) => {
                p.write_field_begin("reserved_field", ::fbthrift::TType::I32, 1);
                ::fbthrift::Serialize::write(inner, p);
                p.write_field_end();
            }
            Self::UnknownField(_) => {}
        }
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P> ::fbthrift::Deserialize<P> for UnionToBeRenamed
where
    P: ::fbthrift::ProtocolReader,
{
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        static FIELDS: &[::fbthrift::Field] = &[
            ::fbthrift::Field::new("reserved_field", ::fbthrift::TType::I32, 1),
        ];
        let _ = p.read_struct_begin(|_| ())?;
        let mut once = false;
        let mut alt = ::std::option::Option::None;
        loop {
            let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
            match (fty, fid as ::std::primitive::i32, once) {
                (::fbthrift::TType::Stop, _, _) => break,
                (::fbthrift::TType::I32, 1, false) => {
                    once = true;
                    alt = ::std::option::Option::Some(Self::reserved_field(::fbthrift::Deserialize::read(p)?));
                }
                (fty, _, false) => p.skip(fty)?,
                (badty, badid, true) => return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ProtocolError::UnwantedExtraUnionField(
                    "UnionToBeRenamed".to_string(),
                    badty,
                    badid,
                ))),
            }
            p.read_field_end()?;
        }
        p.read_struct_end()?;
        ::std::result::Result::Ok(alt.unwrap_or_default())
    }
}

impl UnionToBeRenamed {
    /// Return current union variant name as a tuple of (Rust name, original name).
    pub fn variant_name(&self) -> Option<(&'static str, &'static str)> {
        match self {
            Self::reserved_field(_) => Some(("reserved_field", "reserved_field")),
            Self::UnknownField(_) => None,
        }
    }
}

impl ::fbthrift::metadata::ThriftAnnotations for UnionToBeRenamed {
    fn get_structured_annotation<T: Sized + 'static>() -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        if type_id == ::std::any::TypeId::of::<hack::types::Name>() {
            let mut tmp = Some(hack::types::Name {
                name: "MyRenamedUnion".to_owned(),
                reason: ::std::default::Default::default(),
                ..::std::default::Default::default()
            });
            let r: &mut dyn ::std::any::Any = &mut tmp;
            let r: &mut Option<T> = r.downcast_mut().unwrap();
            return r.take();
        }

        None
    }

    fn get_field_structured_annotation<T: Sized + 'static>(field_id: i16) -> ::std::option::Option<T> {
        #[allow(unused_variables)]
        let type_id = ::std::any::TypeId::of::<T>();

        #[allow(clippy::match_single_binding)]
        match field_id {
            1 => {

                if type_id == ::std::any::TypeId::of::<hack::types::Name>() {
                    let mut tmp = Some(hack::types::Name {
                        name: "renamed_field".to_owned(),
                        reason: ::std::default::Default::default(),
                        ..::std::default::Default::default()
                    });
                    let r: &mut dyn ::std::any::Any = &mut tmp;
                    let r: &mut Option<T> = r.downcast_mut().unwrap();
                    return r.take();
                }
            },
            _ => {}
        }

        None
    }
}

mod dot_dot {
    #[derive(Copy, Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
    pub struct OtherFields(pub(crate) ());

    #[allow(dead_code)] // if serde isn't being used
    pub(super) fn default_for_serde_deserialize() -> OtherFields {
        OtherFields(())
    }
}

pub(crate) mod r#impl {
    use ref_cast::RefCast;

    #[derive(RefCast)]
    #[repr(transparent)]
    pub(crate) struct LocalImpl<T>(T);

    #[allow(unused)]
    pub(crate) fn write<T, P>(value: &T, p: &mut P)
    where
        LocalImpl<T>: ::fbthrift::Serialize<P>,
        P: ::fbthrift::ProtocolWriter,
    {
        ::fbthrift::Serialize::write(LocalImpl::ref_cast(value), p);
    }

    #[allow(unused)]
    pub(crate) fn read<T, P>(p: &mut P) -> ::anyhow::Result<T>
    where
        LocalImpl<T>: ::fbthrift::Deserialize<P>,
        P: ::fbthrift::ProtocolReader,
    {
        let value: LocalImpl<T> = ::fbthrift::Deserialize::read(p)?;
        ::std::result::Result::Ok(value.0)
    }
}
