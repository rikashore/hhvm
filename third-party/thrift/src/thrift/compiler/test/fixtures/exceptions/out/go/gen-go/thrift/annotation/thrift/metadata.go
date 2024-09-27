// Autogenerated by Thrift for thrift/annotation/thrift.thrift
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//  @generated

package thrift

import (
    "maps"

    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift/types"
    metadata "github.com/facebook/fbthrift/thrift/lib/thrift/metadata"
)

// (needed to ensure safety because of naive import list construction)
var _ = thrift.ZERO
var _ = maps.Copy[map[int]int, map[int]int]
var _ = metadata.GoUnusedProtection__

// Premade Thrift types
var (
    premadeThriftType_thrift_RpcPriority = metadata.NewThriftType().SetTEnum(
        metadata.NewThriftEnumType().
            SetName("thrift.RpcPriority"),
            )
    premadeThriftType_thrift_Experimental = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.Experimental"),
            )
    premadeThriftType_i32 = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_I32_TYPE.Ptr(),
            )
    premadeThriftType_list_i32 = metadata.NewThriftType().SetTList(
        metadata.NewThriftListType().
            SetValueType(premadeThriftType_i32),
            )
    premadeThriftType_map_i32_i32 = metadata.NewThriftType().SetTMap(
        metadata.NewThriftMapType().
            SetKeyType(premadeThriftType_i32).
            SetValueType(premadeThriftType_i32),
            )
    premadeThriftType_thrift_ReserveIds = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.ReserveIds"),
            )
    premadeThriftType_bool = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_BOOL_TYPE.Ptr(),
            )
    premadeThriftType_thrift_RequiresBackwardCompatibility = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.RequiresBackwardCompatibility"),
            )
    premadeThriftType_thrift_TerseWrite = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.TerseWrite"),
            )
    premadeThriftType_thrift_Box = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.Box"),
            )
    premadeThriftType_thrift_Mixin = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.Mixin"),
            )
    premadeThriftType_thrift_SerializeInFieldIdOrder = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.SerializeInFieldIdOrder"),
            )
    premadeThriftType_thrift_BitmaskEnum = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.BitmaskEnum"),
            )
    premadeThriftType_thrift_ExceptionMessage = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.ExceptionMessage"),
            )
    premadeThriftType_thrift_InternBox = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.InternBox"),
            )
    premadeThriftType_thrift_Serial = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.Serial"),
            )
    premadeThriftType_string = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_STRING_TYPE.Ptr(),
            )
    premadeThriftType_thrift_Uri = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.Uri"),
            )
    premadeThriftType_thrift_Priority = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.Priority"),
            )
    premadeThriftType_map_string_string = metadata.NewThriftType().SetTMap(
        metadata.NewThriftMapType().
            SetKeyType(premadeThriftType_string).
            SetValueType(premadeThriftType_string),
            )
    premadeThriftType_thrift_DeprecatedUnvalidatedAnnotations = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.DeprecatedUnvalidatedAnnotations"),
            )
    premadeThriftType_thrift_AllowReservedIdentifier = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.AllowReservedIdentifier"),
            )
    premadeThriftType_thrift_AllowReservedFilename = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("thrift.AllowReservedFilename"),
            )
)

var structMetadatas = []*metadata.ThriftStruct{
    metadata.NewThriftStruct().
    SetName("thrift.Experimental").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.ReserveIds").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("ids").
    SetIsOptional(false).
    SetType(premadeThriftType_list_i32),
            metadata.NewThriftField().
    SetId(2).
    SetName("id_ranges").
    SetIsOptional(false).
    SetType(premadeThriftType_map_i32_i32),
        },
    ),
    metadata.NewThriftStruct().
    SetName("thrift.RequiresBackwardCompatibility").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field_name").
    SetIsOptional(false).
    SetType(premadeThriftType_bool),
        },
    ),
    metadata.NewThriftStruct().
    SetName("thrift.TerseWrite").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.Box").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.Mixin").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.SerializeInFieldIdOrder").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.BitmaskEnum").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.ExceptionMessage").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.InternBox").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.Serial").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.Uri").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("value").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
        },
    ),
    metadata.NewThriftStruct().
    SetName("thrift.Priority").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("level").
    SetIsOptional(false).
    SetType(premadeThriftType_thrift_RpcPriority),
        },
    ),
    metadata.NewThriftStruct().
    SetName("thrift.DeprecatedUnvalidatedAnnotations").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("items").
    SetIsOptional(false).
    SetType(premadeThriftType_map_string_string),
        },
    ),
    metadata.NewThriftStruct().
    SetName("thrift.AllowReservedIdentifier").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("thrift.AllowReservedFilename").
    SetIsUnion(false),
}

