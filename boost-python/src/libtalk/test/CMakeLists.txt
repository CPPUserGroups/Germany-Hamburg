
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(functions_test functions_test.cpp)
target_link_libraries(functions_test talk
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(NAME "test::functions" COMMAND functions_test)
add_dependencies(check functions_test)

add_executable(sensor_test sensor_test.cpp)
target_link_libraries(sensor_test 
                      talk ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(NAME "test::sensor" COMMAND sensor_test)

add_executable(motor_test motor_test.cpp)
target_link_libraries(motor_test 
                      talk ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(NAME "test::motor" COMMAND motor_test)

add_executable(step_motor_test step_motor_test.cpp)
target_link_libraries(step_motor_test 
                      talk ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(NAME "test::step_motor" COMMAND step_motor_test)
#
#add_executable(step_motor_test step_motor_test.cpp)
#target_link_libraries(step_motor_test 
#                      mcs ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
#add_test(NAME "test::step_motor" COMMAND step_motor_test)

add_executable(device_test device_test.cpp)
target_link_libraries(device_test 
                      talk ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(NAME "test::device" COMMAND device_test)

