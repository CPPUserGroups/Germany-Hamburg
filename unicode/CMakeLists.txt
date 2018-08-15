cmake_minimum_required(VERSION 3.0.0)
project(unicode LANGUAGES CXX C VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)

find_package(ICU REQUIRED COMPONENTS uc io data tu i18n)

add_executable(reader1 reader1.cpp)

add_executable(reader2 reader2.cpp)
target_link_libraries(reader2 ICU::uc ICU::io)

add_executable(reader3 reader3.cpp)
target_link_libraries(reader3 ICU::uc ICU::io ICU::data ICU::tu ICU::i18n)