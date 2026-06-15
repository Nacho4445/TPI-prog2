#include <iostream>
#include "StockEquipos.h"
using namespace std;

StockEquipos::StockEquipos(Equipo _equipo, int _stock){
    equipo = _equipo;
    stock = _stock;
}
int StockEquipos::getStock(){
    return stock;
}
void StockEquipos::setStock(int _stock){
    stock = _stock;
}

Equipo StockEquipos::getEquipo(){
    return equipo;
}
void StockEquipos::setEquipo(Equipo _equipo){
    equipo = _equipo;
}
