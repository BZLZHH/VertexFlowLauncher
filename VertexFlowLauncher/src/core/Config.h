// Part of the Vertex Flow Launcher project.
// Copyright 2025 BZLZHH
// Licensed under the Apache License, Version 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
// SPDX-License-Identifier: Apache-2.0

#pragma once

#define PROJECT_NAME_DEF "Vertex Flow Launcher"
#define VERSION_SUFFIX_DEF "alpha"

constexpr const char* PROJECT_NAME = PROJECT_NAME_DEF;
constexpr const char* PROJECT_AUTHOR = "BZLZHH";
constexpr const char* PROJECT_COPYRIGHT_YEAR = "2025";
constexpr const char* PROJECT_LICENSE = "Apache License 2.0";

constexpr int VERSION_MAJOR = 0;
constexpr int VERSION_MINOR = 1;
constexpr int VERSION_PATCH = 0;
constexpr const char* VERSION_SUFFIX = VERSION_SUFFIX_DEF;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

constexpr const char* TARGET_PLATFORM = "Windows";
constexpr const char* TARGET_ARCH =
#if defined(_M_X64) || defined(__x86_64__) || defined(__amd64__)
"x86_64";
#elif defined(_M_IX86) || defined(__i386__)
"x86";
#elif defined(_M_ARM64) || defined(__aarch64__)
"ARM64";
#elif defined(_M_ARM) || defined(__arm__)
"ARM";
#else
"Unknown";
#endif

constexpr const char* BUILD_CONFIGURATION =
#if defined(NDEBUG)
"Release";
#else
"Debug";
#endif

#if !defined(BUILD_TIMESTAMP)
#define BUILD_TIMESTAMP "0000-00-00T00:00:00Z"
#endif

constexpr const char* BUILD_TIME = BUILD_TIMESTAMP;
constexpr int DEFAULT_WINDOW_WIDTH = 944;
constexpr int DEFAULT_WINDOW_HEIGHT = 531;
constexpr bool DEFAULT_VSYNC_ENABLED = true;
constexpr bool CAN_WINDOW_RESIZE = false;

constexpr bool LOG_FPS = false;

constexpr int OPENGL_MAJOR_VERSION = 4;
constexpr int OPENGL_MINOR_VERSION = 3;

#define CHECK_MIN_VERSION(major, minor) \
    (VERSION_MAJOR > (major) || (VERSION_MAJOR == (major) && VERSION_MINOR >= (minor)))

#if defined(__GNUC__) || defined(__clang__)
#define DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED __declspec(deprecated)
#else
#define DEPRECATED
#endif
