cmake_minimum_required(VERSION 3.29)
project(Caso_Final_Integrador_Tema_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(Variant)

add_executable(Caso_Final_Integrador_Tema_4
    Variant/Variant.cpp
    Variant/Variant.h
    json11/json11.cpp)
