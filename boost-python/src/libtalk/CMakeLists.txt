cmake_minimum_required(VERSION 2.8)

project(libmcs)
enable_testing()
include(GNUInstallDirs)
add_definitions(-std=c++11 -O2 -Wall -Wextra -pedantic)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
include_directories(include)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)
