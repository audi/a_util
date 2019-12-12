find_package(a_util COMPONENTS base process REQUIRED)

##process_tests
add_executable(process_tests process_execute_test.cpp process_env_test.cpp)
target_link_libraries(process_tests PRIVATE GTest::Main a_util_base a_util_process)
add_test(process_tests process_tests)
set_target_properties(process_tests PROPERTIES FOLDER a_util/test/process)