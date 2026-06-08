#include <iostream>
#include "Vista/MenuClientes.h"
using namespace std;
#include <cstdio>

MenuClientes::MenuClientes(){
    setCantidadOpciones(4);
}

void MenuClientes::mostrarOpciones(){
    cout << "------------------------" << endl;
    cout << "-----MENU CLIENTES-----" << endl;
    cout << "1. Registrar Cliente" << endl;
    cout << "2. Modificar Cliente" << endl;
    cout << "3. Eliminar Cliente" << endl;
    cout << "4. Listar Clientes" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuClientes::ejecutarOpcion(int opcion){
    switch(opcion){
case 1:
    ///Registrar Cliente
    break;
case 2:
    ///Modificar Cliente
    break;
case 3:
    ///Eliminar Cliente
    break;
case 4:
    ///Listar Clientes
    break;
case 0:
    cout << "Regresando al menu principal..." << endl;
    break;


    }
}
