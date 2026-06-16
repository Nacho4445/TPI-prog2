#pragma once
#include "modelos/TipoEquipo.h"
#include <string>

class ArchivoTipoEquipo {

public:
    ArchivoTipoEquipo();

    int getCantidadTipos();
    bool guardar(TipoEquipo tipo);
    int getPosicion(int idTipoEquipo);
    TipoEquipo leer(int idTipoEquipo);
    TipoEquipo leerPorPosicion(int posicion);
    int generarNuevoId();
    bool borrarRegistro(int idTipoEquipo);
    void vaciar();

private:
    std::string _ruta;
};
