function(pcre_patch_hardcode_mangle filename)
    # copy file to memory
    file(READ ${PCRE_DIR}/${filename} CONTENT)
    
    # now patch the hardcoded symbol
    string(REPLACE
           "#if defined(__GNUC__) && __GNUC__ >= 3 && defined(__ELF__) && !defined(__INTEL_COMPILER)" "#if 0"
           CONTENT
           "${CONTENT}"
    )
    
    # write the file to the binary dir
    file(WRITE ${PCRE_CUSTOM_BINARY_DIR}/${filename} "${CONTENT}")
endfunction()

# patch the pcrecpp namespace to be able to link both the old utils and the new utils
pcre_patch_hardcode_mangle(pcrecpp.cc)

set(PCRE_SOURCES
    ${PCRE_CUSTOM_BINARY_DIR}/pcre_chartables.c
    ${PCRE_CUSTOM_BINARY_DIR}/pcrecpp.cc
    ${PCRE_DIR}/pcre_scanner.cc
    ${PCRE_DIR}/pcre_stringpiece.cc
    ${PCRE_DIR}/pcre_byte_order.c
    ${PCRE_DIR}/pcre_compile.c
    ${PCRE_DIR}/pcre_config.c
    ${PCRE_DIR}/pcre_dfa_exec.c
    ${PCRE_DIR}/pcre_exec.c
    ${PCRE_DIR}/pcre_fullinfo.c
    ${PCRE_DIR}/pcre_get.c
    ${PCRE_DIR}/pcre_globals.c
    ${PCRE_DIR}/pcre_jit_compile.c
    ${PCRE_DIR}/pcre_maketables.c
    ${PCRE_DIR}/pcre_newline.c
    ${PCRE_DIR}/pcre_ord2utf8.c
    ${PCRE_DIR}/pcre_refcount.c
    ${PCRE_DIR}/pcre_string_utils.c
    ${PCRE_DIR}/pcre_study.c
    ${PCRE_DIR}/pcre_tables.c
    ${PCRE_DIR}/pcre_ucd.c
    ${PCRE_DIR}/pcre_valid_utf8.c
    ${PCRE_DIR}/pcre_version.c
    ${PCRE_DIR}/pcre_xclass.c
)
source_group(PCRE FILES ${PCRE_SOURCES})

add_library(a_util_regex STATIC 
    regularexpression.h
    regularexpression.cpp
    ${PCRE_SOURCES}
)

target_compile_definitions(a_util_regex PRIVATE HAVE_CONFIG_H PCRE_STATIC pcrecpp=pcrecppinternal)

target_include_directories(a_util_regex
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
          $<INSTALL_INTERFACE:include>
    PRIVATE ${PCRE_CUSTOM_BINARY_DIR} ${PCRE_DIR}
)

target_link_libraries(a_util_regex PUBLIC a_util_base a_util_memory)

set_target_properties(a_util_regex PROPERTIES FOLDER a_util)

install(TARGETS a_util_regex
        EXPORT a_util_regex
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

install(EXPORT a_util_regex FILE a_util_regex_targets.cmake DESTINATION lib/cmake/a_util_regex)

install(FILES regularexpression.h DESTINATION include/a_util/regex)

##Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/a_util_regex-config-version.cmake
                                 COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/a_util_regex-config-version.cmake
              a_util_regex-config.cmake
        DESTINATION lib/cmake/a_util_regex)