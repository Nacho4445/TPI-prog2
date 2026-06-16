#pragma once
#include "modelos/Menu.h"
#include "negocio/EquipoManager.h"
#include "utils/Consola.h"

class MenuEquipos : public Menu{
private:
    EquipoManager managerEquipos;
    Consola consola;
public:
    MenuEquipos();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
