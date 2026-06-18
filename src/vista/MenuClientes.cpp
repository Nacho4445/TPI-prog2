#include <iostream>
#include "vista/MenuClientes.h"
using namespace std;
#include <cstdio>

MenuClientes::MenuClientes(){
    setCantidadOpciones(4);
}

void MenuClientes::mostrarOpciones(){
    consola.limpiar();
    // system("cls");
    cout << "------------------------" << endl;
    cout << "-----MENU CLIENTES-----" << endl;
    cout << "1. Registrar Cliente" << endl;
    cout << "2. Consultar Cliente" << endl;
    cout << "3. Modificar Cliente" << endl;
    cout << "4. Listar Clientes" << endl;
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
case 2:
    int opcionConsulta;

    do{
        consola.limpiar();
        //system("cls");
        cout << "------------------------" << endl;
        cout << "--- CONSULTAS CLIENTES ---" << endl;
        cout << "1. Consultar por ID" << endl;
        cout << "2. Consultar por CUIT" << endl;
        cout << "3. Consultar por Apellido" << endl;
        cout << "4. Consultar por Tipo de Cliente" << endl;
        cout << "------------------------" << endl;
        cout << "0. Volver" << endl;
        cout<<endl;
        cout << "Opcion: ";
        cin >> opcionConsulta;

        switch(opcionConsulta){
        case 1:
            consola.limpiar();
            managerClientes.consultarPorId();
            consola.pausar();
            //system("pause");
            break;
        case 2:
            consola.limpiar();
            managerClientes.consultarPorCuit();
            consola.pausar();
            //system("pause");
            break;
        case 3:
             int opcionApellido;
             do{
                 consola.limpiar();
                 cout << "----------------------------" << endl;
                 cout << "1. Buscar por un apellido" << endl;
                 cout << "2. Ordenar alfabeticamente" << endl;
                 cout << "----------------------------" << endl;
                 cout << "0. Volver" << endl;
                 cout << "Opcion: ";
                 cin >> opcionApellido;

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
             }while(opcionApellido!=0);

             break;

        case 4:
            int opcionTipo;

            do{
             consola.limpiar();
             cout << "---------------------------------" << endl;
             cout << "1. Buscar por un tipo de cliente" << endl;
             cout << "2. Listar todos ordenados" << endl;
             cout << "---------------------------------" << endl;
             cout << "0. Volver" << endl;
             cout << "Opcion: ";
             cin >> opcionTipo;

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

        case 0:
            cout << "Volviendo al menu clientes..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }

    }while(opcionConsulta != 0);

    break;

case 3:
    consola.limpiar();
    managerClientes.modificarCliente();
    consola.pausar();
    break;
case 4:
    consola.limpiar();
     managerClientes.listarClientes();
     consola.pausar();
    break;
case 0:
    cout << "Regresando al menu principal..." << endl;
    break;


    }
}
