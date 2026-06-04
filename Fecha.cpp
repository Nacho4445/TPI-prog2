#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anio) {

    if (dia > 0 && mes > 0 && anio > 0) {
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
}

int Fecha::getDia() {
    return _dia;
}

int Fecha::getMes() {
    return _mes;
}

int Fecha::getAnio() {
    return _anio;
}

void Fecha::setDia(int dia) {

    if (dia > 0) {
        _dia = dia;
    }
}

void Fecha::setMes(int mes) {

    if (mes > 0) {
        _mes = mes;
    }
}

void Fecha::setAnio(int anio) {

    if (anio > 0) {
        _anio = anio;
    }
}
