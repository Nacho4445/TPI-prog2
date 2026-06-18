#pragma once
#include "archivos/ArchivoCliente.h"
#include "negocio/ClienteManager.h"
#include "utils/Consola.h"
#include "utils/Validador.h"

class ClienteManager {
private:
    Consola consola;
    Validador validador;

    ArchivoCliente _archivoClientes;

    Cliente crearCliente();
    void mostrarCliente(Cliente &reg);
    void ordenarClientes(Cliente vClientes[], int cantidad);
    void ordenarClientesPorTipo(Cliente *vClientes, int cantidad);
    void ordenarClientesPorId(Cliente vClientes[], int cantidad);




public:
	ClienteManager();

    void guardarCliente();
    void consultarPorId();
    void consultarPorCuit();
    void consultarPorApellido();
    void consultarPorTipo();
    void modificarCliente();
    void eliminarCliente();
    void mostrarClientesOrdenados();
    void mostrarClientesOrdenadosPorTipo();
    void mostrarClientesOrdenadosPorId();




};
