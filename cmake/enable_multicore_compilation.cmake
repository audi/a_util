set(_msvc_compiler "$<OR:$<CXX_COMPILER_ID:MSVC>,$<C_COMPILER_ID:MSVC>>")
add_compile_options($<${_msvc_compiler}:/MP>)
unset(_msvc_compiler)