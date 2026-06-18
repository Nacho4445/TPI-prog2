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
            consola.limpiar();
            managerClientes.consultarPorApellido();
            consola.pausar();
            //system("pause");
            break;
        case 4:
            consola.limpiar();
            managerClientes.consultarPorTipo();
            consola.pausar();
            //system("pause");
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
