from distutils.core import setup
from distutils.extension import Extension

ext = Extension('embed', 
      sources = ['embed.cpp'],
      extra_compile_args=['-std=c++11'])

setup(name='embed',
      ext_modules = [ext])

