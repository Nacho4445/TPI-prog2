#pragma once
#include "Archivos/ArchivoEmpleado.h"

class EmpleadoManager {
private:
   Empleado crearEmpleado();
   void mostrarEmpleado(const Empleado &reg);
   void ordenarEmpleados(Empleado vEmpleados[], int cantidad);
   ArchivoEmpleado _archivoEmpleados;

public:
	EmpleadoManager();

   void guardarEmpleado();
   void listarEmpleados();
   void modificarEmpleado();
   void mostrarEmpleadosOrdenados();


};
