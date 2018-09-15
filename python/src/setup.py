from distutils.core import setup, Extension
from Cython.Build import cythonize
#import numpy as np

COMPILE_ARGS = ['-std=c++11']
ext = Extension("cKDTree",
                sources=["cKDTree.pyx", "../../src/KDTree.cpp"],
                language="c++",
                extra_compile_args = COMPILE_ARGS)
                #include_dirs=['.', np.get_include()])

setup(name="cKDTree",
      ext_modules=cythonize(ext))
import cKDTree