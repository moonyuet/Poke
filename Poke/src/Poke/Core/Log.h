#pragma once


#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>



namespace Poke {

	class POKE_API Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define PK_CORE_TRACE(...)    ::Poke::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PK_CORE_INFO(...)     ::Poke::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PK_CORE_WARN(...)     ::Poke::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PK_CORE_ERROR(...)    ::Poke::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PK_CORE_FATAL(...)	  ::Poke::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PK_TRACE(...)         ::Poke::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PK_INFO(...)          ::Poke::Log::GetClientLogger()->info(__VA_ARGS__)
#define PK_WARN(...)          ::Poke::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PK_ERROR(...)         ::Poke::Log::GetClientLogger()->error(__VA_ARGS__)
#define PK_FATAL(...)         ::Poke::Log::GetClientLogger()->fatal(__VA_ARGS__)
