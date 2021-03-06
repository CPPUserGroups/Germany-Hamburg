#setup script for python-talk
from __future__ import print_function
import sys
import os
from setuptools import setup, find_packages, Extension

boost_python_lib = 'boost_python-py{version[0]}{version[1]}'.format(version=sys.version_info)

extra_compile_args = ['-std=c++11','-Wall','-Wextra',
                      '-fdiagnostics-show-option',
                      '-Wno-strict-prototypes']

functions_ext = Extension("talk.functions",
                          ["src/functions.cpp"],
                          libraries = ["talk",boost_python_lib],
                          language="c++",
                          extra_compile_args = extra_compile_args)

sensor_ext = Extension("talk.sensor",
                          ["src/sensor.cpp"],
                          libraries = ["talk",boost_python_lib],
                          language="c++",
                          extra_compile_args = extra_compile_args)

motors_ext = Extension("talk.motors",
                          ["src/motors.cpp"],
                          libraries = ["talk",boost_python_lib],
                          language="c++",
                          extra_compile_args = extra_compile_args)
array_ext = Extension("talk.array",
                      ["src/array.cpp"],
                      libraries=[boost_python_lib],
                      extra_compile_args = extra_compile_args)

test_exceptions_ext = Extension("talk.test.exceptions_test_module",
                          ["src/exceptions_test_module.cpp"],
                          libraries = ["talk",boost_python_lib],
                          language="c++",
                          extra_compile_args = extra_compile_args)

setup(name="talk",
      author="Eugen Wintersberger",
      author_email="eugen.wintersberger@gmail.com",
      description="Python wrapper for the talk library",
      maintainer = "Eugen Wintersberger",
      maintainer_email = "eugen.wintersberger@gmail.com",
      license = "GPLv2",
      version = "1.0.0",
      ext_modules=[functions_ext,test_exceptions_ext,sensor_ext,motors_ext,
                   array_ext],
      packages = find_packages(),
      test_suite="talk.test",
      test_loader = "unittest:TestLoader",
    )

