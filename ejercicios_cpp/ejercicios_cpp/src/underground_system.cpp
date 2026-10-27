#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
    struct Viaje { string estacion; int tiempo; };
    struct Resumen { long long total = 0; int cantidad = 0; };
    unordered_map<int, Viaje> activos;
    unordered_map<string, Resumen> rutas;
    string clave(const string& a, const string& b) const { return a + "->" + b; }
public:
    void checkIn(int id, string stationName, int t) { activos[id] = {stationName, t}; }
    void checkOut(int id, string stationName, int t) {
        auto viaje = activos.at(id);
        auto& r = rutas[clave(viaje.estacion, stationName)];
        r.total += t - viaje.tiempo;
        ++r.cantidad;
        activos.erase(id);
    }
    double getAverageTime(string startStation, string endStation) {
        const auto& r = rutas.at(clave(startStation, endStation));
        return static_cast<double>(r.total) / r.cantidad;
    }
};
int main() {
    UndergroundSystem s;
    s.checkIn(45, "Leyton", 3); s.checkIn(32, "Paradise", 8); s.checkIn(27, "Leyton", 10);
    s.checkOut(45, "Waterloo", 15); s.checkOut(27, "Waterloo", 20); s.checkOut(32, "Cambridge", 22);
    cout << "Promedio Leyton-Waterloo: " << s.getAverageTime("Leyton", "Waterloo") << '\n';
}
