#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <mutex>
#include <thread>

using namespace std;


// ============================================================
// EJERCICIO 1 - AuthenticationManager
// ============================================================

class AuthenticationManager
{
private:
    int timeToLive;
    unordered_map<string, int> tokens;

public:

    AuthenticationManager(int timeToLive)
    {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        tokens[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime)
    {
        if (tokens.find(tokenId) != tokens.end())
        {
            if (tokens[tokenId] > currentTime)
            {
                tokens[tokenId] = currentTime + timeToLive;
            }
        }
    }

    int countUnexpiredTokens(int currentTime)
    {
        int contador = 0;

        for (auto token : tokens)
        {
            if (token.second > currentTime)
            {
                contador++;
            }
        }

        return contador;
    }
};

void pruebaAuthenticationManager()
{
    AuthenticationManager authenticationManager(5);

    authenticationManager.renew("aaa", 1);

    authenticationManager.generate("aaa", 2);

    cout << "AuthenticationManager - Resultado 1: "
         << authenticationManager.countUnexpiredTokens(6) << endl;

    authenticationManager.generate("bbb", 7);

    authenticationManager.renew("aaa", 8);

    authenticationManager.renew("bbb", 10);

    cout << "AuthenticationManager - Resultado 2: "
         << authenticationManager.countUnexpiredTokens(15) << endl;
}


// ============================================================
// EJERCICIO 2 - ExamTracker
// ============================================================

class ExamTracker
{
private:
    vector<int> times;
    vector<long long> prefix;

public:

    ExamTracker()
    {
        prefix.push_back(0);
    }

    void record(int time, int score)
    {
        times.push_back(time);

        prefix.push_back(prefix.back() + score);
    }

    long long totalScore(int startTime, int endTime)
    {
        auto inicio = lower_bound(
            times.begin(),
            times.end(),
            startTime
        );

        auto fin = upper_bound(
            times.begin(),
            times.end(),
            endTime
        );

        int indiceInicio = inicio - times.begin();
        int indiceFin = fin - times.begin();

        return prefix[indiceFin] - prefix[indiceInicio];
    }
};

void pruebaExamTracker()
{
    ExamTracker examTracker;

    examTracker.record(1, 98);

    cout << "ExamTracker - Resultado 1: "
         << examTracker.totalScore(1, 1) << endl;

    examTracker.record(5, 99);

    cout << "ExamTracker - Resultado 2: "
         << examTracker.totalScore(1, 3) << endl;

    cout << "ExamTracker - Resultado 3: "
         << examTracker.totalScore(1, 5) << endl;

    cout << "ExamTracker - Resultado 4: "
         << examTracker.totalScore(3, 4) << endl;

    cout << "ExamTracker - Resultado 5: "
         << examTracker.totalScore(2, 5) << endl;
}


// ============================================================
// EJERCICIO 3 - Square Cipher
// ============================================================

string normalize(string texto)
{
    string resultado = "";

    for (char caracter : texto)
    {
        if (isalpha(caracter))
        {
            resultado += tolower(caracter);
        }
    }

    return resultado;
}

string encode(string texto)
{
    string mensaje = normalize(texto);

    int longitud = mensaje.length();

    int columnas = ceil(sqrt(longitud));

    int filas = ceil((double)longitud / columnas);

    if (columnas < filas)
    {
        swap(columnas, filas);
    }

    string resultado = "";

    for (int columna = 0; columna < columnas; columna++)
    {
        for (int fila = 0; fila < filas; fila++)
        {
            int posicion = fila * columnas + columna;

            if (posicion < longitud)
            {
                resultado += mensaje[posicion];
            }
        }

        if (columna != columnas - 1)
        {
            resultado += ' ';
        }
    }

    return resultado;
}

void pruebaSquareCipher()
{
    string texto =
        "If man was meant to stay on the ground, "
        "god would have given us roots.";

    cout << "Square Cipher - Resultado: "
         << encode(texto) << endl;
}


// ============================================================
// EJERCICIO 4 - Bank
// ============================================================

class Bank
{
private:

    struct Account
    {
        long long balance;
        bool abierta;
        mutex mtx;

        Account()
        {
            balance = 0;
            abierta = true;
        }
    };

    unordered_map<int, Account*> cuentas;
    mutex bankMutex;

public:

    bool open(int id)
    {
        lock_guard<mutex> lock(bankMutex);

        if (cuentas.find(id) != cuentas.end())
        {
            return false;
        }

        cuentas[id] = new Account();

        return true;
    }

    bool close(int id)
    {
        lock_guard<mutex> lock(bankMutex);

        auto it = cuentas.find(id);

        if (it == cuentas.end())
        {
            return false;
        }

        Account* cuenta = it->second;

        lock_guard<mutex> accountLock(cuenta->mtx);

        if (!cuenta->abierta)
        {
            return false;
        }

        cuenta->abierta = false;

        return true;
    }

    bool deposit(int id, long long amount)
    {
        lock_guard<mutex> lock(bankMutex);

        auto it = cuentas.find(id);

        if (it == cuentas.end())
        {
            return false;
        }

        Account* cuenta = it->second;

        lock_guard<mutex> accountLock(cuenta->mtx);

        if (!cuenta->abierta)
        {
            return false;
        }

        cuenta->balance += amount;

        return true;
    }

    bool withdraw(int id, long long amount)
    {
        lock_guard<mutex> lock(bankMutex);

        auto it = cuentas.find(id);

        if (it == cuentas.end())
        {
            return false;
        }

        Account* cuenta = it->second;

        lock_guard<mutex> accountLock(cuenta->mtx);

        if (!cuenta->abierta)
        {
            return false;
        }

        if (cuenta->balance < amount)
        {
            return false;
        }

        cuenta->balance -= amount;

        return true;
    }

    long long getBalance(int id)
    {
        lock_guard<mutex> lock(bankMutex);

        auto it = cuentas.find(id);

        if (it == cuentas.end())
        {
            return -1;
        }

        Account* cuenta = it->second;

        lock_guard<mutex> accountLock(cuenta->mtx);

        if (!cuenta->abierta)
        {
            return -1;
        }

        return cuenta->balance;
    }
};

void hacerDeposito(Bank& banco, int id, int cantidad)
{
    banco.deposit(id, cantidad);
}

void pruebaBank()
{
    Bank banco;

    banco.open(1);

    thread hilo1(hacerDeposito, ref(banco), 1, 100);
    thread hilo2(hacerDeposito, ref(banco), 1, 200);
    thread hilo3(hacerDeposito, ref(banco), 1, 300);

    hilo1.join();
    hilo2.join();
    hilo3.join();

    cout << "Bank - Saldo: "
         << banco.getBalance(1) << endl;

    banco.withdraw(1, 100);

    cout << "Bank - Saldo despues del retiro: "
         << banco.getBalance(1) << endl;

    banco.close(1);

    cout << "Bank - Operacion despues de cerrar: "
         << banco.deposit(1, 500) << endl;
}


// ============================================================
// MAIN GENERAL
// ============================================================

int main()
{
    cout << "========================================" << endl;
    cout << "       TALLER - 4 EJERCICIOS C++" << endl;
    cout << "========================================" << endl;

    cout << endl;

    pruebaAuthenticationManager();

    cout << endl;

    pruebaExamTracker();

    cout << endl;

    pruebaSquareCipher();

    cout << endl;

    pruebaBank();

    return 0;
}
