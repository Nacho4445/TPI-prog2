#pragma once

class TipoMarca {

public:
    TipoMarca() = default;

    TipoMarca(int idTipoMarca, const char descripcion[], bool estado = true);

    int getIdTipoMarca();
    const char* getDescripcion();
    bool getEstado();

    void setIdTipoMarca(int idTipoMarca);
    void setDescripcion(const char descripcion[]);
    void setEstado(bool estado);

private:
    int _idTipoMarca = 0;
    char _descripcion[30] = "";
    bool _estado = false;
};
