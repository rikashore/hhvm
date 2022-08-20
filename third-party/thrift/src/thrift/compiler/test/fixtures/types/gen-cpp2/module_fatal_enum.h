/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/types/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/types/gen-cpp2/module_fatal.h"

#include <fatal/type/enum.h>

#include <type_traits>

namespace apache { namespace thrift { namespace fixtures { namespace types {

namespace __fbthrift_refl {
namespace __fbthrift_refl_impl = ::apache::thrift::detail::reflection_impl;

class has_bitwise_ops_enum_traits {
 public:
  using type = ::apache::thrift::fixtures::types::has_bitwise_ops;

 private:
  struct __fbthrift_value_none {
    using name = __fbthrift_strings_module::__fbthrift_hash_140bedbf9c3f6d56a9846d2ba7088798683f4da0c248231336e6a05679e4fdfe;
    using value = std::integral_constant<type, type::none>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_value_zero {
    using name = __fbthrift_strings_module::__fbthrift_hash_f9194e73f9e9459e3450ea10a179cdf77aafa695beecd3b9344a98d111622243;
    using value = std::integral_constant<type, type::zero>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_value_one {
    using name = __fbthrift_strings_module::__fbthrift_hash_7692c3ad3540bb803c020b3aee66cd8887123234ea0c6e7143c0add73ff431ed;
    using value = std::integral_constant<type, type::one>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_value_two {
    using name = __fbthrift_strings_module::__fbthrift_hash_3fc4ccfe745870e2c0d99f71f30ff0656c8dedd41cc1d7d3d376b0dbe685e2f3;
    using value = std::integral_constant<type, type::two>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_value_three {
    using name = __fbthrift_strings_module::__fbthrift_hash_8b5b9db0c13db24256c829aa364aa90c6d2eba318b9232a4ab9313b954d3555f;
    using value = std::integral_constant<type, type::three>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_member {
    using none = __fbthrift_value_none;
    using zero = __fbthrift_value_zero;
    using one = __fbthrift_value_one;
    using two = __fbthrift_value_two;
    using three = __fbthrift_value_three;
  };

 public:
  using name = __fbthrift_strings_module::has_bitwise_ops;
  using member = __fbthrift_member;
  using fields = ::fatal::list<
      member::none,
      member::zero,
      member::one,
      member::two,
      member::three
  >;

  class annotations {
    struct __fbthrift_keys {
      using cpp_declare_bitwise_ops = __fbthrift_strings_module::cpp_declare_bitwise_ops;
    };

    struct __fbthrift_values {
      using cpp_declare_bitwise_ops = ::fatal::sequence<char, '1'>;
    };

   public:
    using keys = __fbthrift_keys;
    using values = __fbthrift_values;
    using map = ::fatal::list<
      ::apache::thrift::annotation<keys::cpp_declare_bitwise_ops, values::cpp_declare_bitwise_ops>
    >;
  };

  static char const *to_string(type e, char const *fallback) {
    switch (e) {
      case type::none: return "none";
      case type::zero: return "zero";
      case type::one: return "one";
      case type::two: return "two";
      case type::three: return "three";
      default: return fallback;
    }
  }
};

class is_unscoped_enum_traits {
 public:
  using type = ::apache::thrift::fixtures::types::is_unscoped;

 private:
  struct __fbthrift_value_hello {
    using name = __fbthrift_strings_module::__fbthrift_hash_2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824;
    using value = std::integral_constant<type, type::hello>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_value_world {
    using name = __fbthrift_strings_module::__fbthrift_hash_486ea46224d1bb4fb680f34f7c9ad96a8f24ec88be73ea8e5a6c65260e9cb8a7;
    using value = std::integral_constant<type, type::world>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_member {
    using hello = __fbthrift_value_hello;
    using world = __fbthrift_value_world;
  };

 public:
  using name = __fbthrift_strings_module::is_unscoped;
  using member = __fbthrift_member;
  using fields = ::fatal::list<
      member::hello,
      member::world
  >;

  class annotations {
    struct __fbthrift_keys {
      using cpp_deprecated_enum_unscoped = __fbthrift_strings_module::cpp_deprecated_enum_unscoped;
    };

    struct __fbthrift_values {
      using cpp_deprecated_enum_unscoped = ::fatal::sequence<char, '1'>;
    };

   public:
    using keys = __fbthrift_keys;
    using values = __fbthrift_values;
    using map = ::fatal::list<
      ::apache::thrift::annotation<keys::cpp_deprecated_enum_unscoped, values::cpp_deprecated_enum_unscoped>
    >;
  };

  static char const *to_string(type e, char const *fallback) {
    switch (e) {
      case type::hello: return "hello";
      case type::world: return "world";
      default: return fallback;
    }
  }
};

class MyForwardRefEnum_enum_traits {
 public:
  using type = ::apache::thrift::fixtures::types::MyForwardRefEnum;

 private:
  struct __fbthrift_value_ZERO {
    using name = __fbthrift_strings_module::__fbthrift_hash_2bf193b40158e8c527d83d622099b9e835d4eb8350c9fb51344aef93d5068fb4;
    using value = std::integral_constant<type, type::ZERO>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_value_NONZERO {
    using name = __fbthrift_strings_module::__fbthrift_hash_ce341f28cce92dd4aef1789ba556e94d03c552eb381fa789efc112a2a7b95913;
    using value = std::integral_constant<type, type::NONZERO>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_member {
    using ZERO = __fbthrift_value_ZERO;
    using NONZERO = __fbthrift_value_NONZERO;
  };

 public:
  using name = __fbthrift_strings_module::MyForwardRefEnum;
  using member = __fbthrift_member;
  using fields = ::fatal::list<
      member::ZERO,
      member::NONZERO
  >;

  using annotations = __fbthrift_refl_impl::no_annotations;

  static char const *to_string(type e, char const *fallback) {
    switch (e) {
      case type::ZERO: return "ZERO";
      case type::NONZERO: return "NONZERO";
      default: return fallback;
    }
  }
};

class MyEnumA_enum_traits {
 public:
  using type = ::apache::thrift::fixtures::types::MyEnumA;

 private:
  struct __fbthrift_value_fieldA {
    using name = __fbthrift_strings_module::__fbthrift_hash_a003c1938a10c7729197e235918bdad7bc795ec24b19f24c66e4f24374526ad8;
    using value = std::integral_constant<type, type::fieldA>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_value_fieldB {
    using name = __fbthrift_strings_module::__fbthrift_hash_c7e10d053d5c1a0a0743c1dfc0a38c439cd181cc30829f18cc684e286d0baf27;
    using value = std::integral_constant<type, type::fieldB>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_value_fieldC {
    using name = __fbthrift_strings_module::__fbthrift_hash_7a60aa9f6a5416b61206a441ce84695a835326c0edc0c9b86b92b618f29eb9ed;
    using value = std::integral_constant<type, type::fieldC>;
    using annotations = __fbthrift_refl_impl::no_annotations;
  };

  struct __fbthrift_member {
    using fieldA = __fbthrift_value_fieldA;
    using fieldB = __fbthrift_value_fieldB;
    using fieldC = __fbthrift_value_fieldC;
  };

 public:
  using name = __fbthrift_strings_module::MyEnumA;
  using member = __fbthrift_member;
  using fields = ::fatal::list<
      member::fieldA,
      member::fieldB,
      member::fieldC
  >;

  using annotations = __fbthrift_refl_impl::no_annotations;

  static char const *to_string(type e, char const *fallback) {
    switch (e) {
      case type::fieldA: return "fieldA";
      case type::fieldB: return "fieldB";
      case type::fieldC: return "fieldC";
      default: return fallback;
    }
  }
};

} // __fbthrift_refl

FATAL_REGISTER_ENUM_TRAITS(
  __fbthrift_refl::has_bitwise_ops_enum_traits,
  ::apache::thrift::detail::type_common_metadata_impl<
      module_tags::module,
      ::apache::thrift::reflected_annotations<__fbthrift_refl::has_bitwise_ops_enum_traits::annotations>,
      static_cast<::apache::thrift::legacy_type_id_t>(1216557680140306888ull)
  >
);
FATAL_REGISTER_ENUM_TRAITS(
  __fbthrift_refl::is_unscoped_enum_traits,
  ::apache::thrift::detail::type_common_metadata_impl<
      module_tags::module,
      ::apache::thrift::reflected_annotations<__fbthrift_refl::is_unscoped_enum_traits::annotations>,
      static_cast<::apache::thrift::legacy_type_id_t>(2509072249807621768ull)
  >
);
FATAL_REGISTER_ENUM_TRAITS(
  __fbthrift_refl::MyForwardRefEnum_enum_traits,
  ::apache::thrift::detail::type_common_metadata_impl<
      module_tags::module,
      ::apache::thrift::reflected_annotations<__fbthrift_refl::MyForwardRefEnum_enum_traits::annotations>,
      static_cast<::apache::thrift::legacy_type_id_t>(11057525912578401640ull)
  >
);
FATAL_REGISTER_ENUM_TRAITS(
  __fbthrift_refl::MyEnumA_enum_traits,
  ::apache::thrift::detail::type_common_metadata_impl<
      module_tags::module,
      ::apache::thrift::reflected_annotations<__fbthrift_refl::MyEnumA_enum_traits::annotations>,
      static_cast<::apache::thrift::legacy_type_id_t>(12764631319602759848ull)
  >
);
}}}} // apache::thrift::fixtures::types
