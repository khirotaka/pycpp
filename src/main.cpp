#define EIGEN_USE_BLAS
#define EIGEN_USE_LAPACKE

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/Dense>

/*
 ndarrayはメモリ配置がデフォルトではC言語で主に用いられるRowMajorなのに対し、
 EigenではデフォルトはfortranのColumnMajorである。
 ただ、両者とも指定することができるのでここではndarrayのRowMajorに揃える。
 毎回RowMajorを宣言するのも面倒なのでRMatrixというテンプレートクラスを作っておく。
 
 Reference: https://qiita.com/lucidfrontier45/items/5048ef74fbf32eeb9f08
 */
template <typename T>
using RMatrix = Eigen::Matrix<T, -1, -1, Eigen::RowMajor>;


int add(int x, int y) {
    return x + y;
}

template <typename T>
RMatrix<T> multiply_array(RMatrix<T> m, T value) {
    return m * value;
}

template <typename T>
Eigen::Vector<T, -1> create_vector(int size) {
    Eigen::VectorXd vector = Eigen::VectorXd::Zero(size);

    return vector;
}

template <typename T>
RMatrix<T> create_matrix(int rows, int columns) {
    Eigen::MatrixXd matrix = Eigen::MatrixXd::Zero(rows, columns);
    return matrix;
}

template <typename T>
RMatrix<T> matmul(RMatrix<T> a, RMatrix<T> b) {
    auto result = a * b;
    return result;
}

std::string available_simd_instructions() {
    return Eigen::SimdInstructionSetsInUse();
}

namespace py = pybind11;

PYBIND11_MODULE(pycpp, m) {
    m.def("add", &add, "Add two numbers");
    m.def("multiply_array", &multiply_array<double>, "");
    m.def("create_vector", &create_vector<double>, "");
    m.def("create_matrix", &create_matrix<double>, "");
    m.def("matmul", &matmul<float>,
          "The function of matrix multiplication. \
          This function using BLAS. \
          If you use Apple Silicon Mac, \
          you will indirectly use Apple AMX Coprocessor,\
          since it uses BLAS in Accelerate.");
    
    m.def("simd_status", &available_simd_instructions,
          "Returns a string indicating the available SIMD instructions");
}
