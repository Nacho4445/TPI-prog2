#include <iostream>
#include "Empleado.h"

using namespace std;

Empleado::Empleado(int idEmpleado, bool estado) : idEmpleado(idEmpleado), estado(estado) {
}

int Empleado::getIdEmpleado() {
	return idEmpleado;
}

bool Empleado::getEstado() {
	return estado;
}

void Empleado::setIdEmpleado(int idEmpleado) {
	this->idEmpleado = idEmpleado;
}

void Empleado::setEstado(bool estado) {
	this->estado = estado;
}
