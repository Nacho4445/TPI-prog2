#include <iostream>
#include "vista/MenuClientes.h"
using namespace std;
#include <cstdio>

MenuClientes::MenuClientes(){
    setCantidadOpciones(5);
}

void MenuClientes::mostrarOpciones(){
    system("cls");
    cout << "------------------------" << endl;
    cout << "-----MENU CLIENTES-----" << endl;
    cout << "1. Registrar Cliente" << endl;
    cout << "2. Consultar Cliente" << endl;
    cout << "3. Modificar Cliente" << endl;
    cout << "4. Eliminar Cliente" << endl;
    cout << "5. Listar Clientes" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuClientes::ejecutarOpcion(int opcion){
    switch(opcion){
case 1:
    managerClientes.guardarCliente();
    break;
case 2:
    int opcionConsulta;

    do{
        system("cls");
        cout << "------------------------" << endl;
        cout << "--- CONSULTAS CLIENTES ---" << endl;
        cout << "1. Consultar por ID" << endl;
        cout << "2. Consultar por CUIT" << endl;
        cout << "3. Consultar por Apellido" << endl;
        cout << "4. Consultar por Tipo de Cliente" << endl;
        cout << "------------------------" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcionConsulta;

        switch(opcionConsulta){
        case 1:
            managerClientes.consultarPorId();
            break;
        case 2:
            managerClientes.consultarPorCuit();
            break;
        case 3:
            managerClientes.consultarPorApellido();
            break;
        case 4:
            managerClientes.consultarPorTipo();
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
    managerClientes.modificarCliente();
    break;
case 4:
    managerClientes.eliminarCliente();
    break;
case 5:
     managerClientes.listarClientes();
    break;
case 0:
    cout << "Regresando al menu principal..." << endl;
    break;


    }
}
