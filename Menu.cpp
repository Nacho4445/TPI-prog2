#include <iostream>
#include "Menu.h"
using namespace std;
#include <cstdio>

Menu::Menu(){
    setCantidadOpciones(0);
}

void Menu::ejecutarMenu(){
    int opcion;
    do{
        system("cls");
        mostrarOpciones();
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);
        if(opcion != 0){
            system("pause");
        }
    }while (opcion !=0);
}

int Menu::seleccionarOpcion(){
    int opcion;
    cout<<endl;
    do{
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;
        if(opcion<0 || opcion>getCantidadOpciones()){
            cout << "Opcion incorrecta..." << endl;
        }
    }while(opcion<0 || opcion>getCantidadOpciones());
    return opcion;
}

void Menu::setCantidadOpciones(int cantidad){
    cantidadOpciones = cantidad;
}
int Menu::getCantidadOpciones(){
    return cantidadOpciones;
}
