// @generated by Thrift for thrift/compiler/test/fixtures/doctext/src/module.thrift
// This file is probably not the place you want to edit!


#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies, clippy::redundant_closure, clippy::type_complexity)]

pub mod consts;

#[allow(unused_imports)]
pub(crate) use crate as types;

#[doc = "Cool new name for string"]
pub type lanyard = ::std::string::String;

#[doc = "Secret name"]
#[derive(Default, Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct number(pub ::std::primitive::i32);

#[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
#[doc = "DefinitionList doctext."]
pub struct A {
    #[doc = "Field doctext."]
    pub useless_field: ::std::primitive::i32,
    // This field forces `..Default::default()` when instantiating this
    // struct, to make code future-proof against new fields added later to
    // the definition in Thrift. If you don't want this, add the annotation
    // `(rust.exhaustive)` to the Thrift struct to eliminate this field.
    #[doc(hidden)]
    pub _dot_dot_Default_default: self::dot_dot::OtherFields,
}

#[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash, Debug)]
#[doc = "Union U"]
pub enum U {
    #[doc = "i32 field i"]
    i(::std::primitive::i32),
    #[doc = "string s"]
    s(::std::string::String),
    UnknownField(::std::primitive::i32),
}

#[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
#[doc = "Something amiss"]
pub struct Bang {
    #[doc = "All explosions can be explained away"]
    pub message: ::std::string::String,
    // This field forces `..Default::default()` when instantiating this
    // struct, to make code future-proof against new fields added later to
    // the definition in Thrift. If you don't want this, add the annotation
    // `(rust.exhaustive)` to the Thrift struct to eliminate this field.
    #[doc(hidden)]
    pub _dot_dot_Default_default: self::dot_dot::OtherFields,
}

impl ::fbthrift::ExceptionInfo for Bang {
    fn exn_value(&self) -> String {
        format!("{:?}", self)
    }

    #[inline]
    fn exn_is_declared(&self) -> bool { true }
}

impl ::std::error::Error for Bang {}

impl ::std::fmt::Display for Bang {
    fn fmt(&self, f: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        write!(f, "{:?}", self)
    }
}

#[doc = "This enum is great"]
#[derive(Copy, Clone, Eq, PartialEq, Ord, PartialOrd, Hash)]
pub struct B(pub ::std::primitive::i32);

impl B {
    #[doc = "EnumDef doctext."]
    pub const HELLO: Self = B(0i32);
}

impl ::fbthrift::ThriftEnum for B {
    fn enumerate() -> &'static [(Self, &'static str)] {
        &[
            (Self::HELLO, "HELLO"),
        ]
    }

    fn variants() -> &'static [&'static str] {
        &[
            "HELLO",
        ]
    }

    fn variant_values() -> &'static [Self] {
        &[
            Self::HELLO,
        ]
    }
}

#[allow(clippy::derivable_impls)]
impl ::std::default::Default for B {
    fn default() -> Self {
        Self(::std::primitive::i32::MIN)
    }
}

impl<'a> ::std::convert::From<&'a B> for ::std::primitive::i32 {
    #[inline]
    fn from(x: &'a B) -> Self {
        x.0
    }
}

impl ::std::convert::From<B> for ::std::primitive::i32 {
    #[inline]
    fn from(x: B) -> Self {
        x.0
    }
}

impl ::std::convert::From<::std::primitive::i32> for B {
    #[inline]
    fn from(x: ::std::primitive::i32) -> Self {
        Self(x)
    }
}

impl ::std::fmt::Display for B {
    fn fmt(&self, fmt: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        static VARIANTS_BY_NUMBER: &[(&::std::primitive::str, ::std::primitive::i32)] = &[
            ("HELLO", 0),
        ];
        ::fbthrift::help::enum_display(VARIANTS_BY_NUMBER, fmt, self.0)
    }
}

impl ::std::fmt::Debug for B {
    fn fmt(&self, fmt: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        write!(fmt, "B::{}", self)
    }
}

impl ::std::str::FromStr for B {
    type Err = ::anyhow::Error;

    fn from_str(string: &::std::primitive::str) -> ::std::result::Result<Self, Self::Err> {
        static VARIANTS_BY_NAME: &[(&::std::primitive::str, ::std::primitive::i32)] = &[
            ("HELLO", 0),
        ];
        ::fbthrift::help::enum_from_str(VARIANTS_BY_NAME, string, "B").map(Self)
    }
}

impl ::fbthrift::GetTType for B {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::I32;
}

impl<P> ::fbthrift::Serialize<P> for B
where
    P: ::fbthrift::ProtocolWriter,
{
    #[inline]
    fn write(&self, p: &mut P) {
        p.write_i32(self.into())
    }
}

impl<P> ::fbthrift::Deserialize<P> for B
where
    P: ::fbthrift::ProtocolReader,
{
    #[inline]
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        ::std::result::Result::Ok(Self::from(p.read_i32()?))
    }
}
impl ::fbthrift::GetTType for number {
    const TTYPE: ::fbthrift::TType = <::std::primitive::i32 as ::fbthrift::GetTType>::TTYPE;
}

impl<P> ::fbthrift::Serialize<P> for number
where
    P: ::fbthrift::ProtocolWriter,
{
    fn write(&self, p: &mut P) {
        self.0.write(p)
    }
}

impl<P> ::fbthrift::Deserialize<P> for number
where
    P: ::fbthrift::ProtocolReader,
{
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        ::fbthrift::Deserialize::read(p).map(number)
    }
}


#[allow(clippy::derivable_impls)]
impl ::std::default::Default for self::A {
    fn default() -> Self {
        Self {
            useless_field: ::std::default::Default::default(),
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        }
    }
}

