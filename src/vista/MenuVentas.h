#pragma once
#include "modelos/Menu.h"
#include "negocio/VentaManager.h"
#include "utils/Consola.h"
#include "utils/Validador.h"

class MenuVentas : public Menu{
private:
    Consola consola;
    Validador validador;
    VentaManager managerVentas;

public:
    MenuVentas();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
