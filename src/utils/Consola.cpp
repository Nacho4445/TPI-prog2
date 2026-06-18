#include "Consola.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void Consola::limpiar() {
#ifdef _WIN32
	system("cls"); // Limpia la consola para Windows
#else
	system("clear"); // Limpia la consola para Linux
#endif
}

void Consola::pausar() {
#ifdef _WIN32
	system("pause");
#else
	cout << "\nPresione Enter para continuar...";
	cin.ignore(); // limpia caracteres en el buffer
	cin.get(); // espera que se presione una tecla
#endif
}

