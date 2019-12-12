option(a_util_cmake_enable_dynamic_error_description "Enable dynamic memory allocation for \
a_util_result component (default: ON)" ON)

add_library(a_util_result STATIC
            ##public
            ../result.h
            error_def.h
            result_info.h
            result_info_decl.h
            result_type.h
            result_type_decl.h
            result_util.h

            ##'protected'
            detail/error_description_intf.h
            detail/reference_counted_object_intf.h
            detail/result_description_decl.h
            detail/result_description_impl.h
            detail/result_info_impl.h
            detail/result_type_impl.h

            ##private
            impl/error_description.h
            impl/error_description.cpp
            impl/reference_counted_object.h
            impl/reference_counted_object_disable_dynamic_alloc.h
            impl/result_description_private.h
            impl/result_util.cpp
            impl/result_type.cpp
            )

target_compile_options(a_util_result PRIVATE
                       $<$<CXX_COMPILER_ID:GNU>:-pedantic -Wall>
                       $<$<CXX_COMPILER_ID:MSVC>:/W4>
                       )

target_compile_definitions(a_util_result PRIVATE 
                           $<$<STREQUAL:${a_util_cmake_enable_dynamic_error_description},ON>:A_UTIL_ENABLE_DYNAMIC_ERROR_DESCRIPTION>)

target_include_directories(a_util_result
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_result a_util_base a_util_concurrency a_util_strings)

set_target_properties(a_util_result PROPERTIES FOLDER a_util)

install(TARGETS a_util_result
        EXPORT a_util_result
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES error_def.h
              result_info.h
              result_info_decl.h
              result_type.h
              result_type_decl.h
              result_util.h
        DESTINATION include/a_util/result)

install(DIRECTORY detail DESTINATION include/a_util/result)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_result-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_result-config-version.cmake a_util_result-config.cmake
        DESTINATION lib/cmake/a_util_result)
install(EXPORT a_util_result FILE a_util_result_targets.cmake DESTINATION lib/cmake/a_util_result)
