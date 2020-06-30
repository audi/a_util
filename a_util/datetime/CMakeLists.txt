add_library(a_util_datetime STATIC
            datetime.h
            datetime.cpp   #common implementation
            )

target_include_directories(a_util_datetime
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_datetime PUBLIC a_util_base a_util_strings a_util_memory a_util_regex)

set_target_properties(a_util_datetime PROPERTIES FOLDER a_util)

install(TARGETS a_util_datetime
        EXPORT a_util_datetime
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES datetime.h DESTINATION include/a_util/datetime)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_datetime-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_datetime-config-version.cmake
              a_util_datetime-config.cmake
        DESTINATION lib/cmake/a_util_datetime)
install(EXPORT a_util_datetime FILE a_util_datetime_targets.cmake DESTINATION lib/cmake/a_util_datetime)