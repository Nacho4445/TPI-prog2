#include <iostream>
#include "vista/MenuEquipos.h"
using namespace std;
#include <cstdio>

MenuEquipos::MenuEquipos(){
    setCantidadOpciones(4);
}

void MenuEquipos::mostrarOpciones(){
    consola.limpiar();

    cout << "------------------------" << endl;
    cout << "-----MENU EQUIPOS-------" << endl;
    cout << "1. Registrar Equipo" << endl;
    cout << "2. Consultas" << endl;
    cout << "3. Modificar Equipo" << endl;
    cout << "4. Dar de baja Equipo" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuEquipos::ejecutarOpcion(int opcion){

    switch(opcion){

    case 1:
        consola.limpiar();
        managerEquipos.guardarEquipo();
        consola.pausar();
        break;

    case 2:{
        int opcionConsulta;

        do{
            consola.limpiar();

            cout << "------------------------" << endl;
            cout << "--- CONSULTAS EQUIPOS ---" << endl;
            cout << "1. Consultar por ID" << endl;
            cout << "2. Consultar por Tipo de Equipo" << endl;
            cout << "3. Consultar por Marca" << endl;
            cout << "4. Consultar por Precio" << endl;
            cout << "5. Consultar con Stock Disponible" << endl;
            cout << "------------------------" << endl;
            cout << "0. Volver" << endl;
            cout << endl;

            validador.leerEnteroConCero(opcionConsulta, "Opcion: ");

            switch(opcionConsulta){

            case 1:
                consola.limpiar();
                managerEquipos.consultarPorId();
                consola.pausar();
                break;

            case 2:{
                int opcionTipo;

                do{
                    consola.limpiar();

                    cout << "1. Buscar un tipo de equipo" << endl;
                    cout << "2. Listar ordenados por tipo" << endl;
                    cout << "0. Volver" << endl;
                    cout << endl;
                    validador.leerEnteroConCero(opcionTipo, "Opcion: ");

                    switch(opcionTipo){

                    case 1:
                        consola.limpiar();
                        managerEquipos.consultarPorTipo();
                        break;

                    case 2:
                        consola.limpiar();
                        managerEquipos.mostrarEquiposOrdenadosPorTipo();
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

            case 3:{
                int opcionMarca;

                do{
                    consola.limpiar();

                    cout << "1. Buscar una marca" << endl;
                    cout << "2. Listar ordenados por marca" << endl;
                    cout << "0. Volver" << endl;

                    validador.leerEnteroConCero(opcionMarca, "Opcion: ");

                    switch(opcionMarca){

                    case 1:
                        consola.limpiar();
                        managerEquipos.consultarPorMarca();
                        break;

                    case 2:
                        consola.limpiar();
                        managerEquipos.mostrarEquiposOrdenadosPorMarca();
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Opcion invalida." << endl;
                        break;
                    }

                    consola.pausar();

                }while(opcionMarca != 0);

                break;
            }

            case 4:{
                int opcionPrecio;

                do{
                    consola.limpiar();

                    cout << "1. Buscar por rango de precio" << endl;
                    cout << "2. Ordenar de menor a mayor" << endl;
                    cout << "3. Ordenar de mayor a menor" << endl;
                    cout << "0. Volver" << endl;

                    validador.leerEnteroConCero(opcionPrecio, "Opcion: ");

                    switch(opcionPrecio){

                    case 1:
                        consola.limpiar();
                        managerEquipos.consultarPorPrecio();
                        break;

                    case 2:
                        consola.limpiar();
                        managerEquipos.mostrarEquiposOrdenadosPorPrecioAsc();
                        break;

                    case 3:
                        consola.limpiar();
                        managerEquipos.mostrarEquiposOrdenadosPorPrecioDesc();
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Opcion invalida." << endl;
                        break;
                    }

                    consola.pausar();

                }while(opcionPrecio != 0);

                break;
            }

            case 5:
                consola.limpiar();
                managerEquipos.consultarPorStock();
                consola.pausar();
                break;

            case 0:
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
        consola.limpiar();
        managerEquipos.modificarEquipo();
        consola.pausar();
        break;

    case 4:
        consola.limpiar();
        managerEquipos.eliminarEquipo();
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
