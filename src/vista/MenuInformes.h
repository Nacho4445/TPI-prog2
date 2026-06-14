#pragma once
#include "modelos/Menu.h"
#include "negocio/InformeManager.h"

class MenuInformes : public Menu{
private:
    InformeManager managerInformes;

public:
    MenuInformes();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
};
