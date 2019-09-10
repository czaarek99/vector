cmake_minimum_required(VERSION 3.12)

project(vector C)

set(CMAKE_C_STANDARD 11)

add_executable(vector
        src/main.c
        src/vector.h src/vector.c
)
