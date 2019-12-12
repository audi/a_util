add_library(a_util_filesystem STATIC
            path.h
            filesystem.h
            path.cpp   #common implementation
            filesystem.cpp   #common implementation
            )

target_include_directories(a_util_filesystem
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_filesystem a_util_base a_util_strings a_util_memory)

set_target_properties(a_util_filesystem PROPERTIES FOLDER a_util)

install(TARGETS a_util_filesystem
        EXPORT a_util_filesystem
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES path.h filesystem.h DESTINATION include/a_util/filesystem)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_filesystem-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(EXPORT a_util_filesystem 
        FILE a_util_filesystem_targets.cmake
        DESTINATION lib/cmake/a_util_filesystem)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_filesystem-config-version.cmake
              a_util_filesystem-config.cmake
        DESTINATION lib/cmake/a_util_filesystem)
