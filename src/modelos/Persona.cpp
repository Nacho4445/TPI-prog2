#include <cstring>
#include "modelos/Persona.h"

Persona::Persona(long long cuit, const char *nombre, const char *apellido, const char *telefono,const char *email,
                 const Direccion &direccion, bool estado)

{

    _cuit = cuit;
    _direccion = direccion;
    _estado = estado;

    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_telefono, telefono);
    strcpy(_email, email);
}

long long Persona::getCuit(){
    return _cuit;
}

const char *Persona::getNombre() {
    return _nombre;
}

const char *Persona::getApellido() {
    return _apellido;
}

const char *Persona::getTelefono() {
    return _telefono;
}

const char *Persona::getEmail() {
    return _email;
}

Direccion Persona::getDireccion() {
    return _direccion;
}

bool Persona::getEstado() {
    return _estado;
}

void Persona::setCuit(long long cuit) {
    _cuit = cuit;
}

void Persona::setNombre(const char *nombre) {
    strcpy(_nombre, nombre);
}

void Persona::setApellido(const char *apellido) {
    strcpy(_apellido, apellido);
}

void Persona::setTelefono(const char *telefono) {
    strcpy(_telefono, telefono);
}

void Persona::setEmail(const char *email) {
    strcpy(_email, email);
}

void Persona::setDireccion(const Direccion &direccion) {
    _direccion = direccion;
}

void Persona::setEstado(bool estado) {
    _estado = estado;
}
