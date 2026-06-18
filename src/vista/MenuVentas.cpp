#include <iostream>
#include "vista/MenuVentas.h"
using namespace std;
#include <cstdio>

MenuVentas::MenuVentas(){
    setCantidadOpciones(3);
}

void MenuVentas::mostrarOpciones(){
    consola.limpiar();

    cout << "------------------------" << endl;
    cout << "-----MENU VENTAS-----" << endl;
    cout << "1. Registrar Venta" << endl;
    cout << "2. Consultar Venta" << endl;
    cout << "3. Cancelar Venta" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuVentas::ejecutarOpcion(int opcion){

    switch(opcion){

    case 1:
        consola.limpiar();
        managerVentas.guardarVenta();
        consola.pausar();
        break;

    case 2:{
        int opcionConsulta;

        do{
            consola.limpiar();

            cout << "------------------------------" << endl;
            cout << "------ CONSULTAS VENTAS ------" << endl;
            cout << "1. Consultar por ID" << endl;
            cout << "2. Consultar por Cliente" << endl;
            cout << "3. Consultar por Empleado" << endl;
            cout << "4. Consultar por Fecha" << endl;
            cout << "5. Consultar por Equipo Vendido" << endl;
            cout << "6. Listar todas las ventas" << endl;
            cout << "-------------------------------" << endl;
            cout << "0. Volver" << endl;

            validador.leerEnteroConCero(opcionConsulta, "Opcion: ");

            switch(opcionConsulta){

            case 1:
                consola.limpiar();
                managerVentas.consultarPorId();
                break;

            case 2:
                consola.limpiar();
                managerVentas.consultarPorCliente();
                break;

            case 3:
                consola.limpiar();
                managerVentas.consultarPorEmpleado();
                break;

            case 4:
                consola.limpiar();
                managerVentas.consultarPorFecha();
                break;

            case 5:
                consola.limpiar();
                managerVentas.consultarPorEquipo();
                break;

            case 6:
                consola.limpiar();
                managerVentas.listarVentas();
                break;

            case 0:
                cout << "Volviendo al menu ventas..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
                break;
            }

            consola.pausar();

        }while(opcionConsulta != 0);

        break;
    }

    case 3:
        consola.limpiar();
        managerVentas.cancelarVenta();
        consola.pausar();
        break;

    case 0:
        cout << "Regresando al menu principal..." << endl;
        break;

    default:
        cout << "Opcion invalida." << endl;
        break;
    }
}
