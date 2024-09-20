<?hh
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Original thrift service:-
 * PrimitivesService
 */
interface PrimitivesServiceAsyncIf extends \IThriftAsyncIf {
  /**
   * Original thrift definition:-
   * i64
   *   init(1: i64 param0,
   *        2: i64 param1);
   */
  public function init(int $param0, int $param1): Awaitable<int>;

  /**
   * Original thrift definition:-
   * Result
   *   method_that_throws()
   *   throws (1: CustomException e);
   */
  public function method_that_throws(): Awaitable<Result>;

  /**
   * Original thrift definition:-
   * void
   *   return_void_method(1: i64 id);
   */
  public function return_void_method(int $id): Awaitable<void>;
}

/**
 * Original thrift service:-
 * PrimitivesService
 */
interface PrimitivesServiceIf extends \IThriftSyncIf {
  /**
   * Original thrift definition:-
   * i64
   *   init(1: i64 param0,
   *        2: i64 param1);
   */
  public function init(int $param0, int $param1): int;

  /**
   * Original thrift definition:-
   * Result
   *   method_that_throws()
   *   throws (1: CustomException e);
   */
  public function method_that_throws(): Result;

  /**
   * Original thrift definition:-
   * void
   *   return_void_method(1: i64 id);
   */
  public function return_void_method(int $id): void;
}

/**
 * Original thrift service:-
 * PrimitivesService
 */
interface PrimitivesServiceAsyncClientIf extends PrimitivesServiceAsyncIf {
}

/**
 * Original thrift service:-
 * PrimitivesService
 */
interface PrimitivesServiceClientIf extends \IThriftSyncIf {
  /**
   * Original thrift definition:-
   * i64
   *   init(1: i64 param0,
   *        2: i64 param1);
   */
  public function init(int $param0, int $param1): Awaitable<int>;

  /**
   * Original thrift definition:-
   * Result
   *   method_that_throws()
   *   throws (1: CustomException e);
   */
  public function method_that_throws(): Awaitable<Result>;

  /**
   * Original thrift definition:-
   * void
   *   return_void_method(1: i64 id);
   */
  public function return_void_method(int $id): Awaitable<void>;
}

/**
 * Original thrift service:-
 * PrimitivesService
 */
trait PrimitivesServiceClientBase {
  require extends \ThriftClientBase;

}

class PrimitivesServiceAsyncClient extends \ThriftClientBase implements PrimitivesServiceAsyncClientIf {
  use PrimitivesServiceClientBase;

  /**
   * Original thrift definition:-
   * i64
   *   init(1: i64 param0,
   *        2: i64 param1);
   */
  public async function init(int $param0, int $param1): Awaitable<int> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = PrimitivesService_init_args::fromShape(shape(
      'param0' => $param0,
      'param1' => $param1,
    ));
    await $this->asyncHandler_->genBefore("PrimitivesService", "init", $args);
    $currentseqid = $this->sendImplHelper($args, "init", false, "PrimitivesService" );
    return await $this->genAwaitResponse(PrimitivesService_init_result::class, "init", false, $currentseqid, $rpc_options);
  }

  /**
   * Original thrift definition:-
   * Result
   *   method_that_throws()
   *   throws (1: CustomException e);
   */
  public async function method_that_throws(): Awaitable<Result> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = PrimitivesService_method_that_throws_args::withDefaultValues();
    await $this->asyncHandler_->genBefore("PrimitivesService", "method_that_throws", $args);
    $currentseqid = $this->sendImplHelper($args, "method_that_throws", false, "PrimitivesService" );
    return await $this->genAwaitResponse(PrimitivesService_method_that_throws_result::class, "method_that_throws", false, $currentseqid, $rpc_options);
  }

  /**
   * Original thrift definition:-
   * void
   *   return_void_method(1: i64 id);
   */
  public async function return_void_method(int $id): Awaitable<void> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = PrimitivesService_return_void_method_args::fromShape(shape(
      'id' => $id,
    ));
    await $this->asyncHandler_->genBefore("PrimitivesService", "return_void_method", $args);
    $currentseqid = $this->sendImplHelper($args, "return_void_method", false, "PrimitivesService" );
    await $this->genAwaitResponse(PrimitivesService_return_void_method_result::class, "return_void_method", true, $currentseqid, $rpc_options);
  }

}

class PrimitivesServiceClient extends \ThriftClientBase implements PrimitivesServiceClientIf {
  use PrimitivesServiceClientBase;

