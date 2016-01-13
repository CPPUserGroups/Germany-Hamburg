set(SOURCES named_object.cpp 
            moveable.cpp
            step_motor.cpp
            sensor.cpp
            )


add_library(mcs SHARED ${SOURCES})
