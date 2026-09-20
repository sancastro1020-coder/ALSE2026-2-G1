#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Posicion
{
    int fila;
    int columna;
};

Posicion convertirPosicion(string casilla)
{
    Posicion posicion;

    // Convertir letra de columna
    posicion.columna = casilla[0] - 'a';

    // Convertir número de fila
    // En ajedrez, 8 está arriba y 1 abajo
    posicion.fila = 8 - (casilla[1] - '0');

    return posicion;
}

bool puedenAtacarse(string reina1, string reina2)
{
    Posicion p1 = convertirPosicion(reina1);
    Posicion p2 = convertirPosicion(reina2);

    // Misma fila
    if (p1.fila == p2.fila)
    {
        return true;
    }

    // Misma columna
    if (p1.columna == p2.columna)
    {
        return true;
    }

    // Misma diagonal
    if (abs(p1.fila - p2.fila) == abs(p1.columna - p2.columna))
    {
        return true;
    }

    return false;
}

int main()
{
    string reinaBlanca;
    string reinaNegra;

    cout << "Posicion de la reina blanca: ";
    cin >> reinaBlanca;

    cout << "Posicion de la reina negra: ";
    cin >> reinaNegra;

    if (puedenAtacarse(reinaBlanca, reinaNegra))
    {
        cout << "Las reinas pueden atacarse." << endl;
    }
    else
    {
        cout << "Las reinas NO pueden atacarse." << endl;
    }

    return 0;
}
