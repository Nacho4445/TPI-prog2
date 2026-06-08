#pragma once
#include "Modelos/Menu.h"
#include "Negocio/VentaManager.h"

class MenuVentas : public Menu{
private:
    VentaManager managerVentas;

public:
    MenuVentas();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
