#pragma once

namespace SHCore
{
/* TODO : Increase platform defines when we support multi-platform in the future. */
#	define PLATFORM_WINDOWS 1

/* Platform Setting */
#	if defined(_WINDOWS)
#		define SH_PLATFORM PLATFORM_WINDOWS
#	endif

/* Windows Setting */
#	if SH_PLATFORM == PLATFORM_WINDOWS
#		if defined(_DEBUG) || defined(DEBUG)
#			define SH_COMPILERMODE_DEBUG 1
#		else
#			define SH_COMPILERMODE_DEBUG 0
#		endif
#	else
#		pragma error "This platform is unsupported platform!"
#	endif

/* Compiler Setting */
#	if SH_COMPILERMODE_DEBUG
#		define SH_DEBUG_ONLY(x) x
#		define SH_ASSERT(x) assert(x)
#		define SH_MEM_TRACE 1
#	else
#		define SH_DEBUG_ONLY(x) 
#		define SH_ASSERT(x)
#		define SH_MEM_TRACE 0
#	endif

/* DLL Setting */
#	if defined(SHCORELIB_EXPORTS)
#		define SH_CORE_API __declspec(dllexport)
#		define SH_CORE_EXTERN_API extern "C" __declspec(dllexport)
#	else
#		define SH_CORE_API __declspec(dllimport)
#		define SH_CORE_EXTERN_API extern "C" __declspec(dllimport)
#	endif
}