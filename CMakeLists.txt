cmake_minimum_required(VERSION 3.23)
project(Lab_Micros_2022 C)

set(CMAKE_C_STANDARD 99)

#[[ Copia del archivo de la carpeta [/data] a la carpeta [debug] para poder ser identificado ]]
configure_file(laboratorio_1/data/archivo.csv
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
add_executable(Lab_Micros_2022.exe laboratorio_1/reto1.c)
