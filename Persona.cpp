#include <cstring>
#include "Persona.h"

using namespace std;

Persona::Persona(int cuit,
                 const char *nombre,
                 const char *apellido,
                 const char *telefono,
                 const char *email,
                 const Direccion &direccion,
                 bool estado) : cuit(cuit), direccion(direccion), estado(estado) {
	strcpy(this->nombre, nombre);
	strcpy(this->apellido, apellido);
	strcpy(this->telefono, telefono);
	strcpy(this->email, email);
}

int Persona::getCuit() {
	return cuit;
}

const char *Persona::getNombre() {
	return nombre;
}

const char *Persona::getApellido() {
	return apellido;
}

const char *Persona::getTelefono() {
	return telefono;
}

const char *Persona::getEmail() {
	return email;
}

Direccion Persona::getDireccion() {
	return direccion;
}

bool Persona::getEstado() {
	return estado;
}

void Persona::setCuit(const int cuit) {
	this->cuit = cuit;
}

void Persona::setNombre(const char *nombre) {
	strcpy(this->nombre, nombre);
}

void Persona::setApellido(const char *apellido) {
	strcpy(this->apellido, apellido);
}

void Persona::setTelefono(const char *telefono) {
	strcpy(this->telefono, telefono);
}

void Persona::setEmail(const char *email) {
	strcpy(this->email, email);
}

void Persona::setDireccion(const Direccion &direccion) {
	this->direccion = direccion;
}

void Persona::setEstado(const bool estado) {
	this->estado = estado;
}
