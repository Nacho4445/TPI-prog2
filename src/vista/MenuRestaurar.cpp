#include <iostream>
#include "MenuRestaurar.h"

using namespace std;

MenuRestaurar::MenuRestaurar() {
	setCantidadOpciones(8);
}

void MenuRestaurar::mostrarOpciones() {
	consola.limpiar();
	cout << "\n### RESTAURACION DE BACKUPS ###\n";
	cout << "1. Restaurar Backup de Empleados\n";
	cout << "2. Restaurar Backup de Clientes\n";
	cout << "3. Restaurar Backup de Tipos de Clientes\n";
	cout << "4. Restaurar Backup de Ventas\n";
	cout << "5. Restaurar Backup de Detalles de Ventas\n";
	cout << "6. Restaurar Backup de Equipos\n";
	cout << "7. Restaurar Backup de Tipos de Equipos\n";
	cout << "8. Restaurar Backup de Tipos de Marcas\n";
	cout << "- - - - - - - - - -\n";
	cout << "0. Volver al menu anterior\n";
}

void MenuRestaurar::ejecutarOpcion(int opcion) {
	switch (opcion) {
		case 1: {
			Empleado empleado;
			archivosManager.restaurarBackup(empleado);
			break;
		}
		case 2: {
			Cliente cliente;
			archivosManager.restaurarBackup(cliente);
			break;
		}
		case 3: {
			TipoCliente tipoCliente;
			archivosManager.restaurarBackup(tipoCliente);
			break;
		}
		case 4: {
			Venta venta;
			archivosManager.restaurarBackup(venta);
			break;
		}
		case 5: {
			DetalleVenta detalleVenta;
			archivosManager.restaurarBackup(detalleVenta);
			break;
		}
		case 6: {
			Equipo equipo;
			archivosManager.restaurarBackup(equipo);
			break;
		}
		case 7: {
			TipoEquipo tipoEquipo;
			archivosManager.restaurarBackup(tipoEquipo);
			break;
		}
		case 8: {
			TipoMarca tipoMarca;
			archivosManager.restaurarBackup(tipoMarca);
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
