// @generated by Thrift for thrift/compiler/test/fixtures/rust-extra-derives/src/mod.thrift
// This file is probably not the place you want to edit!

#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies)]
#![doc(hidden)]


pub fn new<'mock, Client>() -> Client::Mock<'mock>
where
    Client: ?::std::marker::Sized + DynClient,
{
    Client::mock()
}

pub trait DynClient {
    type Mock<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock>;
}

