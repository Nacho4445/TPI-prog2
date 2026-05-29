#include <iostream>
#include "Venta.h"

using namespace std;

Venta::Venta(
	int idVenta,
	int idCliente,
	int idEmpleado,
	Fecha fechaVenta,
	double importeTotal,
	bool estado
) : idVenta(idVenta),
    idCliente(idCliente),
    idEmpleado(idEmpleado),
    fechaVenta(fechaVenta),
    importeTotal(importeTotal),
    estado(estado) {
}

int Venta::getIdVenta() {
	return idVenta;
}

int Venta::getIdCliente() {
	return idCliente;
}

int Venta::getIdEmpleado() {
	return idEmpleado;
}

Fecha Venta::getFecha() {
	return fechaVenta;
}

double Venta::getImporteTotal() {
	return importeTotal;
}

bool Venta::getEstado() {
	return estado;
}

void Venta::setIdVenta(int idVenta) {
	this->idVenta = idVenta;
}

void Venta::setIdCliente(int idCliente) {
	this->idCliente = idCliente;
}

void Venta::setIdEmpleado(int idEmpleado) {
	this->idEmpleado = idEmpleado;
}

void Venta::setFecha(Fecha fechaVenta) {
	this->fechaVenta = fechaVenta;
}

void Venta::setImporteTotal(double importeTotal) {
	if (importeTotal > 0.0) {
		this->importeTotal = importeTotal;
	}
}

void Venta::setEstado(bool estado) {
	this->estado = estado;
}
