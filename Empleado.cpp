#include <iostream>
#include "Empleado.h"

using namespace std;

Empleado::Empleado(int idEmpleado) : idEmpleado(idEmpleado) {
}

int Empleado::getIdEmpleado() {
	return idEmpleado;
}

void Empleado::setIdEmpleado(int idEmpleado) {
	this->idEmpleado = idEmpleado;
}
