#include <iostream>
#include "vista/MenuInformes.h"
using namespace std;
#include <cstdio>

MenuInformes::MenuInformes(){
    setCantidadOpciones(5);
}

void MenuInformes::mostrarOpciones(){
    system("cls");
    cout << "------------------------" << endl;
    cout << "-----MENU INFORMES-----" << endl;
    cout << "1. Recaudacion anual" << endl;
    cout << "2. Recaudacion por cliente" << endl;
    cout << "3. Equipos mas vendidos" << endl;
    cout << "4. Ventas realizadas por empleado" << endl;
    cout << "5. Stock disponible" << endl;
    cout << "------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------" << endl;
}

void MenuInformes::ejecutarOpcion(int opcion){
    switch(opcion){

    case 1:
        managerInformes.recaudacionXanio();
        break;

    case 2:
        ///managerInformes.recaudacionXcliente();
        break;
    case 3:
        ///managerInformes.equiposMasVendidos();
        break;

    case 4:
        ///managerEquipos.ventasXempleado();
        break;

    case 5:
        ///managerInformes.stockDisponible();
        break;

    case 0:
        cout << "Regresando al menu principal..." << endl;
        break;
    }
}
