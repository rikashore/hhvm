// @generated by Thrift for thrift/compiler/test/fixtures/types/src/module.thrift
// This file is probably not the place you want to edit!

#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies)]

pub use ::::mock::SomeService;

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

impl crate::DynClient for dyn ::::SomeService {
    type Mock<'mock> = ::::mock::SomeService::<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock> {
        <dyn ::::SomeService>::mock()
    }
}
