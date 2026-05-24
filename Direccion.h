#ifndef TPI_PROG2_DIRECCION_H
#define TPI_PROG2_DIRECCION_H

class Direccion {
private:
	int idDireccion = 0;
	char calle[50] = "";
	int altura = 0;
	char piso[10] = "";
	char departamento[10] = "";
	char localidad[50] = "";
	char codigoPostal[10] = "";
	char provincia[50] = "";
	bool estado = false;

public:
	Direccion() = default;

	Direccion(long idDireccion,
	          const char *calle,
	          int altura,
	          const char *piso,
	          const char *departamento,
	          const char *localidad,
	          const char *codigoPostal,
	          const char *provincia,
	          bool estado = true);

	int getIdDireccion();

	const char *getCalle();

	int getAltura();

	const char *getPiso();

	const char *getDepartamento();

	const char *getLocalidad();

	const char *getCodigoPostal();

	const char *getProvincia();

	bool getEstado();

	void setIdDireccion(int idDireccion);

	void setCalle(char *calle);

	void setAltura(int altura);

	void setPiso(char *piso);

	void setDepartamento(char *departamento);

	void setLocalidad(char *localidad);

	void setCodigoPostal(char *codigoPostal);

	void setProvincia(char *provincia);

	void setEstado(bool estado);
};


#endif //TPI_PROG2_DIRECCION_H
