#include <iostream>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <Eigen/Eigen>
#include <omp.h>
#include "simd.h"

void print_hello() {
    #pragma omp parallel
    {
        std::cout << "Hello, World" << std::endl;
    }
}


std::vector<int> fetch_list(int size) {
    std::vector<int> result(size);
    std::vector<int> a(size, 1);
    std::vector<int> b(size, 5);
    
    #pragma omp for
    for (int i = 0; i < size; ++i) {
        result[i] = a[i] + b[i];
    }
    
    return result;
}


std::string available_simd_instructions() {
    return Eigen::SimdInstructionSetsInUse();
}

namespace py = pybind11;

PYBIND11_MODULE(utils, m) {
    m.def("available_simd_instructions", &available_simd_instructions,
          "Returns a string indicating the available SIMD instructions");
    m.def("print_hello", &print_hello, "");
    m.def("fetch_list", &fetch_list, "");
}
