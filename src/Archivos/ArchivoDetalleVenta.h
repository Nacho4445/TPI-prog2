#pragma once
#include "Modelos/DetalleVenta.h"
#include <string>


class ArchivoDetalleVenta {

private:

    std::string _ruta;

public:
    ArchivoDetalleVenta();
    int getCantidadRegistros();
    bool guardar(DetalleVenta detalleVenta);
    DetalleVenta leer(int idDetalleVenta);
    bool borrarRegistro(int idDetalleVenta);
    void vaciar();

};
