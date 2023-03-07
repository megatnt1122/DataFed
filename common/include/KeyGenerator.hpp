#ifndef KEY_GENERATOR_HPP
#define KEY_GENERATOR_HPP
#pragma once

// Local includes
#include "ICredentials.hpp"
#include "ProtocolTypes.hpp"

// Standard includes
#include <string>
#include <unordered_map>

namespace SDMS {

  enum class KeyType {
    PUBLIC_PRIVATE
  };
  
  class KeyGenerator {
    public:
      std::unordered_map<CredentialType, std::string> generate(const ProtocolType, const KeyType);
  };

} // namespace SDMS

#endif // KEY_GENERATOR_HPP