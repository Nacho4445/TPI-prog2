#pragma once

class TipoEquipo {

public:
    TipoEquipo() = default;

    TipoEquipo(int idTipoEquipo, const char* descripcion, bool estado = true);

    int getIdTipoEquipo();
    const char* getDescripcion();
    bool getEstado();

    void setIdTipoEquipo(int idTipoEquipo);
    void setDescripcion(const char* descripcion);
    void setEstado(bool estado);

private:
    int _idTipoEquipo = 0;
    char _descripcion[30] = {};
    bool _estado = false;

};
