// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/client.proto

#include "proto/client.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace proto {
PROTOBUF_CONSTEXPR ClientReadRequest::ClientReadRequest(
    ::_pbi::ConstantInitialized)
  : rows_()
  , client_ip_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , txn_id_(uint64_t{0u}){}
struct ClientReadRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ClientReadRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ClientReadRequestDefaultTypeInternal() {}
  union {
    ClientReadRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ClientReadRequestDefaultTypeInternal _ClientReadRequest_default_instance_;
PROTOBUF_CONSTEXPR ClientReadResponse::ClientReadResponse(
    ::_pbi::ConstantInitialized)
  : rows_()
  , txn_id_(uint64_t{0u})
  , result_(0)
{}
struct ClientReadResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ClientReadResponseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ClientReadResponseDefaultTypeInternal() {}
  union {
    ClientReadResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ClientReadResponseDefaultTypeInternal _ClientReadResponse_default_instance_;
}  // namespace proto
static ::_pb::Metadata file_level_metadata_proto_2fclient_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_proto_2fclient_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_proto_2fclient_2eproto = nullptr;

const uint32_t TableStruct_proto_2fclient_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::proto::ClientReadRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::proto::ClientReadRequest, client_ip_),
  PROTOBUF_FIELD_OFFSET(::proto::ClientReadRequest, txn_id_),
  PROTOBUF_FIELD_OFFSET(::proto::ClientReadRequest, rows_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::proto::ClientReadResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::proto::ClientReadResponse, result_),
  PROTOBUF_FIELD_OFFSET(::proto::ClientReadResponse, txn_id_),
  PROTOBUF_FIELD_OFFSET(::proto::ClientReadResponse, rows_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::proto::ClientReadRequest)},
  { 9, -1, -1, sizeof(::proto::ClientReadResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::proto::_ClientReadRequest_default_instance_._instance,
  &::proto::_ClientReadResponse_default_instance_._instance,
};

const char descriptor_table_protodef_proto_2fclient_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022proto/client.proto\022\005proto\032\027proto/trans"
  "action.proto\032\020proto/node.proto\"P\n\021Client"
  "ReadRequest\022\021\n\tclient_ip\030\001 \001(\t\022\016\n\006txn_id"
  "\030\002 \001(\004\022\030\n\004rows\030\003 \003(\0132\n.proto.Row\"]\n\022Clie"
  "ntReadResponse\022\035\n\006result\030\001 \001(\0162\r.proto.R"
  "esult\022\016\n\006txn_id\030\002 \001(\004\022\030\n\004rows\030\003 \003(\0132\n.pr"
  "oto.Rowb\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_proto_2fclient_2eproto_deps[2] = {
  &::descriptor_table_proto_2fnode_2eproto,
  &::descriptor_table_proto_2ftransaction_2eproto,
};
static ::_pbi::once_flag descriptor_table_proto_2fclient_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_proto_2fclient_2eproto = {
    false, false, 255, descriptor_table_protodef_proto_2fclient_2eproto,
    "proto/client.proto",
    &descriptor_table_proto_2fclient_2eproto_once, descriptor_table_proto_2fclient_2eproto_deps, 2, 2,
    schemas, file_default_instances, TableStruct_proto_2fclient_2eproto::offsets,
    file_level_metadata_proto_2fclient_2eproto, file_level_enum_descriptors_proto_2fclient_2eproto,
    file_level_service_descriptors_proto_2fclient_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_proto_2fclient_2eproto_getter() {
  return &descriptor_table_proto_2fclient_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_proto_2fclient_2eproto(&descriptor_table_proto_2fclient_2eproto);
namespace proto {

// ===================================================================

class ClientReadRequest::_Internal {
 public:
};

void ClientReadRequest::clear_rows() {
  rows_.Clear();
}
ClientReadRequest::ClientReadRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  rows_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:proto.ClientReadRequest)
}
ClientReadRequest::ClientReadRequest(const ClientReadRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      rows_(from.rows_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  client_ip_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    client_ip_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_client_ip().empty()) {
    client_ip_.Set(from._internal_client_ip(), 
      GetArenaForAllocation());
  }
  txn_id_ = from.txn_id_;
  // @@protoc_insertion_point(copy_constructor:proto.ClientReadRequest)
}

inline void ClientReadRequest::SharedCtor() {
client_ip_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  client_ip_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
txn_id_ = uint64_t{0u};
}

ClientReadRequest::~ClientReadRequest() {
  // @@protoc_insertion_point(destructor:proto.ClientReadRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ClientReadRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  client_ip_.Destroy();
}

void ClientReadRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ClientReadRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.ClientReadRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  rows_.Clear();
  client_ip_.ClearToEmpty();
  txn_id_ = uint64_t{0u};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ClientReadRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string client_ip = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_client_ip();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "proto.ClientReadRequest.client_ip"));
        } else
          goto handle_unusual;
        continue;
      // uint64 txn_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          txn_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .proto.Row rows = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_rows(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ClientReadRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.ClientReadRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string client_ip = 1;
  if (!this->_internal_client_ip().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_client_ip().data(), static_cast<int>(this->_internal_client_ip().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "proto.ClientReadRequest.client_ip");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_client_ip(), target);
  }

  // uint64 txn_id = 2;
  if (this->_internal_txn_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(2, this->_internal_txn_id(), target);
  }

  // repeated .proto.Row rows = 3;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_rows_size()); i < n; i++) {
    const auto& repfield = this->_internal_rows(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(3, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.ClientReadRequest)
  return target;
}

