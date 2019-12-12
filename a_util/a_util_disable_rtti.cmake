if(MSVC)
    #disable RTTI msvc
    add_compile_options(/GR)
else(MSVC)
    #disable RTTI gcc (only cpp files)
    add_compile_options($<$<AND:$<CXX_COMPILER_ID:GNU>,$<COMPILE_LANGUAGE:CXX>>:-fno-rtti>)
endif(MSVC)
