<?hh

type ExprTreeInfo<TInfer> = shape(
  'splices' => dict<string, mixed>,
  'functions' => vec<mixed>,
  'static_methods' => vec<mixed>,
  ?'type' => (function (): TInfer),
);

function concat_arg_list(vec<string> $args): string {
  return implode(",", $args);
}

function concat_block(vec<string> $block): string {
  return implode("\n", $block);
}

class ExampleDsl {
  const type TAst = string;

    // Virtual types (These do not have to be implemented)
  public static function intType()[]: ExampleInt {
    throw new Exception();
  }
  public static function floatType(): ExampleFloat {
    throw new Exception();
  }
  public static function boolType(): ExampleBool {
    throw new Exception();
  }
  public static function stringType(): ExampleString {
    throw new Exception();
  }
  public static function nullType(): null {
    throw new Exception();
  }
  public static function voidType(): ExampleVoid {
    throw new Exception();
  }
  public static function symbolType<T>(
    (function(ExampleContext): Awaitable<ExprTree<ExampleDsl, ExampleDsl::TAst, T>>) $_,
  ): T {
    throw new Exception();
  }

  public static function makeTree<TVisitor as ExampleDsl, TInfer>(
    ?ExprPos $pos,
    ExprTreeInfo<TInfer> $metadata,
    (function(TVisitor): ExampleDsl::TAst) $ast,
  ): ExprTree<TVisitor, ExampleDsl::TAst, TInfer> {
    return new ExprTree($pos, $metadata, $ast);
  }

  // Desugared nodes (These should be implemented)
  public function visitInt(?ExprPos $_, int $i): string {
    return (string)$i;
  }
  public function visitFloat(?ExprPos $_, float $f): string {
    return (string)$f;
  }
  public function visitBool(?ExprPos $_, bool $b): string {
    return $b ? "true" : "false";
  }
  public function visitString(?ExprPos $_, string $s): string {
    return "\"$s\"";
  }
  public function visitNull(?ExprPos $_): string {
    return "null";
  }

  public function visitGlobalFunction<T>(
    ?ExprPos $_,
    (function(ExampleContext): Awaitable<ExprTree<ExampleDsl, ExampleDsl::TAst, T>>) $_,
  ): ExampleDsl::TAst {
    return "function_ptr";
  }

  public function visitStaticMethod<T>(
    ?ExprPos $_,
    (function(ExampleContext): Awaitable<ExprTree<ExampleDsl, ExampleDsl::TAst, T>>) $_,
  ): ExampleDsl::TAst {
    return "function_ptr";
  }

  // Expressions
  public function visitLocal(?ExprPos $_, string $local): ExampleDsl::TAst {
    return $local;
  }

  public function visitLambda(
    ?ExprPos $_,
    vec<string> $args,
    vec<ExampleDsl::TAst> $body,
    ?vec<Code::TAst> $_optional_params,
  ): ExampleDsl::TAst {
    return "(".concat_arg_list($args).")"." ==> {\n".concat_block($body)."}";
  }

  // New operators
  public function visitBinop(
    ?ExprPos $_,
    string $lhs,
    string $op,
    string $rhs,
  ): string {
    return "$lhs $op $rhs";
  }

  public function visitUnop(
    ?ExprPos $_,
    string $op,
    string $operand,
  ): string {
    return "$op $operand";
  }

  public function visitInstanceMethod(
    ?ExprPos $_,
    ExampleDsl::TAst $expr,
    string $method,
  ): ExampleDsl::TAst {
    return "$expr->$method";
  }

  public function visitCall<T>(
    ?ExprPos $_,
    ExampleDsl::TAst $callee,
    vec<ExampleDsl::TAst> $args,
  ): ExampleDsl::TAst {
    return $callee."(".concat_arg_list($args).")";
  }

  public function visitAssign(
    ?ExprPos $_,
    ExampleDsl::TAst $local,
    ExampleDsl::TAst $value,
  ): ExampleDsl::TAst {
    return $local." = ".$value.";";
  }

  public function visitTernary(
    ?ExprPos $_,
    ExampleDsl::TAst $condition,
    ?ExampleDsl::TAst $truthy,
    ExampleDsl::TAst $falsy,
  ): ExampleDsl::TAst {
    return $condition." ? ".$truthy." : ".$falsy;
  }

  public function visitOptionalParameter(
    ?ExprPos $_,
    string $name,
    Code::TAst $arg,
  ): Code::TAst {
    return $name." ".$arg;
  }

  public function visitIf(
    ?ExprPos $_,
    ExampleDsl::TAst $cond,
    vec<ExampleDsl::TAst> $then_body,
    vec<ExampleDsl::TAst> $else_body,
  ): ExampleDsl::TAst {
    return "if (".
      $cond.
      ") {\n".
      concat_block($then_body).
      "} else {\n".
      concat_block($else_body).
      "}";
  }

  public function visitWhile(
    ?ExprPos $_,
    ExampleDsl::TAst $cond,
    vec<ExampleDsl::TAst> $body,
  ): ExampleDsl::TAst {
    return "while (".$cond.") {\n".concat_block($body)."}";
  }

