set(SOURCES main.cpp)

add_executable(pyshell ${SOURCES})
target_link_libraries(pyshell boost_python-py34
                              ${PYTHON_LIBRARIES})

add_executable(pyshell2 pyshell2.cpp)
target_link_libraries(pyshell2 boost_python-py34
                               ${PYTHON_LIBRARIES})
