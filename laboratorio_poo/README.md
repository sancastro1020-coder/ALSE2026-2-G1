# Laboratorio de Programación Orientada a Objetos en C++

**Estudiante:** Santiago Castro Delgado  
**Asignatura:** Algoritmos en Sistemas Electrónicos 2026

## Descripción

Este proyecto implementa dos sistemas sencillos en C++ aplicando
programación orientada a objetos.

### Ejercicio 1: Sistema de biblioteca

Permite registrar libros, buscarlos por título o autor, mostrar los
disponibles, prestar libros, devolverlos y eliminarlos mediante su ISBN.

### Ejercicio 2: Sistema de alquiler de vehículos

Permite registrar autos y bicicletas, consultar los vehículos disponibles,
alquilar un vehículo y registrar su devolución. Se utiliza herencia y
polimorfismo a partir de la clase base `Vehiculo`.

### Ejercicio 3: Sistema de carrito de compras

Pendiente de implementar.

### Ejercicio 4: Diagrama UML

El diagrama UML corresponde al sistema de alquiler de vehículos y muestra
las clases, sus atributos, métodos y relaciones.

## Estructura

- `include/`: declaraciones de clases.
- `src/`: implementaciones y programas principales.
- `docs/`: documentación y diagrama UML.
- `CMakeLists.txt`: configuración de compilación.

## Compilación

Desde la raíz del repositorio:

```bash
cmake -S laboratorio_poo -B laboratorio_poo/build
cmake --build laboratorio_poo/build
