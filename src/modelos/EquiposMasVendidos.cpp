#include <iostream>
#include "EquiposMasVendidos.h"
using namespace std;

EquiposMasVendidos::EquiposMasVendidos(Equipo _equipo, int _cantidadVendida){
    equipo = _equipo;
    cantidadVendida = _cantidadVendida;
}
Equipo EquiposMasVendidos::getEquipo(){
    return equipo;
}
void EquiposMasVendidos::setEquipo(Equipo _equipo){
    equipo = _equipo;
}

int EquiposMasVendidos::getCantidadVendida(){
    return cantidadVendida;
}
void EquiposMasVendidos::setCantidadVendida(int _cantidadVendida){
    cantidadVendida = _cantidadVendida;
}
