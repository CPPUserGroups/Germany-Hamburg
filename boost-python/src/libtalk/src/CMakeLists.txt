set(SOURCES functions.cpp 
            sensor.cpp
            motor.cpp
            step_motor.cpp
            device.cpp
            )


add_library(talk SHARED ${SOURCES})
install(TARGETS talk 
        DESTINATION ${CMAKE_INSTALL_LIBDIR})

