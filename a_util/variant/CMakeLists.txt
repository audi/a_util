add_library(a_util_variant STATIC
            variant.h
            variant.cpp   #common implementation
            )

target_include_directories(a_util_variant
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_variant a_util_base a_util_strings a_util_memory)

set_target_properties(a_util_variant PROPERTIES FOLDER a_util)

install(TARGETS a_util_variant
        EXPORT a_util_variant
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES variant.h DESTINATION include/a_util/variant)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_variant-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_variant-config-version.cmake
              a_util_variant-config.cmake
        DESTINATION lib/cmake/a_util_variant)
install(EXPORT a_util_variant FILE a_util_variant_targets.cmake DESTINATION lib/cmake/a_util_variant)