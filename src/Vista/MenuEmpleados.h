#pragma once
#include "Modelos/Menu.h"
#include "Negocio/EmpleadoManager.h"

class MenuEmpleados : public Menu{
private:
    EmpleadoManager managerEmpleados;

public:
    MenuEmpleados();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
