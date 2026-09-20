#include <iostream>
#include <string>
using namespace std;

struct Posicion
{
    int x;
    int y;
};

enum Direccion
{
    NORTE,
    ESTE,
    SUR,
    OESTE
};

class Robot
{
private:
    Posicion posicion;
    Direccion direccion;

public:

    Robot(int x, int y, Direccion dir)
    {
        posicion.x = x;
        posicion.y = y;
        direccion = dir;
    }

    void girarDerecha()
    {
        if (direccion == NORTE)
        {
            direccion = ESTE;
        }
        else if (direccion == ESTE)
        {
            direccion = SUR;
        }
        else if (direccion == SUR)
        {
            direccion = OESTE;
        }
        else if (direccion == OESTE)
        {
            direccion = NORTE;
        }
    }

    void girarIzquierda()
    {
        if (direccion == NORTE)
        {
            direccion = OESTE;
        }
        else if (direccion == OESTE)
        {
            direccion = SUR;
        }
        else if (direccion == SUR)
        {
            direccion = ESTE;
        }
        else if (direccion == ESTE)
        {
            direccion = NORTE;
        }
    }

    void avanzar()
    {
        if (direccion == NORTE)
        {
            posicion.y++;
        }
        else if (direccion == ESTE)
        {
            posicion.x++;
        }
        else if (direccion == SUR)
        {
            posicion.y--;
        }
        else if (direccion == OESTE)
        {
            posicion.x--;
        }
    }

    void ejecutar(string instrucciones)
    {
        for (char instruccion : instrucciones)
        {
            if (instruccion == 'R')
            {
                girarDerecha();
            }
            else if (instruccion == 'L')
            {
                girarIzquierda();
            }
            else if (instruccion == 'A')
            {
                avanzar();
            }
        }
    }

    void mostrar()
    {
        cout << "Posicion: {" 
             << posicion.x << ", " 
             << posicion.y << "}" << endl;

        cout << "Direccion: ";

        if (direccion == NORTE)
        {
            cout << "Norte";
        }
        else if (direccion == ESTE)
        {
            cout << "Este";
        }
        else if (direccion == SUR)
        {
            cout << "Sur";
        }
        else
        {
            cout << "Oeste";
        }

        cout << endl;
    }
};


int main()
{
    Robot robot(7, 3, NORTE);

    string instrucciones = "RAALAL";

    robot.ejecutar(instrucciones);

    robot.mostrar();

    return 0;
}
