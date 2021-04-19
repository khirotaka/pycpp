# pycpp
C++でPythonパッケージを書く練習台

## System Requirements
* macOS 11.2.3 on Apple M1


## Build
Building Universal 2 binary

```sh
$ python -m venv venv
$ source venv/bin/activate
$ pip install -U pip && pip install pybind11
$ mkdir build
$ python setup.py build && python setup.py install
```

## Coding

```sh
$ cd build
$ cmake -G Xcode ..
$ open pycpp.xcodeproj/
```

