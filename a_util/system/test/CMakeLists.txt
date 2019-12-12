# QNX port Copyright (c) 2019 by dSPACE GmbH, Paderborn, Germany. All Rights Reserved.
#
find_package(a_util COMPONENTS system filesystem REQUIRED)

##system_tests
add_executable(system_tests system_test.cpp)
target_link_libraries(system_tests PRIVATE GTest::Main a_util_system a_util_filesystem)
add_test(system_tests system_tests)
set_target_properties(system_tests PROPERTIES FOLDER a_util/test)

add_executable(timer_tests timer_test.cpp)
target_link_libraries(timer_tests PRIVATE GTest::Main a_util_system)
add_test(timer_tests timer_tests)
set_target_properties(timer_tests PROPERTIES FOLDER a_util/test)

add_executable(uuid_tests uuid_test.cpp)
target_link_libraries(uuid_tests PRIVATE GTest::Main a_util_system)
if(QNXNTO)
    target_link_libraries(uuid_tests PUBLIC socket)
endif()
add_test(uuid_tests uuid_tests)
set_target_properties(uuid_tests PROPERTIES FOLDER a_util/test)
