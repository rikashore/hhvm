<?hh // strict
<<file: __EnableUnstableFeatures('coeffects_provisional')>>

<<__Rx>>
async function f(int $x)[rx]: Awaitable<int> {
  return $x;
}

<<__Rx>>
async function g(bool $x)[rx]: Awaitable<void> {
  // OK
  $a = await ($x ? f(1) : f(2));
}
