#include <iostream>
#include "MenuBackups.h"

using namespace std;

MenuBackups::MenuBackups() {
	setCantidadOpciones(8);
}

void MenuBackups::mostrarOpciones() {
	consola.limpiar();
	cout << "-------------------------------------\n";
	cout << "---------- HACER UN BACKUP ----------\n";
	cout << "1. Hacer Backup de Empleados\n";
	cout << "2. Hacer Backup de Clientes\n";
	cout << "3. Hacer Backup de Tipos de Clientes\n";
	cout << "4. Hacer Backup de Ventas\n";
	cout << "5. Hacer Backup de Detalles de Ventas\n";
	cout << "6. Hacer Backup de Equipos\n";
	cout << "7. Hacer Backup de Tipos de Equipos\n";
	cout << "8. Hacer Backup de Tipos de Marcas\n";
	cout << "-------------------------------------\n";
	cout << "0. Salir\n";
	cout << "-------------------------------------\n";
}

void MenuBackups::ejecutarOpcion(int opcion) {
	switch (opcion) {
		case 1: {
		    consola.limpiar();
			Empleado empleado;
			archivosManager.crearBackup(empleado);
			consola.pausar();
			break;
		}
		case 2: {
		    consola.limpiar();
			Cliente cliente;
			archivosManager.crearBackup(cliente);
			consola.pausar();
			break;
		}
		case 3: {
		    consola.limpiar();
			TipoCliente tipoCliente;
			archivosManager.crearBackup(tipoCliente);
			consola.pausar();
			break;
		}
		case 4: {
		    consola.limpiar();
			Venta venta;
			archivosManager.crearBackup(venta);
			consola.pausar();
			break;
		}
		case 5: {
		    consola.limpiar();
			DetalleVenta detalleVenta;
			archivosManager.crearBackup(detalleVenta);
			consola.pausar();
			break;
		}
		case 6: {
		    consola.limpiar();
			Equipo equipo;
			archivosManager.crearBackup(equipo);
			consola.pausar();
			break;
		}
		case 7: {
		    consola.limpiar();
			TipoEquipo tipoEquipo;
			archivosManager.crearBackup(tipoEquipo);
			consola.pausar();
			break;
		}
		case 8: {
		    consola.limpiar();
			TipoMarca tipoMarca;
			archivosManager.crearBackup(tipoMarca);
			consola.pausar();
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
