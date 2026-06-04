#ifndef TPI_PROG2_EMPLEADO_H
#define TPI_PROG2_EMPLEADO_H

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

#endif // TPI_PROG2_EMPLEADO_H
