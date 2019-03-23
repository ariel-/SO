cmake_minimum_required(VERSION 3.6)
project(Ejercicio_01 C)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -pedantic -Wstrict-prototypes")
set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ejercicio_01
        Basics.c
        Basics.h
        Driver.c)
