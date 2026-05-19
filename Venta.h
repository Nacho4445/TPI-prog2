#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include <string>
#include "Cliente.h"
#include "Equipo.h"

class Venta {
private:
    int idEquipoVendido;
    std::string cuitCliente;
    std::string fecha;
    double importe;
};

#endif