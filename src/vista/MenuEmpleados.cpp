#include <iostream>
#include "vista/MenuEmpleados.h"
using namespace std;
#include <cstdio>

MenuEmpleados::MenuEmpleados(){
    setCantidadOpciones(5);
}

void MenuEmpleados::mostrarOpciones(){
    system("cls");
    cout << "------------------------" << endl;
    cout << "-----MENU EMPLEADOS-----" << endl;
    cout << "1. Registrar Empleado" << endl;
    cout << "2. Consultas de Empleados" << endl;
    cout << "3. Modificar Empleado" << endl;
    cout << "4. Eliminar Empleado" << endl;
    cout << "5. Listar Empleados" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuEmpleados::ejecutarOpcion(int opcion){
    switch(opcion){
case 1:
    managerEmpleados.guardarEmpleado();
    break;
case 2:{
    int opcionConsulta;

    do{
        system("cls");
        cout << "---------------------------" << endl;
        cout << "--- CONSULTAS EMPLEADOS ---" << endl;
        cout << "1. Consultar por ID" << endl;
        cout << "2. Consultar por CUIT" << endl;
        cout << "3. Consultar por Apellido" << endl;
        cout << "---------------------------" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcionConsulta;

        switch(opcionConsulta){

        case 1:
            managerEmpleados.consultarPorId();
            system("pause");
            break;

        case 2:
            managerEmpleados.consultarPorCuit();
            system("pause");
            break;

        case 3:
            managerEmpleados.consultarPorApellido();
            system("pause");
            break;

        case 0:
            cout << "Volviendo al menu empleados..." << endl;
            system("pause");
            break;

        default:
            cout << "Opcion invalida." << endl;
            system("pause");
            break;
        }

    }while(opcionConsulta != 0);

    break;
 }

case 3:
    managerEmpleados.modificarEmpleado();
    break;

case 4:
    managerEmpleados.eliminarEmpleado();
    break;

case 5:
    managerEmpleados.listarEmpleados();
    break;

  }
}
