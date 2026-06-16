#pragma once
#include "modelos/TipoMarca.h"
#include <string>

class ArchivoTipoMarca {

public:
    ArchivoTipoMarca();

    int getCantidadTipos();
    bool guardar(TipoMarca tipo);
    int getPosicion(int idTipoMarca);
    TipoMarca leer(int idTipoMarca);
    TipoMarca leerPorPosicion(int posicion);
    int generarNuevoId();
    bool borrarRegistro(int idTipoMarca);
    void vaciar();

private:
    std::string _ruta;
};
