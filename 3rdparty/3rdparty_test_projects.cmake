##This file is included by integrated test projects and standalone project
# For the standalone test the directory is not a subdirectory, hence always add a custom binary dir.
# Also, this file is included from different directories depending on integrated or standalone test build,
# therefore the actual subdirectory needs to be prefixed by CMAKE_CURRENT_LIST_DIR
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/clara/test ${CMAKE_CURRENT_BINARY_DIR}/clara/test)