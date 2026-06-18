#include <iostream>
#include "vista/MenuClientes.h"
using namespace std;
#include <cstdio>

MenuClientes::MenuClientes(){
    setCantidadOpciones(3);
}

void MenuClientes::mostrarOpciones(){
    consola.limpiar();

    cout << "------------------------" << endl;
    cout << "-----MENU CLIENTES-----" << endl;
    cout << "1. Registrar Cliente" << endl;
    cout << "2. Consultar Cliente" << endl;
    cout << "3. Modificar Cliente" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuClientes::ejecutarOpcion(int opcion){

    switch(opcion){

    case 1:
        consola.limpiar();
        managerClientes.guardarCliente();
        consola.pausar();
        break;

    case 2:{
        int opcionConsulta;

        do{
            consola.limpiar();

            cout << "------------------------" << endl;
            cout << "--- CONSULTAS CLIENTES ---" << endl;
            cout << "1. Consultar por ID" << endl;
            cout << "2. Consultar por CUIT" << endl;
            cout << "3. Consultar por Apellido" << endl;
            cout << "4. Consultar por Tipo de Cliente" << endl;
            cout << "------------------------" << endl;
            cout << "0. Volver" << endl;
            cout << endl;

            validador.leerEnteroConCero(opcionConsulta, "Opcion: ");

            switch(opcionConsulta){

            case 1:{
                 int opcionId;
                 do{
                     consola.limpiar();
                 cout << "----------------------------" << endl;
                 cout << "1. Buscar por ID" << endl;
                 cout << "2. Ordenar por ID" << endl;
                 cout << "----------------------------" << endl;
                 cout << "0. Volver" << endl;
                 validador.leerEnteroConCero(opcionId, "Opcion: ");

                 switch(opcionId){
                     case 1:
                         consola.limpiar();
                         managerClientes.consultarPorId();
                         break;

                     case 2:
                         consola.limpiar();
                         managerClientes.mostrarClientesOrdenadosPorId();
                         break;

                     case 0:
                         break;

                     default:
                         cout << "Opcion invalida." << endl;
                         consola.pausar();
                         break;
                         }
                     consola.pausar();
                }while(opcionId != 0);
                break;
            }

            case 2:
                consola.limpiar();
                managerClientes.consultarPorCuit();
                consola.pausar();
                break;

            case 3:{
                int opcionApellido;

                do{
                    consola.limpiar();

                    cout << "----------------------------" << endl;
                    cout << "1. Buscar por un apellido" << endl;
                    cout << "2. Ordenar alfabeticamente" << endl;
                    cout << "----------------------------" << endl;
                    cout << "0. Volver" << endl;

                    validador.leerEnteroConCero(opcionApellido, "Opcion: ");

                    switch(opcionApellido){

                    case 1:
                        consola.limpiar();
                        managerClientes.consultarPorApellido();
                        break;

                    case 2:
                        consola.limpiar();
                        managerClientes.mostrarClientesOrdenados();
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

            case 4:{
                int opcionTipo;

                do{
                    consola.limpiar();

                    cout << "---------------------------------" << endl;
                    cout << "1. Buscar por un tipo de cliente" << endl;
                    cout << "2. Listar todos ordenados" << endl;
                    cout << "---------------------------------" << endl;
                    cout << "0. Volver" << endl;

                    validador.leerEnteroConCero(opcionTipo, "Opcion: ");

                    switch(opcionTipo){

                    case 1:
                        consola.limpiar();
                        managerClientes.consultarPorTipo();
                        break;

                    case 2:
                        consola.limpiar();
                        managerClientes.mostrarClientesOrdenadosPorTipo();
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Opcion invalida." << endl;
                        break;
                    }

                    consola.pausar();

                }while(opcionTipo != 0);

                break;
            }

            case 0:
                cout << "Volviendo al menu clientes..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
                break;
            }

        }while(opcionConsulta != 0);

        break;
    }

    case 3:
        consola.limpiar();
        managerClientes.modificarCliente();
        consola.pausar();
        break;

    case 0:
        cout << "Regresando al menu principal..." << endl;
        break;
    }
}
