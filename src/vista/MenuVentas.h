#pragma once
#include "modelos/Menu.h"
#include "negocio/VentaManager.h"
#include "utils/Consola.h"

class MenuVentas : public Menu{
private:
    VentaManager managerVentas;
    Consola consola;
public:
    MenuVentas();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
