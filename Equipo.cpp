#include "Equipo.h"

#include <cstring>

Equipo::Equipo(int idEquipo,  int idTipoEquipo, int idTipoMarca,  const char *descripcion, int stock, 
               float precioUnitario, bool estado) {

    _idEquipo = idEquipo;
    _idTipoEquipo = idTipoEquipo;
    _idTipoMarca = idTipoMarca;
    _stock = stock;
    _precioUnitario = precioUnitario;
    _estado = estado;

    strcpy(_descripcion, descripcion);
}

int Equipo::getIdEquipo() {
    return _idEquipo;
}

int Equipo::getIdTipoEquipo() {
    return _idTipoEquipo;
}

int Equipo::getIdTipoMarca() {
    return _idTipoMarca;
}

const char *Equipo::getDescripcion() {
    return _descripcion;
}

int Equipo::getStock() {
    return _stock;
}

float Equipo::getPrecioUnitario() {
    return _precioUnitario;
}

bool Equipo::getEstado() {
    return _estado;
}

void Equipo::setIdEquipo(int idEquipo) {
    _idEquipo = idEquipo;
}

void Equipo::setIdTipoEquipo(int idTipoEquipo) {
    _idTipoEquipo = idTipoEquipo;
}

void Equipo::setIdTipoMarca(int idTipoMarca) {
    _idTipoMarca = idTipoMarca;
}

void Equipo::setDescripcion(const char *descripcion) {
    strcpy(_descripcion, descripcion);
}

void Equipo::setStock(int stock) {
    if (stock >= 0) {
        _stock = stock;
    }
}

void Equipo::setPrecioUnitario(float precioUnitario) {
    if (precioUnitario >= 0) {
        _precioUnitario = precioUnitario;
    }
}

void Equipo::setEstado(bool estado) {
    _estado = estado;
}
