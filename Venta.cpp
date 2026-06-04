#include "Venta.h"

Venta::Venta(int idVenta, int idCliente, int idEmpleado, Fecha fechaVenta, double importeTotal, bool estado) 

{
    _idVenta = idVenta;
    _idCliente = idCliente;
    _idEmpleado = idEmpleado;
    _fechaVenta = fechaVenta;
    _importeTotal = importeTotal;
    _estado = estado;
}

int Venta::getIdVenta() {
    return _idVenta;
}

int Venta::getIdCliente() {
    return _idCliente;
}

int Venta::getIdEmpleado() {
    return _idEmpleado;
}

Fecha Venta::getFecha() {
    return _fechaVenta;
}

double Venta::getImporteTotal() {
    return _importeTotal;
}

bool Venta::getEstado() {
    return _estado;
}

void Venta::setIdVenta(int idVenta) {
    _idVenta = idVenta;
}

void Venta::setIdCliente(int idCliente) {
    _idCliente = idCliente;
}

void Venta::setIdEmpleado(int idEmpleado) {
    _idEmpleado = idEmpleado;
}

void Venta::setFecha(Fecha fechaVenta) {
    _fechaVenta = fechaVenta;
}

void Venta::setImporteTotal(double importeTotal) {
    if (importeTotal > 0.0) {
        _importeTotal = importeTotal;
    }
}

void Venta::setEstado(bool estado) {
    _estado = estado;
}
