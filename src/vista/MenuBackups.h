#pragma once

#include "negocio/BackupManager.h"

class MenuBackups {
private:
	BackupManager backupManager;

public:
	void mostrarOpciones();
	void mostrarOpcionesBackups();
	void mostrarOpcionesRestaurar();
};
