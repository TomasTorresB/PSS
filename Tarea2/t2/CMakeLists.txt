cmake_minimum_required(VERSION 3.12)
project(t2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t2
        colapri-lista.c
    test-colapri-lista.c
        colapri-arreglo.c)
