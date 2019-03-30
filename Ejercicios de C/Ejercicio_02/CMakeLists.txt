cmake_minimum_required(VERSION 3.6)
project(Ejercicio_02 C)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wstrict-prototypes")
set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ejercicio_02
        Driver.c
        File.c
        File.h)

target_link_libraries(Ejercicio_02 commons)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tests.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
