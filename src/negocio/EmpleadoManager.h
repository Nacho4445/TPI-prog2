#pragma once
#include "archivos/ArchivoEmpleado.h"
#include "utils/Consola.h"
#include "utils/Validador.h"

class EmpleadoManager {
private:

    Consola consola;
	Validador validador;

	Empleado crearEmpleado();
    ArchivoEmpleado _archivoEmpleados;

    void mostrarEmpleado(Empleado &reg);
    void ordenarEmpleados(Empleado vEmpleados[], int cantidad);


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
