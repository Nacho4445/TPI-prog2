#pragma once
#include "Fecha.h"

class Venta {

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

private:
    int _idVenta = 0;
    int _idCliente = 0;
    int _idEmpleado = 0;
    Fecha _fechaVenta;
    double _importeTotal = 0.0;
    bool _estado = false;
};
