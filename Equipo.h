#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

class Equipo {
private:
	int idEquipo = 0;
	// Objeto tipoEquipo?
	// Objeto tipoMarca?
	char descripcion[30] = "";
	int stock = 0;
	float precioUnitario = 0.0;
	bool estado = false;

public:
	Equipo() = default;

	Equipo(int idEmpleado, const char *descripcion, int stock, float precioUnitario, bool estado = true);

	int getIdEquipo();

	const char *getDescripcion();

	int getStock();

	float getPrecioUnitario();

	bool getEstado();

	void setIdEquipo(int idEquipo);

	void setDescripcion(char *descripcion);

	void setStock(int stock);

	void setPrecioUnitario(float precioUnitario);

	void setEstado(bool estado);
};

#endif // EQUIPOS_H_INCLUDED