var exceptionMetadatas = []*metadata.ThriftException{
}

var enumMetadatas = []*metadata.ThriftEnum{
    metadata.NewThriftEnum().
    SetName("thrift.RpcPriority").
    SetElements(
        map[int32]string{
            0: "HIGH_IMPORTANT",
            1: "HIGH",
            2: "IMPORTANT",
            3: "NORMAL",
            4: "BEST_EFFORT",
        },
    ),
}

var serviceMetadatas = []*metadata.ThriftService{
}

// GetThriftMetadata returns complete Thrift metadata for current and imported packages.
func GetThriftMetadata() *metadata.ThriftMetadata {
    allEnums := GetEnumsMetadata()
    allStructs := GetStructsMetadata()
    allExceptions := GetExceptionsMetadata()
    allServices := GetServicesMetadata()

    return metadata.NewThriftMetadata().
        SetEnums(allEnums).
        SetStructs(allStructs).
        SetExceptions(allExceptions).
        SetServices(allServices)
}

// GetEnumsMetadata returns Thrift metadata for enums in the current and recursively included packages.
func GetEnumsMetadata() map[string]*metadata.ThriftEnum {
    allEnumsMap := make(map[string]*metadata.ThriftEnum)

    // Add enum metadatas from the current program...
    for _, enumMetadata := range enumMetadatas {
        allEnumsMap[enumMetadata.GetName()] = enumMetadata
    }

    // ...now add enum metadatas from recursively included programs.

    return allEnumsMap
}

// GetStructsMetadata returns Thrift metadata for structs in the current and recursively included packages.
func GetStructsMetadata() map[string]*metadata.ThriftStruct {
    allStructsMap := make(map[string]*metadata.ThriftStruct)

    // Add struct metadatas from the current program...
    for _, structMetadata := range structMetadatas {
        allStructsMap[structMetadata.GetName()] = structMetadata
    }

    // ...now add struct metadatas from recursively included programs.

    return allStructsMap
}

// GetExceptionsMetadata returns Thrift metadata for exceptions in the current and recursively included packages.
func GetExceptionsMetadata() map[string]*metadata.ThriftException {
    allExceptionsMap := make(map[string]*metadata.ThriftException)

    // Add exception metadatas from the current program...
    for _, exceptionMetadata := range exceptionMetadatas {
        allExceptionsMap[exceptionMetadata.GetName()] = exceptionMetadata
    }

    // ...now add exception metadatas from recursively included programs.

    return allExceptionsMap
}

// GetServicesMetadata returns Thrift metadata for services in the current and recursively included packages.
func GetServicesMetadata() map[string]*metadata.ThriftService {
    allServicesMap := make(map[string]*metadata.ThriftService)

    // Add service metadatas from the current program...
    for _, serviceMetadata := range serviceMetadatas {
        allServicesMap[serviceMetadata.GetName()] = serviceMetadata
    }

    // ...now add service metadatas from recursively included programs.

    return allServicesMap
}

// GetThriftMetadataForService returns Thrift metadata for the given service.
func GetThriftMetadataForService(scopedServiceName string) *metadata.ThriftMetadata {
    thriftMetadata := GetThriftMetadata()

    allServicesMap := thriftMetadata.GetServices()
    relevantServicesMap := make(map[string]*metadata.ThriftService)

    serviceMetadata := allServicesMap[scopedServiceName]
    // Visit and record all recursive parents of the target service.
    for serviceMetadata != nil {
        relevantServicesMap[serviceMetadata.GetName()] = serviceMetadata
        if serviceMetadata.IsSetParent() {
            serviceMetadata = allServicesMap[serviceMetadata.GetParent()]
        } else {
            serviceMetadata = nil
        }
    }

    thriftMetadata.SetServices(relevantServicesMap)

    return thriftMetadata
}
