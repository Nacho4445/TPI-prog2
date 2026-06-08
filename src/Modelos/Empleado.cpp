#include <iostream>
#include "Modelos/Empleado.h"

Empleado::Empleado(int idEmpleado) {
    _idEmpleado = idEmpleado;
}

int Empleado::getIdEmpleado() {
    return _idEmpleado;
}

void Empleado::setIdEmpleado(int idEmpleado) {
    _idEmpleado = idEmpleado;
}
