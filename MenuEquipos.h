#pragma once
#include "Menu.h"
#include "EquipoManager.h"

class MenuEquipos : public Menu{
private:
    EquipoManager managerEquipos;

public:
    MenuEquipos();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
