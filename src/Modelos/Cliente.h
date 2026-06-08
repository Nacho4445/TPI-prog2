#pragma once
#include "Modelos/Persona.h"

class Cliente : public Persona {

public:
    Cliente() = default;

    Cliente(int idCliente, int tipoCliente);

    int getIdCliente();
    int getTipoCliente();

    void setIdCliente(int idCliente);
    void setTipoCliente(int tipoCliente);

private:
    int _idCliente = 0;
    int _tipoCliente = 0; // 1 = particular, 2 = empresa
};