  public function visitReturn(?ExprPos $_, ?ExampleDsl::TAst $return_val): ExampleDsl::TAst {
    if ($return_val is null) {
      return "return;";
    }
    return "return ".$return_val.";";
  }

  public function visitFor(
    ?ExprPos $_,
    vec<ExampleDsl::TAst> $initializers,
    ?ExampleDsl::TAst $cond,
    vec<ExampleDsl::TAst> $increments,
    vec<ExampleDsl::TAst> $body,
  ): ExampleDsl::TAst {
    return "for (".
      concat_arg_list($initializers).
      ";".
      ($cond ?? "").
      ";".
      concat_arg_list($increments).
      ") {\n".
      concat_block($body).
      "}";
  }

  public function visitBreak(?ExprPos $_): ExampleDsl::TAst {
    return "break;";
  }

  public function visitContinue(?ExprPos $_): ExampleDsl::TAst {
    return "continue;";
  }

  public function visitXhp(
    ?ExprPos $_,
    string $class_name,
    dict<string, ExampleDsl::TAst> $attrs,
    vec<ExampleDsl::TAst> $children,
  )[]: ExampleDsl::TAst {
    $attr_parts = vec[];
    foreach ($attrs as $name => $value) {
      $attr_parts[] = $name."=".$value;
    }
    $attr_string = implode(" ", $attr_parts);

    return "<".
      $class_name.
      " ".
      $attr_string.
      ">\n".
      concat_block($children).
      "\n</".
      $class_name.
      ">";
  }

   public function visitKeyedCollection(
    ?ExprPos $_,
    string $collection,
    (ExampleDsl::TAst, ExampleDsl::TAst) ...$operand
   ): ExampleDsl::TAst {
   $v = HH\Lib\Vec\map($operand, $kv ==> $kv[0]."=>".$kv[1]);
   return "$collection {".concat_arg_list($v)."}";
  }

  // Splice
  public function splice<T>(
    ?ExprPos $_,
    string $_key,
    Spliceable<ExampleDsl, ExampleDsl::TAst, T> $splice_val,
  ): ExampleDsl::TAst {
    return "\${".($splice_val->visit($this))."}";
  }
}

interface Spliceable<TVisitor, TResult, +TInfer> {
  public function visit(TVisitor $v): TResult;
}

final class ExprTree<TVisitor, TResult, +TInfer>
  implements Spliceable<TVisitor, TResult, TInfer> {
  public function __construct(
    private ?ExprPos $pos,
    private ExprTreeInfo<TInfer> $metadata,
    private (function(TVisitor): TResult) $ast,
  ) {}

  public function visit(TVisitor $v): TResult {
    return ($this->ast)($v);
  }

  public function getExprPos(): ?ExprPos {
    return $this->pos;
  }

  public function getSplices(): dict<string, mixed> {
    return $this->metadata['splices'];
  }
}

type ExprPos = shape(...);

abstract class ExampleMixed {
  public abstract function __tripleEquals(ExampleMixed $_): ExampleBool;
  public abstract function __notTripleEquals(ExampleMixed $_): ExampleBool;
}
abstract class ExampleInt extends ExampleMixed {
  public abstract function __plus(ExampleInt $_): ExampleInt;
  public abstract function __minus(ExampleInt $_): ExampleInt;
  public abstract function __star(ExampleInt $_): ExampleInt;
  public abstract function __slash(ExampleInt $_): ExampleInt;
  public abstract function __percent(ExampleInt $_): ExampleInt;
  public abstract function __negate(): ExampleInt;

  public abstract function __lessThan(ExampleInt $_): ExampleBool;
  public abstract function __lessThanEqual(ExampleInt $_): ExampleBool;
  public abstract function __greaterThan(ExampleInt $_): ExampleBool;
  public abstract function __greaterThanEqual(ExampleInt $_): ExampleBool;

  public abstract function __amp(ExampleInt $_): ExampleInt;
  public abstract function __bar(ExampleInt $_): ExampleInt;
  public abstract function __caret(ExampleInt $_): ExampleInt;
  public abstract function __lessThanLessThan(ExampleInt $_): ExampleInt;
  public abstract function __greaterThanGreaterThan(ExampleInt $_): ExampleInt;
  public abstract function __tilde(): ExampleInt;
}

abstract class ExampleBool extends ExampleMixed {
  public abstract function __ampamp(ExampleBool $_): ExampleBool;
  public abstract function __barbar(ExampleBool $_): ExampleBool;
  public abstract function __bool(): bool;
  public abstract function __exclamationMark(): ExampleBool;
}

abstract class ExampleString extends ExampleMixed {
  public abstract function __dot(ExampleString $_): ExampleString;
}

abstract class ExampleFloat extends ExampleMixed {}

abstract class ExampleVoid extends ExampleMixed {}

final class ExampleContext {}

function print_et<TInfer>(ExprTree<ExampleDsl, ExampleDsl::TAst, TInfer> $et): void {
  $visitor = new ExampleDsl();
  $string = $et->visit($visitor);
  echo($string."\n");
}
