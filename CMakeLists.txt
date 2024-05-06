cmake_minimum_required(VERSION 3.27)
project(Pyroeffect C)

set(CMAKE_C_STANDARD 11)

include_directories(max6675/src)

add_executable(Pyroeffect
        max6675/src/main.c
        max6675/src/Max6675_Temperature.c
        max6675/src/Max6675_Temperature.h
        max6675/src/receiving_data_max6675.c
        max6675/src/receiving_data_max6675.h)
