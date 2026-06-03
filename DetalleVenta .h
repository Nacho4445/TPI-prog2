#ifndef DETALLEVENTA _H
#define DETALLEVENTA _H


#pragma once

class DetalleVenta {


public:
    DetalleVenta() = default;

    DetalleVenta(int idDetalleVenta, int idVenta, int idEquipo, int cantidad, float precioUnitario,float Subtotal, bool estado = true);

    int getIdDetalleVenta();
    int getIdVenta();
    int getIdEquipo();
    int getCantidad();
    float getPrecioUnitario();
    float getSubtotal();
    bool getEstado();


    void setIdDetalleVenta(int idDetalleVenta);
    void setIdVenta(int idVenta);
    void setIdEquipo(int idEquipo);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);
    void setSubtotal(float getSubtotal);
    void setEstado(bool estado);

private:

   private:

    int _idDetalleVenta = 0;
    int _idVenta = 0;
    int _idEquipo = 0;
    int _cantidad = 0;
    float _precioUnitario = 0;
    float _subtotal = 0;
    bool _estado = false;
};

#endif // DETALLEVENTA _H
