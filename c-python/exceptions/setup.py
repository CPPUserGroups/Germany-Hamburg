from distutils.core import setup
from distutils.extension import Extension

ext = Extension('sampleexc', 
      sources = ['sampleexc.cpp'],
      extra_compile_args=['-std=c++11'])

setup(name='sampleexc',
      ext_modules = [ext])

