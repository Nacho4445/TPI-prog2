#include <iostream>
#include "../modelos/RecaudacionClientes.h"
using namespace std;

RecaudacionClientes::RecaudacionClientes(float _recaudacion, Cliente _cliente){
    recaudacion = _recaudacion;
    cliente = _cliente;
}
Cliente RecaudacionClientes::getCliente(){
    return cliente;
}
void RecaudacionClientes::setCliente(Cliente _cliente){
    cliente = _cliente;
}

float RecaudacionClientes::getRecaudacion(){
    return recaudacion;
}
void RecaudacionClientes::setRecaudacion(float _recaudacion){
    recaudacion = _recaudacion;
}
