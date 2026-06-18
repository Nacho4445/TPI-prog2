#include <iostream>
#include "MenuRestaurar.h"

using namespace std;

MenuRestaurar::MenuRestaurar() {
	setCantidadOpciones(8);
}

void MenuRestaurar::mostrarOpciones() {
	consola.limpiar();
	cout << "#### RESTAURACION DE BACKUPS ####" << endl;
	cout << "1. Restaurar Backup de Empleados" << endl;
	cout << "2. Restaurar Backup de Clientes" << endl;
	cout << "3. Restaurar Backup de Tipos de Clientes" << endl;
	cout << "4. Restaurar Backup de Ventas" << endl;
	cout << "5. Restaurar Backup de Detalles de Ventas" << endl;
	cout << "6. Restaurar Backup de Equipos" << endl;
	cout << "7. Restaurar Backup de Tipos de Equipos" << endl;
	cout << "8. Restaurar Backup de Tipos de Marcas" << endl;
	cout << "- - - - - - - - - - -" << endl;
	cout << "0. Volver al menu anterior" << endl;
}

void MenuRestaurar::ejecutarOpcion(int opcion) {

    switch (opcion) {

    case 1: {
        consola.limpiar();
        Empleado empleado;
        archivosManager.restaurarBackup(empleado);
        consola.pausar();
        break;
    }
    case 2: {
        consola.limpiar();
        Cliente cliente;
        archivosManager.restaurarBackup(cliente);
        consola.pausar();
        break;
    }
    case 3: {
        consola.limpiar();
        TipoCliente tipoCliente;
        archivosManager.restaurarBackup(tipoCliente);
        consola.pausar();
        break;
    }
    case 4: {
        consola.limpiar();
        Venta venta;
        archivosManager.restaurarBackup(venta);
        consola.pausar();
        break;
    }
    case 5: {
        consola.limpiar();
        DetalleVenta detalleVenta;
        archivosManager.restaurarBackup(detalleVenta);
        consola.pausar();
        break;
    }
    case 6: {
        consola.limpiar();
        Equipo equipo;
        archivosManager.restaurarBackup(equipo);
        consola.pausar();
        break;
    }
    case 7: {
        consola.limpiar();
        TipoEquipo tipoEquipo;
        archivosManager.restaurarBackup(tipoEquipo);
        consola.pausar();
        break;
    }
    case 8: {
        consola.limpiar();
        TipoMarca tipoMarca;
        archivosManager.restaurarBackup(tipoMarca);
        consola.pausar();
        break;
    }
    case 0:
        cout << "Volviendo al menu archivos..." << endl;
        consola.pausar();
        break;

    default:
        cout << "Opcion incorrecta." << endl;
        consola.pausar();
        break;
    }
}
