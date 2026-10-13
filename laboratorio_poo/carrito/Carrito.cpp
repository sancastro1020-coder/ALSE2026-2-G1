#include "Carrito.h"
#include <iostream>

Carrito::~Carrito()
{
}

bool Carrito::agregarProducto(Producto* producto, int cantidad)
{
    if (producto == nullptr || cantidad <= 0)
    {
        return false;
    }

    if (producto->getStock() < cantidad)
    {
        return false;
    }

    productos.push_back(producto);
    cantidades.push_back(cantidad);

    return true;
}

bool Carrito::eliminarProducto(std::string nombre)
{
    for (size_t i = 0; i < productos.size(); i++)
    {
        if (productos[i]->getNombre() == nombre)
        {
            productos.erase(productos.begin() + i);
            cantidades.erase(cantidades.begin() + i);
            return true;
        }
    }

    return false;
}

double Carrito::calcularTotal() const
{
    double total = 0;

    for (size_t i = 0; i < productos.size(); i++)
    {
        total += productos[i]->getPrecio() * cantidades[i];
    }

    return total;
}

void Carrito::mostrarCarrito() const
{
    std::cout << "=== CARRITO DE COMPRAS ===" << std::endl;

    for (size_t i = 0; i < productos.size(); i++)
    {
        std::cout << "Producto: " << productos[i]->getNombre()
                  << " | Precio: " << productos[i]->getPrecio()
                  << " | Cantidad: " << cantidades[i]
                  << " | Subtotal: "
                  << productos[i]->getPrecio() * cantidades[i]
                  << std::endl;
    }

    std::cout << "Total: " << calcularTotal() << std::endl;
}
