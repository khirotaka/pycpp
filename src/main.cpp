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

namespace py = pybind11;

PYBIND11_MODULE(pycpp, m) {
    m.def("add", &add, "Add two numbers");
    m.def("multiply_array", &multiply_array<double>, "");
}
