#include <iostream>
#include "vista/MenuInformes.h"
using namespace std;
#include <cstdio>

MenuInformes::MenuInformes(){
    setCantidadOpciones(5);
}

void MenuInformes::mostrarOpciones(){
    consola.limpiar();
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
        consola.limpiar();
        managerInformes.recaudacionXanio();
        consola.pausar();
        break;

    case 2:
        consola.limpiar();
        managerInformes.recaudacionXcliente();
        consola.pausar();
        break;
    case 3:
        consola.limpiar();
        managerInformes.equiposMasVendidos();
        consola.pausar();
        break;

    case 4:
        consola.limpiar();
         managerInformes.ventasXempleado();
        consola.pausar();
        break;

    case 5:
        consola.limpiar();
        managerInformes.stockDisponible();
        consola.pausar();
        break;

    case 0:
        cout << "Regresando al menu principal..." << endl;
        consola.pausar();
        break;
    }
}
