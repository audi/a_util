add_library(a_util_csv_reader STATIC
            csv_reader.h
            csv_reader.cpp
)

target_include_directories(a_util_csv_reader
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_csv_reader PUBLIC a_util_base)

set_target_properties(a_util_csv_reader PROPERTIES FOLDER a_util)

install(TARGETS a_util_csv_reader
        EXPORT a_util_csv_reader
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(EXPORT a_util_csv_reader FILE a_util_csv_reader_targets.cmake DESTINATION lib/cmake/a_util_csv_reader)

install(FILES csv_reader.h DESTINATION include/a_util/parser)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_csv_reader-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_csv_reader-config-version.cmake
              a_util_csv_reader-config.cmake
        DESTINATION lib/cmake/a_util_csv_reader)
