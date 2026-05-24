#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "Cliente.h"
#include "Empleado.h"
#include "Equipo.h"
#include "Fecha.h"

class Venta {
private:
    int idVenta;
    Cliente comprador;
    Empleado vendedor;
    Equipo *equipos;
    Fecha fecha;
    double importe;
    bool estado;

public:
    Venta();

    Venta(int idVenta, Cliente comprador, Empleado vendedor, Equipo *equipos, Fecha fecha, double importe, bool estado);

    const int getIdVenta();

    const Cliente getComprador();

    const Empleado getVendedor();

    const Equipo *getEquipos();

    const Fecha getFecha();

    const double getImporite();

    const bool getEstado();

    void setIdVenta(int idVenta);

    void setComprador(Cliente comprador);

    void setVendedor(Empleado vendedor);

    void setEquipos(Equipo *equipos);

    void setFecha(Fecha fecha);

    void setImporte(double importe);

    void setEstado(bool estado);
};

#endif