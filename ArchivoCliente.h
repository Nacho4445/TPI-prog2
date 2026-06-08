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
    Cliente leer(int id);
    Cliente leerPorPosicion(int posicion);
    int buscarPorCuit(long long cuit);
    bool borrarRegistro(int id);
    void vaciar();
} ;
