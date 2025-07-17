// Part of the Vertex Flow Launcher project.
// Copyright 2025 BZLZHH
// Licensed under the Apache License, Version 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
// SPDX-License-Identifier: Apache-2.0

#include "Log.h"

std::shared_ptr<spdlog::logger> Log::s_logger;

class UpperLevelFormatter : public spdlog::custom_flag_formatter {
public:
    void format(const spdlog::details::log_msg& msg, const std::tm&, spdlog::memory_buf_t& dest) override {
        auto sv = spdlog::level::to_string_view(msg.level);
        std::string level(sv.begin(), sv.end());
        std::transform(level.begin(), level.end(), level.begin(), [](unsigned char c) { return std::toupper(c); });
        dest.append(level.data(), level.data() + level.size());
    }
    std::unique_ptr<custom_flag_formatter> clone() const override {
        return spdlog::details::make_unique<UpperLevelFormatter>();
    }
};

void Log::Init() {
    s_logger = spdlog::stdout_color_mt("VFL");
    s_logger->set_level(spdlog::level::trace);
    auto formatter = std::make_unique<spdlog::pattern_formatter>();
    formatter->add_flag<UpperLevelFormatter>('U');
    formatter->set_pattern(
        "[%Y-%m-%d %H:%M:%S.%e] "
        PROJECT_HEADER " "
        "%^[%U]%$ "
        "%v"
    );
    s_logger->set_formatter(std::move(formatter));
}
