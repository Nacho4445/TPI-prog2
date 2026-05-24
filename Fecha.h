#ifndef TPI_PROG2_FECHA_H
#define TPI_PROG2_FECHA_H

class Fecha {
private:
	int dia = 0, mes = 0, anio = 0;

public:
	Fecha() = default;

	Fecha(int dia, int mes, int anio);

	int getDia();

	int getMes();

	int getAnio();

	void setDia(int dia);

	void setMes(int mes);

	void setAnio(int anio);
};

#endif //TPI_PROG2_FECHA_H