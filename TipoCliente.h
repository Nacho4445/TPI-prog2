#pragma once

class TipoCliente {

public:
    TipoCliente() = default;

    TipoCliente(int idTipoCliente, const char *descripcion, bool estado = true);

    int getIdTipoCliente();
    const char *getDescripcion();
    bool getEstado();

    void setIdTipoCliente(int idTipoCliente);
    void setDescripcion(const char *descripcion);
    void setEstado(bool estado);

private:
    int _idTipoCliente = 0;
    char _descripcion[30] = "";
    bool _estado = false;
};

