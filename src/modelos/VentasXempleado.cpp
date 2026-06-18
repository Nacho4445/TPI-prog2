#include <iostream>
#include "VentasXempleado.h"
using namespace std;

VentasXempleado::VentasXempleado(Empleado _empleado, int _cantidadVentas, double _totalVendido){
    empleado = _empleado;
    cantidadVentas = _cantidadVentas;
    totalVendido = _totalVendido;
}
Empleado VentasXempleado::getEmpleado(){
    return empleado;
}
void VentasXempleado::setEmpleado(Empleado _empleado){
    empleado = _empleado;
}

int VentasXempleado::getCantidadVentas(){
    return cantidadVentas;
}
void VentasXempleado::setCantidadVentas(int _cantidadVentas){
    cantidadVentas = _cantidadVentas;
}

double VentasXempleado::getTotalVendido(){
    return totalVendido;
}
void VentasXempleado::setTotalVendido(double _totalVendido){
    totalVendido = _totalVendido;
}
