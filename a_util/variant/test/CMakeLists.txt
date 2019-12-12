find_package(a_util COMPONENTS variant REQUIRED)

add_executable(variant_tests variant_test.cpp)

# Link test executable against gtest & gtest_main (also gets their include paths)
target_link_libraries(variant_tests PRIVATE GTest::Main a_util_variant)

add_test(variant_tests variant_tests)

set_target_properties(variant_tests PROPERTIES FOLDER a_util/test)
