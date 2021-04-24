cmake_minimum_required(VERSION 3.17)
project(pycpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)


IF (APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
ENDIF(APPLE)

find_package(BLAS REQUIRED)
message(STATUS BLAS: ${BLAS_LIBRARIES})

find_package(LAPACK REQUIRED)
message(STATUS LAPACK: ${LAPACK_LIBRARIES})

add_subdirectory(third_party/pybind11)

include_directories(third_party/eigen)

pybind11_add_module(_C src/main.cpp)
pybind11_add_module(utils src/utils/simd.cpp)
target_link_libraries(_C PRIVATE ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})
