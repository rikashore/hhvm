// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

use std::fmt;

use anyhow::Error;
use once_cell::sync::OnceCell;
use strum::EnumProperty as _;
use strum_macros::EnumIter;
use strum_macros::EnumProperty;

use crate::mangle::MangleWithClass as _;
use crate::textual;
use crate::textual::Sid;

const BUILTINS_CLASS: ir::ClassName<'static> = ir::ClassName::new(ffi::Str::new(b"$builtins"));

type Result<T = (), E = Error> = std::result::Result<T, E>;

/// These represent builtins for handling HHVM bytecode instructions. In general
/// the names should match the HHBC name except when they are compound bytecodes
/// (like Cmp with a parameter of Eq becoming CmpEq). Documentation can be found
/// in hphp/doc/bytecode.specification.
#[derive(Copy, Clone, EnumIter, EnumProperty)]
pub(crate) enum Hhbc {
    #[strum(props(Function = "hhbc_add"))]
    Add,
    #[strum(props(Function = "hhbc_cmp_eq"))]
    CmpEq,
    #[strum(props(Function = "hhbc_cmp_gt"))]
    CmpGt,
    #[strum(props(Function = "hhbc_cmp_gte"))]
    CmpGte,
    #[strum(props(Function = "hhbc_cmp_lt"))]
    CmpLt,
    #[strum(props(Function = "hhbc_cmp_lte"))]
    CmpLte,
    #[strum(props(Function = "hhbc_cmp_nsame"))]
    CmpNSame,
    #[strum(props(Function = "hhbc_cmp_neq"))]
    CmpNeq,
    #[strum(props(Function = "hhbc_cmp_same"))]
    CmpSame,
    #[strum(props(Function = "hhbc_concat"))]
    Concat,
    #[strum(props(Function = "hhbc_div"))]
    Div,
    #[strum(props(Function = "hhbc_exit"))]
    Exit,
    #[strum(props(Function = "hhbc_is_type_int"))]
    IsTypeInt,
    #[strum(props(Function = "hhbc_is_type_null"))]
    IsTypeNull,
    #[strum(props(Function = "hhbc_is_type_str"))]
    IsTypeStr,
    #[strum(props(Function = "hhbc_modulo"))]
    Modulo,
    #[strum(props(Function = "hhbc_mul"))]
    Mul,
    #[strum(props(Function = "hhbc_new_obj"))]
    NewObj,
    #[strum(props(Function = "hhbc_new_vec"))]
    NewVec,
    #[strum(props(Function = "hhbc_not"))]
    Not,
    #[strum(props(Function = "hhbc_print"))]
    Print,
    #[strum(props(Function = "hhbc_sub"))]
    Sub,
    #[strum(props(Function = "hhbc_throw"))]
    Throw,
    #[strum(props(Function = "hhbc_verify_failed"))]
    VerifyFailed,
}

// Need Default for EnumIter on Builtin
impl std::default::Default for Hhbc {
    fn default() -> Self {
        Hhbc::Add
    }
}

#[derive(EnumIter, EnumProperty)]
pub(crate) enum Builtin {
    /// Allocate an array with the given number of words (a word is a
    /// pointer-sized value).
    ///   AllocWords(int) -> *void
    #[strum(props(Function = "alloc_words"))]
    AllocWords,
    /// Throws a BadMethodCall exception.
    ///   BadMethodCall() -> noreturn
    #[strum(props(Function = "hack_bad_method_call"))]
    BadMethodCall,
    /// Throws a BadProperty exception.
    ///   BadProperty() -> noreturn
    #[strum(props(Function = "hack_bad_property"))]
    BadProperty,
    /// Turns a raw boolean into a HackMixed.
    ///   Bool(n: bool) -> *HackMixed
    #[strum(props(Function = "hack_bool"))]
    Bool,
    /// Turns a raw float into a Mixed.
    ///   Float(f: float) -> *Mixed
    #[strum(props(Function = "hack_float"))]
    Float,
    /// Returns the Class identifier for the given class.
    #[strum(props(Function = "hack_get_class"))]
    GetClass,
    /// Returns the Class identifier for the given class's static class.
    #[strum(props(Function = "hack_get_static_class"))]
    GetStaticClass,
    /// Hhbc handlers.  See hphp/doc/bytecode.specification for docs.
    Hhbc(Hhbc),
    /// Turns a raw int into a HackMixed.
    ///   Int(n: int) -> *HackMixed
    #[strum(props(Function = "hack_int"))]
    Int,
    /// Returns true if the given HackMixed is truthy.
    ///   IsTrue(p: *HackMixed) -> bool
    #[strum(props(Function = "hack_is_true"))]
    IsTrue,
    /// Returns true if the given HackMixed is of the named type.
    ///   IsType(p: *HackMixed, t: *string) -> bool
    #[strum(props(Function = "hack_is_type"))]
    IsType,
    /// Returns a HackMixed containing a `null`.
    ///   Null() -> *HackMixed
    #[strum(props(Function = "hack_null"))]
    Null,
    /// Returns true if the given raw pointer is null.
    ///   RawPtrIsNull(*void) -> bool
    #[strum(props(Function = "raw_ptr_is_null"))]
    RawPtrIsNull,
    /// Lazily initializes a static singleton.
    ///   lazy_initialize(*HackMixed)
    #[strum(props(Function = "lazy_initialize"))]
    SilLazyInitialize,
    /// Turns a raw string into a HackMixed.
    ///   String(s: *string) -> *HackMixed
    #[strum(props(Function = "hack_string"))]
    String,
    /// Used to check param count on function entry.
    ///   VerifyParamCount(params, min, max)
    #[strum(props(Function = "verify_param_count"))]
    VerifyParamCount,
}

impl fmt::Display for Builtin {
    fn fmt(&self, w: &mut fmt::Formatter<'_>) -> fmt::Result {
        static DUMMY: OnceCell<ir::StringInterner> = OnceCell::new();
        let strings = DUMMY.get_or_init(Default::default);

        let name = match self {
            Builtin::Hhbc(hhbc) => hhbc.get_str("Function").unwrap(),
            _ => self.get_str("Function").unwrap(),
        };
        let method = ir::MethodName::new(ffi::Str::new(name.as_bytes()));
        // Use a dummy string table - this is fine because builtins will never
        // be based on the UnitBytesId.
        w.write_str(&method.mangle(&BUILTINS_CLASS, strings))
    }
}

pub(crate) fn call_builtin(
    w: &mut textual::FuncWriter<'_>,
    target: Builtin,
    params: impl textual::VarArgs,
) -> Result<Sid> {
    w.call(&target.to_string(), params)
}

pub(crate) fn expr_builtin(target: Builtin, params: impl textual::VarArgs) -> textual::Expr {
    textual::Expr::call(target.to_string(), params)
}
