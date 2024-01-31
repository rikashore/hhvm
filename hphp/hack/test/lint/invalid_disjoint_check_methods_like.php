<?hh

class ExpectObj<T> {
  public function __construct(private T $item) { }
  public function isEqual<<<__NonDisjoint>> T1, <<__NonDisjoint>> T2>(T2 $other):bool where T = T1 {
    return $this->item === $other;
  }
}

<<__NoAutoLikes>>
function expect<T>(T $x):ExpectObj<T> {
  return new ExpectObj($x);
}

function get_vec_like_int():vec<~int> {
  return vec[\HH\FIXME\UNSAFE_CAST<string, int>("A")];
}

function test_expect2():void {
  $like_int = get_vec_like_int()[0];
  // Call through a like-type receiver
  $a = expect($like_int)->isEqual("A");
  // Call with a like-type argument
  $b = expect("A")->isEqual($like_int);
}
