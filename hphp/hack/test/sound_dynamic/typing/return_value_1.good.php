<?hh
// Copyright (c) Facebook, Inc. and its affiliates. All Rights Reserved.

class C<T> {}

class E {}

<<__SoundDynamicCallable>>
class D {
  public function foo(C<int> $x): ?E { return null; }
}
