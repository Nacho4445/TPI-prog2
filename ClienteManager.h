#pragma once
#include "ArchivoCliente.h"

class ClienteManager {
private:
   Cliente crearCliente();
   void mostrarCliente(const Cliente &reg);
   void ordenarClientes(Cliente vClientes[], int cantidad);
   ArchivoCliente _repoClientes;

public:
	ClienteManager();

   void guardarCliente();
   void listarClientes();
   void modificarCliente();
   void mostrarClientesOrdenados();


};
