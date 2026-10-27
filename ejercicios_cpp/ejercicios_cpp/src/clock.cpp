#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
class Clock {
    int minutos;
    static int normalizar(int total) { total %= 1440; if (total < 0) total += 1440; return total; }
public:
    Clock(int hora, int minuto) : minutos(normalizar(hora * 60 + minuto)) {}
    Clock plus(int agregar) const { return Clock(0, minutos + agregar); }
    Clock minus(int restar) const { return Clock(0, minutos - restar); }
    string toString() const {
        ostringstream out; out << setw(2) << setfill('0') << minutos / 60 << ':'
                                << setw(2) << setfill('0') << minutos % 60;
        return out.str();
    }
    bool operator==(const Clock& otro) const { return minutos == otro.minutos; }
};
int main() {
    Clock reloj(8, 0);
    cout << "Hora inicial: " << reloj.toString() << '\n';
    cout << "Mas 90 minutos: " << reloj.plus(90).toString() << '\n';
    cout << "Menos 10 minutos: " << reloj.minus(10).toString() << '\n';
    cout << boolalpha << "08:00 == 32:00: " << (Clock(8, 0) == Clock(32, 0)) << '\n';
}
