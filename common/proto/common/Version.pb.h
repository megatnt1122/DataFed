// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Version.proto
// Protobuf C++ Version: 4.25.2

#ifndef GOOGLE_PROTOBUF_INCLUDED_Version_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_Version_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025002 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_Version_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_Version_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_Version_2eproto;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

enum Version : int {
  DATAFED_RELEASE_YEAR = 2023,
  DATAFED_RELEASE_MONTH = 8,
  DATAFED_RELEASE_DAY = 21,
  DATAFED_RELEASE_HOUR = 10,
  DATAFED_RELEASE_MINUTE = 40,
  DATAFED_COMMON_PROTOCOL_API_MAJOR = 0,
  DATAFED_COMMON_PROTOCOL_API_MINOR = 0,
  DATAFED_COMMON_PROTOCOL_API_PATCH = 0,
};

bool Version_IsValid(int value);
extern const uint32_t Version_internal_data_[];
constexpr Version Version_MIN = static_cast<Version>(0);
constexpr Version Version_MAX = static_cast<Version>(2023);
constexpr int Version_ARRAYSIZE = 2023 + 1;
const ::google::protobuf::EnumDescriptor*
Version_descriptor();
template <typename T>
const std::string& Version_Name(T value) {
  static_assert(std::is_same<T, Version>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to Version_Name().");
  return ::google::protobuf::internal::NameOfEnum(Version_descriptor(), value);
}
inline bool Version_Parse(absl::string_view name, Version* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Version>(
      Version_descriptor(), name, value);
}

// ===================================================================



// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::Version> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::Version>() {
  return ::Version_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_Version_2eproto_2epb_2eh
