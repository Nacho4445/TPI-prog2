#include "utils/Direccion.h"

#include <cstring>

Direccion::Direccion(long idDireccion, const char *calle, int altura, const char *piso, const char *departamento, 
                     const char *localidad, const char *codigoPostal, const char *provincia, bool estado) 

{

    _idDireccion = idDireccion;
    _altura = altura;
    _estado = estado;

    strcpy(_calle, calle);
    strcpy(_piso, piso);
    strcpy(_departamento, departamento);
    strcpy(_localidad, localidad);
    strcpy(_codigoPostal, codigoPostal);
    strcpy(_provincia, provincia);
}

int Direccion::getIdDireccion() {
    return _idDireccion;
}

const char *Direccion::getCalle() {
    return _calle;
}

int Direccion::getAltura() {
    return _altura;
}

const char *Direccion::getPiso() {
    return _piso;
}

const char *Direccion::getDepartamento() {
    return _departamento;
}

const char *Direccion::getLocalidad() {
    return _localidad;
}

const char *Direccion::getCodigoPostal() {
    return _codigoPostal;
}

const char *Direccion::getProvincia() {
    return _provincia;
}

bool Direccion::getEstado() {
    return _estado;
}

void Direccion::setIdDireccion(int idDireccion) {
    _idDireccion = idDireccion;
}

void Direccion::setCalle(const char *calle) {
    strcpy(_calle, calle);
}

void Direccion::setAltura(int altura) {
    _altura = altura;
}

void Direccion::setPiso(const char *piso) {
    strcpy(_piso, piso);
}

void Direccion::setDepartamento(const char *departamento) {
    strcpy(_departamento, departamento);
}

void Direccion::setLocalidad(const char *localidad) {
    strcpy(_localidad, localidad);
}

void Direccion::setCodigoPostal(const char *codigoPostal) {
    strcpy(_codigoPostal, codigoPostal);
}

void Direccion::setProvincia(const char *provincia) {
    strcpy(_provincia, provincia);
}

void Direccion::setEstado(bool estado) {
    _estado = estado;
}
