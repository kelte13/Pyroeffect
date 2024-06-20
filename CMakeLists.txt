cmake_minimum_required(VERSION 3.27)
project(Pyroeffect C)

set(CMAKE_C_STANDARD 11)

include_directories(max6675/src)

add_executable(Pyroeffect
        max6675/src/main.c
        max6675/src/Max6675_Temperature.c
        max6675/src/Max6675_Temperature.h
        max6675/src/receiving_data_max6675.c
        max6675/src/receiving_data_max6675.h
        max6675/src/HAL_SPI_Received.c
        max6675/src/write_to_file.c
        max6675/src/write_to_file.c
        max6675/src/delete_data_from_file.c)
