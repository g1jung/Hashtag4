#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hashtag4 {

	class HASHTAG4_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define H4_CORE_TRACE(...)::Hashtag4::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define H4_CORE_INFO(...) ::Hashtag4::Log::GetCoreLogger()->info(__VA_ARGS__)
#define H4_CORE_WARN(...) ::Hashtag4::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define H4_CORE_ERROR(...)::Hashtag4::Log::GetCoreLogger()->error(__VA_ARGS__)
#define H4_CORE_FATAL(...)::Hashtag4::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define H4_TRACE(...)::Hashtag4::Log::GetClientLogger()->trace(__VA_ARGS__)
#define H4_INFO(...) ::Hashtag4::Log::GetClientLogger()->info(__VA_ARGS__)
#define H4_WARN(...) ::Hashtag4::Log::GetClientLogger()->warn(__VA_ARGS__)
#define H4_ERROR(...)::Hashtag4::Log::GetClientLogger()->error(__VA_ARGS__)
#define H4_FATAL(...)::Hashtag4::Log::GetClientLogger()->fatal(__VA_ARGS__)
