#pragma once
#include "ArchivoEquipo.h"

class EquipoManager {
private:
   Equipo crearEquipo();
   void mostrarEquipo(const Equipo &reg);
   void ordenarEquipos(Equipo vEquipos[], int cantidad);
   ArchivoEquipo _repoEquipos;

public:
	EquipoManager();

   void guardarEquipo();
   void listarEquipos();
   void modificarEquipo();
   void mostrarEquiposOrdenados();


};
