#pragma once
#include "../modelos/Equipo.h"

class StockEquipos{
private:
    Equipo equipo;
    int stock;

public:
    StockEquipos(Equipo _equipo, int _stock);
    Equipo getEquipo();
    void setEquipo(Equipo _equipo);

    int getStock();
    void setStock(int _stock);

};
