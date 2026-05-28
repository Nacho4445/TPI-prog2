#ifndef TPI_PROG2_EMPLEADO_H
#define TPI_PROG2_EMPLEADO_H
#include "Persona.h"

class Empleado : public Persona {
private:
	int idEmpleado = 0;

public:
	Empleado() = default;

	Empleado(int idEmpleado);

	int getIdEmpleado();

	void setIdEmpleado(int idEmpleado);
};


#endif //TPI_PROG2_EMPLEADO_H