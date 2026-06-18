#pragma once
#include "modelos/Equipo.h"
#include <string>

class ArchivoEquipo {

public:
    ArchivoEquipo();

    int getCantidadEquipos();
    bool guardar(Equipo equipo);
    int getPosicion(int idEquipo);
    Equipo leer(int idEquipo);
    Equipo leerPorPosicion(int posicion);
    bool modificar(Equipo equipo);
    bool borrarRegistro(int idEquipo);
    void vaciar();
    bool exportarDatosCSV(FILE *pBinario, FILE *pCSV);

private:
    std::string _ruta;
};
