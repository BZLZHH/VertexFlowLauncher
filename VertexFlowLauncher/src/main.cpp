// Part of the Vertex Flow Launcher project.
// Copyright 2025 BZLZHH
// Licensed under the Apache License, Version 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
// SPDX-License-Identifier: Apache-2.0

#include "platform/windows/WindowManager.h"
#include "utils/logging/Log.h"
#include "core/Config.h"

void LogProjectInfo() {
    LOG_INFO("{} | Version {}.{}.{}", PROJECT_NAME, VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    LOG_INFO("Platform: {} ({})", TARGET_PLATFORM, TARGET_ARCH);
    LOG_INFO("Build: {} | {}", BUILD_CONFIGURATION, BUILD_TIMESTAMP);
    LOG_INFO("This is free software: you are free to change and redistribute it.");
	LOG_INFO("License: {}", PROJECT_LICENSE);
}

int main() {
    Log::Init();
    LogProjectInfo();

    WindowManager window;
    if (!window.Create(DEFAULT_WINDOW_WIDTH,
        DEFAULT_WINDOW_HEIGHT,
        PROJECT_NAME,
        CAN_WINDOW_RESIZE)) {
        LOG_CRITICAL("Failed to create application window!");
        return -1;
    }

    while (!window.ShouldClose()) {
        window.BeginFrame();

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.EndFrame();
    }

    return 0;
}
