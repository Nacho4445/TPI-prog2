#pragma once
#include "../modelos/Empleado.h"
class VentasXempleado{
private:
    Empleado empleado;
    int cantidadVentas;
    double totalVendido;

public:
    VentasXempleado(Empleado _empleado, int _cantidadVentas, double _totalVendido);


    Empleado getEmpleado();
    void setEmpleado(Empleado _empleado);

    int getCantidadVentas();
    void setCantidadVentas(int _cantidadVentas);

    double getTotalVendido();
    void setTotalVendido(double _totalVendido);

};
