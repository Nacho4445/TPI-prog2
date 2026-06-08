#pragma once
#include "Persona.h"

class Empleado : public Persona {


public:
    Empleado() = default;
    Empleado(int idEmpleado);

    int getIdEmpleado();
    void setIdEmpleado(int idEmpleado);

private:
    int _idEmpleado = 0;

};
