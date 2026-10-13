#ifndef SISTEMA_ALQUILER_H
#define SISTEMA_ALQUILER_H

#include "Vehiculo.h"
#include <vector>
#include <string>

class SistemaAlquiler
{
private:
    std::vector<Vehiculo*> vehiculos;

public:
    ~SistemaAlquiler();

    void registrarVehiculo(Vehiculo* vehiculo);
    bool alquilarVehiculo(std::string placa);
    bool devolverVehiculo(std::string placa);
    void mostrarDisponibles() const;
};

#endif
