
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(named_object_test named_object_test.cpp)
target_link_libraries(named_object_test 
                      mcs ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(NAME "test::named_object" COMMAND named_object_test)

add_dependencies(check named_object_test)
