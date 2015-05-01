from distutils.core import setup, Extension
from Cython.Build import cythonize

cython_extensions = [
    Extension('rect_cython',
              sources=['rect_cython.pyx', 'rectangle.cpp'],
              language='c++'),
    Extension('queue_cython',
              sources=['queue_cython.pyx', 'c-algorithms/src/queue.c'],
              include_dirs=['c-algorithms/src']),
    Extension('foo',
              sources=['foo.pyx','foo_helper.cpp'],
              language='c++'),
]

cffi_extensions = [
    Extension('rect_cffi_dl',
              sources=['rectangle.cpp'],
              language='c++'),
]

setup(
    name = 'foo', 
    ext_modules = (cythonize(cython_extensions) + 
                   cffi_extensions)
)
