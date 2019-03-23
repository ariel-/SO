cmake_minimum_required(VERSION 3.6)
project(Problema C)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wstrict-prototypes")
set(CMAKE_C_STANDARD 11)

include_directories(src)
include_directories(src/Collections)

add_executable(Problema
        src/Collections/list.c
        src/Collections/list.h
        src/Collections/node.h
        src/Collections/queue.c
        src/Collections/queue.h
        src/Cliente.c
        src/Cliente.h
        src/Factura.c
        src/Factura.h
        src/Item.c
        src/Item.h
        src/Leaks.c)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/ticket.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources)
