#pragma once

#include "modelos/Empleado.h"
#include "modelos/Cliente.h"
#include "modelos/TipoCliente.h"
#include "modelos/Venta.h"
#include "modelos/DetalleVenta.h"
#include "modelos/Equipo.h"
#include "modelos/TipoEquipo.h"
#include "modelos/TipoMarca.h"

class BackupManager {
private:
	bool copiarArchivo(const std::string &nombreOrigen, const std::string &nombreDestino, void *pGenerico, int tamanio);
	bool restaurarArchivo(const std::string &rutaBackup, const std::string &rutaOriginal, void *pGenerico, int tamanio);
	std::string crearNombre(const std::string &nombreOriginal);
public:
	std::string seleccionarBackup(const std::string &filtro);
	// Sobrecarga de metodos
	bool crearBackup(Empleado &empleado);
	bool crearBackup(Cliente &cliente);
	bool crearBackup(TipoCliente &tipoCliente);
	bool crearBackup(Venta &venta);
	bool crearBackup(DetalleVenta &detalleVenta);
	bool crearBackup(Equipo &equipo);
	bool crearBackup(TipoEquipo &tipoEquipo);
	bool crearBackup(TipoMarca &tipoMarca);
	bool restaurarBackup(const std::string &rutaBackup, Empleado &empleado);
	bool restaurarBackup(const std::string &rutaBackup, Cliente &cliente);
	bool restaurarBackup(const std::string &rutaBackup, TipoCliente &tipoCliente);
	bool restaurarBackup(const std::string &rutaBackup, Venta &venta);
	bool restaurarBackup(const std::string &rutaBackup, DetalleVenta &detalleVenta);
	bool restaurarBackup(const std::string &rutaBackup, Equipo &equipo);
	bool restaurarBackup(const std::string &rutaBackup, TipoEquipo &tipoEquipo);
	bool restaurarBackup(const std::string &rutaBackup, TipoMarca &tipoMarca);
	void restaurarBackupGeneral(const std::string &rutaBackup);
};
