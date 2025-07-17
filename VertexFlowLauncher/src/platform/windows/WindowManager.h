// Part of the Vertex Flow Launcher project.
// Copyright 2025 BZLZHH
// Licensed under the Apache License, Version 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
// SPDX-License-Identifier: Apache-2.0

#pragma once
#include <GLFW/glfw3.h>

#include "../../utils/logging/Log.h"

class WindowManager {
public:
    bool Create(int width, int height, const char* title, bool canResize);
    void Destroy();
    bool ShouldClose() const;

    void BeginFrame();
    void EndFrame();

    double GetFPS() const { return m_fps; }

private:
    GLFWwindow* m_window = nullptr;
    double m_lastTime = 0.0;
    int m_frameCount = 0;
    double m_fps = 0.0;
};
