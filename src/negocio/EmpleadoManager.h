#pragma once
#include "archivos/ArchivoEmpleado.h"
#include "utils/Consola.h"

class EmpleadoManager {
private:
   Empleado crearEmpleado();
   void mostrarEmpleado(Empleado &reg);
   void ordenarEmpleados(Empleado vEmpleados[], int cantidad);
   ArchivoEmpleado _archivoEmpleados;
	Consola consola;
public:
	EmpleadoManager();

   void guardarEmpleado();
   void consultarPorId();
   void consultarPorCuit();
   void consultarPorApellido();
   void modificarEmpleado();
   void mostrarEmpleadosOrdenados();
   void darDeBajaEmpleado();


};
