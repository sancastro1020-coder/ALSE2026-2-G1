#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto
{
private:
    std::string nombre;
    double precio;
    int stock;

public:
    Producto(std::string nombre, double precio, int stock);

    std::string getNombre() const;
    double getPrecio() const;
    int getStock() const;

    bool reducirStock(int cantidad);
};

#endif
