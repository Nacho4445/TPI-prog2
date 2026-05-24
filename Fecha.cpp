#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anio) {
	if (dia > 0 && mes > 0 && anio > 0) {
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
	}
}

int Fecha::getDia() {
	return this->dia;
}

int Fecha::getMes() {
	return this->mes;
}

int Fecha::getAnio() {
	return this->anio;
}

void Fecha::setDia(int dia) {
	if (dia > 0) {
		this->dia = dia;
	}
}

void Fecha::setMes(int mes) {
	if (mes > 0) {
		this->mes = mes;
	}
}

void Fecha::setAnio(int anio) {
	if (anio > 0) {
		this->anio = anio;
	}
}
