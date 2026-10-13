#ifndef CARRITO_H
#define CARRITO_H

#include "Producto.h"
#include <vector>

class Carrito
{
private:
    std::vector<Producto*> productos;
    std::vector<int> cantidades;

public:
    ~Carrito();

    bool agregarProducto(Producto* producto, int cantidad);
    bool eliminarProducto(std::string nombre);
    double calcularTotal() const;
    void mostrarCarrito() const;
};

#endif
