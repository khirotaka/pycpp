# pycpp
C++でPythonパッケージを書く練習台

## System Requirements
* macOS 11.2.3 on Apple M1


## Build

```sh
$ python -m venv venv
$ source venv/bin/activate
$ pip install -U pip
$ python setup.py build
$ python setup.py install
```

## Coding

```sh
$ cd build
$ cmake -G Xcode ..
$ open pycpp.xcodeproj/
```

