#include <iostream>
#include <cstring>
#include "modelos/Cliente.h"

using namespace std;

Cliente::Cliente(int idCliente, int tipoCliente) {

    _idCliente = idCliente;

    if (tipoCliente == 1 || tipoCliente == 2) {
        _tipoCliente = tipoCliente;
        setEstado(true);
    }
    else {
        _tipoCliente = 0;
        setEstado(false);
    }
}

int Cliente::getIdCliente() {
    return _idCliente;
}

int Cliente::getTipoCliente() {
    return _tipoCliente;
}

void Cliente::setIdCliente(int idCliente) {
    _idCliente = idCliente;
}

void Cliente::setTipoCliente(int tipoCliente) {

    if (tipoCliente == 1 || tipoCliente == 2) {
        _tipoCliente = tipoCliente;
    }
    else {
        cout << "tipoCliente invalido para cliente: " << _idCliente << endl;
    }
}
