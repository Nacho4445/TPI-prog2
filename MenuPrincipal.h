#pragma once
#include "Menu.h"
#include "MenuClientes.h"
#include "MenuEquipos.h"
#include "MenuVentas.h"
#include "MenuEmpleados.h"

class MenuPrincipal : public Menu{
private:
    MenuClientes menuClientes;
    MenuEquipos menuEquipos;
    MenuVentas menuVentas;
    MenuEmpleados menuEmpleados;

public:
    MenuPrincipal();

    void mostrarOpciones() override;
    void ejecutarOpcion(int opcion) override;

};

