#include "Direccion.h"

#include <cstring>

Direccion::Direccion(long idDireccion,
                     const char *calle,
                     int altura,
                     const char *piso,
                     const char *departamento,
                     const char *localidad,
                     const char *codigoPostal,
                     const char *provincia,
                     bool estado) : idDireccion(idDireccion), altura(altura), estado(estado) {
	strcpy(this->calle, calle);
	strcpy(this->piso, piso);
	strcpy(this->departamento, departamento);
	strcpy(this->localidad, localidad);
	strcpy(this->codigoPostal, codigoPostal);
	strcpy(this->provincia, provincia);
}

int Direccion::getIdDireccion() {
	return idDireccion;
}

const char *Direccion::getCalle() {
	return calle;
}

int Direccion::getAltura() {
	return altura;
}

const char *Direccion::getPiso() {
	return piso;
}

const char *Direccion::getDepartamento() {
	return departamento;
}

const char *Direccion::getLocalidad() {
	return localidad;
}

const char *Direccion::getCodigoPostal() {
	return codigoPostal;
}

const char *Direccion::getProvincia() {
	return provincia;
}

bool Direccion::getEstado() {
	return estado;
}

void Direccion::setIdDireccion(int idDireccion) {
	this->idDireccion = idDireccion;
}

void Direccion::setCalle(char *calle) {
	strcpy(this->calle, calle);
}

void Direccion::setAltura(int altura) {
	this->altura = altura;
}

void Direccion::setPiso(char *piso) {
	strcpy(this->piso, piso);
}

void Direccion::setDepartamento(char *departamento) {
	strcpy(this->departamento, departamento);
}

void Direccion::setLocalidad(char *localidad) {
	strcpy(this->localidad, localidad);
}

void Direccion::setCodigoPostal(char *codigoPostal) {
	strcpy(this->codigoPostal, codigoPostal);
}

void Direccion::setProvincia(char *provincia) {
	strcpy(this->provincia, provincia);
}

void Direccion::setEstado(bool estado) {
	this->estado = estado;
}
