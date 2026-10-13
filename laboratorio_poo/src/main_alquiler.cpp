#include "../include/SistemaAlquiler.h"
#include "../include/Auto.h"
#include "../include/Bicicleta.h"
#include <iostream>

int main()
{
    SistemaAlquiler sistema;

    sistema.registrarVehiculo(
        new Auto("Toyota", "Corolla", "ABC123", 5)
    );

    sistema.registrarVehiculo(
        new Bicicleta("GW", "Lynx", "BIC001", "Montaña")
    );

    std::cout << "=== VEHICULOS DISPONIBLES ===" << std::endl;
    sistema.mostrarDisponibles();

    std::cout << "\n=== ALQUILAR AUTO ===" << std::endl;

    if (sistema.alquilarVehiculo("ABC123"))
        std::cout << "Auto alquilado correctamente." << std::endl;
    else
        std::cout << "No se pudo alquilar el auto." << std::endl;

    std::cout << "\n=== DISPONIBLES DESPUES DEL ALQUILER ==="
              << std::endl;
    sistema.mostrarDisponibles();

    std::cout << "\n=== DEVOLVER AUTO ===" << std::endl;

    if (sistema.devolverVehiculo("ABC123"))
        std::cout << "Auto devuelto correctamente." << std::endl;
    else
        std::cout << "No se pudo devolver el auto." << std::endl;

    std::cout << "\n=== DISPONIBLES AL FINAL ===" << std::endl;
    sistema.mostrarDisponibles();

    return 0;
}

