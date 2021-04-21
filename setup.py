import os
import sys
from glob import glob
from setuptools import setup

DIR = os.path.abspath(os.path.dirname(__file__))
sys.path.append(os.path.join(DIR, "third_party", "pybind11"))

from pybind11.setup_helpers import Pybind11Extension, build_ext

__version__ = "0.0.1"
ext_modules = [
    Pybind11Extension(
        "pycpp",
        sorted(glob("src/*.cpp")),
        define_macros=[("VERSION_INFO", __version__)],
    ),
]

setup(
    name="pycpp",
    version="0.0.1",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
