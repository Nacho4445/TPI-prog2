#pragma once

#include "modelos/Empleado.h"
#include "modelos/Cliente.h"
#include "modelos/TipoCliente.h"
#include "modelos/Venta.h"
#include "modelos/DetalleVenta.h"
#include "modelos/Equipo.h"
#include "modelos/TipoEquipo.h"
#include "modelos/TipoMarca.h"
#include "utils/Consola.h"

class ArchivosManager {
private:
	Consola consola;

	bool copiarArchivo(const std::string &rutaOrigen, const std::string &rutaDestino, void *pGenerico, int tamanio);

public:
	bool abrirArchivosExport(const std::string &rutaOrigen,
	                         const std::string &rutaDestino,
	                         FILE *&pBinario,
	                         FILE *&pCSV);

	// Sobrecarga de metodos
	void crearBackup(Empleado &empleado);
	void crearBackup(Cliente &cliente);
	void crearBackup(TipoCliente &tipoCliente);
	void crearBackup(Venta &venta);
	void crearBackup(DetalleVenta &detalleVenta);
	void crearBackup(Equipo &equipo);
	void crearBackup(TipoEquipo &tipoEquipo);
	void crearBackup(TipoMarca &tipoMarca);

	void restaurarBackup(Empleado &empleado);
	void restaurarBackup(Cliente &cliente);
	void restaurarBackup(TipoCliente &tipoCliente);
	void restaurarBackup(Venta &venta);
	void restaurarBackup(DetalleVenta &detalleVenta);
	void restaurarBackup(Equipo &equipo);
	void restaurarBackup(TipoEquipo &tipoEquipo);
	void restaurarBackup(TipoMarca &tipoMarca);

	bool exportarEmpleadosCSV();
	bool exportarClientesCSV();
	bool exportarTipoClientesCSV();
	bool exportarVentasCSV();
	bool exportarDetalleVentasCSV();
	bool exportarEquiposCSV();
	bool exportarTipoEquiposCSV();
	bool exportarTipoMarcasCSV();
};
