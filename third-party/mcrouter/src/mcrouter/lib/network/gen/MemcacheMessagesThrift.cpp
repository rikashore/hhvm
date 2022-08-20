/*
 *  Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#include "mcrouter/lib/network/gen/MemcacheMessages.h"

#include "mcrouter/lib/network/gen/gen-cpp2/Memcache_types.h"

namespace facebook {
namespace memcache {
namespace thrift {

void MemcacheRequestCommon::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(beforeLatencyUs_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(afterLatencyUs_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(bucketId_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McGetRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McGetReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McSetRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McSetReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McDeleteRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(attributes_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McDeleteReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McLeaseGetRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McLeaseGetReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(leaseToken_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 6: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McLeaseSetRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(leaseToken_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McLeaseSetReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McAddRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McAddReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McReplaceRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McReplaceReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McGetsRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McGetsReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(casToken_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 6: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McCasRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(casToken_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McCasReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McIncrRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(delta_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McIncrReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(delta_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McDecrRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(delta_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McDecrReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(delta_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McMetagetRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McMetagetReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(age_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(ipv_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(ipAddress_ref(), fieldType);
        break;
      }
      case 6: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 7: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McAppendRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McAppendReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McPrependRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McPrependReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McTouchRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McTouchReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McFlushReRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McFlushReReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McFlushAllRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(delay_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McFlushAllReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McGatRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McGatReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McGatsRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(memcacheRequestCommon, fieldType);
        break;
      }
      case 1: {
        reader.readField(exptime_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void McGatsReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(casToken_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(value_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(flags_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      case 6: {
        reader.readField(appSpecificErrorCode_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}
} // namespace thrift
} // namespace memcache
} // namespace facebook
