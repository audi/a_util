install(FILES delegate.h types.h DESTINATION include/a_util/base)
install(DIRECTORY detail DESTINATION include/a_util/base)

## interface target for a_util_base
add_library(a_util_base INTERFACE)

target_include_directories(a_util_base
    INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
           $<INSTALL_INTERFACE:include>
)

target_compile_features(a_util_base INTERFACE cxx_std_11)

install(TARGETS a_util_base
        EXPORT a_util_base
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_base-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_base-config-version.cmake
        DESTINATION lib/cmake/a_util_base)
install(EXPORT a_util_base FILE a_util_base-config.cmake DESTINATION lib/cmake/a_util_base)
