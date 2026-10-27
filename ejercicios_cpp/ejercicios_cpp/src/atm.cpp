#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
class ATM {
    // Orden de denominaciones: 20, 50, 100, 200, 500
    array<long long, 5> billetes{0, 0, 0, 0, 0};
    const array<int, 5> valores{20, 50, 100, 200, 500};
public:
    void deposit(const array<int, 5>& cantidad) {
        for (int i = 0; i < 5; ++i) billetes[i] += cantidad[i];
    }
    array<int, 5> withdraw(int amount) {
        array<int, 5> usados{0, 0, 0, 0, 0};
        long long restante = amount;
        for (int i = 4; i >= 0; --i) {
            long long tomar = min(billetes[i], restante / valores[i]);
            usados[i] = static_cast<int>(tomar);
            restante -= tomar * valores[i];
        }
        if (restante != 0) return {-1};
        for (int i = 0; i < 5; ++i) billetes[i] -= usados[i];
        return usados;
    }
};
int main() {
    ATM cajero; cajero.deposit({0, 0, 1, 2, 1});
    auto r = cajero.withdraw(600);
    cout << "Billetes (20, 50, 100, 200, 500): ";
    for (int x : r) cout << x << ' ';
    cout << '\n';
}
