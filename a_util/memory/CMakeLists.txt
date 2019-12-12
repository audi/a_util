add_library(a_util_memory STATIC
    ##public
    memory.h
    memorybuffer.h
    unique_ptr.h
    shared_ptr.h
    stack_ptr.h

    ##'protected'
    detail/shared_ptr_cxx11.h
    detail/stack_ptr_decl.h
    detail/stack_ptr_impl.h
    detail/unique_ptr_cxx11.h

    ##private
    impl/memory.cpp
    impl/memorybuffer.cpp
    )

target_include_directories(a_util_memory PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_memory a_util_base a_util_concurrency)

set_target_properties(a_util_memory PROPERTIES FOLDER a_util)

install(TARGETS a_util_memory
        EXPORT a_util_memory
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES unique_ptr.h
              shared_ptr.h
              memory.h
              memorybuffer.h
              stack_ptr.h
        DESTINATION include/a_util/memory)

install(DIRECTORY detail DESTINATION include/a_util/memory)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_memory-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(EXPORT a_util_memory FILE a_util_memory_targets.cmake DESTINATION lib/cmake/a_util_memory)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_memory-config-version.cmake
              a_util_memory-config.cmake
        DESTINATION lib/cmake/a_util_memory)
