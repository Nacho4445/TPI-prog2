#pragma once
#include "Menu.h"
#include "ClienteManager.h"

class MenuClientes : public Menu{
private:
    ClienteManager managerClientes;

public:
    MenuClientes();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
