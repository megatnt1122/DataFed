#ifndef PROTOCOL_TYPES_HPP
#define PROTOCOL_TYPES_HPP
#pragma once

namespace SDMS {

enum class ProtocolType {
  HTTP,
  ZQTP // ZeroMQ Transport Layer Protocol
};

enum class ProtocolTechnology {
  CURL,
  ZEROMQ
};

} // namespace SDMS

#endif // PROTOCOL_TYPES_HPP
