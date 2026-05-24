#ifndef TPI_PROG2_PERSONA_H
#define TPI_PROG2_PERSONA_H

#include "Direccion.h"

class Persona {
protected:
	int cuit = 0;
	char nombre[30] = "";
	char apellido[30] = "";
	char telefono[20] = "";
	char email[50] = "";
	Direccion direccion;

public:
	Persona() = default;

	Persona(int cuit,
	        const char *nombre,
	        const char *apellido,
	        const char *telefono,
	        const char *email,
	        const Direccion &direccion);

	int getCuit();

	const char *getNombre();

	const char *getApellido();

	const char *getTelefono();

	const char *getEmail();

	Direccion getDireccion();

	void setCuit(int cuit);

	void setNombre(const char *nombre);

	void setApellido(const char *apellido);

	void setTelefono(const char *telefono);

	void setEmail(const char *email);

	void setDireccion(const Direccion &direccion);
};

#endif //TPI_PROG2_PERSONA_H
