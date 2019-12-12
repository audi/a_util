set(_clara_version 1.1.2)
install(FILES Clara-${_clara_version}/clara.hpp
        DESTINATION include/3rdparty/clara/Clara-${_clara_version}/single_include)

##Packaging
add_library(Clara INTERFACE)
target_include_directories(Clara
    INTERFACE $<INSTALL_INTERFACE:include/3rdparty/clara/Clara-${_clara_version}/single_include>
)

install(TARGETS Clara EXPORT Clara)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/clara-config-version.cmake
                                 VERSION ${_clara_version}
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/clara-config-version.cmake
        DESTINATION lib/cmake/3rdparty)
install(EXPORT Clara FILE clara-config.cmake DESTINATION lib/cmake/3rdparty)
unset(_clara_version)