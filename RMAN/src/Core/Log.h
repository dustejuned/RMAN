#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"
namespace RMAN {
	class RMAN_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _clientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;

	};

#define RMAN_CORE_TRACE(...) ::RMAN::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RMAN_CORE_INFO(...) ::RMAN::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RMAN_CORE_DEBUG(...) ::RMAN::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define RMAN_CORE_WARN(...) ::RMAN::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RMAN_CORE_CRITICAL(...) ::RMAN::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define RMAN_CORE_ERROR(...) ::RMAN::Log::GetCoreLogger()->error(__VA_ARGS__)

#define RMAN_TRACE(...) ::RMAN::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RMAN_INFO(...) ::RMAN::Log::GetClientLogger()->info(__VA_ARGS__)
#define RMAN_DEBUG(...) ::RMAN::Log::GetClientLogger()->debug(__VA_ARGS__)
#define RMAN_WARN(...) ::RMAN::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RMAN_CRITICAL(...) ::RMAN::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define RMAN_ERROR(...) ::RMAN::Log::GetCoreLogger()->error(__VA_ARGS__)
}

