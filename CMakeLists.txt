cmake_minimum_required(VERSION 3.17)
project(pycpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party/pybind11)

include_directories(third_party/eigen)

pybind11_add_module(pycpp src/main.cpp)

IF (APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
ENDIF(APPLE)

target_compile_definitions(pycpp PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

