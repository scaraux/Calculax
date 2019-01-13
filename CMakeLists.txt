cmake_minimum_required(VERSION 3.13)
project(todd C)

set(CMAKE_C_STANDARD 11)

find_package(curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})
include_directories(src)

add_executable(todd
        src/actions.c
        src/calculator.c
        src/history.c
        src/interpreter.c
        src/interpreter.h
        src/main.c
        src/memory.c
        src/split_line.c
        src/utils.c)

target_link_libraries(todd ${CURSES_LIBRARIES})



