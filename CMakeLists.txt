cmake_minimum_required(VERSION 3.17)
project(pycpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)


find_package(BLAS REQUIRED)
message(STATUS BLAS: ${BLAS_LIBRARIES})

find_package(LAPACK REQUIRED)
message(STATUS LAPACK: ${LAPACK_LIBRARIES})

add_subdirectory(third_party/pybind11)

include_directories(third_party/eigen)

pybind11_add_module(pycpp src/main.cpp)
target_link_libraries(pycpp PRIVATE ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})

IF (APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
ENDIF(APPLE)

target_compile_definitions(pycpp PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
