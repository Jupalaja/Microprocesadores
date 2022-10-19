cmake_minimum_required(VERSION 3.23)
project(Lab_Micros_2022 C)

set(CMAKE_C_STANDARD 99)

file(GLOB MY_FILES ${CMAKE_CURRENT_BINARY_DIR}"*.csv")
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/laboratorio_1/data/)
configure_file(laboratorio_1/data/archivo.csv
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
add_executable(Lab_Micros_2022 laboratorio_1/reto1.c)
