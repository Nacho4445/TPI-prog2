#include <iostream>
#include "MenuBackups.h"

using namespace std;

void MenuBackups::mostrarOpciones() {
	int opcion = 0;

	cout << "\n### MENU BACKUPS ###\n";
	cout << "1. Realizar un Backup\n";
	cout << "2. Restaurar un Backup\n";
	cout << "3. Exportar un archivo CSV\n";
	cout << "- - - - - - - - - -\n";
	cout << "0. Volver al menu principal\n";
	cin >> opcion;

	switch (opcion) {
		case 1:
			mostrarOpcionesBackups();
			break;
		case 2:
			mostrarOpcionesRestaurar();
			break;
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

void MenuBackups::mostrarOpcionesBackups() {
	int opcion = 0;

	cout << "\n### OPCIONES DE BACKUPS ###\n";
	cout << "1. Realizar un Backup de Empleados\n";
	cout << "2. Realizar un Backup de Clientes\n";
	cout << "3. Realizar un Backup de Tipos de Clientes\n";
	cout << "4. Realizar un Backup de Ventas\n";
	cout << "5. Realizar un Backup de Detalles de Ventas\n";
	cout << "6. Realizar un Backup de Equipos\n";
	cout << "7. Realizar un Backup de Tipos de Equipos\n";
	cout << "8. Realizar un Backup de Tipos de Marcas\n";
	cout << "- - - - - - - - - -\n";
	cout << "0. Volver al menu anterior\n";
	cin >> opcion;

	switch (opcion) {
		case 1: {
			Empleado empleado;
			backupManager.crearBackup(empleado);
			break;
		}
		case 2: {
			Cliente cliente;
			backupManager.crearBackup(cliente);
			break;
		}
		case 3: {
			TipoCliente tipoCliente;
			backupManager.crearBackup(tipoCliente);
			break;
		}
		case 4: {
			Venta venta;
			backupManager.crearBackup(venta);
			break;
		}
		case 5: {
			DetalleVenta detalleVenta;
			backupManager.crearBackup(detalleVenta);
			break;
		}
		case 6: {
			Equipo equipo;
			backupManager.crearBackup(equipo);
			break;
		}
		case 7: {
			TipoEquipo tipoEquipo;
			backupManager.crearBackup(tipoEquipo);
			break;
		}
		case 8: {
			TipoMarca tipoMarca;
			backupManager.crearBackup(tipoMarca);
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

void MenuBackups::mostrarOpcionesRestaurar() {
	int opcion = 0;

	cout << "\n### OPCIONES PARA RESTAURAR BACKUPS ###\n";
	cout << "1. Listar Backups de Empleados\n";
	cout << "2. Listar Backups de Clientes\n";
	cout << "3. Listar Backups de Tipos de Clientes\n";
	cout << "4. Listar Backups de Ventas\n";
	cout << "5. Listar Backups de Detalles de Ventas\n";
	cout << "6. Listar Backups de Equipos\n";
	cout << "7. Listar Backups de Tipos de Equipos\n";
	cout << "8. Listar Backups de Tipos de Marcas\n";
	cout << "9. Listar todos los Backups\n";
	cout << "- - - - - - - - - -\n";
	cout << "0. Volver al menu anterior\n";
	cin >> opcion;

	switch (opcion) {
		case 1: {
			Empleado empleado;
			const string rutaBackup = backupManager.seleccionarBackup("empleados");
			backupManager.restaurarBackup(rutaBackup, empleado);
			break;
		}
		case 2: {
			Cliente cliente;
			const string rutaBackup = backupManager.seleccionarBackup("clientes");
			backupManager.restaurarBackup(rutaBackup, cliente);
			break;
		}
		case 3: {
			TipoCliente tipoCliente;
			const string rutaBackup = backupManager.seleccionarBackup("tiposClientes");
			backupManager.restaurarBackup(rutaBackup, tipoCliente);
			break;
		}
		case 4: {
			Venta venta;
			const string rutaBackup = backupManager.seleccionarBackup("ventas");
			backupManager.restaurarBackup(rutaBackup, venta);
			break;
		}
		case 5: {
			DetalleVenta detalleVenta;
			const string rutaBackup = backupManager.seleccionarBackup("detalleVentas");
			backupManager.restaurarBackup(rutaBackup, detalleVenta);
			break;
		}
		case 6: {
			Equipo equipo;
			const string rutaBackup = backupManager.seleccionarBackup("equipos");
			backupManager.restaurarBackup(rutaBackup, equipo);
			break;
		}
		case 7: {
			TipoEquipo tipoEquipo;
			const string rutaBackup = backupManager.seleccionarBackup("tiposEquipos");
			backupManager.restaurarBackup(rutaBackup, tipoEquipo);
			break;
		}
		case 8: {
			TipoMarca tipoMarca;
			const string rutaBackup = backupManager.seleccionarBackup("tiposMarcas");
			backupManager.restaurarBackup(rutaBackup, tipoMarca);
			break;
		}
		case 9: {
			const string rutaBackup = backupManager.seleccionarBackup("todos");
			if (!rutaBackup.empty()) {
				backupManager.restaurarBackupGeneral(rutaBackup);
			}
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
