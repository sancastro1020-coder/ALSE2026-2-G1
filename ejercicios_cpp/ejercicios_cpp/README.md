# Ejercicios de diseño en C++

Soluciones en C++17:
- `UndergroundSystem`: promedio de tiempos entre estaciones.
- `ATM`: depósitos y retiros priorizando billetes grandes.
- `AuctionSystem`: administración de ofertas por artículo.
- `Meetup`: fecha según día de semana y ordinal (`first`, `teenth`, `last`, etc.).
- `Clock`: sumar/restar minutos, normalizar el día y comparar horas.

## Compilar en Ubuntu

```bash
sudo apt update
sudo apt install build-essential cmake
cmake -S . -B build
cmake --build build
```

## Ejecutar

```bash
./build/underground_system
./build/atm
./build/auction_system
./build/meetup
./build/clock
```
