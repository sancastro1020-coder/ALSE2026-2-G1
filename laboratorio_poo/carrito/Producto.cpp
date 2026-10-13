#include "Producto.h"

Producto::Producto(std::string nombre, double precio, int stock)
    : nombre(nombre), precio(precio), stock(stock)
{
}

std::string Producto::getNombre() const
{
    return nombre;
}

double Producto::getPrecio() const
{
    return precio;
}

int Producto::getStock() const
{
    return stock;
}

bool Producto::reducirStock(int cantidad)
{
    if (cantidad <= 0 || cantidad > stock)
    {
        return false;
    }

    stock -= cantidad;
    return true;
}
