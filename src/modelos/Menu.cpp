#include <iostream>
#include "modelos/Menu.h"
using namespace std;
#include <cstdio>

Menu::Menu(){
    setCantidadOpciones(0);
}

void Menu::ejecutarMenu(){
    int opcion;
    do{
        consola.limpiar();
        mostrarOpciones();
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);
        if(opcion != 0){
            consola.limpiar();
        }
    }while (opcion !=0);
}

int Menu::seleccionarOpcion(){
    char opcion[10];
    int numero;
    cout << endl;
    do {
        cout << "Seleccione una opcion: ";
        validador.leerTamanioEntrada(opcion, 10);
        cout << endl;

        // Si no es un numero colocamos el valor -1 para continuar el el loop while
        if (!validador.esNumero(opcion)) {
            cout << "Error ingrese un numero valido!" << endl;
            numero = -1;
        } else {
            // Si es numero lo convertimos a entero
            numero = validador.convertirEntero(opcion);

            if(numero < 0 || numero > getCantidadOpciones()){
                cout << "Opcion incorrecta..." << endl;
            }
        }
    } while(numero < 0 || numero > getCantidadOpciones());
    return numero;
}

void Menu::setCantidadOpciones(int cantidad){
    cantidadOpciones = cantidad;
}
int Menu::getCantidadOpciones(){
    return cantidadOpciones;
}
