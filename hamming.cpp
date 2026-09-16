#include <iostream>
#include <string>
using namespace std;

int hammingDistance(string cadena1, string cadena2)
{
    int diferencias = 0;

    for (int i = 0; i < cadena1.length(); i++)
    {
        if (cadena1[i] != cadena2[i])
        {
            diferencias++;
        }
    }

    return diferencias;
}

int main()
{
    string cadena1 = "GAGCCTACTAACGGGAT";
    string cadena2 = "CATCGTAATGACGGGCT";

    int resultado = hammingDistance(cadena1, cadena2);

    cout << "Distancia de Hamming: " << resultado << endl;

    return 0;
}
