#pragma once

#include "modelos/Menu.h"
#include "negocio/ArchivosManager.h"

class MenuRestaurar : public Menu {
private:
	ArchivosManager archivosManager;
	Consola consola;

public:
	MenuRestaurar();

	void mostrarOpciones() override;
	void ejecutarOpcion(int opcion) override;
};
