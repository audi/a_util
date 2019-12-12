add_library(a_util_logging STATIC
            ../logging.h
            log.h
            log.cpp
            )

target_compile_options(a_util_logging PRIVATE
                       $<$<CXX_COMPILER_ID:GNU>:-Wall>
                       $<$<CXX_COMPILER_ID:MSVC>:/W4>)

target_include_directories(a_util_logging
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_logging PUBLIC a_util_base a_util_strings a_util_datetime a_util_filesystem a_util_concurrency)
                      
set_target_properties(a_util_logging PROPERTIES FOLDER a_util)

install(TARGETS a_util_logging
        EXPORT a_util_logging
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES log.h
        DESTINATION include/a_util/logging)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_logging-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_logging-config-version.cmake
              a_util_logging-config.cmake
        DESTINATION lib/cmake/a_util_logging)
install(EXPORT a_util_logging FILE a_util_logging_targets.cmake DESTINATION lib/cmake/a_util_logging)
