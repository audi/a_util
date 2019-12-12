if (CMAKE_VERSION VERSION_LESS 3.0.0)
    message(FATAL_ERROR "a_util requires at least CMake version 3.0.0")
endif()

get_filename_component(_a_util_install_prefix "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

if (NOT a_util_FIND_COMPONENTS)
    ##if there are no components given, simply list all components...
    file(GLOB a_util_FIND_COMPONENTS_PATH RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${_a_util_install_prefix}/a_util_*)
    foreach(component ${a_util_FIND_COMPONENTS_PATH})
        string(REPLACE "../a_util_" "" component ${component})
        list(APPEND a_util_FIND_COMPONENTS ${component})
    endforeach(component ${a_util_FIND_COMPONENTS_PATH})

    ##create interface target, pulling in all individual component libraries at once
    if(NOT TARGET a_util)
        add_library(a_util INTERFACE)
        foreach(component ${a_util_FIND_COMPONENTS})
            target_link_libraries(a_util INTERFACE a_util_${component})
        endforeach()
    endif()
endif()

set(_a_util_FIND_PARTS_REQUIRED)
if (a_util_FIND_REQUIRED)
    set(_a_util_FIND_PARTS_REQUIRED REQUIRED)
endif()
set(_a_util_FIND_PARTS_QUIET)
if (a_util_FIND_QUIETLY)
    set(_a_util_FIND_PARTS_QUIET QUIET)
endif()

set(_a_util_NOTFOUND_MESSAGE)

foreach(component ${a_util_FIND_COMPONENTS})
    if(NOT TARGET a_util_${component})
        find_package(a_util_${component}
            ${_a_util_FIND_PARTS_QUIET}
            ${_a_util_FIND_PARTS_REQUIRED}
            PATHS "${_a_util_install_prefix}" NO_DEFAULT_PATH
        )
        if (NOT a_util_${component}_FOUND)
            if (a_util_FIND_REQUIRED_${component})
                set(_a_util_NOTFOUND_MESSAGE "${_a_util_NOTFOUND_MESSAGE}Failed to find a_util component \"${component}\" config file at \"${_a_util_install_prefix}/a_util_${component}/a_util_${component}-config.cmake\"\n")
            elseif(NOT a_util_FIND_QUIETLY)
                message(WARNING "Failed to find a_util component \"${component}\" config file at \"${_a_util_install_prefix}/a_util_${component}/a_util_${component}-config.cmake\"")
            endif()
        endif()
    endif(NOT TARGET a_util_${component})
endforeach()

if (_a_util_NOTFOUND_MESSAGE)
    set(a_util_NOT_FOUND_MESSAGE "${_a_util_NOTFOUND_MESSAGE}")
    set(a_util_FOUND False)
endif()

##3rdparty components - do not include them directly but make them available via subsequent calls
# to find_package()
set(Clara_DIR ${_a_util_install_prefix}/3rdparty)