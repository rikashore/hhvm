/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

include "thrift/annotation/cpp.thrift"
include "thrift/annotation/thrift.thrift"
cpp_include "thrift/test/AdapterTest.h"

package "apache.org/thrift/test"

struct Foo {
  1: i32 field1;
  3: i32 field2;
}

struct Bar {
  // The field id is intentionally flipped to test if the methods use field id
  // and ordinal correctly.
  2: list<Foo> foos;
  1: Foo foo;
}

struct Baz {
  @cpp.Adapter{name = "TemplatedTestAdapter"}
  1: Foo foo;
}

struct Foo2 {
  1: optional i32 field_1;
  2: optional i32 field_2;
}

struct Bar2 {
  1: optional Foo2 field_3;
  2: string field_4;
}

struct CustomDefault {
  1: string field = "default";
}

@thrift.TerseWrite
struct TerseWrite {
  1: i32 field;
  2: Foo foo;
}

struct SmartPointerStruct {
  @cpp.Ref{type = cpp.RefType.Unique}
  1: optional Foo2 unique;
  @cpp.Ref{type = cpp.RefType.SharedMutable}
  2: optional Foo2 shared;
  @thrift.Box
  3: optional Foo2 boxed;
}
