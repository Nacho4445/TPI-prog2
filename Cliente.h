#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "Persona.h"

class Cliente : public Persona {
private:
    long idCliente = 0;
    int tipoCliente = 0; // 1 = particular, 2 = empresa
public:
    Cliente() = default;

    Cliente(long idCliente, int tipoCliente);

    long getIdCliente();

    int getTipoCliente();

    void setIdCliente(long idCliente);

    void setTipoCliente(int tipoCliente);
};

#endif // CLIENTE_H_INCLUDED
