#include "modelos/TipoMarca.h"
#include <cstring>

TipoMarca::TipoMarca(int idTipoMarca, const char descripcion[], bool estado) {


    _idTipoMarca = idTipoMarca;
    strcpy(_descripcion, descripcion);
    _estado = estado;
}

int TipoMarca::getIdTipoMarca() {
    return _idTipoMarca;
}

const char* TipoMarca::getDescripcion() {
    return _descripcion;
}

bool TipoMarca::getEstado() {
    return _estado;
}

void TipoMarca::setIdTipoMarca(int idTipoMarca) {
    _idTipoMarca = idTipoMarca;
}

void TipoMarca::setDescripcion(const char descripcion[]) {
    strcpy(_descripcion, descripcion);
}

void TipoMarca::setEstado(bool estado) {
    _estado = estado;
}
