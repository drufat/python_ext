from distutils.core import setup, Extension
from Cython.Build import cythonize

cython_extensions = [
    Extension('rect',
              sources=['rect.pyx', 'rectangle.cpp'],
              language='c++'),
    Extension('foo',
              sources=['foo.pyx','foo_helper.cpp'],
              language='c++'),
    Extension('queue',
              sources=['queue.pyx', 'c-algorithms/src/queue.c'],
              include_dirs=['c-algorithms/src']),
]

setup(
    name = 'foo', 
    ext_modules = cythonize(cython_extensions)
)
