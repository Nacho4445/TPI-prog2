#pragma once

#include "modelos/Menu.h"
#include "negocio/ArchivosManager.h"
#include "utils/Consola.h"

class MenuExports : public Menu {
private:
	ArchivosManager archivosManager;
	Consola consola;

public:
	MenuExports();

	void mostrarOpciones() override;
	void ejecutarOpcion(int opcion) override;
};