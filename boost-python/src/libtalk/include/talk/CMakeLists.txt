set(HEADERS functions.hpp
            exceptions.hpp
    )

install(FILES ${HEADERS} 
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/talk")

