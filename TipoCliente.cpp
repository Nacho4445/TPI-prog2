#include <iostream>
#include <cstring>
#include "TipoCliente.h"

using namespace std;

TipoCliente::TipoCliente(int idTipoCliente, const char *descripcion, bool estado)
    : idTipoCliente(idTipoCliente), estado(estado) {
    strcpy(this->descripcion, descripcion);
}

int TipoCliente::getIdTipoCliente() {
    return idTipoCliente;
}

const char *TipoCliente::getDescripcion() {
    return descripcion;
}

bool TipoCliente::getEstado() {
    return estado;
}

void TipoCliente::setIdTipoCliente(int idTipoCliente) {
    this->idTipoCliente = idTipoCliente;
}

void TipoCliente::setDescripcion(const char *descripcion) {
    strcpy(this->descripcion, descripcion);
}

void TipoCliente::setEstado(bool estado) {
    this->estado = estado;
}
