find_package(a_util COMPONENTS logging REQUIRED)

##logging_tests
add_executable(logging_tests logging_test.cpp)
target_link_libraries(logging_tests PRIVATE GTest::Main a_util_logging)
add_test(logging_tests logging_tests)
set_target_properties(logging_tests PROPERTIES FOLDER a_util/test)
