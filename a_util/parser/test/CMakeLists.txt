find_package(a_util COMPONENTS csv_reader REQUIRED)
add_executable(csv_reader_test csv_reader_test.cpp)

# Link test executable against gtest & gtest_main (also gets their include paths)
target_link_libraries(csv_reader_test PRIVATE GTest::Main a_util_csv_reader)
add_test(NAME csv_reader_test
         COMMAND ${CMAKE_CURRENT_BINARY_DIR}/csv_reader_test
         WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(csv_reader_test PROPERTIES FOLDER a_util/test)
