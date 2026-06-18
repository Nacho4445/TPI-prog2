#include "ArchivosManager.h"
#include <iostream>

using namespace std;

// void *pGenerico es un puntero que acepta la direccion de cualquier objeto
bool ArchivosManager::copiarArchivo(const string &rutaOrigen, const string &rutaDestino, void *pGenerico,
                                  const int tamanio) {
	// Puntero del archivo origen
	FILE *pOrigen = fopen(rutaOrigen.c_str(), "rb");
	if (pOrigen == NULL) {
		cout << "Error al intentar abrir el archivo '" << rutaOrigen << endl;
		return false;
	}

	// Puntero del archivo destino
	FILE *pDestino = fopen(rutaDestino.c_str(), "wb");
	if (pDestino == NULL) {
		cout << "Error al crear/editar el archivo '" << rutaDestino << endl;
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
	                                 "backups/empleados.dat",
	                                 &empleado,
	                                 sizeof(Empleado));

	if (exito) cout << "Backup de Empleados generado!\n";
}

void ArchivosManager::crearBackup(Cliente &cliente) {
	const bool exito = copiarArchivo("datos/clientes.dat",
	                                 "backups/clientes.dat",
	                                 &cliente,
	                                 sizeof(Cliente));
	if (exito) cout << "Backup de Clientes generado!\n";
}

void ArchivosManager::crearBackup(TipoCliente &tipoCliente) {
	const bool exito = copiarArchivo("datos/tiposClientes.dat",
	                                 "backups/tiposClientes.dat",
	                                 &tipoCliente,
	                                 sizeof(TipoCliente));
	if (exito) cout << "Backup de Tipos de Clientes generado!\n";
}

void ArchivosManager::crearBackup(Venta &venta) {
	const bool exito = copiarArchivo("datos/ventas.dat",
	                                 "backups/ventas.dat",
	                                 &venta,
	                                 sizeof(Venta));
	if (exito) cout << "Backup de Ventas generado!\n";
}

void ArchivosManager::crearBackup(DetalleVenta &detalleVenta) {
	const bool exito = copiarArchivo("datos/detalleVentas.dat",
	                                 "backups/detalleVentas.dat",
	                                 &detalleVenta,
	                                 sizeof(DetalleVenta));
	if (exito) cout << "Backup de Detalles de Venta generado!\n";
}

void ArchivosManager::crearBackup(Equipo &equipo) {
	const bool exito = copiarArchivo("datos/equipos.dat",
	                                 "backups/equipos.dat",
	                                 &equipo,
	                                 sizeof(Equipo));
	if (exito) cout << "Backup de Equipos generado!\n";
}

void ArchivosManager::crearBackup(TipoEquipo &tipoEquipo) {
	const bool exito = copiarArchivo("datos/tiposEquipos.dat",
	                                 "backups/tiposEquipos.dat",
	                                 &tipoEquipo,
	                                 sizeof(TipoEquipo));
	if (exito) cout << "Backup de Tipos de Equipos generado!\n";
}

void ArchivosManager::crearBackup(TipoMarca &tipoMarca) {
	const bool exito = copiarArchivo("datos/tiposMarcas.dat",
	                                 "backups/tiposMarcas.dat",
	                                 &tipoMarca,
	                                 sizeof(TipoMarca));
	if (exito) cout << "Backup de Tipos de Marcas generado!\n";
}

// ------------------------------------ SOBRECARGA RESTAURACION BACKUPS -----------------------------------------------

void ArchivosManager::restaurarBackup(Empleado &empleado) {
	const bool exito = copiarArchivo("backups/empleados.dat",
	                                 "datos/empleados.dat",
	                                 &empleado,
	                                 sizeof(Empleado));
	if (exito) cout << "Backup de Empleados restaurado!\n";
}

void ArchivosManager::restaurarBackup(Cliente &cliente) {
	const bool exito = copiarArchivo("backups/clientes.dat",
	                                 "datos/clientes.dat",
	                                 &cliente,
	                                 sizeof(Cliente));
	if (exito) cout << "Backup de Clientes restaurado!\n";
}

void ArchivosManager::restaurarBackup(TipoCliente &tipoCliente) {
	const bool exito = copiarArchivo("backups/tiposClientes.dat",
	                                 "datos/tiposClientes.dat",
	                                 &tipoCliente,
	                                 sizeof(TipoCliente));
	if (exito) cout << "Backup de Tipos de Clientes restaurado!\n";
}

void ArchivosManager::restaurarBackup(Venta &venta) {
	const bool exito = copiarArchivo("backups/ventas.dat",
	                                 "datos/ventas.dat",
	                                 &venta,
	                                 sizeof(Venta));
	if (exito) cout << "Backup de Ventas restaurado!\n";
}

void ArchivosManager::restaurarBackup(DetalleVenta &detalleVenta) {
	const bool exito = copiarArchivo("backups/detalleVentas.dat",
	                                 "datos/detalleVentas.dat",
	                                 &detalleVenta,
	                                 sizeof(DetalleVenta));
	if (exito) cout << "Backup de Detalles de Ventas restaurado!\n";
}

void ArchivosManager::restaurarBackup(Equipo &equipo) {
	const bool exito = copiarArchivo("backups/equipos.dat",
	                                 "datos/equipos.dat",
	                                 &equipo,
	                                 sizeof(Equipo));
	if (exito) cout << "Backup de Equipos restaurado!\n";
}

void ArchivosManager::restaurarBackup(TipoEquipo &tipoEquipo) {
	const bool exito = copiarArchivo("backups/tiposEquipos.dat",
	                                 "datos/tiposEquipos.dat",
	                                 &tipoEquipo,
	                                 sizeof(TipoEquipo));
	if (exito) cout << "Backup de Tipos de Equipos restaurado!\n";
}

void ArchivosManager::restaurarBackup(TipoMarca &tipoMarca) {
	const bool exito = copiarArchivo("backups/tiposMarcas.dat",
	                                 "datos/tiposMarcas.dat",
	                                 &tipoMarca,
	                                 sizeof(TipoMarca));
	if (exito) cout << "Backup de Tipos de Marcas restaurado!\n";
}
