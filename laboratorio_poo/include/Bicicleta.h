#ifndef BICICLETA_H
#define BICICLETA_H

#include "Vehiculo.h"

class Bicicleta : public Vehiculo
{
private:
    std::string tipo;

public:
    Bicicleta(std::string marca, std::string modelo,
              std::string placa, std::string tipo);

    void mostrarInformacion() const override;
};

#endif