size_t ClientReadRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.ClientReadRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .proto.Row rows = 3;
  total_size += 1UL * this->_internal_rows_size();
  for (const auto& msg : this->rows_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string client_ip = 1;
  if (!this->_internal_client_ip().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_client_ip());
  }

  // uint64 txn_id = 2;
  if (this->_internal_txn_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_txn_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ClientReadRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ClientReadRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ClientReadRequest::GetClassData() const { return &_class_data_; }

void ClientReadRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ClientReadRequest *>(to)->MergeFrom(
      static_cast<const ClientReadRequest &>(from));
}


void ClientReadRequest::MergeFrom(const ClientReadRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto.ClientReadRequest)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  rows_.MergeFrom(from.rows_);
  if (!from._internal_client_ip().empty()) {
    _internal_set_client_ip(from._internal_client_ip());
  }
  if (from._internal_txn_id() != 0) {
    _internal_set_txn_id(from._internal_txn_id());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ClientReadRequest::CopyFrom(const ClientReadRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.ClientReadRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClientReadRequest::IsInitialized() const {
  return true;
}

void ClientReadRequest::InternalSwap(ClientReadRequest* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  rows_.InternalSwap(&other->rows_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &client_ip_, lhs_arena,
      &other->client_ip_, rhs_arena
  );
  swap(txn_id_, other->txn_id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ClientReadRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_proto_2fclient_2eproto_getter, &descriptor_table_proto_2fclient_2eproto_once,
      file_level_metadata_proto_2fclient_2eproto[0]);
}

// ===================================================================

class ClientReadResponse::_Internal {
 public:
};

void ClientReadResponse::clear_rows() {
  rows_.Clear();
}
ClientReadResponse::ClientReadResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  rows_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:proto.ClientReadResponse)
}
ClientReadResponse::ClientReadResponse(const ClientReadResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      rows_(from.rows_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&txn_id_, &from.txn_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&result_) -
    reinterpret_cast<char*>(&txn_id_)) + sizeof(result_));
  // @@protoc_insertion_point(copy_constructor:proto.ClientReadResponse)
}

inline void ClientReadResponse::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&txn_id_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&result_) -
    reinterpret_cast<char*>(&txn_id_)) + sizeof(result_));
}

ClientReadResponse::~ClientReadResponse() {
  // @@protoc_insertion_point(destructor:proto.ClientReadResponse)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ClientReadResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void ClientReadResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ClientReadResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.ClientReadResponse)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  rows_.Clear();
  ::memset(&txn_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&result_) -
      reinterpret_cast<char*>(&txn_id_)) + sizeof(result_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ClientReadResponse::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .proto.Result result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_result(static_cast<::proto::Result>(val));
        } else
          goto handle_unusual;
        continue;
      // uint64 txn_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          txn_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .proto.Row rows = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_rows(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ClientReadResponse::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.ClientReadResponse)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .proto.Result result = 1;
  if (this->_internal_result() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      1, this->_internal_result(), target);
  }

  // uint64 txn_id = 2;
  if (this->_internal_txn_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(2, this->_internal_txn_id(), target);
  }

  // repeated .proto.Row rows = 3;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_rows_size()); i < n; i++) {
    const auto& repfield = this->_internal_rows(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(3, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.ClientReadResponse)
  return target;
}

size_t ClientReadResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.ClientReadResponse)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .proto.Row rows = 3;
  total_size += 1UL * this->_internal_rows_size();
  for (const auto& msg : this->rows_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // uint64 txn_id = 2;
  if (this->_internal_txn_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_txn_id());
  }

  // .proto.Result result = 1;
  if (this->_internal_result() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_result());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ClientReadResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ClientReadResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ClientReadResponse::GetClassData() const { return &_class_data_; }

void ClientReadResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ClientReadResponse *>(to)->MergeFrom(
      static_cast<const ClientReadResponse &>(from));
}


void ClientReadResponse::MergeFrom(const ClientReadResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto.ClientReadResponse)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  rows_.MergeFrom(from.rows_);
  if (from._internal_txn_id() != 0) {
    _internal_set_txn_id(from._internal_txn_id());
  }
  if (from._internal_result() != 0) {
    _internal_set_result(from._internal_result());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ClientReadResponse::CopyFrom(const ClientReadResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.ClientReadResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClientReadResponse::IsInitialized() const {
  return true;
}

void ClientReadResponse::InternalSwap(ClientReadResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  rows_.InternalSwap(&other->rows_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ClientReadResponse, result_)
      + sizeof(ClientReadResponse::result_)
      - PROTOBUF_FIELD_OFFSET(ClientReadResponse, txn_id_)>(
          reinterpret_cast<char*>(&txn_id_),
          reinterpret_cast<char*>(&other->txn_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ClientReadResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_proto_2fclient_2eproto_getter, &descriptor_table_proto_2fclient_2eproto_once,
      file_level_metadata_proto_2fclient_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::proto::ClientReadRequest*
Arena::CreateMaybeMessage< ::proto::ClientReadRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto::ClientReadRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::proto::ClientReadResponse*
Arena::CreateMaybeMessage< ::proto::ClientReadResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto::ClientReadResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
