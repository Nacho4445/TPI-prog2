#include "ArchivosManager.h"
#include "archivos/ArchivoEmpleado.h"
#include "archivos/ArchivoCliente.h"
#include "archivos/ArchivoTipoCliente.h"
#include "archivos/ArchivoVenta.h"
#include "archivos/ArchivoDetalleVenta.h"
#include "archivos/ArchivoEquipo.h"
#include "archivos/ArchivoTipoEquipo.h"
#include "archivos/ArchivoTipoMarca.h"
#include <iostream>

using namespace std;

// void *pGenerico es un puntero que acepta la direccion de cualquier objeto
bool ArchivosManager::copiarArchivo(const string &rutaOrigen, const string &rutaDestino, void *pGenerico,
                                    const int tamanio) {
	// Puntero del archivo origen
	FILE *pOrigen = fopen(rutaOrigen.c_str(), "rb");
	if (pOrigen == NULL) {
		cout << "Error al intentar leer el archivo '" << rutaOrigen << "'\n";
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

bool ArchivosManager::abrirArchivosExport(const std::string &rutaOrigen,
                                          const std::string &rutaDestino,
                                          FILE *&pBinario,
                                          FILE *&pCSV) {
	pBinario = fopen(rutaOrigen.c_str(), "rb");
	if (pBinario == NULL) {
		cout << "Error al intentar leer el archivo '" << rutaOrigen << "'\n";
		return false;
	}

	pCSV = fopen(rutaDestino.c_str(), "w");
	if (pCSV == NULL) {
		cout << "Error al exportar el archivo '" << rutaDestino << "'\n";
		return false;
	}
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

// ------------------------------------ EXPORTACION ARCHIVOS CSV ------------------------------------------------------

bool ArchivosManager::exportarEmpleadosCSV() {
	FILE *pBinario = NULL;
	FILE *pCSV = NULL;

	if (!abrirArchivosExport("datos/empleados.dat", "exports/empleados.csv", pBinario, pCSV)) {
		cout << "Operacion cancelada!\n";
		return false;
	}

	ArchivoEmpleado archivo;
	const bool exito = archivo.exportarDatosCSV(pBinario, pCSV);

	fclose(pBinario);
	fclose(pCSV);

	if (exito) {
		cout << "Archivo 'empleados.csv' exportado correctamente!\n";
	}

	return exito;
}

bool ArchivosManager::exportarClientesCSV() {
	FILE *pBinario = NULL;
	FILE *pCSV = NULL;

	if (!abrirArchivosExport("datos/clientes.dat", "exports/clientes.csv", pBinario, pCSV)) {
		cout << "Operacion cancelada!\n";
		return false;
	}

	ArchivoCliente archivo;
	const bool exito = archivo.exportarDatosCSV(pBinario, pCSV);

	fclose(pBinario);
	fclose(pCSV);

	if (exito) {
		cout << "Archivo 'clientes.csv' exportado correctamente!\n";
	}

	return exito;
}

bool ArchivosManager::exportarTipoClientesCSV() {
	FILE *pBinario = NULL;
	FILE *pCSV = NULL;

	if (!abrirArchivosExport("datos/tiposClientes.dat",
	                         "exports/tiposClientes.csv",
	                         pBinario,
	                         pCSV)) {
		cout << "Operacion cancelada!\n";
		return false;
	}

	ArchivoTipoCliente archivo;
	const bool exito = archivo.exportarDatosCSV(pBinario, pCSV);

	fclose(pBinario);
	fclose(pCSV);

	if (exito) {
		cout << "Archivo 'tiposClientes.csv' exportado correctamente!\n";
	}

	return exito;
}

bool ArchivosManager::exportarVentasCSV() {
	FILE *pBinario = NULL;
	FILE *pCSV = NULL;

	if (!abrirArchivosExport("datos/ventas.dat",
							 "exports/ventas.csv",
							 pBinario,
							 pCSV)) {
		cout << "Operacion cancelada!\n";
		return false;
							 }

	ArchivoVenta archivo;
	const bool exito = archivo.exportarDatosCSV(pBinario, pCSV);

	fclose(pBinario);
	fclose(pCSV);

	if (exito) {
		cout << "Archivo 'ventas.csv' exportado correctamente!\n";
	}

	return exito;
}

bool ArchivosManager::exportarDetalleVentasCSV() {
	FILE *pBinario = NULL;
	FILE *pCSV = NULL;

	if (!abrirArchivosExport("datos/detalleVentas.dat",
							 "exports/detalleVentas.csv",
							 pBinario,
							 pCSV)) {
		cout << "Operacion cancelada!\n";
		return false;
							 }

	ArchivoDetalleVenta archivo;
	const bool exito = archivo.exportarDatosCSV(pBinario, pCSV);

	fclose(pBinario);
	fclose(pCSV);

	if (exito) {
		cout << "Archivo 'detalleVentas.csv' exportado correctamente!\n";
	}

	return exito;
}

bool ArchivosManager::exportarEquiposCSV() {
	FILE *pBinario = NULL;
	FILE *pCSV = NULL;

	if (!abrirArchivosExport("datos/equipos.dat",
							 "exports/equipos.csv",
							 pBinario,
							 pCSV)) {
		cout << "Operacion cancelada!\n";
		return false;
							 }

	ArchivoEquipo archivo;
	const bool exito = archivo.exportarDatosCSV(pBinario, pCSV);

	fclose(pBinario);
	fclose(pCSV);

	if (exito) {
		cout << "Archivo 'equipos.csv' exportado correctamente!\n";
	}

	return exito;
}

bool ArchivosManager::exportarTipoEquiposCSV() {
	FILE *pBinario = NULL;
	FILE *pCSV = NULL;

	if (!abrirArchivosExport("datos/tiposEquipos.dat",
							 "exports/tiposEquipos.csv",
							 pBinario,
							 pCSV)) {
		cout << "Operacion cancelada!\n";
		return false;
							 }

	ArchivoTipoEquipo archivo;
	const bool exito = archivo.exportarDatosCSV(pBinario, pCSV);

	fclose(pBinario);
	fclose(pCSV);

	if (exito) {
		cout << "Archivo 'tiposEquipos.csv' exportado correctamente!\n";
	}

	return exito;
}

bool ArchivosManager::exportarTipoMarcasCSV() {
	FILE *pBinario = NULL;
	FILE *pCSV = NULL;

	if (!abrirArchivosExport("datos/tiposMarcas.dat",
							 "exports/tiposMarcas.csv",
							 pBinario,
							 pCSV)) {
		cout << "Operacion cancelada!\n";
		return false;
							 }

	ArchivoTipoMarca archivo;
	const bool exito = archivo.exportarDatosCSV(pBinario, pCSV);

	fclose(pBinario);
	fclose(pCSV);

	if (exito) {
		cout << "Archivo 'tiposMarcas.csv' exportado correctamente!\n";
	}

	return exito;
}
