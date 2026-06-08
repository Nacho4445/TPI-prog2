#pragma once
#include "Modelos/Empleado.h"
#include <string>

class ArchivoEmpleado{

public:
    ArchivoEmpleado();
    ArchivoEmpleado(std::string _ruta);

    int getCantidadRegistros();
    bool guardar(Empleado reg);
    int buscar(int id);
    Empleado leer(int id);
    int buscarPorCuit(long long cuit);
    bool borrarRegistro(int id);
    void vaciar();

private:
    std::string ruta;
} ;
