cmake_minimum_required(VERSION 3.19)
project(learnOpenGL)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

link_libraries(glfw)
link_libraries(glad::glad)

add_executable(learnOpenGL main.cpp)