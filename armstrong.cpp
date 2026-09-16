#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    int original = numero;
    int temporal = numero;
    int cantidadDigitos = 0;
    int suma = 0;

    // Contar cuantos digitos tiene
    while (temporal > 0)
    {
        cantidadDigitos++;
        temporal = temporal / 10;
    }

    temporal = numero;

    // Sacar cada digito y elevarlo
    while (temporal > 0)
    {
        int digito = temporal % 10;

        suma = suma + pow(digito, cantidadDigitos);

        temporal = temporal / 10;
    }

    if (suma == original)
    {
        cout << "Es un numero de Armstrong" << endl;
    }
    else
    {
        cout << "No es un numero de Armstrong" << endl;
    }

    return 0;
}
