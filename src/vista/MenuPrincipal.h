#pragma once
#include "modelos/Menu.h"
#include "vista/MenuClientes.h"
#include "vista/MenuEquipos.h"
#include "vista/MenuVentas.h"
#include "vista/MenuEmpleados.h"

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

