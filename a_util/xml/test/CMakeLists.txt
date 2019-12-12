find_package(a_util COMPONENTS xml filesystem REQUIRED)

add_executable(xml_tests xml_test.cpp)

# Link test executable against gtest & gtest_main (also gets their include paths)
target_link_libraries(xml_tests PRIVATE GTest::Main a_util_xml a_util_filesystem)

add_test(NAME xml_tests COMMAND ${CMAKE_CURRENT_BINARY_DIR}/xml_tests WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(xml_tests PROPERTIES FOLDER a_util/test)