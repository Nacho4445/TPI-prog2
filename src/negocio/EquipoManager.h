#pragma once

#include "archivos/ArchivoEquipo.h"
#include "archivos/ArchivoTipoEquipo.h"
#include "archivos/ArchivoTipoMarca.h"

#include "modelos/Equipo.h"
#include "modelos/TipoEquipo.h"
#include "modelos/TipoMarca.h"

#include "utils/Consola.h"
#include "utils/Validador.h"

class EquipoManager {
private:
    Equipo crearEquipo();

    ArchivoEquipo _archivoEquipos;
    ArchivoTipoEquipo _archivoTipoEquipos;
    ArchivoTipoMarca _archivoTipoMarcas;

    Consola consola;
    Validador validador;

    void mostrarEquipo(Equipo &reg);
    void ordenarEquiposPorTipo(Equipo vEquipos[], int cantidad);
    void ordenarEquiposPorMarca(Equipo vEquipos[], int cantidad);
    void ordenarEquiposPorPrecioAsc(Equipo vEquipos[], int cantidad);
    void ordenarEquiposPorPrecioDesc(Equipo vEquipos[], int cantidad);
    int cargarEquiposActivos(Equipo vEquipos[]);

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
	void modificarEquipo();
	void eliminarEquipo();
	void mostrarEquiposOrdenadosPorTipo();
    void mostrarEquiposOrdenadosPorMarca();
    void mostrarEquiposOrdenadosPorPrecioAsc();
    void mostrarEquiposOrdenadosPorPrecioDesc();


};
