#pragma once
#include "Modelos/Menu.h"
#include "Vista/MenuClientes.h"
#include "Vista/MenuEquipos.h"
#include "Vista/MenuVentas.h"
#include "Vista/MenuEmpleados.h"

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