  /**
   * Original thrift definition:-
   * i64
   *   init(1: i64 param0,
   *        2: i64 param1);
   */
  public async function init(int $param0, int $param1): Awaitable<int> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = PrimitivesService_init_args::fromShape(shape(
      'param0' => $param0,
      'param1' => $param1,
    ));
    await $this->asyncHandler_->genBefore("PrimitivesService", "init", $args);
    $currentseqid = $this->sendImplHelper($args, "init", false, "PrimitivesService" );
    return await $this->genAwaitResponse(PrimitivesService_init_result::class, "init", false, $currentseqid, $rpc_options);
  }

  /**
   * Original thrift definition:-
   * Result
   *   method_that_throws()
   *   throws (1: CustomException e);
   */
  public async function method_that_throws(): Awaitable<Result> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = PrimitivesService_method_that_throws_args::withDefaultValues();
    await $this->asyncHandler_->genBefore("PrimitivesService", "method_that_throws", $args);
    $currentseqid = $this->sendImplHelper($args, "method_that_throws", false, "PrimitivesService" );
    return await $this->genAwaitResponse(PrimitivesService_method_that_throws_result::class, "method_that_throws", false, $currentseqid, $rpc_options);
  }

  /**
   * Original thrift definition:-
   * void
   *   return_void_method(1: i64 id);
   */
  public async function return_void_method(int $id): Awaitable<void> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = PrimitivesService_return_void_method_args::fromShape(shape(
      'id' => $id,
    ));
    await $this->asyncHandler_->genBefore("PrimitivesService", "return_void_method", $args);
    $currentseqid = $this->sendImplHelper($args, "return_void_method", false, "PrimitivesService" );
    await $this->genAwaitResponse(PrimitivesService_return_void_method_result::class, "return_void_method", true, $currentseqid, $rpc_options);
  }

  /* send and recv functions */
  public function send_init(int $param0, int $param1): int {
    $args = PrimitivesService_init_args::fromShape(shape(
      'param0' => $param0,
      'param1' => $param1,
    ));
    return $this->sendImplHelper($args, "init", false, "PrimitivesService" );
  }
  public function recv_init(?int $expectedsequenceid = null): int {
    return $this->recvImplHelper(PrimitivesService_init_result::class, "init", false, $expectedsequenceid);
  }
  public function send_method_that_throws(): int {
    $args = PrimitivesService_method_that_throws_args::withDefaultValues();
    return $this->sendImplHelper($args, "method_that_throws", false, "PrimitivesService" );
  }
  public function recv_method_that_throws(?int $expectedsequenceid = null): Result {
    return $this->recvImplHelper(PrimitivesService_method_that_throws_result::class, "method_that_throws", false, $expectedsequenceid);
  }
  public function send_return_void_method(int $id): int {
    $args = PrimitivesService_return_void_method_args::fromShape(shape(
      'id' => $id,
    ));
    return $this->sendImplHelper($args, "return_void_method", false, "PrimitivesService" );
  }
  public function recv_return_void_method(?int $expectedsequenceid = null): void {
    $this->recvImplHelper(PrimitivesService_return_void_method_result::class, "return_void_method", true, $expectedsequenceid);
  }
}

// HELPER FUNCTIONS AND STRUCTURES

class PrimitivesService_init_args implements \IThriftSyncStruct, \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
    1 => shape(
      'var' => 'param0',
      'type' => \TType::I64,
    ),
    2 => shape(
      'var' => 'param1',
      'type' => \TType::I64,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'param0' => 1,
    'param1' => 2,
  ];

  const type TConstructorShape = shape(
    ?'param0' => ?int,
    ?'param1' => ?int,
  );

  const int STRUCTURAL_ID = 4426064482866805446;
  public int $param0;
  public int $param1;

  public function __construct(?int $param0 = null, ?int $param1 = null)[] {
    $this->param0 = $param0 ?? 0;
    $this->param1 = $param1 ?? 0;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'param0'),
      Shapes::idx($shape, 'param1'),
    );
  }

  public function getName()[]: string {
    return 'PrimitivesService_init_args';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.init_args",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I64_TYPE,
                )
              ),
              "name" => "param0",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 2,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I64_TYPE,
                )
              ),
              "name" => "param1",
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

