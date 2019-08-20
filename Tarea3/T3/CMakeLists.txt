cmake_minimum_required(VERSION 3.12)
project(T3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(T3
        test-reunion.c
            reunion.c)
