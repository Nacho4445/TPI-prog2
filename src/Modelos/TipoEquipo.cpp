#include "Modelos/TipoEquipo.h"
#include <cstring>

TipoEquipo::TipoEquipo(int idTipoEquipo, const char* descripcion, bool estado) {

    _idTipoEquipo = idTipoEquipo;
    strcpy(_descripcion, descripcion);
    _estado = estado;
}

int TipoEquipo::getIdTipoEquipo() {
    return _idTipoEquipo;
}

const char* TipoEquipo::getDescripcion() {
    return _descripcion;
}

bool TipoEquipo::getEstado() {
    return _estado;
}

void TipoEquipo::setIdTipoEquipo(int idTipoEquipo) {
    _idTipoEquipo = idTipoEquipo;
}

void TipoEquipo::setDescripcion(const char* descripcion) {
    strcpy(_descripcion, descripcion);
}

void TipoEquipo::setEstado(bool estado) {
    _estado = estado;
}
