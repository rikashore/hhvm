/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <iterator>
#include <stdexcept>

#include <thrift/lib/cpp2/op/detail/BaseOp.h>
#include <thrift/lib/cpp2/type/Id.h>
#include <thrift/lib/cpp2/type/NativeType.h>
#include <thrift/lib/cpp2/type/Tag.h>
#include <thrift/lib/cpp2/type/ThriftType.h>
#include <thrift/lib/cpp2/type/detail/Runtime.h>
#include <thrift/lib/cpp2/type/detail/TypeInfo.h>

namespace apache {
namespace thrift {
namespace op {
namespace detail {

template <typename Tag>
struct ContainerOp : BaseOp<Tag> {
  using T = type::native_type<Tag>;
  using I = typename T::iterator;
  using Base = BaseOp<Tag>;
  using Base::ref;
  using Base::ret;

  static size_t size(const void* s) { return ref(s).size(); }

  static auto find(void* s, size_t pos) {
    if (pos >= ref(s).size()) {
      // TODO(afuller): Consider returning 'end' instead.
      folly::throw_exception<std::out_of_range>("out of range");
    }
    auto itr = ref(s).begin();
    std::advance(itr, pos);
    return itr;
  }

  // Get or begin iterator.
  static I& iter(T& self, std::any& i) {
    if (!i.has_value()) {
      i = self.begin();
    }
    return std::any_cast<I&>(i);
  }

  template <typename ITag>
  static Ptr next(ITag tag, T& self, std::any& i) {
    auto& itr = iter(self, i);
    if (itr != self.end()) {
      return ret(tag, *itr++);
    }
    return {};
  }
};

template <typename VTag, typename Tag = type::list<VTag>>
struct ListOp : ContainerOp<Tag> {
  using T = type::native_type<Tag>;
  using Base = ContainerOp<Tag>;
  using Base::check_op;
  using Base::find;
  using Base::next;
  using Base::ref;
  using Base::ret;
  using Base::unimplemented;

  template <typename V = type::native_type<VTag>>
  static void prepend(T& self, V&& val) {
    self.insert(self.begin(), std::forward<V>(val));
  }
  static void prepend(void* s, const Dyn& v) { prepend(ref(s), v.as<VTag>()); }
  template <typename V = type::native_type<VTag>>
  static void append(T& self, V&& val) {
    self.push_back(std::forward<V>(val));
  }
  static void append(void* s, const Dyn& v) { append(ref(s), v.as<VTag>()); }

  template <typename V = type::native_type<VTag>>
  [[noreturn]] static bool add(T&, V&&) {
    unimplemented(); // TODO(afuller): Add if not already present.
  }
  static bool add(void* s, const Dyn& v) { return add(ref(s), v.as<VTag>()); }

  template <typename U>
  static decltype(auto) get(U&& self, size_t pos) {
    return folly::forward_like<U>(self.at(pos));
  }

  static Ptr get(void* s, FieldId, size_t pos, const Dyn&) {
    check_op(pos != std::string::npos);
    return ret(VTag{}, *find(s, pos));
  }

  static Ptr next(void* s, IterType t, std::any& i) {
    check_op(t != IterType::Key);
    return next(VTag{}, ref(s), i);
  }
};

template <typename VTag>
struct AnyOp<type::list<VTag>> : ListOp<VTag> {};
template <typename T, typename VTag>
struct AnyOp<type::cpp_type<T, type::list<VTag>>>
    : ListOp<VTag, type::cpp_type<T, type::list<VTag>>> {};

template <typename KTag, typename Tag = type::set<KTag>>
struct SetOp : ContainerOp<Tag> {
  using T = type::native_type<Tag>;
  using Base = ContainerOp<Tag>;
  using Base::check_op;
  using Base::find;
  using Base::next;
  using Base::ref;
  using Base::ret;
  using Base::unimplemented;

  template <typename K = type::native_type<KTag>>
  static bool add(T& self, K&& key) {
    return self.insert(std::forward<K>(key)).second;
  }
  static bool add(void* s, const Dyn& k) { return add(ref(s), k.as<KTag>()); }

  template <typename K = type::native_type<KTag>>
  static bool contains(const T& self, K&& key) {
    return self.find(std::forward<K>(key)) != self.end();
  }
  [[noreturn]] static Ptr get(void*, FieldId, size_t, const Dyn&) {
    unimplemented(); // TODO(afuller): Get by key (aka contains/intern set).
  }

  static Ptr next(void* s, IterType t, std::any& i) {
    check_op(t != IterType::Value);
    return next(KTag{}, ref(s), i);
  }
};

template <typename KTag>
struct AnyOp<type::set<KTag>> : SetOp<KTag> {};

template <typename KTag, typename VTag, typename Tag = type::map<KTag, VTag>>
struct MapOp : ContainerOp<Tag> {
  using T = type::native_type<Tag>;
  using K = type::native_type<KTag>;
  using V = type::native_type<VTag>;
  using Base = ContainerOp<Tag>;
  using Base::bad_op;
  using Base::check_op;
  using Base::iter;
  using Base::ref;
  using Base::ret;
  using Base::unimplemented;

  template <typename J = K, typename U = V>
  static bool put(T& self, J&& key, U&& val) {
    auto itr = self.find(key);
    if (itr == self.end()) {
      self.emplace(std::forward<J>(key), std::forward<U>(val));
      return false; // new entry.`
    }
    itr->second = std::forward<U>(val);
    return true; // replacing existing.
  }

  template <typename J = K, typename U = V>
  static V& ensure(T& self, J&& key, U&& val) {
    auto itr = self.find(key);
    if (itr == self.end()) {
      itr = self.emplace(std::forward<J>(key), std::forward<U>(val)).first;
    }
    return itr->second;
  }

  static bool put(void* s, FieldId, const Dyn& k, const Dyn& v) {
    check_op(k != nullptr);
    return put(ref(s), k.as<KTag>(), v.as<VTag>());
  }

  static Ptr ensure(void* s, FieldId, const Dyn& k, const Dyn& v) {
    check_op(k != nullptr);
    if (v == nullptr) {
      return ret(VTag{}, ensure(ref(s), k.as<KTag>(), V{}));
    } else {
      return ret(VTag{}, ensure(ref(s), k.as<KTag>(), v.as<VTag>()));
    }
  }

  static Ptr get(void* s, FieldId, size_t, const Dyn& k) {
    if (k != nullptr) {
      return ret(VTag{}, ref(s).at(k.as<KTag>()));
    }
    bad_op();
  }

  static Ptr next(T& self, IterType type, typename T::iterator& itr) {
    if (itr == self.end()) {
      return {};
    }
    auto& entry = *itr++;
    switch (type) {
      case IterType::Key:
        return ret(KTag{}, entry.first);
      case IterType::Value:
        return ret(VTag{}, entry.second);
      case IterType::Default:
        unimplemented();
    }
  }

  static Ptr next(void* s, IterType type, std::any& i) {
    if (type == IterType::Default) {
      unimplemented(); // TODO(afuller): Key-value pair?
    }
    return next(ref(s), type, iter(ref(s), i));
  }
};

template <typename KTag, typename VTag>
struct AnyOp<type::map<KTag, VTag>> : MapOp<KTag, VTag> {};
template <typename T, typename KTag, typename VTag>
struct AnyOp<type::cpp_type<T, type::map<KTag, VTag>>>
    : MapOp<KTag, VTag, type::cpp_type<T, type::map<KTag, VTag>>> {};

} // namespace detail
} // namespace op
} // namespace thrift
} // namespace apache
