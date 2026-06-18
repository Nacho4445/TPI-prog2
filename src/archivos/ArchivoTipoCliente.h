#pragma once
#include "modelos/TipoCliente.h"
#include <string>

class ArchivoTipoCliente {

public:
    ArchivoTipoCliente();
    ArchivoTipoCliente(std::string _ruta);

    int getCantidadRegistros();
    bool guardar(TipoCliente reg);
    int buscar(int id);
    TipoCliente leer(int id);
    bool borrarRegistro(int id);
    void vaciar();
    bool exportarDatosCSV(FILE *pBinario, FILE *pCSV);

private:
    std::string ruta;
};
