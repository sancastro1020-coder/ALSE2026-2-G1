# Proyecto PaqueteEnvio

Sistema en C++ para registrar paquetes, actualizar estados y consultar su historial.

## Estructura
- `include/PaqueteEnvio.h`: clase y documentación Doxygen.
- `src/PaqueteEnvio.cpp`: implementación y validaciones.
- `src/main.cpp`: solicita datos, crea dos objetos y usa `std::vector`.
- `CMakeLists.txt`: configuración de compilación.
- `Doxyfile`: configuración de Doxygen.

## Compilar y ejecutar en Ubuntu
Desde la carpeta raíz:

```bash
cmake -S . -B build
cmake --build build
./build/paquetes
```

Si faltan herramientas: `sudo apt update && sudo apt install build-essential cmake`

## Generar documentación
Instale Doxygen si hace falta: `sudo apt install doxygen`
Después ejecute `doxygen Doxyfile`. El HTML estará en `docs/html/index.html`.

El programa crea dos paquetes, solicita datos, registra estados, permite marcarlos como entregados y muestra el resumen y el historial.
