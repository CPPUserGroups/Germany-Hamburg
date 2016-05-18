cmake_minimum_required(VERSION 3.0.0)
project(pyshell)
include(FindPythonLibs)
include(FindBoost)

#find the appropriate Python interpreter
find_package(PythonLibs)
if(PYTHONLIBS_FOUND)
    message(STATUS "Found: ${PYTHON_LIBRARIES}")
    message(STATUS "Python Version: ${PYTHONLIBS_VERSION_STRING}")
    include_directories(${PYTHON_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "No Python libraries found!")
endif()

find_package(Boost COMPONENTS python)

if(Boost_PYTHON_FOUND)
    message(STATUS "Found: ${Boost_PYTHON_LIBRARY}")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else()
    message(FATAL_ERROR "No Boost Python library found")
endif()

add_subdirectory(src)
