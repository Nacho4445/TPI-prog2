#pragma once
#include "Cliente.h"
#include <string>

class ArchivoCliente{
private:
    std::string ruta;
public:
    ArchivoCliente();
    ArchivoCliente(std::string _ruta);

    int getCantidadRegistros();
    bool guardar(Cliente reg);
    int buscar(int id);
    Cliente leer(int nroRegistro);
    bool borrarRegistro(int nroRegistro);
    void vaciar();
} ;
