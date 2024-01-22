// Public includes
#include "GlobalStateSingleton.hpp"

namespace SDMS {



std::size_t GlobalStateSingleton::InitFunctionsHash::operator()(
    const InitFunctions& func) const {
    // Custom hash implementation based on the function's target
    return std::hash<InitFunctions>{}(func);
}

bool GlobalStateSingleton::InitFunctionsEqual::operator()(
    const InitFunctions& lhs,
    const InitFunctions& rhs) const {
      // Custom equality comparison based on the function's target
      return lhs == rhs;
}

std::size_t GlobalStateSingleton::CleanupFunctionsHash::operator()(
    const CleanupFunctions& func) const {
    // Custom hash implementation based on the function's target
    return std::hash<CleanupFunctions>{}(func);
}

bool GlobalStateSingleton::CleanupFunctionsEqual::operator()(
    const CleanupFunctions& lhs,
    const CleanupFunctions& rhs) const {
    // Custom equality comparison based on the function's target
    return lhs == rhs;
}

void GlobalStateSingleton::init() {
  std::lock_guard<std::mutex> lock(m_init_mutex);
  if( m_initialized ) return;
  for( auto & init_func : this->m_init_functions ) {
    init_func();
  }
  m_initialized = true;
}

void GlobalStateSingleton::cleanup() {
  std::lock_guard<std::mutex> lock(m_cleanup_mutex);
  if( m_cleanup ) return;
  for( auto & cleanup_func : this->m_cleanup_functions ) {
    cleanup_func();
  }
  m_cleanup = true;
}

bool GlobalStateSingleton::initialized() const {
  std::lock_guard<std::mutex> lock(m_init_mutex);
  return m_initialized;
}

bool GlobalStateSingleton::initialized() const {
  std::lock_guard<std::mutex> lock(m_cleanup_mutex);
  return m_cleanup;
}

} // namespace SDMS
