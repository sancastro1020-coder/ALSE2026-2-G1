#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spreadsheet
{
private:

    // 26 columnas: A hasta Z
    // rows filas
    vector<vector<int>> hoja;

    // Convierte una referencia como "A1" en el valor de esa celda
    int obtenerCelda(string celda)
    {
        int columna = celda[0] - 'A';

        int fila = stoi(celda.substr(1)) - 1;

        return hoja[fila][columna];
    }

    // Determina si algo es una referencia de celda o un número
    int obtenerValor(string dato)
    {
        if (dato[0] >= 'A' && dato[0] <= 'Z')
        {
            return obtenerCelda(dato);
        }

        return stoi(dato);
    }

public:

    // Constructor
    Spreadsheet(int rows)
    {
        hoja = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    // Establecer valor de una celda
    void setCell(string cell, int value)
    {
        int columna = cell[0] - 'A';

        int fila = stoi(cell.substr(1)) - 1;

        hoja[fila][columna] = value;
    }

    // Reiniciar una celda a 0
    void resetCell(string cell)
    {
        int columna = cell[0] - 'A';

        int fila = stoi(cell.substr(1)) - 1;

        hoja[fila][columna] = 0;
    }

    // Obtener el resultado de una fórmula
    int getValue(string formula)
    {
        // Quitamos el '='
        string expresion = formula.substr(1);

        // Buscamos el '+'
        int posicion = expresion.find('+');

        // Separamos X y Y
        string X = expresion.substr(0, posicion);
        string Y = expresion.substr(posicion + 1);

        int valorX = obtenerValor(X);
        int valorY = obtenerValor(Y);

        return valorX + valorY;
    }
};


int main()
{
    Spreadsheet spreadsheet(3);

    // Ejemplo del problema

    cout << "Resultado 1: "
         << spreadsheet.getValue("=5+7")
         << endl;

    spreadsheet.setCell("A1", 10);

    cout << "Resultado 2: "
         << spreadsheet.getValue("=A1+6")
         << endl;

    spreadsheet.setCell("B2", 15);

    cout << "Resultado 3: "
         << spreadsheet.getValue("=A1+B2")
         << endl;

    spreadsheet.resetCell("A1");

    cout << "Resultado 4: "
         << spreadsheet.getValue("=A1+B2")
         << endl;

    return 0;
}
