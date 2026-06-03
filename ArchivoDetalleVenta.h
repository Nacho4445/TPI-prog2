#ifndef ARCHIVODETALLEVENTA_H
#define ARCHIVODETALLEVENTA_H


#pragma once
#include "DetalleVenta.h"
#include <string>


class ArchivoDetalleVenta {

public:
    int getCantidadRegistros();

    bool guardar(DetalleVenta detalleVenta);

    DetalleVenta leer(int idDetalleVenta);

    bool borrarRegistro(int idDetalleVenta);

    void vaciar();

private:
    std::string _ruta;

};
#endif // ARCHIVODETALLEVENTA_H
