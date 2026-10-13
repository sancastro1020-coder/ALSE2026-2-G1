#include "../include/Bicicleta.h"
#include <iostream>

Bicicleta::Bicicleta(std::string marca, std::string modelo,
                     std::string placa, std::string tipo)
    : Vehiculo(marca, modelo, placa)
{
    this->tipo = tipo;
}

void Bicicleta::mostrarInformacion() const
{
    std::cout << "Bicicleta"
              << " | Marca: " << marca
              << " | Modelo: " << modelo
              << " | Placa: " << placa
              << " | Tipo: " << tipo
              << " | Disponible: "
              << (disponible ? "Si" : "No")
              << std::endl;
}
