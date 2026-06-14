#include <iostream>
#include "RecaudacionAnual.h"
using namespace std;

RecaudacionAnual::RecaudacionAnual(float _recaudacion, int _anio){
    recaudacion = _recaudacion;
    anio = _anio;
}
int RecaudacionAnual::getAnio(){
    return anio;
}
void RecaudacionAnual::setAnio(int _anio){
    anio = _anio;
}

float RecaudacionAnual::getRecaudacion(){
    return recaudacion;
}
void RecaudacionAnual::setRecaudacion(float _recaudacion){
    recaudacion = _recaudacion;
}
