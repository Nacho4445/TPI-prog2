#include <iostream>
#include "vista/MenuVentas.h"
using namespace std;
#include <cstdio>

MenuVentas::MenuVentas(){
    setCantidadOpciones(4);
}

void MenuVentas::mostrarOpciones(){
    cout << "------------------------" << endl;
    cout << "-----MENU VENTAS-----" << endl;
    cout << "1. Registrar Venta" << endl;
    cout << "2. Modificar Venta" << endl;
    cout << "3. Eliminar Venta" << endl;
    cout << "4. Listar Ventas" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuVentas::ejecutarOpcion(int opcion){
    switch(opcion){
case 1:
    managerVentas.guardarVenta();
    break;
case 2:
    managerVentas.modificarVenta();
    break;
case 3:
    managerVentas.eliminarVenta();
    break;
case 4:
    managerVentas.listarVentas();
    break;
case 0:
    cout << "Regresando al menu principal..." << endl;
    break;


    }
}