class PrimitivesService_init_result extends \ThriftSyncStructWithResult implements \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const type TResult = int;

  const \ThriftStructTypes::TSpec SPEC = dict[
    0 => shape(
      'var' => 'success',
      'type' => \TType::I64,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'success' => 0,
  ];

  const type TConstructorShape = shape(
    ?'success' => ?this::TResult,
  );

  const int STRUCTURAL_ID = 5548670328188446575;
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
    return 'PrimitivesService_init_result';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.PrimitivesService_init_result",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 0,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I64_TYPE,
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

class PrimitivesService_method_that_throws_args implements \IThriftSyncStruct, \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct()[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'PrimitivesService_method_that_throws_args';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.method_that_throws_args",
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

class PrimitivesService_method_that_throws_result extends \ThriftSyncStructWithResult implements \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const type TResult = Result;

  const \ThriftStructTypes::TSpec SPEC = dict[
    0 => shape(
      'var' => 'success',
      'type' => \TType::I32,
      'enum' => Result::class,
    ),
    1 => shape(
      'var' => 'e',
      'type' => \TType::STRUCT,
      'class' => CustomException::class,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'success' => 0,
    'e' => 1,
  ];

  const type TConstructorShape = shape(
    ?'success' => ?this::TResult,
    ?'e' => ?CustomException,
  );

  const int STRUCTURAL_ID = 8885166390166279584;
  public ?this::TResult $success;
  public ?CustomException $e;

  public function __construct(?this::TResult $success = null, ?CustomException $e = null)[] {
    $this->success = $success;
    $this->e = $e;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'success'),
      Shapes::idx($shape, 'e'),
    );
  }

  public function getName()[]: string {
    return 'PrimitivesService_method_that_throws_result';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.PrimitivesService_method_that_throws_result",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 0,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_enum" => tmeta_ThriftEnumType::fromShape(
                    shape(
                      "name" => "module.Result",
                    )
                  ),
                )
              ),
              "name" => "success",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_struct" => tmeta_ThriftStructType::fromShape(
                    shape(
                      "name" => "module.CustomException",
                    )
                  ),
                )
              ),
              "name" => "e",
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

  public function checkForException(): ?\TException {
    if ($this->e !== null) {
      return $this->e;
    }
    return null;
  }
  
  public function setException(\TException $e): bool {
    if ($e is CustomException) {
      $this->e = $e;
      return true;
    }
    return false;
  }
}

class PrimitivesService_return_void_method_args implements \IThriftSyncStruct, \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
    1 => shape(
      'var' => 'id',
      'type' => \TType::I64,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'id' => 1,
  ];

  const type TConstructorShape = shape(
    ?'id' => ?int,
  );

  const int STRUCTURAL_ID = 3807211151619655933;
  public int $id;

  public function __construct(?int $id = null)[] {
    $this->id = $id ?? 0;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'id'),
    );
  }

  public function getName()[]: string {
    return 'PrimitivesService_return_void_method_args';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.return_void_method_args",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I64_TYPE,
                )
              ),
              "name" => "id",
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

class PrimitivesService_return_void_method_result extends \ThriftSyncStructWithoutResult implements \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct()[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'PrimitivesService_return_void_method_result';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.PrimitivesService_return_void_method_result",
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

class PrimitivesServiceStaticMetadata implements \IThriftServiceStaticMetadata {
  public static function getServiceMetadata()[]: \tmeta_ThriftService {
    return tmeta_ThriftService::fromShape(
      shape(
        "name" => "module.PrimitivesService",
        "functions" => vec[
          tmeta_ThriftFunction::fromShape(
            shape(
              "name" => "init",
              "return_type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I64_TYPE,
                )
              ),
              "arguments" => vec[
                tmeta_ThriftField::fromShape(
                  shape(
                    "id" => 1,
                    "type" => tmeta_ThriftType::fromShape(
                      shape(
                        "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I64_TYPE,
                      )
                    ),
                    "name" => "param0",
                  )
                ),
                tmeta_ThriftField::fromShape(
                  shape(
                    "id" => 2,
                    "type" => tmeta_ThriftType::fromShape(
                      shape(
                        "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I64_TYPE,
                      )
                    ),
                    "name" => "param1",
                  )
                ),
              ],
            )
          ),
          tmeta_ThriftFunction::fromShape(
            shape(
              "name" => "method_that_throws",
              "return_type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_enum" => tmeta_ThriftEnumType::fromShape(
                    shape(
                      "name" => "module.Result",
                    )
                  ),
                )
              ),
              "exceptions" => vec[
                tmeta_ThriftField::fromShape(
                  shape(
                    "id" => 1,
                    "type" => tmeta_ThriftType::fromShape(
                      shape(
                        "t_struct" => tmeta_ThriftStructType::fromShape(
                          shape(
                            "name" => "module.CustomException",
                          )
                        ),
                      )
                    ),
                    "name" => "e",
                  )
                ),
              ],
            )
          ),
          tmeta_ThriftFunction::fromShape(
            shape(
              "name" => "return_void_method",
              "return_type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_VOID_TYPE,
                )
              ),
              "arguments" => vec[
                tmeta_ThriftField::fromShape(
                  shape(
                    "id" => 1,
                    "type" => tmeta_ThriftType::fromShape(
                      shape(
                        "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I64_TYPE,
                      )
                    ),
                    "name" => "id",
                  )
                ),
              ],
            )
          ),
        ],
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
                'name' => 'module',
              )
            ),
          )
        ),
        'metadata' => \tmeta_ThriftMetadata::fromShape(
          shape(
            'enums' => dict[
              'module.Result' => Result_TEnumStaticMetadata::getEnumMetadata(),
            ],
            'structs' => dict[
            ],
            'exceptions' => dict[
              'module.CustomException' => CustomException::getExceptionMetadata(),
            ],
            'services' => dict[
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

