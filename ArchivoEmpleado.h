#pragma once
#include "Empleado.h"
#include <string>

class ArchivoEmpleado{
private:
    std::string ruta;
public:
    ArchivoEmpleado();
    ArchivoEmpleado(std::string _ruta);

    int getCantidadRegistros();
    bool guardar(Empleado reg);
    int buscar(int id);
    Empleado leer(int id);
    bool borrarRegistro(int id);
    void vaciar();
} ;
