#pragma once
#include "Archivos/ArchivoCliente.h"
#include "Negocio/ClienteManager.h"

class ClienteManager {
private:
   Cliente crearCliente();
   void mostrarCliente(Cliente &reg);
   void ordenarClientes(Cliente vClientes[], int cantidad);
   ArchivoCliente _archivoClientes;

public:
	ClienteManager();

   void guardarCliente();
   void listarClientes();
   void modificarCliente();
   void mostrarClientesOrdenados();


};
