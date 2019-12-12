##This file is included by integrated test projects and standalone project
# For the standalone test the directory is not a subdirectory, hence always add a custom binary dir.
# Also, this file is included from different directories depending on integrated or standalone test build,
# therefore the actual subdirectory needs to be prefixed by CMAKE_CURRENT_LIST_DIR
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/base/test        ${CMAKE_CURRENT_BINARY_DIR}/base/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/concurrency/test ${CMAKE_CURRENT_BINARY_DIR}/concurrency/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/datetime/test    ${CMAKE_CURRENT_BINARY_DIR}/datetime/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/filesystem/test  ${CMAKE_CURRENT_BINARY_DIR}/filesystem/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/logging/test     ${CMAKE_CURRENT_BINARY_DIR}/logging/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/memory/test      ${CMAKE_CURRENT_BINARY_DIR}/memory/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/parser/test      ${CMAKE_CURRENT_BINARY_DIR}/parser/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/regex/test       ${CMAKE_CURRENT_BINARY_DIR}/regex/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/result/test      ${CMAKE_CURRENT_BINARY_DIR}/result/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/strings/test     ${CMAKE_CURRENT_BINARY_DIR}/strings/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/system/test      ${CMAKE_CURRENT_BINARY_DIR}/system/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/variant/test     ${CMAKE_CURRENT_BINARY_DIR}/variant/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/xml/test         ${CMAKE_CURRENT_BINARY_DIR}/xml/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/process/test     ${CMAKE_CURRENT_BINARY_DIR}/process/test)
