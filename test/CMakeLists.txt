cmake_minimum_required(VERSION 3.0.0)   #minimum for generated find scripts
project(a_util_tests)

set(CMAKE_CXX_EXTENSIONS OFF)   # we want standard compliant code without compiler extensions

# Generator expressions take 0 as FALSE/OFF and 1 as TRUE/ON
set(a_util_cmake_enable_integrated_tests 0 CACHE BOOL "" FORCE)

if(CONAN_COMPILER)
    message(STATUS "Including Conan build info")
    if ( EXISTS ${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
        include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
    elseif ( EXISTS ${CMAKE_CURRENT_BINARY_DIR}/../conanbuildinfo.cmake)
        include(${CMAKE_CURRENT_BINARY_DIR}/../conanbuildinfo.cmake)
    elseif ( EXISTS ${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo_multi.cmake)
        include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo_multi.cmake)
    elseif ( EXISTS ${CMAKE_CURRENT_BINARY_DIR}/../conanbuildinfo_multi.cmake)
        include(${CMAKE_CURRENT_BINARY_DIR}/../conanbuildinfo_multi.cmake)
    else()
        message(FATAL_ERROR "Conan build info can't be found.")
    endif()

    if(CORTEX_WORKSPACE)
        conan_basic_setup(TARGETS)
    else()
        conan_basic_setup(TARGETS NO_OUTPUT_DIRS)
    endif()
endif()

find_package(GTest REQUIRED PATHS ${CONAN_TESTING_ROOT})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

##functional test integration, also includes googletest via redirection
enable_testing()
add_subdirectory(function)
