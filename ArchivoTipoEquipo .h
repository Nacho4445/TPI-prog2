#pragma once
#include "TipoEquipo.h"
#include <string>

class ArchivoTipoEquipo {

public:
    ArchivoTipoEquipo();

    int getCantidadTipos();
    bool guardar(TipoEquipo tipo);
    int getPosicion(int idTipoEquipo);
    TipoEquipo leer(int idTipoEquipo);
    bool borrarRegistro(int idTipoEquipo);
    void vaciar();

private:
    std::string _ruta;
};
