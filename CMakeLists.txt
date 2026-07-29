cmake_minimum_required(VERSION 3.24)

project(DungeonGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/6.0.tar.gz
)

FetchContent_MakeAvailable(raylib)

add_executable(DungeonGame
    src/main.cpp
)

target_link_libraries(DungeonGame PRIVATE raylib)