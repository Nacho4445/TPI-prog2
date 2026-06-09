#include <iostream>
#include "vista/MenuPrincipal.h"
using namespace std;
#include <cstdio>

MenuPrincipal::MenuPrincipal(){
    setCantidadOpciones(4);
}

void MenuPrincipal::mostrarOpciones(){
    cout << "------------------------" << endl;
    cout << "-----MENU PRINCIPAL-----" << endl;
    cout << "1. Gestionar Clientes" << endl;
    cout << "2. Gestionar Equipos" << endl;
    cout << "3. Gestionar Ventas" << endl;
    cout << "4. Gestionar Empleados" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuPrincipal::ejecutarOpcion(int opcion){
    switch(opcion){
case 1:
    menuClientes.ejecutarMenu();
    break;
case 2:
    menuEquipos.ejecutarMenu();
    break;
case 3:
    menuVentas.ejecutarMenu();
    break;
case 4:
    menuEmpleados.ejecutarMenu();
    break;
case 0:
    cout << "Saliendo del programa..." << endl;
    break;


    }
}
