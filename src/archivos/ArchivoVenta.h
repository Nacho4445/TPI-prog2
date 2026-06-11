#pragma once
#include "modelos/Venta.h"
#include <string>

class ArchivoVenta {

public:
    ArchivoVenta();
    ArchivoVenta(std::string _ruta);

    int getCantidadRegistros();
    bool guardar(Venta reg);
    int buscar(int id);
    Venta leer(int id);
    Venta leerPorPosicion(int posicion);
    bool borrarRegistro(int id);
    void vaciar();

private:
    std::string ruta;
};


