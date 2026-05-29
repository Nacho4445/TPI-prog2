#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "Fecha.h"

class Venta {
private:
    int idVenta = 0;
    int idCliente = 0;
    int idEmpleado = 0;
    Fecha fechaVenta;
    double importeTotal = 0.0;
    bool estado = false;

public:
    Venta() = default;

    Venta(int idVenta, int idCliente, int idEmpleado, Fecha fecha, double importe, bool estado = true);

    int getIdVenta();

    int getIdCliente();

    int getIdEmpleado();

    Fecha getFecha();

    double getImporteTotal();

    bool getEstado();

    void setIdVenta(int idVenta);

    void setIdCliente(int idCliente);

    void setIdEmpleado(int idEmpleado);

    void setFecha(Fecha fechaVenta);

    void setImporteTotal(double importeTotal);

    void setEstado(bool estado);
};

#endif