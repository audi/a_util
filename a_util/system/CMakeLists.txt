add_library(a_util_system STATIC
            ##public
            ../system.h
            system.h
            timer.h
            timer_decl.h
            uuid.h
            
            #'protected'
            detail/timer_impl.h
            
            ##private
            impl/system.cpp
            impl/timer.cpp
            impl/uuid.cpp
            $<TARGET_OBJECTS:uuid>
            )

target_compile_options(a_util_system PRIVATE
                       $<$<CXX_COMPILER_ID:GNU>:-Wall>
                       $<$<CXX_COMPILER_ID:MSVC>:/W4>)

target_include_directories(a_util_system
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>
                           PRIVATE ${UUID_DIR})

target_link_libraries(a_util_system PUBLIC a_util_base a_util_memory a_util_concurrency)

if(UNIX AND NOT QNXNTO)
    target_link_libraries(a_util_system PUBLIC rt)
endif()
if(WIN32)
    target_link_libraries(a_util_system PUBLIC winmm)
endif()

set_target_properties(a_util_system PROPERTIES FOLDER a_util)

install(TARGETS a_util_system
        EXPORT a_util_system
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES system.h timer.h timer_decl.h uuid.h
        DESTINATION include/a_util/system)

install(DIRECTORY detail DESTINATION include/a_util/system)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_system-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_system-config-version.cmake
              a_util_system-config.cmake
        DESTINATION lib/cmake/a_util_system)
install(EXPORT a_util_system FILE a_util_system_targets.cmake DESTINATION lib/cmake/a_util_system)
