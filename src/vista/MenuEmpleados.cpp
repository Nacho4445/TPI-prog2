#include <iostream>
#include "vista/MenuEmpleados.h"
using namespace std;
#include <cstdio>

MenuEmpleados::MenuEmpleados(){
    setCantidadOpciones(4);
}

void MenuEmpleados::mostrarOpciones(){
    consola.limpiar();
    //system("cls");
    cout << "------------------------" << endl;
    cout << "-----MENU EMPLEADOS-----" << endl;
    cout << "1. Registrar Empleado" << endl;
    cout << "2. Consultas de Empleados" << endl;
    cout << "3. Modificar Empleado" << endl;
    cout << "4. Dar de baja Empleado" << endl;
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
            consola.limpiar();

            cout << "---------------------------" << endl;
            cout << "--- CONSULTAS EMPLEADOS ---" << endl;
            cout << "1. Consultar por ID" << endl;
            cout << "2. Consultar por CUIT" << endl;
            cout << "3. Consultar por Apellido" << endl;
            cout << "---------------------------" << endl;
            cout << "0. Volver" << endl;

            validador.leerEnteroConCero(opcionConsulta, "Opcion: ");

            switch(opcionConsulta){

            case 1:
                managerEmpleados.consultarPorId();
                consola.pausar();
                break;

            case 2:
                managerEmpleados.consultarPorCuit();
                consola.pausar();
                break;

            case 3:{
                int opcionApellido;

                do{
                    consola.limpiar();

                    cout << "1. Buscar por un apellido" << endl;
                    cout << "2. Ordenar alfabeticamente" << endl;
                    cout << "0. Volver" << endl;

                    validador.leerEnteroConCero(opcionApellido, "Opcion: ");

                    switch(opcionApellido){

                    case 1:
                        consola.limpiar();
                        managerEmpleados.consultarPorApellido();
                        break;

                    case 2:
                        consola.limpiar();
                        managerEmpleados.mostrarEmpleadosOrdenados();
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Opcion invalida." << endl;
                        break;
                    }

                    consola.pausar();

                }while(opcionApellido != 0);

                break;
            }

            case 0:
                cout << "Volviendo al menu empleados..." << endl;
                consola.pausar();
                break;

            default:
                cout << "Opcion invalida." << endl;
                consola.pausar();
                break;
            }

        }while(opcionConsulta != 0);

        break;
    }

    case 3:
        managerEmpleados.modificarEmpleado();
        break;

    case 4:
        managerEmpleados.darDeBajaEmpleado();
        break;

    case 0:
        cout << "Regresando al menu principal..." << endl;
        break;

    default:
        cout << "Opcion invalida." << endl;
        break;
    }
}
