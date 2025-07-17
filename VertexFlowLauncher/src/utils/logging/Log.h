// Part of the Vertex Flow Launcher project.
// Copyright 2025 BZLZHH
// Licensed under the Apache License, Version 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <memory>
#include <spdlog/logger.h>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/pattern_formatter.h>
#include <spdlog\sinks\ansicolor_sink.h>

#include "../../core/Config.h"

class Log {
public:
    static void Init();

    template<typename... Args>
    static void Trace(const char* fmt, Args&&... args) {
        s_logger->trace(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void Info(const char* fmt, Args&&... args) {
        s_logger->info(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void Warn(const char* fmt, Args&&... args) {
        s_logger->warn(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void Error(const char* fmt, Args&&... args) {
        s_logger->error(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void Critical(const char* fmt, Args&&... args) {
        s_logger->critical(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void Debug(const char* fmt, Args&&... args) {
        s_logger->debug(fmt, std::forward<Args>(args)...);
    }

private:
    static std::shared_ptr<spdlog::logger> s_logger;
};

#define COLOR_YELLOW "\033[33;1m"
#define COLOR_SKY_BLUE "\033[36;1m"
#define COLOR_RESET  "\033[0m"

#define PROJECT_HEADER COLOR_SKY_BLUE "[" PROJECT_NAME_DEF "]" COLOR_RESET

#define LOG_TRACE(...)    Log::Trace(__VA_ARGS__)
#define LOG_INFO(...)     Log::Info(__VA_ARGS__)
#define LOG_WARN(...)     Log::Warn(__VA_ARGS__)
#define LOG_ERROR(...)    Log::Error(__VA_ARGS__)
#define LOG_CRITICAL(...) Log::Critical(__VA_ARGS__)
#define LOG_DEBUG(...)    Log::Debug(__VA_ARGS__)