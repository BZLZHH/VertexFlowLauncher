// Part of the Vertex Flow Launcher project.
// Copyright 2025 BZLZHH
// Licensed under the Apache License, Version 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
// SPDX-License-Identifier: Apache-2.0

#include "WindowManager.h"
#include "utils/logging/Log.h"
#include "core/Config.h"

bool WindowManager::Create(int width, int height, const char* title, bool canResize) {
    if (!glfwInit()) {
        LOG_ERROR("GLFW initialization failed");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, canResize ? GLFW_TRUE : GLFW_FALSE);

    const char* windowTitle = (title && *title) ? title : PROJECT_NAME;

    m_window = glfwCreateWindow(width, height, windowTitle, nullptr, nullptr);
    if (!m_window) {
        LOG_ERROR("Failed to create GLFW window");
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(DEFAULT_VSYNC_ENABLED ? 1 : 0);
    return true;
}

void WindowManager::BeginFrame() {
    glfwPollEvents();

    double currentTime = glfwGetTime();
    m_frameCount++;

    double delta = currentTime - m_lastTime;

    if (delta >= 1.0) {
        m_fps = m_frameCount / delta;
        m_frameCount = 0;
        m_lastTime = currentTime;

        if (LOG_FPS) {
            static double lastLogTime = 0.0;
            if (currentTime - lastLogTime >= 10.0) {
                LOG_DEBUG("FPS: {:.1f}", m_fps);
                lastLogTime = currentTime;
            }
        }
    }
}


void WindowManager::EndFrame() {
    glfwSwapBuffers(m_window);
}

bool WindowManager::ShouldClose() const {
    return glfwWindowShouldClose(m_window);
}

void WindowManager::Destroy() {
    if (m_window) {
        glfwDestroyWindow(m_window);
        glfwTerminate();
        m_window = nullptr;
    }
}