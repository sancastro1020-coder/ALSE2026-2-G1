#include "../include/Biblioteca.h"
#include <iostream>

int main()
{
    Biblioteca biblioteca;

    Libro libro1("El principito", "Antoine de Saint-Exupery", "001");
    Libro libro2("Cien años de soledad", "Gabriel Garcia Marquez", "002");
    Libro libro3("1984", "George Orwell", "003");

    // Agregar libros
    biblioteca.agregarLibro(libro1);
    biblioteca.agregarLibro(libro2);
    biblioteca.agregarLibro(libro3);

    std::cout << "=== LIBROS DISPONIBLES ===" << std::endl;
    biblioteca.mostrarDisponibles();

    // Buscar por titulo
    Libro* encontrado = biblioteca.buscarPorTitulo("1984");

    if (encontrado != nullptr)
    {
        std::cout << "\nLibro encontrado: "
                  << encontrado->getTitulo() << std::endl;

        encontrado->prestar();
    }

    std::cout << "\n=== DISPONIBIBLES DESPUES DEL PRESTAMO ==="
              << std::endl;
    biblioteca.mostrarDisponibles();

    // Buscar por autor
    Libro* porAutor =
        biblioteca.buscarPorAutor("Gabriel Garcia Marquez");

    if (porAutor != nullptr)
    {
        std::cout << "\nEncontrado por autor: "
                  << porAutor->getTitulo() << std::endl;
    }

    // Eliminar un libro
    if (biblioteca.eliminarLibro("001"))
    {
        std::cout << "\nLibro con ISBN 001 eliminado."
                  << std::endl;
    }

    return 0;
}

