option(a_util_cmake_enable_documentation "If enabled, generate the source code documentation -\
 requires doxygen (default: ON)" ON)
option(a_util_cmake_enable_post_install_doc_generation "If enabled, doxygen will generate the\
 documentation as post-install event. Disable only for development purposes. (default: ON)" ON)
option(DOXYGEN_SKIP_DOT "If true this module will skip trying to find Dot (default: OFF)" OFF)

##installation of documentation related files
## DO NOT MOVE THE FILES AROUND!!! Otherwise markdown support for either bitbucket or doxygen breaks
install(FILES changelog.md DESTINATION doc/)
install(FILES license/MPL2.0.txt DESTINATION .)
install(FILES license/MPL2.0.txt DESTINATION doc/html/doc/license)    #for doxygen doc
install(DIRECTORY license DESTINATION doc/)

if(EXISTS "${CURRENT_IMPORTS_DIR}/licenses/list_used_licenses.md.in")
    set (AEV_PRODUCT_FULL_NAME "a_util_library")

    if(NOT EXCLUDE_PRODUCT_LICENSES)
        set(LICENSE_FILES_EXTENSION "* [licenses.txt](../license/licenses.txt)\n\
    * [MPL2.0.txt](../license/MPL2.0.txt)\n\
    * [used_oss.md](../license/used_oss.md#)\n")
    endif()

    configure_file(${CURRENT_IMPORTS_DIR}/licenses/list_used_licenses.md.in 
        ${CURRENT_IMPORTS_DIR}/licenses/list_used_licenses.md)
endif()
 
##continue only if enabled
if(a_util_cmake_enable_documentation)
    find_package(Doxygen)
    if(NOT DOXYGEN_FOUND)
        message(WARNING "No doxygen executable found. Disabling build of documentation. Either\
 set the correct DOXYGEN_EXECUTABLE or set CMake option 'a_util_cmake_enable_documentation' to\
 'OFF' to disable this warning.")
        return()
    endif(NOT DOXYGEN_FOUND)
    if(NOT DOXYGEN_SKIP_DOT AND NOT DOXYGEN_DOT_FOUND)
        message(FATAL_ERROR "No dot executable found. Either set the "
                            "correct DOXYGEN_DOT_EXECUTABLE or enable DOXYGEN_SKIP_DOT.")
    elseif(NOT DOXYGEN_SKIP_DOT AND DOXYGEN_DOT_FOUND)
        EXECUTE_PROCESS(COMMAND ${DOXYGEN_DOT_EXECUTABLE} -V OUTPUT_VARIABLE dot_version_info
                                                             ERROR_VARIABLE dot_version_info
                                                             OUTPUT_STRIP_TRAILING_WHITESPACE
                                                             ERROR_STRIP_TRAILING_WHITESPACE)
        set(dot_version_info "(found version: \"${dot_version_info}\")")
        message(STATUS "Found dot: ${DOXYGEN_DOT_EXECUTABLE} ${dot_version_info}")
        unset(dot_version_info)
    endif(NOT DOXYGEN_SKIP_DOT AND NOT DOXYGEN_DOT_FOUND)
else()
    return()
endif(a_util_cmake_enable_documentation)

configure_file(run_doxygen.cmake.in run_doxygen.cmake @ONLY)
##create seperate target excluded from all
add_custom_target(a_util_DOC ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/run_doxygen.cmake)
set_target_properties(a_util_DOC PROPERTIES FOLDER process)

##post install script to run doxygen over install tree
if(a_util_cmake_enable_post_install_doc_generation)
    install(SCRIPT ${CMAKE_CURRENT_BINARY_DIR}/run_doxygen.cmake)
endif(a_util_cmake_enable_post_install_doc_generation)
