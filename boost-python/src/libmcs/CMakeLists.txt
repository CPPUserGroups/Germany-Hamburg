cmake_minimum_required(VERSION 2.8)

project(libmcs)
enable_testing()
include(GNUInstallDirs)
add_definitions(-std=c++11 -O2)

add_custom_target(check)
include_directories(include)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)
