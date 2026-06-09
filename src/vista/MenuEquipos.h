#pragma once
#include "modelos/Menu.h"
#include "negocio/EquipoManager.h"

class MenuEquipos : public Menu{
private:
    EquipoManager managerEquipos;

public:
    MenuEquipos();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
