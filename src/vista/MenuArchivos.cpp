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
	cout << "\n### MENU ARCHIVOS ###\n";
	cout << "1. Realizar un Backup\n";
	cout << "2. Restaurar un Backup\n";
	cout << "3. Exportar un archivo CSV\n";
	cout << "- - - - - - - - - -\n";
	cout << "0. Volver al menu principal\n";
}

void MenuArchivos::ejecutarOpcion(int opcion) {
	switch (opcion) {
		case 1: {
			MenuBackups menuBackups;
			menuBackups.ejecutarMenu();
			break;
		}
		case 2: {
			MenuRestaurar menuRestaurar;
			menuRestaurar.ejecutarMenu();
			break;
		}
		case 3:
			// Falta generar CSV
			break;
		case 0:
			break;
		default:
			cout << "Opcion Incorrecta!\n";
			break;
	}
}
