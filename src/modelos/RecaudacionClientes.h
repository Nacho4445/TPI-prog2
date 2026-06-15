#pragma once
#include "../modelos/Cliente.h"

class RecaudacionClientes{
private:
    Cliente cliente;
    float recaudacion;

public:
    RecaudacionClientes(float _recaudacion, Cliente _cliente);
    Cliente getCliente();
    void setCliente(Cliente _cliente);

    float getRecaudacion();
    void setRecaudacion(float _recaudacion);

};
