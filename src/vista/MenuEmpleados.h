#pragma once
#include "modelos/Menu.h"
#include "negocio/EmpleadoManager.h"

class MenuEmpleados : public Menu{
private:
    EmpleadoManager managerEmpleados;

public:
    MenuEmpleados();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
