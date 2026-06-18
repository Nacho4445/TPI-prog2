#pragma once
#include "modelos/Empleado.h"
#include <string>

class ArchivoEmpleado{

public:
    ArchivoEmpleado();
    ArchivoEmpleado(std::string _ruta);

    int getCantidadRegistros();
    bool guardar(Empleado reg);
    int buscar(int id);
    int buscarIncluyendoBajas(int id);
    Empleado leer(int id);
    Empleado leerPorPosicion(int posicion);
    Empleado leerIncluyendoBajas(int id);
    int buscarPorCuit(long long cuit);
    bool modificar(Empleado empleado);
    bool borrarRegistro(int id);
    void vaciar();
    bool exportarDatosCSV(FILE *pBinario, FILE *pCSV);

private:
    std::string ruta;
} ;
