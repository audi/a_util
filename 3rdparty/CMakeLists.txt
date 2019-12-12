add_subdirectory(boost)
add_subdirectory(clara)
add_subdirectory(pcre)
add_subdirectory(pugixml)
add_subdirectory(uuid)
add_subdirectory(utfcpp)

##license information must be delivered
install(FILES boost/boost_1_64_0/boost/current_function.hpp 
        DESTINATION 3rdparty/boost/boost_1_64_0/boost)
install(FILES clara/Clara-1.1.2/LICENSE.txt clara/Clara-1.1.2/README.md 
        DESTINATION 3rdparty/clara/Clara-1.1.2)
install(FILES pcre/pcre-8.39/LICENCE
        DESTINATION 3rdparty/pcre/pcre-8.39)
install(FILES pugixml/pugixml-1.8/readme.txt
        DESTINATION 3rdparty/pugixml/pugixml-1.8)
install(FILES uuid/uuid-1.6.2/license.txt
        DESTINATION 3rdparty/uuid/uuid-1.6.2)
install(FILES utfcpp/utf8_v2_3_4/source/utf8.h
        DESTINATION 3rdparty/utfcpp/utf8_v2_3_4/source)