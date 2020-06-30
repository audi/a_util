find_package(a_util COMPONENTS base REQUIRED)

#delegate test
add_executable(delegate_tests delegate_test.cpp)
target_link_libraries(delegate_tests PRIVATE GTest::Main a_util_base)
add_test(delegate_tests delegate_tests)
set_target_properties(delegate_tests PROPERTIES FOLDER a_util/test/base)

#maybe_unused test
add_executable(maybe_unused_tests maybe_unused_test.cpp)
target_link_libraries(maybe_unused_tests PRIVATE GTest::Main a_util_base)
add_test(maybe_unused_tests maybe_unused_tests)
set_target_properties(maybe_unused_tests PROPERTIES FOLDER a_util/test/base)

target_compile_options(maybe_unused_tests PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/WX>)
target_compile_options(maybe_unused_tests PRIVATE $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Werror>)