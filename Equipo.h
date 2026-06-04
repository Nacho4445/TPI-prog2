#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

class Equipo {

public:
    Equipo() = default;

    Equipo(int idEquipo, int idTipoEquipo, int idTipoMarca, const char *descripcion, int stock, float precioUnitario,bool estado = true);

    int getIdEquipo();
    int getIdTipoEquipo();
    int getIdTipoMarca();
    const char *getDescripcion();
    int getStock();
    float getPrecioUnitario();
    bool getEstado();

    void setIdEquipo(int idEquipo);
    void setIdTipoEquipo(int idTipoEquipo);
    void setIdTipoMarca(int idTipoMarca);
    void setDescripcion(const char *descripcion);
    void setStock(int stock);
    void setPrecioUnitario(float precioUnitario);
    void setEstado(bool estado);

private:
    int _idEquipo = 0;
    int _idTipoEquipo = 0;
    int _idTipoMarca = 0;
    char _descripcion[30] = "";
    int _stock = 0;
    float _precioUnitario = 0.0f;
    bool _estado = false;
};

#endif // EQUIPOS_H_INCLUDED
