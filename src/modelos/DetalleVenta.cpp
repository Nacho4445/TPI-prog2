#include <iostream>
#include "modelos/DetalleVenta.h"

DetalleVenta::DetalleVenta(int idDetalleVenta,int idVenta,int idEquipo,int cantidad,float precioUnitario,float subtotal,bool estado)

{
    _idDetalleVenta = idDetalleVenta;
    _idVenta = idVenta;
    _idEquipo = idEquipo;
    _cantidad = cantidad;
    _precioUnitario = precioUnitario;
    _subtotal = subtotal;
    _estado = estado;
}

int DetalleVenta::getIdDetalleVenta()
{
    return _idDetalleVenta;
}

int DetalleVenta::getIdVenta()
{
    return _idVenta;
}

int DetalleVenta::getIdEquipo()
{
    return _idEquipo;
}

int DetalleVenta::getCantidad()
{
    return _cantidad;
}

float DetalleVenta::getPrecioUnitario()
{
    return _precioUnitario;
}

float DetalleVenta::getSubtotal()
{
    return _subtotal;
}

bool DetalleVenta::getEstado()
{
    return _estado;
}

void DetalleVenta::setIdDetalleVenta(int idDetalleVenta)
{
    _idDetalleVenta = idDetalleVenta;
}

void DetalleVenta::setIdVenta(int idVenta)
{
    _idVenta = idVenta;
}

void DetalleVenta::setIdEquipo(int idEquipo)
{
    _idEquipo = idEquipo;
}

void DetalleVenta::setCantidad(int cantidad)
{
    _cantidad = cantidad;
}

void DetalleVenta::setPrecioUnitario(float precioUnitario)
{
    _precioUnitario = precioUnitario;
}

void DetalleVenta::setSubtotal(float subtotal)
{
    _subtotal = subtotal;
}

void DetalleVenta::setEstado(bool estado)
{
    _estado = estado;
}
