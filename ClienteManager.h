#pragma once
#include "ArchivoCliente.h"
#include "ClienteManager.h"

class ClienteManager {
private:
   Cliente crearCliente();
   void mostrarCliente(const Cliente &reg);
   void ordenarClientes(Cliente vClientes[], int cantidad);
   ArchivoCliente _archivoClientes;

public:
	ClienteManager();

   void guardarCliente();
   void listarClientes();
   void modificarCliente();
   void mostrarClientesOrdenados();


};
