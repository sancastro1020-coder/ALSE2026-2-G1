#include "../include/Libro.h"

Libro::Libro(std::string titulo, std::string autor, std::string isbn)
{
    this->titulo = titulo;
    this->autor = autor;
    this->isbn = isbn;
    this->disponible = true;
}

std::string Libro::getTitulo() const
{
    return titulo;
}

std::string Libro::getAutor() const
{
    return autor;
}

std::string Libro::getIsbn() const
{
    return isbn;
}

bool Libro::estaDisponible() const
{
    return disponible;
}

void Libro::prestar()
{
    if (disponible)
    {
        disponible = false;
    }
}

void Libro::devolver()
{
    disponible = true;
}
