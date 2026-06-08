#pragma once
#include "Modelos/Menu.h"
#include "Negocio/ClienteManager.h"

class MenuClientes : public Menu{
private:
    ClienteManager managerClientes;

public:
    MenuClientes();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
