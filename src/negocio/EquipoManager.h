#pragma once

#include "archivos/ArchivoEquipo.h"
#include "archivos/ArchivoTipoEquipo.h"
#include "archivos/ArchivoTipoMarca.h"

#include "modelos/Equipo.h"
#include "modelos/TipoEquipo.h"
#include "modelos/TipoMarca.h"

#include "utils/Consola.h"

class EquipoManager {
private:
    Equipo crearEquipo();

    ArchivoEquipo _archivoEquipos;
    ArchivoTipoEquipo _archivoTipoEquipos;
    ArchivoTipoMarca _archivoTipoMarcas;

    Consola consola;

    void mostrarEquipo(Equipo &reg);
    void ordenarEquipos(Equipo vEquipos[], int cantidad);

    int seleccionarTipoEquipo();
    int seleccionarMarca();
    int buscarTipoEquipo();
    int buscarMarca();

public:
	EquipoManager();

	void guardarEquipo();
	void consultarPorId();
	void consultarPorTipo();
	void consultarPorMarca();
	void consultarPorPrecio();
	void consultarPorStock();
	void listarEquipos();
	void modificarEquipo();
	void mostrarEquiposOrdenados();
	void eliminarEquipo();


};
