#pragma once
#include "Menu.h"
#include "EmpleadoManager.h"

class MenuEmpleados : public Menu{
private:
    EmpleadoManager managerEmpleados;

public:
    MenuEmpleados();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
