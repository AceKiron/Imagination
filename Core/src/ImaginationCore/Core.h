#pragma once

#include "imaginationpch.h"

#include "Log.h"

#ifdef IMAGINATION_CONFIGURATION_DEBUG
	// Debug configuration
	#define IMAGINATION_CONSTRUCTOR_LOG_ADDRESS
	#define IMAGINATION_DEBUG_BREAK(...) { IMAGINATION_LOG_ERROR(__VA_ARGS__); __debugbreak(); }
	#define IMAGINATION_ASSERT(x, ...) { if(!x) { IMAGINATION_DEBUG_BREAK(__VA_ARGS__) } }
#else
#ifdef IMAGINATION_CONFIGURATION_RELEASE
	// Release configuration
	#define IMAGINATION_DEBUG_BREAK(...) { IMAGINATION_LOG_ERROR(__VA_ARGS__); __debugbreak(); }
	#define IMAGINATION_ASSERT(x, ...) { if(!x) { IMAGINATION_DEBUG_BREAK(__VA_ARGS__) } }
#else
	// Dist configuration
	#define IMAGINATION_DEBUG_BREAK(...)
	#define IMAGINE_ASSERT(x, ...)
#endif
#endif

#define BIT(x) (1 << x)