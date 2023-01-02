#pragma once

#include <spdlog/spdlog.h>

#define IMAGINATION_LOG_INFO(...)		spdlog::info(__VA_ARGS__)
#define IMAGINATION_LOG_WARN(...)		spdlog::warn(__VA_ARGS__)
#define IMAGINATION_LOG_ERROR(...)		spdlog::error(__VA_ARGS__)
#define IMAGINATION_LOG_CRITICAL(...)	spdlog::critical(__VA_ARGS__)