from distutils.core import setup
from distutils.extension import Extension

ext = Extension('cust', 
      sources = ['cust.cpp'],
      extra_compile_args=['-std=c++11'])

setup(name='cust',
      ext_modules = [ext])

