#ifndef TIPOCLIENTE_H_INCLUDED
#define TIPOCLIENTE_H_INCLUDED

class TipoCliente {
private:
    int idTipoCliente = 0;
    char descripcion[30] = "";
    bool estado = false;

public:
    TipoCliente() = default;
    TipoCliente(int idTipoCliente, const char *descripcion, bool estado = true);

    int getIdTipoCliente();
    const char *getDescripcion();
    bool getEstado();

    void setIdTipoCliente(int idTipoCliente);
    void setDescripcion(const char *descripcion);
    void setEstado(bool estado);
};

#endif // TIPOCLIENTE_H_INCLUDED
