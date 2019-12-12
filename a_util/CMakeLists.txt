##set global compiler options
include(a_util_disable_rtti.cmake)

##set library name conventions
include(../cmake/set_library_naming_conventions.cmake)

##all a_util components
add_subdirectory(base)
add_subdirectory(strings)
add_subdirectory(filesystem)
add_subdirectory(memory)
add_subdirectory(xml)
add_subdirectory(regex)
add_subdirectory(variant)
add_subdirectory(datetime)
add_subdirectory(system)
add_subdirectory(concurrency)
add_subdirectory(logging)
add_subdirectory(result)
add_subdirectory(parser)
add_subdirectory(process)

##create interface target, pulling in all individual component libraries at once
add_library(a_util INTERFACE)
target_link_libraries(a_util INTERFACE a_util_base)
target_link_libraries(a_util INTERFACE a_util_strings)
target_link_libraries(a_util INTERFACE a_util_filesystem)
target_link_libraries(a_util INTERFACE a_util_memory)
target_link_libraries(a_util INTERFACE a_util_xml)
target_link_libraries(a_util INTERFACE a_util_regex)
target_link_libraries(a_util INTERFACE a_util_variant)
target_link_libraries(a_util INTERFACE a_util_datetime)
target_link_libraries(a_util INTERFACE a_util_system)
target_link_libraries(a_util INTERFACE a_util_concurrency)
target_link_libraries(a_util INTERFACE a_util_logging)
target_link_libraries(a_util INTERFACE a_util_result)
target_link_libraries(a_util INTERFACE a_util_parser)
target_link_libraries(a_util INTERFACE a_util_process)

##TODO: Header files to install automatically adding?!
install(FILES base.h
              filesystem.h
              memory.h
              strings.h
              xml.h
              regex.h
              variant.h
              datetime.h
              system.h
              concurrency.h
              logging.h
              result.h
              parser.h
              process.h
        DESTINATION include/a_util)
