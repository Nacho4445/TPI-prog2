#pragma once

class Direccion {

public:
	Direccion() = default;

	Direccion(const char *calle, int altura,const char *piso,const char *departamento, const char *localidad,
              const char *codigoPostal, const char *provincia, bool estado = true);

	int getIdDireccion();
    const char* getCalle();
    int getAltura();
    const char* getPiso();
    const char* getDepartamento();
    const char* getLocalidad();
    const char* getCodigoPostal();
    const char* getProvincia();
    bool getEstado();

	void setIdDireccion(int idDireccion);
    void setCalle(const char* calle);
    void setAltura(int altura);
    void setPiso(const char* piso);
    void setDepartamento(const char* departamento);
    void setLocalidad(const char* localidad);
    void setCodigoPostal(const char* codigoPostal);
    void setProvincia(const char* provincia);
    void setEstado(bool estado);


private:
	long _idDireccion = 0;
    char _calle[50] = "";
    int _altura = 0;
    char _piso[10] = "";
    char _departamento[10] = "";
    char _localidad[50] = "";
    char _codigoPostal[20] = "";
    char _provincia[50] = "";
    bool _estado = false;
};


