#pragma once
#include "archivos/ArchivoEquipo.h"

class EquipoManager {
private:
   Equipo crearEquipo();
   void mostrarEquipo(Equipo &reg);
   void ordenarEquipos(Equipo vEquipos[], int cantidad);
   ArchivoEquipo _archivoEquipos;

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
