#pragma once
#include "modelos/Menu.h"
#include "vista/MenuClientes.h"
#include "vista/MenuEquipos.h"
#include "vista/MenuVentas.h"
#include "vista/MenuEmpleados.h"
#include "vista/MenuArchivos.h"
#include "vista/MenuInformes.h"

class MenuPrincipal : public Menu{
private:
    MenuClientes menuClientes;
    MenuEquipos menuEquipos;
    MenuVentas menuVentas;
    MenuEmpleados menuEmpleados;
    MenuArchivos menuArchivos;
    MenuInformes menuInformes;

public:
    MenuPrincipal();

    void mostrarOpciones() override;
    void ejecutarOpcion(int opcion) override;

};

