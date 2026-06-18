#include <iostream>
#include "MenuArchivos.h"
#include "MenuBackups.h"
#include "MenuRestaurar.h"
#include "MenuExports.h"

using namespace std;

MenuArchivos::MenuArchivos() {
	setCantidadOpciones(3);
}

void MenuArchivos::mostrarOpciones() {
	consola.limpiar();
	cout << "---------------------------" << endl;
	cout << "------ MENU ARCHIVOS ------" << endl;
	cout << "1. Realizar un Backup" << endl;
	cout << "2. Restaurar un Backup" << endl;
	cout << "3. Exportar un archivo CSV" << endl;
	cout << "---------------------------" << endl;
	cout << "0. Salir" << endl;
	cout << "---------------------------" << endl;
}

void MenuArchivos::ejecutarOpcion(int opcion) {
	switch (opcion) {
		case 1: {
		    consola.limpiar();
			MenuBackups menuBackups;
			menuBackups.ejecutarMenu();
			break;
		}
		case 2: {
		    consola.limpiar();
			MenuRestaurar menuRestaurar;
			menuRestaurar.ejecutarMenu();
			break;
		}
		case 3: {
			consola.limpiar();
			MenuExports menuExports;
			menuExports.ejecutarMenu();
			break;
		}
		case 0:
			break;
		default:
			cout << "Opcion Incorrecta!\n";
			consola.pausar();
			break;
	}
}
