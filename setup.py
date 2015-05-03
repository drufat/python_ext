from distutils.core import setup, Extension
from Cython.Build import cythonize

cython_extensions = [
    Extension('rect_cython',
              sources=['rect_cython.pyx', 'rectangle.cpp'],
              language='c++'
              ),
    Extension('queue_cython',
              sources=['queue_cython.pyx', 'c-algorithms/src/queue.c'],
              include_dirs=['c-algorithms/src']
              ),
    Extension('foo',
              sources=['foo.pyx','foo_helper.cpp'],
              language='c++'
              ),
]

extensions = [
    Extension('rect_cpp',
              sources=['rect_cpp.cpp', 'rectangle.cpp'],
              language='c++',
              extra_compile_args=['-std=c++11']
              ),
]

setup(
    name = 'foo', 
    ext_modules = (extensions + cythonize(cython_extensions))
)
