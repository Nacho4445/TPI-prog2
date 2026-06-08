#include <cstring>
#include "Modelos/TipoCliente.h"

TipoCliente::TipoCliente(int idTipoCliente, const char *descripcion, bool estado) 

{

    _idTipoCliente = idTipoCliente;
    _estado = estado;

    strcpy(_descripcion, descripcion);
}

int TipoCliente::getIdTipoCliente() {
    return _idTipoCliente;
}

const char *TipoCliente::getDescripcion() {
    return _descripcion;
}

bool TipoCliente::getEstado() {
    return _estado;
}

void TipoCliente::setIdTipoCliente(int idTipoCliente) {
    _idTipoCliente = idTipoCliente;
}

void TipoCliente::setDescripcion(const char *descripcion) {
    strcpy(_descripcion, descripcion);
}

void TipoCliente::setEstado(bool estado) {
    _estado = estado;
}
