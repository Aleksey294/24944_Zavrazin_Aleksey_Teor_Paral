cmake_minimum_required(VERSION 3.10)
project(sin_array)

option(USE_DOUBLE "Use double instead of float" OFF)

if (USE_DOUBLE)
    add_compile_definitions(USE_DOUBLE)
endif ()

add_executable(sin_array task.cpp)
