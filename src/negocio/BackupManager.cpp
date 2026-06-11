#include "BackupManager.h"
#include <iostream>
#include <cstdio>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// void *pGenerico es un puntero que acepta la direccion de cualquier objeto
bool BackupManager::copiarArchivo(const string &nombreOrigen, const string &nombreDestino, void *pGenerico,
                                  const int tamanio) {
	// Puntero del archivo origen
	FILE *pOrigen = fopen(nombreOrigen.c_str(), "rb");
	if (pOrigen == NULL) {
		cout << "Error al intentar abrir el archivo '" << nombreOrigen << "'\n";
		return false;
	}

	const string nombreFinal = crearNombre(nombreDestino);

	// Puntero del archivo destino
	FILE *pDestino = fopen(nombreFinal.c_str(), "wb");
	if (pDestino == NULL) {
		cout << "Error al crear el archivo '" << nombreFinal << "'\n";
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

// void *pGenerico es un puntero que acepta la direccion de cualquier objeto
bool BackupManager::restaurarArchivo(const string &rutaBackup, const string &rutaOriginal, void *pGenerico,
                                     const int tamanio) {
	FILE *pBackup = fopen(rutaBackup.c_str(), "rb");
	if (pBackup == NULL) {
		cout << "Error al intentar abrir el archivo de backup '" << rutaBackup << "'\n";
		return false;
	}

	// Cambiar nombre del backup a la version simple, borrar los caracteres a partir de '_'

	FILE *pDestino = fopen(rutaOriginal.c_str(), "wb");
	if (pDestino == NULL) {
		cout << "Error al intentar sobreescribir el archivo '" << rutaOriginal << "'\n";
		fclose(pBackup);
		return false;
	}

	while (fread(pGenerico, tamanio, 1, pBackup)) {
		fwrite(pGenerico, tamanio, 1, pDestino);
	}

	fclose(pBackup);
	fclose(pDestino);
	return true;
}


string BackupManager::crearNombre(const string &nombreOriginal) {
	const time_t tiempoActual = time(NULL);
	const tm *tiempoLocal = localtime(&tiempoActual);
	char fecha[50];

	// Formatea la fecha y hora actual< con el formato _AAAAMMDD_HHMMSS y la guarda en 'fecha'
	sprintf(fecha, "_%04d%02d%02d_%02d%02d%02d",
	        tiempoLocal->tm_year + 1900,
	        tiempoLocal->tm_mon + 1,
	        tiempoLocal->tm_mday,
	        tiempoLocal->tm_hour,
	        tiempoLocal->tm_min,
	        tiempoLocal->tm_sec);

	return "datos/backups/" + nombreOriginal + string(fecha) + ".dat";
}

string BackupManager::seleccionarBackup(const string &filtro) {
	const string rutaBackups = "datos/backups/";

	if (!fs::exists(rutaBackups)) {
		cout << "La carpeta '" << rutaBackups << "' no existe!";
		return "";
	}

	// Se cuenta cuantos archivos coinciden con el filtro
	int cantidadOpciones = 0;
	for (const fs::directory_entry &item: fs::directory_iterator(rutaBackups)) {
		if (item.is_regular_file()) {
			string nombreArchivo = item.path().filename().string();
			if (filtro == "todos" || nombreArchivo.find(filtro) != string::npos) {
				cantidadOpciones++;
			}
		}
	}

	if (cantidadOpciones == 0) {
		cout << "No se encontraron backups para: " << filtro << "\n";
		return "";
	}

	string *opciones = new string[cantidadOpciones];

	cout << "\n### BACKUPS DISPONIBLES (" << filtro << ") ###\n";

	int indice = 0;
	for (const fs::directory_entry &item: fs::directory_iterator(rutaBackups)) {
		if (item.is_regular_file()) {
			string nombreArchivo = item.path().filename().string();

			if (filtro == "todos" || nombreArchivo.find(filtro) != string::npos) {
				opciones[indice] = nombreArchivo;
				cout << indice + 1 << ") " << nombreArchivo << "\n";
				indice++;
			}
		}
	}

	int seleccion;
	cout << "Seleccione el numero de backup a restaurar (0 para cancelar): ";
	cin >> seleccion;

	if (seleccion == 0) {
		cout << "Operacion cancelada.\n";
		delete[] opciones;
		return "";
	}
	if (seleccion < 0 || seleccion > cantidadOpciones) {
		cout << "Opcion invalida.\n";
		delete[] opciones;
		return "";
	}

	const string nombreElegido = opciones[seleccion - 1];

	delete[] opciones;

	return rutaBackups + nombreElegido;
}

bool BackupManager::crearBackup(Empleado &empleado) {
	const bool exito = copiarArchivo("datos/empleados.dat", "empleados", &empleado, sizeof(Empleado));
	if (exito) cout << "Backup de Empleados generado!\n";
	return exito;
}

bool BackupManager::crearBackup(Cliente &cliente) {
	const bool exito = copiarArchivo("datos/clientes.dat", "clientes", &cliente, sizeof(Cliente));
	if (exito) cout << "Backup de Clientes generado!\n";
	return exito;
}

bool BackupManager::crearBackup(TipoCliente &tipoCliente) {
	const bool exito = copiarArchivo("datos/tiposClientes.dat", "tiposClientes", &tipoCliente, sizeof(TipoCliente));
	if (exito) cout << "Backup de Tipos de Clientes generado!\n";
	return exito;
}

bool BackupManager::crearBackup(Venta &venta) {
	const bool exito = copiarArchivo("datos/ventas.dat", "ventas", &venta, sizeof(Venta));
	if (exito) cout << "Backup de Ventas generado!\n";
	return exito;
}

bool BackupManager::crearBackup(DetalleVenta &detalleVenta) {
	const bool exito = copiarArchivo("datos/detalleVentas.dat", "detalleVentas", &detalleVenta, sizeof(DetalleVenta));
	if (exito) cout << "Backup de Detalles de Venta generado!\n";
	return exito;
}

bool BackupManager::crearBackup(Equipo &equipo) {
	const bool exito = copiarArchivo("datos/equipos.dat", "equipos", &equipo, sizeof(Equipo));
	if (exito) cout << "Backup de Equipos generado!\n";
	return exito;
}

bool BackupManager::crearBackup(TipoEquipo &tipoEquipo) {
	const bool exito = copiarArchivo("datos/tiposEquipos.dat", "tiposEquipos", &tipoEquipo, sizeof(TipoEquipo));
	if (exito) cout << "Backup de Tipos de Equipos generado!\n";
	return exito;
}

bool BackupManager::crearBackup(TipoMarca &tipoMarca) {
	const bool exito = copiarArchivo("datos/tiposMarcas.dat", "tiposMarcas", &tipoMarca, sizeof(TipoMarca));
	if (exito) cout << "Backup de Tipos de Marcas generado!\n";
	return exito;
}

bool BackupManager::restaurarBackup(const string &rutaBackup, Empleado &empleado) {
	const bool exito = restaurarArchivo(rutaBackup, "datos/empleados.dat", &empleado, sizeof(Empleado));
	if (exito) cout << "Backup de Empleados restaurado!\n";
	return exito;
}

bool BackupManager::restaurarBackup(const string &rutaBackup, Cliente &cliente) {
	const bool exito = restaurarArchivo(rutaBackup, "datos/clientes.dat", &cliente, sizeof(Cliente));
	if (exito) cout << "Backup de Clientes restaurado!\n";
	return exito;
}

bool BackupManager::restaurarBackup(const string &rutaBackup, TipoCliente &tipoCliente) {
	const bool exito = restaurarArchivo(rutaBackup, "datos/tiposClientes.dat", &tipoCliente, sizeof(TipoCliente));
	if (exito) cout << "Backup de Tipos de Clientes restaurado!\n";
	return exito;
}

bool BackupManager::restaurarBackup(const string &rutaBackup, Venta &venta) {
	const bool exito = restaurarArchivo(rutaBackup, "datos/ventas.dat", &venta, sizeof(Venta));
	if (exito) cout << "Backup de Ventas restaurado!\n";
	return exito;
}

bool BackupManager::restaurarBackup(const string &rutaBackup, DetalleVenta &detalleVenta) {
	const bool exito = restaurarArchivo(rutaBackup, "datos/detalleVentas.dat", &detalleVenta, sizeof(DetalleVenta));
	if (exito) cout << "Backup de Detalles de Ventas restaurado!\n";
	return exito;
}

bool BackupManager::restaurarBackup(const string &rutaBackup, Equipo &equipo) {
	const bool exito = restaurarArchivo(rutaBackup, "datos/equipos.dat", &equipo, sizeof(Equipo));
	if (exito) cout << "Backup de Equipos restaurado!\n";
	return exito;
}

bool BackupManager::restaurarBackup(const string &rutaBackup, TipoEquipo &tipoEquipo) {
	const bool exito = restaurarArchivo(rutaBackup, "datos/tiposEquipos.dat", &tipoEquipo, sizeof(TipoEquipo));
	if (exito) cout << "Backup de Tipos de Equipos restaurado!\n";
	return exito;
}

bool BackupManager::restaurarBackup(const string &rutaBackup, TipoMarca &tipoMarca) {
	const bool exito = restaurarArchivo(rutaBackup, "datos/tiposMarcas.dat", &tipoMarca, sizeof(TipoMarca));
	if (exito) cout << "Backup de Tipos de Marcas restaurado!\n";
	return exito;
}

void BackupManager::restaurarBackupGeneral(const std::string &rutaBackup) {
	if (rutaBackup.find("empleados") != string::npos) {
		Empleado empleado;
		restaurarBackup(rutaBackup, empleado);
	} else if (rutaBackup.find("tiposClientes") != string::npos) {
		TipoCliente tipoCliente;
		restaurarBackup(rutaBackup, tipoCliente);
	} else if (rutaBackup.find("clientes") != string::npos) {
		Cliente cliente;
		restaurarBackup(rutaBackup, cliente);
	} else if (rutaBackup.find("detalleVentas") != string::npos) {
		DetalleVenta detalleVenta;
		restaurarBackup(rutaBackup, detalleVenta);
	} else if (rutaBackup.find("ventas") != string::npos) {
		Venta venta;
		restaurarBackup(rutaBackup, venta);
	} else if (rutaBackup.find("tiposEquipos") != string::npos) {
		TipoEquipo tipoEquipo;
		restaurarBackup(rutaBackup, tipoEquipo);
	} else if (rutaBackup.find("equipos") != string::npos) {
		Equipo equipo;
		restaurarBackup(rutaBackup, equipo);
	} else if (rutaBackup.find("tiposMarcas") != string::npos) {
		TipoMarca tipoMarca;
		restaurarBackup(rutaBackup, tipoMarca);
	} else {
		cout << "Error: No se pudo determinar el tipo de entidad del backup.\n";
	}
}

