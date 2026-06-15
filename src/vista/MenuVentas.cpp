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
    cout << "2. Consultar Venta" << endl;
    cout << "3. Cancelar Venta" << endl;
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

    case 2:{
        int opcionConsulta;

        do{
            cout << "------------------------" << endl;
            cout << "--- CONSULTAS VENTAS ---" << endl;
            cout << "1. Consultar por ID" << endl;
            cout << "2. Consultar por Cliente" << endl;
            cout << "3. Consultar por Empleado" << endl;
            cout << "4. Consultar por Fecha" << endl;
            cout << "5. Consultar por Equipo Vendido" << endl;
            cout << "------------------------" << endl;
            cout << "0. Volver" << endl;
            cout << "Opcion: ";
            cin >> opcionConsulta;

            switch(opcionConsulta){

            case 1:
                managerVentas.consultarPorId();
                system("pause");
                break;

            case 2:
                managerVentas.consultarPorCliente();
                system("pause");
                break;

            case 3:
                managerVentas.consultarPorEmpleado();
                system("pause");
                break;

            case 4:
                managerVentas.consultarPorFecha();
                system("pause");
                break;

            case 5:
                managerVentas.consultarPorEquipo();
                system("pause");
                break;

            case 0:
                cout << "Volviendo al menu ventas..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
                break;
            }

        }while(opcionConsulta != 0);

        break;
    }

    case 3:
        managerVentas.cancelarVenta();
        break;

    case 5:
        managerVentas.listarVentas();
        break;

    case 0:
        cout << "Regresando al menu principal..." << endl;
        break;
    }
}
