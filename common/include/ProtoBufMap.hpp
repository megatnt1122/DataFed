#ifndef PROTOBUFMAP_HPP
#define PROTOBUFMAP_HPP
#pragma once

// Public common includes
#include "IMessageMapper.hpp"

// Third party includes
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>

// Standard includes
#include <map>
#include <unordered_map>

namespace SDMS {
  
  class ProtoBufMap : public IMessageMapper {
    public:
      typedef std::map<uint8_t,const ::google::protobuf::FileDescriptor *>    FileDescriptorMap;
      typedef std::map<uint16_t,const ::google::protobuf::Descriptor *>       DescriptorMap;
      typedef std::map<const ::google::protobuf::Descriptor *,uint16_t>       MsgTypeMap;

    private:

      FileDescriptorMap m_file_descriptor_map;
      DescriptorMap m_descriptor_map;
      MsgTypeMap m_msg_type_map;
      std::unordered_map<MessageProtocol, uint16_t> m_protocol_ids;

    public:
      ProtoBufMap();

      const ::google::protobuf::Descriptor * getDescriptorType(uint16_t message_type) const;
      uint16_t getMessageType(::google::protobuf::Message &);
      virtual uint16_t getMessageType(uint8_t a_proto_id, const std::string & a_message_name) final;
      virtual uint8_t getProtocolID(MessageProtocol) const final;

  };
}

#endif // PROTOBUFMAP_HPP