#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include <vector>
#include <string>

class Biblioteca
{
private:
    std::vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro);
    bool eliminarLibro(std::string isbn);
    Libro* buscarPorTitulo(std::string titulo);
    Libro* buscarPorAutor(std::string autor);
    void mostrarDisponibles() const;
};

#endif
