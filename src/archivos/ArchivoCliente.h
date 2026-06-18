#pragma once
#include "modelos/Cliente.h"
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
    bool modificar(Cliente cliente);
    bool borrarRegistro(int id);
    void vaciar();
    bool exportarDatosCSV(FILE *pBinario, FILE *pCSV);
} ;
