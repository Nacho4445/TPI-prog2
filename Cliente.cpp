#include <iostream>
#include <cstring>
#include "Cliente.h"

using namespace std;

Cliente::Cliente(long idCliente, int tipoCliente) : idCliente(idCliente) {
	if (tipoCliente == 1 || tipoCliente == 2) {
		this->tipoCliente = tipoCliente;
		setEstado(true);
	} else {
		this->tipoCliente = 0;
		setEstado(false);
	}
}

long Cliente::getIdCliente() {
	return idCliente;
}

int Cliente::getTipoCliente() {
	return tipoCliente;
}

void Cliente::setIdCliente(long idCliente) {
	this->idCliente = idCliente;
}

void Cliente::setTipoCliente(int tipoCliente) {
	if (tipoCliente == 1 || tipoCliente == 2) {
		this->tipoCliente = tipoCliente;
	} else {
		cout << "tipoCliente invalido para cliente: " << idCliente << endl;
	}
}
