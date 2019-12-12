find_package(a_util COMPONENTS result REQUIRED)

##library to test Result return values from libraries
add_library(result_type_tester_lib SHARED lib/result_tester_lib.cpp lib/result_tester_lib.h)
target_link_libraries(result_type_tester_lib PRIVATE a_util_result)
target_include_directories(result_type_tester_lib PUBLIC .)
set_target_properties(result_type_tester_lib PROPERTIES FOLDER a_util/test/result/dependencies)

##test1
add_executable(result_type_test result_type_test.cpp)
target_link_libraries(result_type_test PRIVATE GTest::Main a_util_result)
add_test(result_type_test result_type_test)
set_target_properties(result_type_test PROPERTIES FOLDER a_util/test/result)

##test2
add_executable(result_type_from_lib_test result_type_from_lib_test.cpp)
target_link_libraries(result_type_from_lib_test PRIVATE
                      result_type_tester_lib
                      GTest::Main
                      a_util_result
                      )
add_test(result_type_from_lib_test result_type_test)
set_target_properties(result_type_from_lib_test PROPERTIES FOLDER a_util/test/result)

##test3
add_executable(error_def_test error_def_test.cpp)
target_link_libraries(error_def_test PRIVATE GTest::Main a_util_result)
add_test(error_def_test error_def_test)
set_target_properties(error_def_test PROPERTIES FOLDER a_util/test/result)

#private tests - use header files directly as those are not inside the install tree
##test4
add_executable(ref_counted_object_test ref_counted_object_test.cpp)
target_include_directories(ref_counted_object_test
                           PRIVATE $<IF:${a_util_cmake_enable_integrated_tests},
                                        ${PROJECT_SOURCE_DIR},
                                        ${PROJECT_SOURCE_DIR}/..>)
target_link_libraries(ref_counted_object_test PRIVATE GTest::Main)
add_test(ref_counted_object_test ref_counted_object_test)
set_target_properties(ref_counted_object_test PROPERTIES FOLDER a_util/test/result)
