<?hh

function make_pair<T1,T2>(T1 $x, T2 $y):(T1,T2) {
  return tuple($x, $y);
}

function testit():void {
  $f = make_pair<>;
  ($f)(5,"A");
  //^ hover-at-caret
}
