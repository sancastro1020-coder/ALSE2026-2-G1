#include "../include/SistemaAlquiler.h"
#include <iostream>

SistemaAlquiler::~SistemaAlquiler()
{
    for (Vehiculo* vehiculo : vehiculos)
    {
        delete vehiculo;
    }
}

void SistemaAlquiler::registrarVehiculo(Vehiculo* vehiculo)
{
    if (vehiculo != nullptr)
    {
        vehiculos.push_back(vehiculo);
    }
}

bool SistemaAlquiler::alquilarVehiculo(std::string placa)
{
    for (Vehiculo* vehiculo : vehiculos)
    {
        if (vehiculo->getPlaca() == placa &&
            vehiculo->estaDisponible())
        {
            vehiculo->alquilar();
            return true;
        }
    }

    return false;
}

bool SistemaAlquiler::devolverVehiculo(std::string placa)
{
    for (Vehiculo* vehiculo : vehiculos)
    {
        if (vehiculo->getPlaca() == placa &&
            !vehiculo->estaDisponible())
        {
            vehiculo->devolver();
            return true;
        }
    }

    return false;
}

void SistemaAlquiler::mostrarDisponibles() const
{
    for (const Vehiculo* vehiculo : vehiculos)
    {
        if (vehiculo->estaDisponible())
        {
            vehiculo->mostrarInformacion();
        }
    }
}
