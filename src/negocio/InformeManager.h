#pragma once
#include "utils/Consola.h"

class InformeManager{
public:
    void recaudacionXanio();
    void recaudacionXcliente();
    void equiposMasVendidos();
    void ventasXempleado();
    void stockDisponible();
private:
    Consola consola;
};
