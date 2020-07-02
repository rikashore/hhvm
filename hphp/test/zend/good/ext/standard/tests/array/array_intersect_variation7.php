<?hh
/* Prototype  : array array_intersect(array $arr1, array $arr2 [, array $...])
 * Description: Returns the entries of arr1 that have values which are present in all the other arguments
 * Source code: ext/standard/array.c
*/

/*
 * Testing the functionality of array_intersect() by passing different
 * associative arrays having different possible values to $arr1 argument.
 * The $arr2 argument is a fixed array
*/

// get a class
class classA
{
  public function __toString(){
    return "Class A object";
  }
}
<<__EntryPoint>> function main(): void {
echo "*** Testing array_intersect() : assoc array with diff values to \$arr1 argument ***\n";

// get an unset variable
$unset_var = 10;
unset ($unset_var);

// get a resource variable
$fp = fopen(__FILE__, "r");

// get a heredoc string
$heredoc = <<<EOT
Hello world
EOT;

// different variations of associative arrays to be passed to $arr1 argument
$arrays = varray [

       // empty array
/*1*/  varray[],

       // arrays with integer values
       darray['0' => 0],
       darray["1" => 1],
       darray["one" => 1, 'two' => 2, "three" => 3, 4 => 4],

       // arrays with float values
/*5*/  darray["float" => 2.3333],
       darray["f1" => 1.2, 'f2' => 3.33, 3 => 4.89999922839999, 'f4' => 33333333.333333],

       // arrays with string values
/*7*/  darray[111 => "\tHello", "red" => "col\tor", 2 => "\v\fworld", 3 =>  "pen\n"],
       darray[111 => '\tHello', "red" => 'col\tor', 2 => '\v\fworld', 3 =>  'pen\n'],
       darray[1 => "hello", "heredoc" => $heredoc],

       // array with object, unset variable and resource variable
/*10*/ darray[11 => new classA(), "unset" => @$unset_var, "resource" => $fp],

       // array with mixed values
/*11*/ darray[1 => 'hello', 2 => new classA(), 222 => "fruit",
             'resource' => $fp, "int" => 133, "float" => 444.432,
             "unset" => @$unset_var, "heredoc" => $heredoc]
];

// array to be passsed to $arr2 argument
$arr2 = varray[1, 2, 1.2, 2.3333, "col\tor", '\v\fworld', $fp,
              "Hello world", $heredoc, new classA(), 444.432, "fruit"];

// loop through each sub-array within $arrrays to check the behavior of array_intersect()
$iterator = 1;
foreach($arrays as $arr1) {
  echo "-- Iterator $iterator --\n";

  // Calling array_intersect() with default arguments
  var_dump( array_intersect($arr1, $arr2) );

  // Calling array_intersect() with more arguments.
  // additional argument passed is the same as $arr1 argument
  var_dump( array_intersect($arr1, $arr2, $arr1) );
  $iterator++;
}

// close the file resource used
fclose($fp);

echo "Done";
}
