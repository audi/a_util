# a_util5 library #

## Delivered Libraries ##

This library contains following packages:

- a_util_concurrency
- a_util_datetime
- a_util_filesystem
- a_util_logging
- a_util_memory
- a_util_parser
- a_util_process
- a_util_regex
- a_util_result
- a_util_strings
- a_util_system
- a_util_variant
- a_util_xml

## Changelog ##

The changelog can be found [here](doc/changelog.md)

## How to build ##

### Build Environment ###

The libraries are currently built and tested using the following compilers and operating systems:

#### Windows ####
- Visual C++ (x86, x86_64): 14.0

#### Linux ####
- GCC, C++11 (x86_64): 4.8.4
- GCC, C++14 (x86_64, armv8): 5.4.0

#### QNX ####
- GCC, C++11 (x86): 5.2

### Build a_util ###

- Use [CMake](https://cmake.org/) at least in version 3.10.1  
- Choose your branch i.e. `"master"`
- Use CMakeLists.txt within the main directory as source directory
- Do not forget to set `CMAKE_INSTALL_PREFIX`
- Build and install for Debug and RelWithDebInfo
- Command line for e.g. Windows
> cmake <source directory> -H<source directory> -B<build directory> -G "Visual Studio 15 2017 Win64" -T v140 -DCMAKE_INSTALL_PREFIX=<install directory> -Da_util_cmake_enable_integrated_tests=ON -DGTEST_DIR=<GTest directory> -DGTEST_LIBRARY=<GTest directory>/lib/gtest.lib -DGTEST_INCLUDE_DIR=<GTest directory>/include -DGTEST_MAIN_LIBRARY=<GTest directory>/lib/gtest_main.lib -DDOXYGEN_EXECUTABLE=<doxygen binary directory>/doxygen.exe -DDOXYGEN_DOT_EXECUTABLE=<graphviz binary directory>/dot.exe


#### Optional requirements 

<table>
<tr>
<td>
a_util_cmake_enable_documentation ON/OFF 
</td>
<td>
choose wether a documentation is created or not
</td>
<td>
dependency to a valid doxygen executable needed (see http://www.doxygen.nl/)
</td>
</tr>
<tr>
<td>
a_util_cmake_enable_integrated_tests ON/OFF 
</td>
<td>
choose wether the tests where build while building the libraries or not
</td>
<td>
dependency to a valid gtest package needed (see https://github.com/google/googletest)
</td>
</tr>
</table>



## License Information ##

### a_util Library - License ###

The a_util Library is delivered under the
[MPL - Mozilla Public License - Version 2.0](doc/license/MPL2.0.txt)

### Used software license information ###

The a_util library is delivered with 3rdparty dependencies.
See [3rdparty Software we are very glad to use](doc/license/used_oss.md).
