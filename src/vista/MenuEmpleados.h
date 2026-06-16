#pragma once
#include "modelos/Menu.h"
#include "negocio/EmpleadoManager.h"
#include "utils/Consola.h"

class MenuEmpleados : public Menu{
private:
    EmpleadoManager managerEmpleados;
    Consola consola;
public:
    MenuEmpleados();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
