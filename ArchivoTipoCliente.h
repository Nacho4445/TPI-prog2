#pragma once
#include "TipoCliente.h"
#include <string>

class ArchivoTipoCliente {

public:
    ArchivoTipoCliente();
    ArchivoTipoCliente(std::string _ruta);

    int getCantidadRegistros();
    bool guardar(TipoCliente reg);
    int buscar(int id);
    TipoCliente leer(int id);
    bool borrarRegistro(int id);
    void vaciar();

private:
    std::string ruta;
};
