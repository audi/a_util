add_library(a_util_concurrency STATIC
            ##public
            ../concurrency.h
            atomic.h
            shared_mutex.h
            thread.h
            semaphore.h
            fast_mutex.h

            ##'protected'
            detail/fast_mutex_decl.h
            detail/fast_mutex_impl.h
            detail/semaphore_decl.h
            detail/semaphore_impl.h
            detail/shared_mutex.h

            ##private
            impl/atomic_fallback.cpp
            impl/shared_mutex.cpp
            )

target_compile_options(a_util_concurrency
                       PRIVATE  $<$<CXX_COMPILER_ID:GNU>:-Wall>
                                $<$<CXX_COMPILER_ID:MSVC>:/W4>
                                )

target_include_directories(a_util_concurrency
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>)

target_link_libraries(a_util_concurrency PUBLIC a_util_base)

set_target_properties(a_util_concurrency PROPERTIES FOLDER a_util)

install(TARGETS a_util_concurrency
        EXPORT a_util_concurrency
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(FILES thread.h
              atomic.h
              chrono.h
              shared_mutex.h
              mutex.h
              condition_variable.h
              semaphore.h
              fast_mutex.h
        DESTINATION include/a_util/concurrency)

install(DIRECTORY detail DESTINATION include/a_util/concurrency)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_concurrency-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_concurrency-config-version.cmake a_util_concurrency-config.cmake
        DESTINATION lib/cmake/a_util_concurrency)
install(EXPORT a_util_concurrency FILE a_util_concurrency_targets.cmake DESTINATION lib/cmake/a_util_concurrency)
