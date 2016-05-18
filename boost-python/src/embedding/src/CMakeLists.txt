set(SOURCES main.cpp)

add_executable(pyshell ${SOURCES})
target_link_libraries(pyshell boost_python-py34
                              ${PYTHON_LIBRARIES})
