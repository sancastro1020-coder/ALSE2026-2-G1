/**
 * @file PaqueteEnvio.cpp
 * @brief Implementación de PaqueteEnvio.
 */
#include "PaqueteEnvio.h"
#include <iostream>
#include <stdexcept>

PaqueteEnvio::PaqueteEnvio(int id, double peso, const std::string& destino)
    : id(id), peso(peso), destino(destino), entregado(false) {
    if (id <= 0) throw std::invalid_argument("El ID debe ser positivo.");
    if (peso <= 0) throw std::invalid_argument("El peso debe ser mayor que cero.");
    if (destino.empty()) throw std::invalid_argument("El destino no puede estar vacío.");
    historialEstados.push_back("Paquete creado");
}

void PaqueteEnvio::actualizarEstado(const std::string& estado) {
    if (estado.empty()) throw std::invalid_argument("El estado no puede estar vacío.");
    if (entregado) throw std::logic_error("El paquete ya fue entregado.");
    historialEstados.push_back(estado);
}

void PaqueteEnvio::marcarEntregado() {
    if (!entregado) {
        entregado = true;
        historialEstados.push_back("Entregado");
    }
}

std::string PaqueteEnvio::obtenerUltimoEstado() const {
    return historialEstados.empty() ? "Sin estado" : historialEstados.back();
}

void PaqueteEnvio::imprimirHistorial() const {
    for (std::size_t i = 0; i < historialEstados.size(); ++i)
        std::cout << "  " << i + 1 << ". " << historialEstados[i] << '\n';
}

int PaqueteEnvio::obtenerId() const { return id; }
double PaqueteEnvio::obtenerPeso() const { return peso; }
std::string PaqueteEnvio::obtenerDestino() const { return destino; }
bool PaqueteEnvio::estaEntregado() const { return entregado; }
