add_library(a_util_process STATIC
            ##public
            ../process.h
            process.h
            
            #'protected'
            detail/process_impl.h
            
            ##private
            impl/process.cpp
            impl/process_win.cpp
            impl/process_lin.cpp
            )

target_compile_options(a_util_process PRIVATE
                       $<$<CXX_COMPILER_ID:GNU>:-Wall>
                       $<$<CXX_COMPILER_ID:MSVC>:/W4>)

target_include_directories(a_util_process
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_process PUBLIC a_util_base a_util_memory a_util_system a_util_strings a_util_filesystem)

if(UNIX AND NOT QNXNTO)
    target_link_libraries(a_util_process PUBLIC rt)
endif()
if(WIN32)
    target_link_libraries(a_util_process PUBLIC winmm)
endif()

set_target_properties(a_util_process PROPERTIES FOLDER a_util)

install(TARGETS a_util_process
        EXPORT a_util_process
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES process.h
        DESTINATION include/a_util/process)

install(DIRECTORY detail DESTINATION include/a_util/process)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_process-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_process-config-version.cmake
              a_util_process-config.cmake
        DESTINATION lib/cmake/a_util_process)
install(EXPORT a_util_process FILE a_util_process_targets.cmake DESTINATION lib/cmake/a_util_process)
