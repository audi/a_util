cmake_minimum_required(VERSION 3.10.0)

# Since CMAKE_CXX_COMPILER_ID is not available before project()
# we cannot determine the required CMAKE_CXX_STANDARD automatically.
# CMAKE_CXX_STANDARD needs to be set from outside, e.g. from a conan recipe

# Disable extensions here and require the chosen CMAKE_CXX_STANDARD
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

# Start project() now, since any include checks will use the correct compiler flags
project(a_util_library VERSION 5.6.0)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
##check for default install prefix and cmake build type
include(cmake/check_cmake_install_prefix.cmake)
include(cmake/check_cmake_build_type.cmake)

# Enable multicore compilation on Windows
include(./cmake/enable_multicore_compilation.cmake)

# Use integrated debug symbols on Windows (avoiding PDBs)
include(./cmake/use_integrated_debug_symbols.cmake)

add_compile_options($<$<CXX_COMPILER_ID:GNU>:-fPIC>)

add_subdirectory(3rdparty)
add_subdirectory(lib)
add_subdirectory(a_util)

##this enables a post-install command, so this must be "Last Dir Standing"!!!
add_subdirectory(doc)

# Enable testing if necessary
option(a_util_cmake_enable_integrated_tests
       "Enable tests as integrated build - requires googletest (default: OFF)"
       OFF)
if(a_util_cmake_enable_integrated_tests)
    # Generator expressions take 0 as FALSE/OFF and 1 as TRUE/ON
    set(a_util_cmake_enable_integrated_tests 1 CACHE BOOL "" FORCE)
    # Use conan if available
    if(CONAN_COMPILER)
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

    #ignore find_package calls inside the source tree from a_util components
    macro(find_package)
        if(NOT "${ARGV0}" MATCHES "^[aA][_][uU][tT][iI][lL]")
            _find_package(${ARGV})
        endif()
    endmacro(find_package)

    find_package(GTest PATHS ${CONAN_TESTING_ROOT})
    if (NOT GTest_FOUND)
        message(WARNING "Googletest not found. Integrated tests disabled.")
    else (NOT GTest_FOUND)
        enable_testing()
        add_subdirectory(test/function)
    endif (NOT GTest_FOUND)
endif(a_util_cmake_enable_integrated_tests)

# License Information must be delivered anyway!
install(FILES README.md DESTINATION .)
if(MSVC)
    install(FILES scripts/debugging/result.natvis DESTINATION scripts/debugging)
endif()