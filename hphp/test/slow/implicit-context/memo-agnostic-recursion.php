<?hh

function attr(): void{
  $x = TestContext::getContext();
  if ($x > 10) return;
  var_dump($x);
  TestContext::runWith($x+1, attr<>);
  var_dump(TestContext::getContext());
}

<<__EntryPoint>>
function main(): mixed{
  include 'memo-agnostic.inc';
  TestContext::runWith(0, attr<>);
}
