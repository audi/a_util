find_package(a_util COMPONENTS datetime system REQUIRED)

add_executable(datetime_tests datetime_test.cpp)

# Link test executable against gtest & gtest_main (also gets their include paths)
target_link_libraries(datetime_tests PRIVATE GTest::Main a_util_datetime a_util_system)

add_test(datetime_tests datetime_tests)

set_target_properties(datetime_tests PROPERTIES FOLDER a_util/test)
