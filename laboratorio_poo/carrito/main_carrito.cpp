#include "Producto.h"
#include "Carrito.h"
#include <iostream>

int main()
{
    Producto laptop("Laptop", 2500000, 10);
    Producto mouse("Mouse", 50000, 20);
    Producto teclado("Teclado", 120000, 15);

    Carrito carrito;

    carrito.agregarProducto(&laptop, 1);
    carrito.agregarProducto(&mouse, 2);
    carrito.agregarProducto(&teclado, 1);

    carrito.mostrarCarrito();

    std::cout << "\nEliminando Mouse..." << std::endl;
    carrito.eliminarProducto("Mouse");

    carrito.mostrarCarrito();

    return 0;
}

