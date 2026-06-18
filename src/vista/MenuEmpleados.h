#pragma once
#include "modelos/Menu.h"
#include "negocio/EmpleadoManager.h"
#include "utils/Consola.h"
#include "utils/Validador.h"

class MenuEmpleados : public Menu{
private:

    Consola consola;
    Validador validador;

    EmpleadoManager managerEmpleados;

public:
    MenuEmpleados();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
