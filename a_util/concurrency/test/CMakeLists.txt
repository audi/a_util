find_package(a_util COMPONENTS concurrency system REQUIRED)

add_executable(thread_tests thread_test.cpp)
target_link_libraries(thread_tests PRIVATE GTest::Main a_util_concurrency a_util_system)
add_test(thread_tests thread_tests)
set_target_properties(thread_tests PROPERTIES FOLDER a_util/test/concurrency)

add_executable(condvar_tests condvar_test.cpp)
target_link_libraries(condvar_tests PRIVATE GTest::Main a_util_concurrency a_util_system)
add_test(condvar_tests condvar_tests)
set_target_properties(condvar_tests PROPERTIES FOLDER a_util/test/concurrency)

add_executable(mutex_tests mutex_test.cpp)
target_link_libraries(mutex_tests PRIVATE GTest::Main a_util_concurrency a_util_system)
add_test(mutex_tests mutex_tests)
set_target_properties(mutex_tests PROPERTIES FOLDER a_util/test/concurrency)

add_executable(semaphore_tests semaphore_test.cpp)
target_link_libraries(semaphore_tests PRIVATE GTest::Main a_util_concurrency a_util_system)
add_test(semaphore_tests semaphore_tests)
set_target_properties(semaphore_tests PROPERTIES FOLDER a_util/test/concurrency)

add_executable(chrono_tests chrono_test.cpp)
target_link_libraries(chrono_tests PRIVATE GTest::Main a_util_concurrency a_util_system)
add_test(chrono_tests chrono_tests)
set_target_properties(chrono_tests PROPERTIES FOLDER a_util/test/concurrency)
