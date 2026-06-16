#pragma once

#include "utils/Consola.h"

class Menu{
private:
    int cantidadOpciones;
    Consola consola;
protected:
    void setCantidadOpciones(int cantidad);
    int getCantidadOpciones();
public:
    Menu();

    void ejecutarMenu();

    virtual void mostrarOpciones() = 0;
    int seleccionarOpcion();
    virtual void ejecutarOpcion(int opcion) = 0;

};
