#include <pybind11/pybind11.h>

int add(int x, int y) {
    return x + y;
}

namespace py = pybind11;

PYBIND11_MODULE(pycpp, m) {
    m.def("add", &add, "Add two numbers");
}
