from distutils.core import setup
from distutils.extension import Extension

setup(name='c_extension_demo',
      ext_modules = [Extension('cppsample', sources = ['cppsample.cpp'])])