impl ::std::fmt::Debug for self::A {
    fn fmt(&self, formatter: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        formatter
            .debug_struct("A")
            .field("useless_field", &self.useless_field)
            .finish()
    }
}

unsafe impl ::std::marker::Send for self::A {}
unsafe impl ::std::marker::Sync for self::A {}
impl ::std::marker::Unpin for self::A {}

impl ::fbthrift::GetTType for self::A {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
}

impl<P> ::fbthrift::Serialize<P> for self::A
where
    P: ::fbthrift::ProtocolWriter,
{
    fn write(&self, p: &mut P) {
        p.write_struct_begin("A");
        p.write_field_begin("useless_field", ::fbthrift::TType::I32, 1);
        ::fbthrift::Serialize::write(&self.useless_field, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P> ::fbthrift::Deserialize<P> for self::A
where
    P: ::fbthrift::ProtocolReader,
{
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        static FIELDS: &[::fbthrift::Field] = &[
            ::fbthrift::Field::new("useless_field", ::fbthrift::TType::I32, 1),
        ];
        let mut field_useless_field = ::std::option::Option::None;
        let _ = p.read_struct_begin(|_| ())?;
        loop {
            let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
            match (fty, fid as ::std::primitive::i32) {
                (::fbthrift::TType::Stop, _) => break,
                (::fbthrift::TType::I32, 1) => field_useless_field = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (fty, _) => p.skip(fty)?,
            }
            p.read_field_end()?;
        }
        p.read_struct_end()?;
        ::std::result::Result::Ok(Self {
            useless_field: field_useless_field.unwrap_or_default(),
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        })
    }
}


impl ::fbthrift::metadata::ThriftAnnotations for A {
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
            _ => {}
        }

        None
    }
}



impl ::std::default::Default for U {
    fn default() -> Self {
        Self::UnknownField(-1)
    }
}

impl ::fbthrift::GetTType for U {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
}

impl<P> ::fbthrift::Serialize<P> for U
where
    P: ::fbthrift::ProtocolWriter,
{
    fn write(&self, p: &mut P) {
        p.write_struct_begin("U");
        match self {
            Self::i(inner) => {
                p.write_field_begin("i", ::fbthrift::TType::I32, 1);
                ::fbthrift::Serialize::write(inner, p);
                p.write_field_end();
            }
            Self::s(inner) => {
                p.write_field_begin("s", ::fbthrift::TType::String, 2);
                ::fbthrift::Serialize::write(inner, p);
                p.write_field_end();
            }
            Self::UnknownField(_) => {}
        }
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P> ::fbthrift::Deserialize<P> for U
where
    P: ::fbthrift::ProtocolReader,
{
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        static FIELDS: &[::fbthrift::Field] = &[
            ::fbthrift::Field::new("i", ::fbthrift::TType::I32, 1),
            ::fbthrift::Field::new("s", ::fbthrift::TType::String, 2),
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
                    alt = ::std::option::Option::Some(Self::i(::fbthrift::Deserialize::read(p)?));
                }
                (::fbthrift::TType::String, 2, false) => {
                    once = true;
                    alt = ::std::option::Option::Some(Self::s(::fbthrift::Deserialize::read(p)?));
                }
                (fty, _, false) => p.skip(fty)?,
                (badty, badid, true) => return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ProtocolError::UnwantedExtraUnionField(
                    "U".to_string(),
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

impl U {
    /// Return current union variant name as a tuple of (Rust name, original name).
    pub fn variant_name(&self) -> Option<(&'static str, &'static str)> {
        match self {
            Self::i(_) => Some(("i", "i")),
            Self::s(_) => Some(("s", "s")),
            Self::UnknownField(_) => None,
        }
    }
}

impl ::fbthrift::metadata::ThriftAnnotations for U {
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
            _ => {}
        }

        None
    }
}

#[allow(clippy::derivable_impls)]
impl ::std::default::Default for self::Bang {
    fn default() -> Self {
        Self {
            message: ::std::default::Default::default(),
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        }
    }
}

impl ::std::fmt::Debug for self::Bang {
    fn fmt(&self, formatter: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
        formatter
            .debug_struct("Bang")
            .field("message", &self.message)
            .finish()
    }
}

unsafe impl ::std::marker::Send for self::Bang {}
unsafe impl ::std::marker::Sync for self::Bang {}
impl ::std::marker::Unpin for self::Bang {}

impl ::fbthrift::GetTType for self::Bang {
    const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
}

impl<P> ::fbthrift::Serialize<P> for self::Bang
where
    P: ::fbthrift::ProtocolWriter,
{
    fn write(&self, p: &mut P) {
        p.write_struct_begin("Bang");
        p.write_field_begin("message", ::fbthrift::TType::String, 1);
        ::fbthrift::Serialize::write(&self.message, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P> ::fbthrift::Deserialize<P> for self::Bang
where
    P: ::fbthrift::ProtocolReader,
{
    fn read(p: &mut P) -> ::anyhow::Result<Self> {
        static FIELDS: &[::fbthrift::Field] = &[
            ::fbthrift::Field::new("message", ::fbthrift::TType::String, 1),
        ];
        let mut field_message = ::std::option::Option::None;
        let _ = p.read_struct_begin(|_| ())?;
        loop {
            let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
            match (fty, fid as ::std::primitive::i32) {
                (::fbthrift::TType::Stop, _) => break,
                (::fbthrift::TType::String, 1) => field_message = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                (fty, _) => p.skip(fty)?,
            }
            p.read_field_end()?;
        }
        p.read_struct_end()?;
        ::std::result::Result::Ok(Self {
            message: field_message.unwrap_or_default(),
            _dot_dot_Default_default: self::dot_dot::OtherFields(()),
        })
    }
}


impl ::fbthrift::metadata::ThriftAnnotations for Bang {
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
