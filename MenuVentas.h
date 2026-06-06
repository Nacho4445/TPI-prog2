#pragma once
#include "Menu.h"
#include "VentaManager.h"

class MenuVentas : public Menu{
private:
    VentaManager managerVentas;

public:
    MenuVentas();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
