cmake_minimum_required(VERSION 3.10)

# Set the project name
project(VariantProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# CMakeLists.txt
include_directories(${CMAKE_SOURCE_DIR}/T-4/Variant)
# Add the executable
add_executable(VariantProject
        "T-4/Variant/variant.h"
        "T-4/Variant/variant.cpp"
        "T-4/json11/json11.cpp"
        "T-4/json11/json11.hpp"
        "T-4/prueba /prueba.cpp"
        "T-4/prueba /prueba.h"
        "T-2/calculartor.cpp"
        "T-2/calculartor.h"
        "T-3/labmain.cpp"
        "T-3/labmain.h"
        "Menu/menu.cpp"
        "Menu/menu.h"
        "main.cpp"
)

