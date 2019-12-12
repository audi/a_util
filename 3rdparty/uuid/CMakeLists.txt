set(UUID_DIR ${CMAKE_CURRENT_LIST_DIR}/uuid-1.6.2 CACHE INTERNAL "UUID directory")
add_library(uuid OBJECT
    ${UUID_DIR}/uuid++.cc
    ${UUID_DIR}/uuid.c
    ${UUID_DIR}/uuid_dce.c
    ${UUID_DIR}/uuid_mac.c
    ${UUID_DIR}/uuid_md5.c
    ${UUID_DIR}/uuid_prng.c
    ${UUID_DIR}/uuid_sha1.c
    ${UUID_DIR}/uuid_str.c
    ${UUID_DIR}/uuid_time.c
    ${UUID_DIR}/uuid_ui128.c
    ${UUID_DIR}/uuid_ui64.c
)
set_target_properties(uuid PROPERTIES FOLDER 3rdparty)