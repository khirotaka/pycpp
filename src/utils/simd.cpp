#include <iostream>
#include <pybind11/pybind11.h>
#include <Eigen/Eigen>
#include <omp.h>

void print_hello() {
    #pragma omp parallel
    {
        std::cout << "Hello, World" << std::endl;
    }
}

std::string available_simd_instructions() {
    return Eigen::SimdInstructionSetsInUse();
}

namespace py = pybind11;

PYBIND11_MODULE(utils, m) {
    m.def("available_simd_instructions", &available_simd_instructions,
          "Returns a string indicating the available SIMD instructions");
    m.def("print_hello", &print_hello, "");
}
