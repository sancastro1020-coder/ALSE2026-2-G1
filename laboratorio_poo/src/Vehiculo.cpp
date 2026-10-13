#include "../include/Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(std::string marca, std::string modelo, std::string placa)
{
    this->marca = marca;
    this->modelo = modelo;
    this->placa = placa;
    this->disponible = true;
}

std::string Vehiculo::getMarca() const
{
    return marca;
}

std::string Vehiculo::getModelo() const
{
    return modelo;
}

std::string Vehiculo::getPlaca() const
{
    return placa;
}

bool Vehiculo::estaDisponible() const
{
    return disponible;
}

void Vehiculo::alquilar()
{
    if (disponible)
    {
        disponible = false;
    }
}

void Vehiculo::devolver()
{
    disponible = true;
}

void Vehiculo::mostrarInformacion() const
{
    std::cout << "Marca: " << marca
              << " | Modelo: " << modelo
              << " | Placa: " << placa
              << " | Disponible: "
              << (disponible ? "Si" : "No")
              << std::endl;
}

