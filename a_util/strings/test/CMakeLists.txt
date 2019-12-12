find_package(a_util COMPONENTS strings memory REQUIRED)

##strings_tests
add_executable(strings_tests strings_test.cpp)
target_link_libraries(strings_tests PRIVATE GTest::Main a_util_strings a_util_memory)
add_test(strings_tests strings_tests)
set_target_properties(strings_tests PROPERTIES FOLDER a_util/test/strings)

##strings_convert_tests
add_executable(strings_convert_tests strings_convert_test.cpp)
target_link_libraries(strings_convert_tests PRIVATE GTest::Main a_util_strings)
set_target_properties(strings_convert_tests PROPERTIES FOLDER a_util/test/strings)
add_test(strings_convert_tests strings_convert_tests)

##strings_format_tests
add_executable(strings_format_tests strings_format_test.cpp)
target_link_libraries(strings_format_tests PRIVATE GTest::Main a_util_strings)
set_target_properties(strings_format_tests PROPERTIES FOLDER a_util/test/strings)
add_test(strings_format_tests strings_format_tests)

##strings_numeric_traits_tests
add_executable(strings_numeric_traits_tests strings_numeric_traits_test.cpp)
target_link_libraries(strings_numeric_traits_tests PRIVATE GTest::Main a_util_strings)
set_target_properties(strings_numeric_traits_tests PROPERTIES FOLDER a_util/test/strings)
add_test(strings_numeric_traits_tests strings_numeric_traits_tests)

##unicode_tests
add_executable(unicode_tests unicode_test.cpp)
target_link_libraries(unicode_tests PRIVATE GTest::Main a_util_strings)
set_target_properties(unicode_tests PROPERTIES FOLDER a_util/test/strings)
add_test(unicode_tests unicode_tests)
