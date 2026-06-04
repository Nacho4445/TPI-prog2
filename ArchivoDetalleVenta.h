#ifndef ARCHIVODETALLEVENTA_H
#define ARCHIVODETALLEVENTA_H

#include "DetalleVenta.h"
#include <string>


class ArchivoDetalleVenta {

private:
    std::string _ruta;

public:
    int getCantidadRegistros();
    bool guardar(DetalleVenta detalleVenta);
    DetalleVenta leer(int idDetalleVenta);
    bool borrarRegistro(int idDetalleVenta);
    void vaciar();

};

#endif // ARCHIVODETALLEVENTA_H
