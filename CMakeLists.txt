cmake_minimum_required(VERSION 3.17)
project(pycpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)


# Numerical Libraries
find_package(BLAS REQUIRED)
message(STATUS BLAS: ${BLAS_LIBRARIES})

find_package(LAPACK REQUIRED)
message(STATUS LAPACK: ${LAPACK_LIBRARIES})

include_directories(third_party/eigen)

# OpenMP
find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

# Pybind11
add_subdirectory(third_party/pybind11)


pybind11_add_module(_C src/math/vector.cpp)
pybind11_add_module(utils src/utils/simd.cpp)
target_link_libraries(_C PRIVATE ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES} OpenMP::OpenMP_CXX)
target_link_libraries(utils PRIVATE OpenMP::OpenMP_CXX)

