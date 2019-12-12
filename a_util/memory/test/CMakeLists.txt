find_package(a_util COMPONENTS memory strings REQUIRED)

add_executable(memory_tests memory_test.cpp)
target_link_libraries(memory_tests PRIVATE GTest::Main a_util_memory)
add_test(memory_tests memory_tests)
set_target_properties(memory_tests PROPERTIES FOLDER a_util/test)

add_executable(unique_ptr_tests unique_ptr_test.cpp)
target_link_libraries(unique_ptr_tests PRIVATE GTest::Main a_util_memory)
add_test(unique_ptr_tests unique_ptr_tests)
set_target_properties(unique_ptr_tests PROPERTIES FOLDER a_util/test)

add_executable(memorybuffer_tests memorybuffer_test.cpp)
target_link_libraries(memorybuffer_tests PRIVATE GTest::Main a_util_memory)
add_test(memorybuffer_tests memorybuffer_tests)
set_target_properties(memorybuffer_tests PROPERTIES FOLDER a_util/test)

add_executable(shared_ptr_tests shared_ptr_test.cpp shared_ptr_incomplete.cpp)
target_link_libraries(shared_ptr_tests PRIVATE GTest::Main a_util_memory)
add_test(shared_ptr_tests shared_ptr_tests)
set_target_properties(shared_ptr_tests PROPERTIES FOLDER a_util/test)

add_executable(stack_ptr_tests stack_ptr_test.cpp)
target_link_libraries(stack_ptr_tests PRIVATE
                                      GTest::Main a_util_memory a_util_strings) #toString()
add_test(stack_ptr_tests stack_ptr_tests)
set_target_properties(stack_ptr_tests PROPERTIES FOLDER a_util/test)
