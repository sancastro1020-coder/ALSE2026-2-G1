#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string columnTitle)
{
    int resultado = 0;

    for (int i = 0; i < columnTitle.length(); i++)
    {
        int valor = columnTitle[i] - 'A' + 1;

        resultado = resultado * 26 + valor;
    }

    return resultado;
}

int main()
{
    string columna = "AB";

    int resultado = titleToNumber(columna);

    cout << resultado;

    return 0;
}
