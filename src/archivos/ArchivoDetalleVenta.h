#pragma once
#include "modelos/DetalleVenta.h"
#include <string>


class ArchivoDetalleVenta {

private:

    std::string _ruta;

public:
    ArchivoDetalleVenta();
    int getCantidadRegistros();
    bool guardar(DetalleVenta detalleVenta);
    DetalleVenta leer(int idDetalleVenta);
    DetalleVenta leerPorPosicion(int posicion);
    void leerPorIdVenta(int idVenta, DetalleVenta *detalles, int &cantidad);
    bool borrarRegistro(int idDetalleVenta);
    void vaciar();
    bool exportarDatosCSV(FILE *pBinario, FILE *pCSV);

};
