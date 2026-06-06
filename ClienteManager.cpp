#include <iostream>
#include "Cliente.h"
#include "ClienteManager.h"
using namespace std;

ClienteManager::ClienteManager()
   : _repoClientes(){
}

Cliente ClienteManager::crearCliente(){}

void ClienteManager::guardarCliente(){}

void ClienteManager::listarClientes(){}

void ClienteManager::mostrarCliente(const Cliente &reg){}

void ClienteManager::modificarCliente(){}

void ClienteManager::ordenarClientes(Cliente vClientes[], int cantidad){}

void ClienteManager::mostrarClientesOrdenados(){}
