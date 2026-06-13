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
    int buscarIncluyendoCanceladas(int id);
    Venta leer(int id);
    Venta leerPorPosicion(int posicion);
    Venta leerIncluyendoCanceladas(int id);
    bool borrarRegistro(int id);
    bool cancelarVenta(int idVenta);


private:
    std::string ruta;
};


