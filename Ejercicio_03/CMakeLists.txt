cmake_minimum_required(VERSION 3.6)
project(Ejercicio_03 C)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wstrict-prototypes")
set(CMAKE_C_STANDARD 11)

add_executable(Ejercicio_03
        Solucion/Ejercicio3.c)
