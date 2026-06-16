#pragma once

#include "modelos/Menu.h"
#include "negocio/ArchivosManager.h"

class MenuArchivos : public Menu {
private:
	ArchivosManager archivosManager;
	Consola consola;

public:
	MenuArchivos();

	void mostrarOpciones() override;
	void ejecutarOpcion(int opcion) override;
};
