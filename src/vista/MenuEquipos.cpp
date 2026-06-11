#include <iostream>
#include "vista/MenuEquipos.h"
using namespace std;
#include <cstdio>

MenuEquipos::MenuEquipos(){
    setCantidadOpciones(5);
}

void MenuEquipos::mostrarOpciones(){
    system("cls");
    cout << "------------------------" << endl;
    cout << "-----MENU EQUIPOS-----" << endl;
    cout << "1. Registrar Equipo" << endl;
    cout << "2. Consultar Equipo" << endl;
    cout << "3. Modificar Equipo" << endl;
    cout << "4. Eliminar Equipo" << endl;
    cout << "5. Listar Equipos" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuEquipos::ejecutarOpcion(int opcion){
    switch(opcion){

    case 1:
        managerEquipos.guardarEquipo();
        break;

    case 2:{
        int opcionConsulta;

        do{
            system("cls");
            cout << "------------------------" << endl;
            cout << "--- CONSULTAS EQUIPOS ---" << endl;
            cout << "1. Consultar por ID" << endl;
            cout << "2. Consultar por Tipo de Equipo" << endl;
            cout << "3. Consultar por Marca" << endl;
            cout << "4. Consultar por Rango de Precio" << endl;
            cout << "5. Consultar con Stock Disponible" << endl;
            cout << "------------------------" << endl;
            cout << "0. Volver" << endl;
            cout << "Opcion: ";
            cin >> opcionConsulta;

            switch(opcionConsulta){

            case 1:
                managerEquipos.consultarPorId();
                system("pause");
                break;

            case 2:
                managerEquipos.consultarPorTipo();
                system("pause");
                break;

            case 3:
                managerEquipos.consultarPorMarca();
                system("pause");
                break;

            case 4:
                managerEquipos.consultarPorPrecio();
                system("pause");
                break;

            case 5:
                managerEquipos.consultarPorStock();
                system("pause");
                break;

            case 0:
                cout << "Volviendo al menu equipos..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
                break;
            }

        }while(opcionConsulta != 0);

        break;
    }

    case 3:
        managerEquipos.modificarEquipo();
        break;

    case 4:
        managerEquipos.eliminarEquipo();
        break;

    case 5:
        managerEquipos.listarEquipos();
        break;

    case 0:
        cout << "Regresando al menu principal..." << endl;
        break;
    }
}
