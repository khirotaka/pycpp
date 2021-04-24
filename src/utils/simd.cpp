#include <pybind11/pybind11.h>
#include <Eigen/Eigen>


std::string available_simd_instructions() {
    return Eigen::SimdInstructionSetsInUse();
}

namespace py = pybind11;

PYBIND11_MODULE(utils, m) {
    m.def("available_simd_instructions", &available_simd_instructions,
          "Returns a string indicating the available SIMD instructions");
}
