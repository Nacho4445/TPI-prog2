#pragma once
#include "archivos/ArchivoCliente.h"
#include "negocio/ClienteManager.h"

class ClienteManager {
private:
   Cliente crearCliente();
   void mostrarCliente(Cliente &reg);
   void ordenarClientes(Cliente vClientes[], int cantidad);
   ArchivoCliente _archivoClientes;

public:
	ClienteManager();

   void guardarCliente();
   void consultarPorId();
   void consultarPorCuit();
   void consultarPorApellido();
   void consultarPorTipo();
   void listarClientes();
   void modificarCliente();
   void mostrarClientesOrdenados();
   void eliminarCliente();


};
