#include <iostream>
#include "MenuArchivos.h"

#include "MenuBackups.h"
#include "MenuRestaurar.h"

using namespace std;

MenuArchivos::MenuArchivos() {
	setCantidadOpciones(3);
}

void MenuArchivos::mostrarOpciones() {
	consola.limpiar();
	cout << "#### MENU ARCHIVOS ####" << endl;
	cout << "1. Realizar un Backup" << endl;
	cout << "2. Restaurar un Backup" << endl;
	cout << "3. Exportar un archivo CSV" << endl;
	cout << "- - - - - - - - - - -" << endl;
	cout << "0. Volver al menu principal" << endl;
}

void MenuArchivos::ejecutarOpcion(int opcion) {
	switch (opcion) {
		case 1: {
		    consola.limpiar();
			MenuBackups menuBackups;
			menuBackups.ejecutarMenu();
			consola.pausar();
			break;
		}
		case 2: {
		    consola.limpiar();
			MenuRestaurar menuRestaurar;
			menuRestaurar.ejecutarMenu();
			consola.pausar();
			break;
		}
		case 3:
		    consola.limpiar();
			// Falta generar CSV
			consola.pausar();
			break;
		case 0:
		    cout << "Volviendo al menu principal..." << endl;
		    consola.pausar();
			break;
		default:
			cout << "Opcion Incorrecta!\n";
			consola.pausar();
			break;
	}
}
