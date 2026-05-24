#ifndef TPI_PROG2_EMPLEADO_H
#define TPI_PROG2_EMPLEADO_H
#include "Persona.h"

class Empleado : public Persona {
private:
	int idEmpleado = 0;
	bool estado = false;

public:
	Empleado() = default;

	Empleado(int idEmpleado, bool estado = true);

	int getIdEmpleado();

	bool getEstado();

	void setIdEmpleado(int idEmpleado);

	void setEstado(bool estado);
};


#endif //TPI_PROG2_EMPLEADO_H