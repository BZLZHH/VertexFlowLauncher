set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party/glfw)
add_subdirectory(third_party/spdlog)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

string(TIMESTAMP BUILD_TIMESTAMP "%Y-%m-%dT%H:%M:%SZ" UTC)
add_definitions(-DBUILD_TIMESTAMP="${BUILD_TIMESTAMP}")

add_executable(VertexFlowLauncher
    src/main.cpp
    src/platform/windows/WindowManager.cpp
    src/utils/logging/Log.cpp
)

target_link_libraries(VertexFlowLauncher
    glfw
    spdlog::spdlog
    opengl32
)
