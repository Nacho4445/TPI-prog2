#pragma once
#include "modelos/Menu.h"
#include "negocio/ClienteManager.h"
#include "utils/Consola.h"

class MenuClientes : public Menu{
private:
    ClienteManager managerClientes;
    Consola consola;
public:
    MenuClientes();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
