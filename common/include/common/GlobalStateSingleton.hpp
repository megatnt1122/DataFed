#ifndef GLOBAL_STATE_SINGLETON_HPP
#define GLOBAL_STATE_SINGLETON_HPP
#pragma once

// Standard includes
#include <atomic>
#include <mutex>
#include <unordered_set>

namespace SDMS {

/**
 * The purpose of this Class is to handle all Global init and cleanup that is:
 * 1. Thread safe
 * 2. Should only be called once.
 **/
class GlobalStateSingleton {

	public:
		using InitFunctions = void (*)(void);
		using CleanupFunctions = void (*)(void);

		/**
		 * Make functions hashable
		 **/
		struct InitFunctionsHash {
				std::size_t operator()(const InitFunctions& func) const;
		};
		struct InitFunctionsEqual {
				bool operator()(const InitFunctions& lhs, const InitFunctions& rhs) const;
		};

		struct CleanupFunctionsHash {
				std::size_t operator()(const CleanupFunctions& func) const;
		};

		struct CleanupFunctionsEqual {
				bool operator()(const CleanupFunctions& lhs, const CleanupFunctions& rhs) const;
		};

	private:
		static std::unordered_set<
			InitFunctions,
			InitFunctionsHash,
			InitFunctionsEqual>
				m_init_functions;

		static std::unordered_set<
			CleanupFunctions,
			CleanupFunctionsHash,
			CleanupFunctionsEqual>
				m_cleanup_functions;

		static GlobalStateSingleton * m_instance;
		static std::once_flag m_onceFlag;

		GlobalStateSingleton() {};

    mutable std::mutex m_init_mutex;
    bool m_initialized = false;
    mutable std::mutex m_cleanup_mutex;
    bool m_cleanup = false;
	public:

    static GlobalStateSingleton* getInstance() {
      std::call_once(m_onceFlag, [] {
          m_instance = new GlobalStateSingleton();
          });
      return m_instance;
    }
		/**
		 * Disable copy constructor
		 **/
		GlobalStateSingleton(const GlobalStateSingleton&) = delete;

		/**
		 * Disable assignment operator
		 **/
		GlobalStateSingleton& operator=(const GlobalStateSingleton&) = delete;

		/**
		 * To statically register init and cleanup functions you need to run the
		 * register method
		 *
		 *
		 * ```C++
		 * GlobalStateSingleton global_state;
		 * gloabl_state.register<RouterBookKeepingOperator,OperatorType::RouterBookKeeping>();
		 * ```
		 **/
		template <class T> static bool registerInitFunction(T func) {
			if (m_init_functions.count(func) > 0) {
				return false;
			} else {
				m_init_functions.insert(func);
			}
			return true;
		}

		template <class T> static bool registerCleanupFunction(T func) {
			if (m_cleanup_functions.count(func) > 0) {
				return false;
			} else {
				m_cleanup_functions.insert(func);
			}
			return true;
		}

    /**
     * Initialize will only execute all functions once.
     **/
		void init();

    /**
     * Cleanup will only call all cleanup functions the first time it is called. 
     **/
		void cleanup(); 

    /**
     * Have the globals been initialized
     **/
    bool initialized() const;

    /**
     * Have the globals been cleaned up
     **/
    bool cleaned() const;

};

} // namespace SDMS


#endif // GLOBAL_STATE_SINGLETON_HPP
