#include "MenuExports.h"
#include <iostream>

using namespace std;

MenuExports::MenuExports() {
	setCantidadOpciones(8);
}


void MenuExports::mostrarOpciones() {
	consola.limpiar();
	cout << "----------------------------------------------\n";
	cout << "---------------- MENU EXPORTS ----------------\n";
	cout << "1. Exportar archivo CSV de Empleados\n";
	cout << "2. Exportar archivo CSV de Clientes\n";
	cout << "3. Exportar archivo CSV de Tipos de Clientes\n";
	cout << "4. Exportar archivo CSV de Ventas\n";
	cout << "5. Exportar archivo CSV de Detalles de Ventas\n";
	cout << "6. Exportar archivo CSV de Equipos\n";
	cout << "7. Exportar archivo CSV de Tipos de Equipos\n";
	cout << "8. Exportar archivo CSV de Tipos de Marcas\n";
	cout << "----------------------------------------------\n";
	cout << "0. Salir\n";
	cout << "----------------------------------------------\n";
}

void MenuExports::ejecutarOpcion(int opcion) {
	switch (opcion) {
		case 1:
			consola.limpiar();
			archivosManager.exportarEmpleadosCSV();
			consola.pausar();
			break;
		case 2:
			consola.limpiar();
			archivosManager.exportarClientesCSV();
			consola.pausar();
			break;
		case 3:
			consola.limpiar();
			archivosManager.exportarTipoClientesCSV();
			consola.pausar();
			break;
		case 4:
			consola.limpiar();
			archivosManager.exportarVentasCSV();
			consola.pausar();
			break;
		case 5:
			consola.limpiar();
			archivosManager.exportarDetalleVentasCSV();
			consola.pausar();
			break;
		case 6:
			consola.limpiar();
			archivosManager.exportarEquiposCSV();
			consola.pausar();
			break;
		case 7:
			consola.limpiar();
			archivosManager.exportarTipoEquiposCSV();
			consola.pausar();
			break;
		case 8:
			consola.limpiar();
			archivosManager.exportarTipoMarcasCSV();
			consola.pausar();
			break;
		case 0:
			break;
		default:
			cout << "Opcion Incorrecta!\n";
			break;
	}
}

