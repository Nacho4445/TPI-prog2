#pragma once
#include "../modelos/Equipo.h"

class EquiposMasVendidos{
private:
    Equipo equipo;
    int cantidadVendida;

public:
    EquiposMasVendidos(Equipo _equipo, int _cantidadVendida);

    Equipo getEquipo();
    void setEquipo(Equipo _equipo);

    int getCantidadVendida();
    void setCantidadVendida(int _cantidadVendida);

};
