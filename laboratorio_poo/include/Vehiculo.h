#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo
{
protected:
    std::string marca;
    std::string modelo;
    std::string placa;
    bool disponible;

public:
    Vehiculo(std::string marca, std::string modelo, std::string placa);

    virtual ~Vehiculo() = default;

    std::string getMarca() const;
    std::string getModelo() const;
    std::string getPlaca() const;
    bool estaDisponible() const;

    void alquilar();
    void devolver();

    virtual void mostrarInformacion() const;
};

#endif

