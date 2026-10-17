/**
 * @file PaqueteEnvio.h
 * @brief Declaración de la clase PaqueteEnvio.
 */
#ifndef PAQUETE_ENVIO_H
#define PAQUETE_ENVIO_H
#include <string>
#include <vector>

/** @class PaqueteEnvio
 *  @brief Representa un paquete y su historial de envío.
 */
class PaqueteEnvio {
private:
    int id; ///< Identificador del paquete.
    double peso; ///< Peso en kilogramos.
    std::string destino; ///< Destino del envío.
    bool entregado; ///< Indica si fue entregado.
    std::vector<std::string> historialEstados; ///< Historial de estados.

public:
    /** @brief Crea un paquete.
     *  @param id Identificador positivo.
     *  @param peso Peso mayor que cero.
     *  @param destino Destino no vacío.
     */
    PaqueteEnvio(int id, double peso, const std::string& destino);
    /** @brief Registra un nuevo estado. */
    void actualizarEstado(const std::string& estado);
    /** @brief Marca el paquete como entregado. */
    void marcarEntregado();
    /** @brief Devuelve el último estado registrado. */
    std::string obtenerUltimoEstado() const;
    /** @brief Imprime todos los estados del historial. */
    void imprimirHistorial() const;
    int obtenerId() const;
    double obtenerPeso() const;
    std::string obtenerDestino() const;
    bool estaEntregado() const;
};
#endif
