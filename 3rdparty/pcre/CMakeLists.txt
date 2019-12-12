# PCRE is not built as separate target, but its CMake generates some build headers that we need.
# Therefore we generate the header using the shipped CMake, but exclude the targets from our Solution.
# explicitly set the following variables into the parent scope, to be usable in the modules
set(PCRE_DIR ${CMAKE_CURRENT_LIST_DIR}/pcre-8.39 CACHE INTERNAL "Path to PCRE dir")
set(PCRE_CUSTOM_BINARY_DIR ${PROJECT_BINARY_DIR}/pcre_prebuild  CACHE INTERNAL "Path to PCRE binary dir")

set(PCRE_BUILD_PCREGREP OFF)
set(PCRE_BUILD_TESTS OFF)
set(PCRE_SHOW_REPORT OFF)
add_subdirectory(${PCRE_DIR} ${PCRE_CUSTOM_BINARY_DIR} EXCLUDE_FROM_ALL)
