#pragma once
#include "modelos/Menu.h"
#include "negocio/EquipoManager.h"
#include "utils/Consola.h"
#include "utils/Validador.h"

class MenuEquipos : public Menu{
private:

    Consola consola;
    Validador validador;
    EquipoManager managerEquipos;

public:
    MenuEquipos();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
