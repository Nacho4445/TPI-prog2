#pragma once

#include "Direccion.h"

class Persona {


public:
    Persona() = default;

    Persona(int cuit, const char *nombre, const char *apellido,  const char *telefono, const char *email,
            const Direccion &direccion, bool estado = true);

    int getCuit();
    const char *getNombre();
    const char *getApellido();
    const char *getTelefono();
    const char *getEmail();
    Direccion getDireccion();
    bool getEstado();

    void setCuit(int cuit);
    void setNombre(const char *nombre);
    void setApellido(const char *apellido);
    void setTelefono(const char *telefono);
    void setEmail(const char *email);
    void setDireccion(const Direccion &direccion);
    void setEstado(bool estado);

private:
    int _cuit = 0;
    char _nombre[30] = "";
    char _apellido[30] = "";
    char _telefono[20] = "";
    char _email[50] = "";
    Direccion _direccion;
    bool _estado = false; // true = Activo, false = Inactivo
};
