#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "Persona.h"

class Cliente : public Persona {

public:
    Cliente() = default;

    Cliente(long idCliente, int tipoCliente);

    int getIdCliente();
    int getTipoCliente();

    void setIdCliente(long idCliente);
    void setTipoCliente(int tipoCliente);

private:
    long _idCliente = 0;
    int _tipoCliente = 0; // 1 = particular, 2 = empresa
};

#endif // CLIENTE_H_INCLUDED
