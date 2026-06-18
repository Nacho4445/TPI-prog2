#pragma once
#include "modelos/Menu.h"
#include "negocio/ClienteManager.h"
#include "utils/Consola.h"
#include "utils/Validador.h"

class MenuClientes : public Menu{

private:
    Consola consola;
    Validador validador;
    ClienteManager managerClientes;

public:
    MenuClientes();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

};
