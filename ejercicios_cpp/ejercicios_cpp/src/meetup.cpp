#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdio>
using namespace std;

string meetupDate(int year, int month, const string& weekday, const string& week) {
    const string dias[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int objetivo = -1;
    for (int i = 0; i < 7; ++i) if (weekday == dias[i]) objetivo = i;
    if (objetivo == -1) throw invalid_argument("Dia de semana invalido");
    auto diaSemana = [](int y, int m, int d) {
        tm fecha{}; fecha.tm_year = y - 1900; fecha.tm_mon = m - 1; fecha.tm_mday = d;
        mktime(&fecha); return fecha.tm_wday; // 0 domingo ... 6 sabado
    };
    int diasMes = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) diasMes = 30;
    else if (month == 2) {
        bool bisiesto = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        diasMes = bisiesto ? 29 : 28;
    }
    int dia = -1;
    if (week == "teenth") {
        for (int d = 13; d <= 19; ++d) if (diaSemana(year, month, d) == objetivo) { dia = d; break; }
    } else if (week == "last") {
        for (int d = diasMes; d >= diasMes - 6; --d) if (diaSemana(year, month, d) == objetivo) { dia = d; break; }
    } else {
        int numero = week == "first" ? 1 : week == "second" ? 2 : week == "third" ? 3 : week == "fourth" ? 4 : 0;
        if (!numero) throw invalid_argument("Semana invalida");
        int cuenta = 0;
        for (int d = 1; d <= diasMes; ++d) if (diaSemana(year, month, d) == objetivo && ++cuenta == numero) { dia = d; break; }
    }
    if (dia == -1) throw runtime_error("No se encontro fecha");
    char salida[11]; snprintf(salida, sizeof(salida), "%04d-%02d-%02d", year, month, dia);
    return salida;
}
int main() {
    cout << meetupDate(2019, 8, "Tuesday", "third") << '\n';
    cout << meetupDate(2020, 5, "Wednesday", "teenth") << '\n';
}
