#include "../include/Biblioteca.h"
#include <iostream>
#include <algorithm>

void Biblioteca::agregarLibro(const Libro& libro)
{
    libros.push_back(libro);
}

bool Biblioteca::eliminarLibro(std::string isbn)
{
    for (auto it = libros.begin(); it != libros.end(); ++it)
    {
        if (it->getIsbn() == isbn)
        {
            libros.erase(it);
            return true;
        }
    }

    return false;
}

Libro* Biblioteca::buscarPorTitulo(std::string titulo)
{
    for (auto& libro : libros)
    {
        if (libro.getTitulo() == titulo)
        {
            return &libro;
        }
    }

    return nullptr;
}

Libro* Biblioteca::buscarPorAutor(std::string autor)
{
    for (auto& libro : libros)
    {
        if (libro.getAutor() == autor)
        {
            return &libro;
        }
    }

    return nullptr;
}

void Biblioteca::mostrarDisponibles() const
{
    for (const auto& libro : libros)
    {
        if (libro.estaDisponible())
        {
            std::cout << "Titulo: " << libro.getTitulo()
                      << " | Autor: " << libro.getAutor()
                      << " | ISBN: " << libro.getIsbn()
                      << std::endl;
        }
    }
}
