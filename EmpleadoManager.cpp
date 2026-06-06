#include <iostream>
#include "Empleado.h"
#include "EmpleadoManager.h"
using namespace std;

EmpleadoManager::EmpleadoManager()
   : _repoEmpleados(){
}

Empleado EmpleadoManager::crearEmpleado(){}

void EmpleadoManager::guardarEmpleado(){}

void EmpleadoManager::listarEmpleados(){}

void EmpleadoManager::mostrarEmpleado(const Empleado &reg){}

void EmpleadoManager::modificarEmpleado(){}

void EmpleadoManager::ordenarEmpleados(Empleado vEmpleados[], int cantidad){}

void EmpleadoManager::mostrarEmpleadosOrdenados(){}
