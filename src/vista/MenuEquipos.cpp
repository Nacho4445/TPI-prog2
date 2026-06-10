#include <iostream>
#include "vista/MenuEquipos.h"
using namespace std;
#include <cstdio>

MenuEquipos::MenuEquipos(){
    setCantidadOpciones(4);
}

void MenuEquipos::mostrarOpciones(){
    cout << "------------------------" << endl;
    cout << "-----MENU EQUIPOS-----" << endl;
    cout << "1. Registrar Equipo" << endl;
    cout << "2. Modificar Equipo" << endl;
    cout << "3. Eliminar Equipo" << endl;
    cout << "4. Listar Equipos" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuEquipos::ejecutarOpcion(int opcion){
    switch(opcion){
case 1:
    managerEquipos.guardarEquipo();
    break;
case 2:
    managerEquipos.modificarEquipo();
    break;
case 3:
    managerEquipos.eliminarEquipo();
    break;
case 4:
    managerEquipos.listarEquipos();
    break;
case 0:
    cout << "Regresando al menu principal..." << endl;
    break;


    }
}
