/**
 * @file main.cpp
 * @brief Programa principal para probar la clase PaqueteEnvio.
 */
#include "PaqueteEnvio.h"
#include <iostream>
#include <limits>
#include <vector>
#include <exception>

int main() {
    std::vector<PaqueteEnvio> paquetes;

    try {
        for (int i = 0; i < 2; ++i) {
            int id;
            double peso;
            std::string destino;
            std::cout << "\n--- Paquete " << i + 1 << " ---\n";
            std::cout << "ID positivo: ";
            std::cin >> id;
            std::cout << "Peso en kg: ";
            std::cin >> peso;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Destino: ";
            std::getline(std::cin, destino);
            paquetes.emplace_back(id, peso, destino);
        }

        for (auto& paquete : paquetes) {
            std::string estado;
            std::cout << "\nNuevo estado para paquete " << paquete.obtenerId()
                      << " (ej. En camino): ";
            std::getline(std::cin, estado);
            paquete.actualizarEstado(estado);

            char respuesta;
            std::cout << "¿Marcar como entregado? (s/n): ";
            std::cin >> respuesta;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (respuesta == 's' || respuesta == 'S') paquete.marcarEntregado();
        }

        std::cout << "\n===== RESUMEN DE ENVIOS =====\n";
        for (const auto& paquete : paquetes) {
            std::cout << "\nID: " << paquete.obtenerId()
                      << "\nPeso: " << paquete.obtenerPeso() << " kg"
                      << "\nDestino: " << paquete.obtenerDestino()
                      << "\nÚltimo estado: " << paquete.obtenerUltimoEstado()
                      << "\nEntregado: " << (paquete.estaEntregado() ? "Sí" : "No")
                      << "\nHistorial:\n";
            paquete.imprimirHistorial();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
