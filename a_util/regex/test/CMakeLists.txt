find_package(a_util COMPONENTS regex REQUIRED)

add_executable(regex_tests regex_test.cpp)

# Link test executable against gtest & gtest_main (also gets their include paths)
target_link_libraries(regex_tests PRIVATE GTest::Main a_util_regex)

add_test(regex_tests regex_tests)
set_target_properties(regex_tests PROPERTIES FOLDER a_util/test)
