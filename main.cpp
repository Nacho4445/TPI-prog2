#include <iostream>
#include "src/vista/MenuPrincipal.h"
#include "src/modelos/CargarDatosPrueba.h"

using namespace std;

/*
agregar baja en cliente
Aclarar rangos a la hora de hacer cargas
Validar id de empleado en ventas
Verificar el nombre ve marca y tipo en listado de ventas
 */

int main() {
    CargarDatosPrueba cargarDatos;
    cargarDatos.cargarDatosPrueba();

    MenuPrincipal menu;
    menu.ejecutarMenu();

    return 0;
}
