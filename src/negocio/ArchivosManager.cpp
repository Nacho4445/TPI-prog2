#include "ArchivosManager.h"
#include <iostream>

using namespace std;

// void *pGenerico es un puntero que acepta la direccion de cualquier objeto
bool ArchivosManager::copiarArchivo(const string &rutaOrigen, const string &rutaDestino, void *pGenerico,
                                  const int tamanio) {
	// Puntero del archivo origen
	FILE *pOrigen = fopen(rutaOrigen.c_str(), "rb");
	if (pOrigen == NULL) {
		cout << "Error al intentar abrir el archivo '" << rutaOrigen << "'\n";
		return false;
	}

	// Puntero del archivo destino
	FILE *pDestino = fopen(rutaDestino.c_str(), "wb");
	if (pDestino == NULL) {
		cout << "Error al crear/editar el archivo '" << rutaDestino << "'\n";
		fclose(pOrigen);
		return false;
	}

	while (fread(pGenerico, tamanio, 1, pOrigen)) {
		fwrite(pGenerico, tamanio, 1, pDestino);
	}

	fclose(pOrigen);
	fclose(pDestino);
	return true;
}

// ------------------------------------ SOBRECARGA CREACION BACKUPS ---------------------------------------------------

void ArchivosManager::crearBackup(Empleado &empleado) {
	const bool exito = copiarArchivo("datos/empleados.dat",
	                                 "datos/backups/empleados.dat",
	                                 &empleado,
	                                 sizeof(Empleado));

	if (exito) cout << "Backup de Empleados generado!\n";
	consola.pausar();
}

void ArchivosManager::crearBackup(Cliente &cliente) {
	const bool exito = copiarArchivo("datos/clientes.dat",
	                                 "datos/backups/clientes.dat",
	                                 &cliente,
	                                 sizeof(Cliente));
	if (exito) cout << "Backup de Clientes generado!\n";
	consola.pausar();
}

void ArchivosManager::crearBackup(TipoCliente &tipoCliente) {
	const bool exito = copiarArchivo("datos/tiposClientes.dat",
	                                 "datos/backups/tiposClientes.dat",
	                                 &tipoCliente,
	                                 sizeof(TipoCliente));
	if (exito) cout << "Backup de Tipos de Clientes generado!\n";
	consola.pausar();
}

void ArchivosManager::crearBackup(Venta &venta) {
	const bool exito = copiarArchivo("datos/ventas.dat",
	                                 "datos/backups/ventas.dat",
	                                 &venta,
	                                 sizeof(Venta));
	if (exito) cout << "Backup de Ventas generado!\n";
	consola.pausar();
}

void ArchivosManager::crearBackup(DetalleVenta &detalleVenta) {
	const bool exito = copiarArchivo("datos/detalleVentas.dat",
	                                 "datos/backups/detalleVentas.dat",
	                                 &detalleVenta,
	                                 sizeof(DetalleVenta));
	if (exito) cout << "Backup de Detalles de Venta generado!\n";
	consola.pausar();
}

void ArchivosManager::crearBackup(Equipo &equipo) {
	const bool exito = copiarArchivo("datos/equipos.dat",
	                                 "datos/backups/equipos.dat",
	                                 &equipo,
	                                 sizeof(Equipo));
	if (exito) cout << "Backup de Equipos generado!\n";
	consola.pausar();
}

void ArchivosManager::crearBackup(TipoEquipo &tipoEquipo) {
	const bool exito = copiarArchivo("datos/tiposEquipos.dat",
	                                 "datos/backups/tiposEquipos.dat",
	                                 &tipoEquipo,
	                                 sizeof(TipoEquipo));
	if (exito) cout << "Backup de Tipos de Equipos generado!\n";
	consola.pausar();
}

void ArchivosManager::crearBackup(TipoMarca &tipoMarca) {
	const bool exito = copiarArchivo("datos/tiposMarcas.dat",
	                                 "datos/backups/tiposMarcas.dat",
	                                 &tipoMarca,
	                                 sizeof(TipoMarca));
	if (exito) cout << "Backup de Tipos de Marcas generado!\n";
	consola.pausar();
}

// ------------------------------------ SOBRECARGA RESTAURACION BACKUPS -----------------------------------------------

void ArchivosManager::restaurarBackup(Empleado &empleado) {
	const bool exito = copiarArchivo("datos/backups/empleados.dat",
	                                 "datos/empleados.dat",
	                                 &empleado,
	                                 sizeof(Empleado));
	if (exito) cout << "Backup de Empleados restaurado!\n";
	consola.pausar();
}

void ArchivosManager::restaurarBackup(Cliente &cliente) {
	const bool exito = copiarArchivo("datos/backups/clientes.dat",
	                                 "datos/clientes.dat",
	                                 &cliente,
	                                 sizeof(Cliente));
	if (exito) cout << "Backup de Clientes restaurado!\n";
	consola.pausar();
}

void ArchivosManager::restaurarBackup(TipoCliente &tipoCliente) {
	const bool exito = copiarArchivo("datos/backups/tiposClientes.dat",
	                                 "datos/tiposClientes.dat",
	                                 &tipoCliente,
	                                 sizeof(TipoCliente));
	if (exito) cout << "Backup de Tipos de Clientes restaurado!\n";
	consola.pausar();
}

void ArchivosManager::restaurarBackup(Venta &venta) {
	const bool exito = copiarArchivo("datos/backups/ventas.dat",
	                                 "datos/ventas.dat",
	                                 &venta,
	                                 sizeof(Venta));
	if (exito) cout << "Backup de Ventas restaurado!\n";
	consola.pausar();
}

void ArchivosManager::restaurarBackup(DetalleVenta &detalleVenta) {
	const bool exito = copiarArchivo("datos/backups/detalleVentas.dat",
	                                 "datos/detalleVentas.dat",
	                                 &detalleVenta,
	                                 sizeof(DetalleVenta));
	if (exito) cout << "Backup de Detalles de Ventas restaurado!\n";
	consola.pausar();
}

void ArchivosManager::restaurarBackup(Equipo &equipo) {
	const bool exito = copiarArchivo("datos/backups/equipos.dat",
	                                 "datos/equipos.dat",
	                                 &equipo,
	                                 sizeof(Equipo));
	if (exito) cout << "Backup de Equipos restaurado!\n";
	consola.pausar();
}

void ArchivosManager::restaurarBackup(TipoEquipo &tipoEquipo) {
	const bool exito = copiarArchivo("datos/backups/tiposEquipos.dat",
	                                 "datos/tiposEquipos.dat",
	                                 &tipoEquipo,
	                                 sizeof(TipoEquipo));
	if (exito) cout << "Backup de Tipos de Equipos restaurado!\n";
	consola.pausar();
}

void ArchivosManager::restaurarBackup(TipoMarca &tipoMarca) {
	const bool exito = copiarArchivo("datos/backups/tiposMarcas.dat",
	                                 "datos/tiposMarcas.dat",
	                                 &tipoMarca,
	                                 sizeof(TipoMarca));
	if (exito) cout << "Backup de Tipos de Marcas restaurado!\n";
	consola.pausar();
}
