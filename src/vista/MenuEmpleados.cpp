#include <iostream>
#include "vista/MenuEmpleados.h"
using namespace std;
#include <cstdio>

MenuEmpleados::MenuEmpleados(){
    setCantidadOpciones(4);
}

void MenuEmpleados::mostrarOpciones(){
    cout << "------------------------" << endl;
    cout << "-----MENU EMPLEADOS-----" << endl;
    cout << "1. Registrar Empleado" << endl;
    cout << "2. Modificar Empleado" << endl;
    cout << "3. Eliminar Empleado" << endl;
    cout << "4. Listar Empleados" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuEmpleados::ejecutarOpcion(int opcion){
    switch(opcion){
case 1:
    ///Registrar Empleado
    break;
case 2:
    ///Modificar Empleado
    break;
case 3:
    ///Eliminar Empleado
    break;
case 4:
    ///Listar Empleados
    break;
case 0:
    cout << "Regresando al menu principal..." << endl;
    break;


    }
}
