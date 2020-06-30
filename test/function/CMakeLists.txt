if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wno-unknown-pragmas -Wno-reorder -Wextra -pedantic)
endif()

##get all tests listed inside ***_test_projects.cmake files (as cmake subdirectories)
include(../../a_util/a_util_test_projects.cmake)
include(../../3rdparty/3rdparty_test_projects.cmake)