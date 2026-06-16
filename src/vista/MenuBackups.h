#pragma once

#include "modelos/Menu.h"
#include "negocio/ArchivosManager.h"

class MenuBackups : public Menu {
private:
	ArchivosManager archivosManager;
	Consola consola;

public:
	MenuBackups();

	void mostrarOpciones() override;
	void ejecutarOpcion(int opcion) override;
};
