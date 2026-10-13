#include "../include/Auto.h"
#include <iostream>

Auto::Auto(std::string marca, std::string modelo,
           std::string placa, int capacidadPasajeros)
    : Vehiculo(marca, modelo, placa)
{
    this->capacidadPasajeros = capacidadPasajeros;
}

void Auto::mostrarInformacion() const
{
    std::cout << "Auto"
              << " | Marca: " << marca
              << " | Modelo: " << modelo
              << " | Placa: " << placa
              << " | Pasajeros: " << capacidadPasajeros
              << " | Disponible: "
              << (disponible ? "Si" : "No")
              << std::endl;
}
