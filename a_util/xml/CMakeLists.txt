set(PUGI_SOURCES ${PUGI_DIR}/src/pugixml.hpp 
                 ${PUGI_DIR}/src/pugiconfig.hpp
                 ${PUGI_DIR}/src/pugixml.cpp)

add_library(a_util_xml STATIC
            dom.h
            dom.cpp
            ${PUGI_SOURCES}
)
            
target_include_directories(a_util_xml
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                                  $<INSTALL_INTERFACE:include>
                           PRIVATE ${PUGI_DIR}/src)
                           
target_link_libraries(a_util_xml a_util_base)

set_target_properties(a_util_xml PROPERTIES FOLDER a_util)

install(TARGETS a_util_xml
        EXPORT a_util_xml
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(EXPORT a_util_xml FILE a_util_xml_targets.cmake DESTINATION lib/cmake/a_util_xml)

install(FILES dom.h DESTINATION include/a_util/xml)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_xml-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_xml-config-version.cmake
              a_util_xml-config.cmake
        DESTINATION lib/cmake/a_util_xml)
