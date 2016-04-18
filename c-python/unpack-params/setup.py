from distutils.core import setup
from distutils.extension import Extension

ext = Extension('unpackparams', 
      sources = ['unpackparams.cpp'],
      extra_compile_args=['-std=c++11'])

setup(name='unpackparams',
      ext_modules = [ext])

