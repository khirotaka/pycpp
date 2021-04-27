import time
import numpy as np
from pycpp.functions._C import matmul


def timer(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        func(*args, **kwargs)
        end = time.time()
        print("{:.4f} s".format(end - start))
    return wrapper


@timer
def np_matmul(array: np.ndarray):
    np.matmul(array, array.T)


@timer
def blas_matmul(array: np.ndarray):
    matmul(array, array.T)


def main():
    np.random.seed(0)
    array = np.random.randn(2**12, 2**12).astype(np.float32)

    print("BLAS(AMX) Speed: ")
    blas_matmul(array)

    print("=" * 50)
    print("NumPy Speed: ")
    np_matmul(array)
    print("=" * 50)


if __name__ == '__main__':
    main()
