<?hh <<__EntryPoint>> function main(): void {
var_dump(filter_var("  234", FILTER_VALIDATE_INT));
var_dump(filter_var("234    ", FILTER_VALIDATE_INT));
var_dump(filter_var("  234  ", FILTER_VALIDATE_INT));
var_dump(filter_var("0xff", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("0Xff", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("0xFF", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("0XFF", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("07", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_OCTAL]));
var_dump(filter_var("0xff0000", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("0666", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_OCTAL]));
var_dump(filter_var("08", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_OCTAL]));
var_dump(filter_var("00", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_OCTAL]));
var_dump(filter_var("000", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_OCTAL]));

var_dump(filter_var("-0xff", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("-0Xff", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("-0xFF", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("-0XFF", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("-07", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_OCTAL]));
var_dump(filter_var("-0xff0000", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_HEX]));
var_dump(filter_var("-0666", FILTER_VALIDATE_INT, dict["flags"=>FILTER_FLAG_ALLOW_OCTAL]));

var_dump(filter_var("6", FILTER_VALIDATE_INT, dict["options" => dict["min_range"=>1, "max_range"=>7]]));
var_dump(filter_var("6", FILTER_VALIDATE_INT, dict["options" => dict["min_range"=>0, "max_range"=>5]]));
var_dump(filter_var(-1, FILTER_VALIDATE_INT, dict["options" => dict["min_range"=>1, "max_range"=>7]]));
var_dump(filter_var(-1, FILTER_VALIDATE_INT, dict["options" => dict["min_range"=>-4, "max_range"=>7]]));

var_dump(filter_var("", FILTER_VALIDATE_INT, dict["options" => dict["min_range"=>-4, "max_range"=>7]]));
var_dump(filter_var("", FILTER_VALIDATE_INT, dict["options" => dict["min_range"=>2, "max_range"=>7]]));
var_dump(filter_var("", FILTER_VALIDATE_INT, dict["options" => dict["min_range"=>-5, "max_range"=>-3]]));
var_dump(filter_var(345, FILTER_VALIDATE_INT, dict["options" => dict["min_range"=>500, "max_range"=>100]]));
var_dump(filter_var("0ff", FILTER_VALIDATE_INT));
var_dump(filter_var("010", FILTER_VALIDATE_INT));

echo "Done\n";
}
