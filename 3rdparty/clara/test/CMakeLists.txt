##this test is all about finding clara using find_package on customer side
if(a_util_cmake_enable_integrated_tests)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/../Clara-1.1.2)
else()
    find_package(a_util REQUIRED) #necessary to actually being able to find package Clara
    find_package(Clara REQUIRED)
endif()

##only include test if clara can be compiled at all - currently C++11 is necessary
cmake_policy(SET CMP0067 NEW) #honor cxx standard in try_compile for current toolchain
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/try_compile_clara/clara.cpp
     "#include \"${CMAKE_CURRENT_LIST_DIR}/../Clara-1.1.2/clara.hpp\"\n"
     "int main(){return 0;}")

try_compile(_clara_compiles
            ${CMAKE_CURRENT_BINARY_DIR}/try_compile_clara
            SOURCES ${CMAKE_CURRENT_BINARY_DIR}/try_compile_clara/clara.cpp
            )

set(component_clara_AVAILABLE ${_clara_compiles} CACHE INTERNAL
    "Indicate whether component clara is available")

##the actual test
if(_clara_compiles)
    add_executable(clara_include_test clara_include_test.cpp)
    target_link_libraries(clara_include_test PRIVATE GTest::Main Clara)
    add_test(clara_include_test clara_include_test)
    set_target_properties(clara_include_test PROPERTIES FOLDER 3rdparty/test)
else()
    message(STATUS "Clara not supported on this platform. Test disabled.")
endif()