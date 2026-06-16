#pragma once
#include "modelos/Menu.h"
#include "negocio/InformeManager.h"
#include "utils/Consola.h"

class MenuInformes : public Menu{
private:
    InformeManager managerInformes;
    Consola consola;
public:
    MenuInformes();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
};
