#pragma once
#include "Modelos/Menu.h"
#include "Negocio/EquipoManager.h"

class MenuEquipos : public Menu{
private:
    EquipoManager managerEquipos;

public:
    MenuEquipos();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
