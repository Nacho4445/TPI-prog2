#pragma once
#include "modelos/Menu.h"
#include "negocio/VentaManager.h"

class MenuVentas : public Menu{
private:
    VentaManager managerVentas;

public:
    MenuVentas();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
