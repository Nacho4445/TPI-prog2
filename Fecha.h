#ifndef TPI_PROG2_FECHA_H
#define TPI_PROG2_FECHA_H

class Fecha {

public:
    Fecha() = default;

    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

private:
    int _dia = 0;
    int _mes = 0;
    int _anio = 0;
};

#endif // TPI_PROG2_FECHA_H
