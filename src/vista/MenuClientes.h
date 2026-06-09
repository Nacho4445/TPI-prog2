#pragma once
#include "modelos/Menu.h"
#include "negocio/ClienteManager.h"

class MenuClientes : public Menu{
private:
    ClienteManager managerClientes;

public:
    MenuClientes();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
