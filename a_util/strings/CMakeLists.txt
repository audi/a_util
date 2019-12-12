add_library(a_util_strings STATIC
            ##public
            ../strings.h
            strings_convert.h
            strings_convert_decl.h
            strings_format.h
            strings_functions.h
            strings_numeric_traits.h
            strings_numeric_traits_decl.h
            unicode.h

            ##'protected'
            detail/strings_convert_impl.h
            detail/strings_numeric_traits_impl.h

            ##private
            impl/strings_format_detail.h
            impl/strings_default_conversion.h
            impl/std_to_detail.h
            impl/strings.cpp
            impl/strings_format.cpp
            impl/strings_convert.cpp
            impl/strings_default_conversion.cpp
            impl/strings_numeric_to_string.cpp
            impl/strings_numeric_traits.cpp
            impl/unicode.cpp
            )

target_compile_options(a_util_strings PRIVATE
                       $<$<CXX_COMPILER_ID:GNU>:-pedantic -Wall>
                       $<$<CXX_COMPILER_ID:MSVC>:/W4>)

target_include_directories(a_util_strings
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_strings a_util_base)

set_target_properties(a_util_strings PROPERTIES FOLDER a_util)

install(TARGETS a_util_strings
        EXPORT a_util_strings
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES strings_convert.h
              strings_convert_decl.h
              strings_format.h 
              strings_functions.h
              strings_numeric_traits.h
              strings_numeric_traits_decl.h
              unicode.h
        DESTINATION include/a_util/strings)

install(DIRECTORY detail DESTINATION include/a_util/strings)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_strings-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_strings-config-version.cmake a_util_strings-config.cmake
        DESTINATION lib/cmake/a_util_strings)
install(EXPORT a_util_strings FILE a_util_strings_targets.cmake DESTINATION lib/cmake/a_util_strings)
