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
    Empleado leer(int id);
    Empleado leerPorPosicion(int posicion);
    int buscarPorCuit(long long cuit);
    bool modificar(Empleado empleado);
    bool borrarRegistro(int id);
    void vaciar();

private:
    std::string ruta;
} ;
