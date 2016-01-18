set(HEADERS functions.hpp
            exceptions.hpp
            sensor.hpp
            motor.hpp
            step_motor.hpp
    )

install(FILES ${HEADERS} 
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/talk")

