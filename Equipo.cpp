#include <iostream>
#include <cstring>
#include "Equipo.h"

using namespace std;

Equipo::Equipo(int idEquipo, const char *descripcion, int stock, float precioUnitario,
               bool estado) : idEquipo(idEquipo), stock(stock), precioUnitario(precioUnitario), estado(estado) {
	strcpy(this->descripcion, descripcion);
}

int Equipo::getIdEquipo() {
	return idEquipo;
}

const char *Equipo::getDescripcion() {
	return descripcion;
}

int Equipo::getStock() {
	return stock;
}

float Equipo::getPrecioUnitario() {
	return precioUnitario;
}

bool Equipo::getEstado() {
	return estado;
}

void Equipo::setIdEquipo(int idEquipo) {
	this->idEquipo = idEquipo;
}

void Equipo::setDescripcion(char *descripcion) {
	strcpy(this->descripcion, descripcion);
}

void Equipo::setStock(int stock) {
	if (stock >= 0) {
		this->stock = stock;
	}
}

void Equipo::setPrecioUnitario(float precioUnitario) {
	if (precioUnitario >= 0.0) {
		this->precioUnitario = precioUnitario;
	}
}

void Equipo::setEstado(bool estado) {
	this->estado = estado;
}
