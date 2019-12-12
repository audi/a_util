find_package(a_util COMPONENTS filesystem REQUIRED)

add_executable(filesystem_tests filesystem_test.cpp)
target_link_libraries(filesystem_tests PRIVATE GTest::Main a_util_filesystem)
add_test(filesystem_tests filesystem_tests)
set_target_properties(filesystem_tests PROPERTIES FOLDER a_util/test/filesystem)

add_executable(path_tests path_test.cpp)
target_link_libraries(path_tests PRIVATE GTest::Main a_util_filesystem)
add_test(path_tests path_tests)
set_target_properties(path_tests PROPERTIES FOLDER a_util/test/filesystem)
