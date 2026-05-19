#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

#include <string>

class Equipo {
private:
	int id_equipo;
	std::string descripcion;
	std::string marca;
	std::string tipoEquipo;
	int stock;
	float precio_unitario;
	bool estado;
};

#endif // EQUIPOS_H_INCLUDED
