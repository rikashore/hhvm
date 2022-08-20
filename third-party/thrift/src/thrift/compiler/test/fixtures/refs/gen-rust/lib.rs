// @generated by Thrift for src/module.thrift
// This file is probably not the place you want to edit!

#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies, clippy::type_complexity)]

pub use self::consts::*;
pub use self::errors::*;
pub use self::types::*;

/// Constant definitions for `module`.
pub mod consts {
    pub static kStructWithRef: ::once_cell::sync::Lazy<crate::types::StructWithRef> = ::once_cell::sync::Lazy::new(|| crate::types::StructWithRef {
            def_field: crate::types::Empty {
                ..::std::default::Default::default()
            },
            opt_field: ::std::option::Option::Some(crate::types::Empty {
                ..::std::default::Default::default()
            }),
            req_field: crate::types::Empty {
                ..::std::default::Default::default()
            },
            ..::std::default::Default::default()
        });

    pub static kStructWithRefTypeUnique: ::once_cell::sync::Lazy<crate::types::StructWithRefTypeUnique> = ::once_cell::sync::Lazy::new(|| crate::types::StructWithRefTypeUnique {
            def_field: crate::types::Empty {
                ..::std::default::Default::default()
            },
            opt_field: ::std::option::Option::Some(crate::types::Empty {
                ..::std::default::Default::default()
            }),
            req_field: crate::types::Empty {
                ..::std::default::Default::default()
            },
            ..::std::default::Default::default()
        });

    pub static kStructWithRefTypeShared: ::once_cell::sync::Lazy<crate::types::StructWithRefTypeShared> = ::once_cell::sync::Lazy::new(|| crate::types::StructWithRefTypeShared {
            def_field: crate::types::Empty {
                ..::std::default::Default::default()
            },
            opt_field: ::std::option::Option::Some(crate::types::Empty {
                ..::std::default::Default::default()
            }),
            req_field: crate::types::Empty {
                ..::std::default::Default::default()
            },
            ..::std::default::Default::default()
        });

    pub static kStructWithRefTypeSharedConst: ::once_cell::sync::Lazy<crate::types::StructWithRefTypeSharedConst> = ::once_cell::sync::Lazy::new(|| crate::types::StructWithRefTypeSharedConst {
            def_field: crate::types::Empty {
                ..::std::default::Default::default()
            },
            opt_field: ::std::option::Option::Some(crate::types::Empty {
                ..::std::default::Default::default()
            }),
            req_field: crate::types::Empty {
                ..::std::default::Default::default()
            },
            ..::std::default::Default::default()
        });
}

pub mod types;

/// Error return types.
pub mod errors {
}
