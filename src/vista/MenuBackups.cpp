#include <iostream>
#include "MenuBackups.h"

using namespace std;

MenuBackups::MenuBackups() {
	setCantidadOpciones(8);
}

void MenuBackups::mostrarOpciones() {
	consola.limpiar();
	cout << "\n### HACER UN BACKUP ###\n";
	cout << "1. Hacer Backup de Empleados\n";
	cout << "2. Hacer Backup de Clientes\n";
	cout << "3. Hacer Backup de Tipos de Clientes\n";
	cout << "4. Hacer Backup de Ventas\n";
	cout << "5. Hacer Backup de Detalles de Ventas\n";
	cout << "6. Hacer Backup de Equipos\n";
	cout << "7. Hacer Backup de Tipos de Equipos\n";
	cout << "8. Hacer Backup de Tipos de Marcas\n";
	cout << "- - - - - - - - - -\n";
	cout << "0. Volver al menu anterior\n";
}

void MenuBackups::ejecutarOpcion(int opcion) {
	switch (opcion) {
		case 1: {
			Empleado empleado;
			archivosManager.crearBackup(empleado);
			break;
		}
		case 2: {
			Cliente cliente;
			archivosManager.crearBackup(cliente);
			break;
		}
		case 3: {
			TipoCliente tipoCliente;
			archivosManager.crearBackup(tipoCliente);
			break;
		}
		case 4: {
			Venta venta;
			archivosManager.crearBackup(venta);
			break;
		}
		case 5: {
			DetalleVenta detalleVenta;
			archivosManager.crearBackup(detalleVenta);
			break;
		}
		case 6: {
			Equipo equipo;
			archivosManager.crearBackup(equipo);
			break;
		}
		case 7: {
			TipoEquipo tipoEquipo;
			archivosManager.crearBackup(tipoEquipo);
			break;
		}
		case 8: {
			TipoMarca tipoMarca;
			archivosManager.crearBackup(tipoMarca);
			break;
		}
		case 0:
			mostrarOpciones();
			break;
		default:
			cout << "Opcion Incorrecta!\n";
			break;
	}
}
