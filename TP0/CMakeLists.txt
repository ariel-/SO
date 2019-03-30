cmake_minimum_required(VERSION 3.6)
project(tp0 C)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wstrict-prototypes")
set(CMAKE_C_STANDARD 11)

include_directories(tp0 .)
include_directories(Servidor)

add_executable(tp0
        tp0.c
        tp0.h
        utils.c
        utils.h)

add_executable(Server
        Servidor/servidor.c
        Servidor/servidor.h
        Servidor/utils.c
        Servidor/utils.h)

target_link_libraries(tp0 readline commons)
target_link_libraries(Server commons)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tp0.config
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
