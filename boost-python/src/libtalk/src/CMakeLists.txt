set(SOURCES functions.cpp 
            sensor.cpp
            )


add_library(talk SHARED ${SOURCES})
install(TARGETS talk 
        DESTINATION ${CMAKE_INSTALL_LIBDIR})

