cmake_minimum_required(VERSION 3.10)

project(LaboratorioPOO)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(biblioteca
    src/main.cpp
    src/Libro.cpp
    src/Biblioteca.cpp
)

add_executable(alquiler
    src/main_alquiler.cpp
    src/Vehiculo.cpp
    src/Auto.cpp
    src/Bicicleta.cpp
    src/SistemaAlquiler.cpp
)

add_executable(carrito
    carrito/main_carrito.cpp
    carrito/Producto.cpp
    carrito/Carrito.cpp
)
