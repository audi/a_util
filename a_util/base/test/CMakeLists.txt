find_package(a_util COMPONENTS base REQUIRED)

#delegate test
add_executable(delegate_tests delegate_test.cpp)
target_link_libraries(delegate_tests PRIVATE GTest::Main a_util_base)
add_test(delegate_tests delegate_tests)
set_target_properties(delegate_tests PROPERTIES FOLDER a_util/test/base)
