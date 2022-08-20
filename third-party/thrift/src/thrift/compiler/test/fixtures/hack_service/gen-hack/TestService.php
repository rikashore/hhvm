<?hh
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

namespace hack_ns2;

/**
 * Original thrift service:-
 * TestService
 */
interface TestServiceAsyncIf extends \foo\hack_ns\FooHackServiceAsyncIf {
  /**
   * Original thrift definition:-
   * i32
   *   ping(1: string str_arg);
   */
  public function ping(string $str_arg): Awaitable<int>;
}

/**
 * Original thrift service:-
 * TestService
 */
interface TestServiceIf extends \foo\hack_ns\FooHackServiceIf {
  /**
   * Original thrift definition:-
   * i32
   *   ping(1: string str_arg);
   */
  public function ping(string $str_arg): int;
}

/**
 * Original thrift service:-
 * TestService
 */
interface TestServiceAsyncClientIf extends TestServiceAsyncIf, \foo\hack_ns\FooHackServiceAsyncClientIf {
}

/**
 * Original thrift service:-
 * TestService
 */
interface TestServiceClientIf extends \foo\hack_ns\FooHackServiceClientIf {
  /**
   * Original thrift definition:-
   * i32
   *   ping(1: string str_arg);
   */
  public function ping(string $str_arg): Awaitable<int>;
}

/**
 * Original thrift service:-
 * TestService
 */
trait TestServiceClientBase {
  require extends \ThriftClientBase;

}

class TestServiceAsyncClient extends \foo\hack_ns\FooHackServiceAsyncClient implements TestServiceAsyncClientIf {
  use TestServiceClientBase;

  /**
   * Original thrift definition:-
   * i32
   *   ping(1: string str_arg);
   */
  public async function ping(string $str_arg): Awaitable<int> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = \hack_ns2\TestService_ping_args::fromShape(shape(
      'str_arg' => $str_arg,
    ));
    await $this->asyncHandler_->genBefore("TestService", "ping", $args);
    $currentseqid = $this->sendImplHelper($args, "ping", false);
    return await $this->genAwaitResponse(\hack_ns2\TestService_ping_result::class, "ping", false, $currentseqid, $rpc_options);
  }

}

class TestServiceClient extends \foo\hack_ns\FooHackServiceClient implements TestServiceClientIf {
  use TestServiceClientBase;

  /**
   * Original thrift definition:-
   * i32
   *   ping(1: string str_arg);
   */
  public async function ping(string $str_arg): Awaitable<int> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = \hack_ns2\TestService_ping_args::fromShape(shape(
      'str_arg' => $str_arg,
    ));
    await $this->asyncHandler_->genBefore("TestService", "ping", $args);
    $currentseqid = $this->sendImplHelper($args, "ping", false);
    return await $this->genAwaitResponse(\hack_ns2\TestService_ping_result::class, "ping", false, $currentseqid, $rpc_options);
  }

  /* send and recv functions */
  public function send_ping(string $str_arg): int {
    $args = \hack_ns2\TestService_ping_args::fromShape(shape(
      'str_arg' => $str_arg,
    ));
    return $this->sendImplHelper($args, "ping", false);
  }
  public function recv_ping(?int $expectedsequenceid = null): int {
    return $this->recvImplHelper(\hack_ns2\TestService_ping_result::class, "ping", false, $expectedsequenceid);
  }
}

// HELPER FUNCTIONS AND STRUCTURES

class TestService_ping_args implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'str_arg',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'str_arg' => 1,
  ];

  const type TConstructorShape = shape(
    ?'str_arg' => ?string,
  );

  const int STRUCTURAL_ID = 5542358918184482101;
  public string $str_arg;

  public function __construct(?string $str_arg = null)[] {
    $this->str_arg = $str_arg ?? '';
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'str_arg'),
    );
  }

  public function getName()[]: string {
    return 'TestService_ping_args';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return \tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module2.ping_args",
        "fields" => vec[
          \tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "str_arg",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

class TestService_ping_result extends \ThriftSyncStructWithResult {
  use \ThriftSerializationTrait;

  const type TResult = int;

  const dict<int, this::TFieldSpec> SPEC = dict[
    0 => shape(
      'var' => 'success',
      'type' => \TType::I32,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'success' => 0,
  ];

  const type TConstructorShape = shape(
    ?'success' => ?this::TResult,
  );

  const int STRUCTURAL_ID = 3865318819874171525;
  public ?this::TResult $success;

  public function __construct(?this::TResult $success = null)[] {
    $this->success = $success;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'success'),
    );
  }

  public function getName()[]: string {
    return 'TestService_ping_result';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return \tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module2.TestService_ping_result",
        "fields" => vec[
          \tmeta_ThriftField::fromShape(
            shape(
              "id" => 0,
              "type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "name" => "success",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

class TestServiceStaticMetadata implements \IThriftServiceStaticMetadata {
  public static function getServiceMetadata()[]: \tmeta_ThriftService {
    return \tmeta_ThriftService::fromShape(
      shape(
        "name" => "module2.TestService",
        "functions" => vec[
          \tmeta_ThriftFunction::fromShape(
            shape(
              "name" => "ping",
              "return_type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "arguments" => vec[
                \tmeta_ThriftField::fromShape(
                  shape(
                    "id" => 1,
                    "type" => \tmeta_ThriftType::fromShape(
                      shape(
                        "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                      )
                    ),
                    "name" => "str_arg",
                  )
                ),
              ],
            )
          ),
        ],
        "parent" => "module.FooHackService",
      )
    );
  }

  public static function getServiceMetadataResponse()[]: \tmeta_ThriftServiceMetadataResponse {
    return \tmeta_ThriftServiceMetadataResponse::fromShape(
      shape(
        'context' => \tmeta_ThriftServiceContext::fromShape(
          shape(
            'service_info' => self::getServiceMetadata(),
            'module' => \tmeta_ThriftModuleContext::fromShape(
              shape(
                'name' => 'module2',
              )
            ),
          )
        ),
        'metadata' => \tmeta_ThriftMetadata::fromShape(
          shape(
            'enums' => dict[
            ],
            'structs' => dict[
            ],
            'exceptions' => dict[
            ],
            'services' => dict[
              'module.FooHackService' => \foo\hack_ns\FooHackServiceStaticMetadata::getServiceMetadata(),
            ],
          )
        ),
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TServiceAnnotations {
    return shape(
      'service' => dict[],
      'functions' => dict[
      ],
    );
  }
}

