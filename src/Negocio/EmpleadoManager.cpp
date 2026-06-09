#include <iostream>
#include <cstring>
#include "../Modelos/Empleado.h"
#include "EmpleadoManager.h"
using namespace std;

EmpleadoManager::EmpleadoManager()
   : _archivoEmpleados(){
}

Empleado EmpleadoManager::crearEmpleado(){

    Empleado empleado;

    int idEmpleado;
    long long cuit;
    int posicion;

    char nombre[30];
    char apellido[30];
    char telefono[20];
    char email[50];

    idEmpleado = _archivoEmpleados.getCantidadRegistros() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    do{
        cout << "CUIT: ";
        cin >> cuit;

        posicion = _archivoEmpleados.buscarPorCuit(cuit);

        if(posicion != -1){
            cout << "Ya existe un empleado con ese CUIT." << endl;
        }

    }while(posicion != -1);

    cin.ignore();

    cout << "Nombre: ";
    cin.getline(nombre, 30);

    cout << "Apellido: ";
    cin.getline(apellido, 30);

    cout << "Telefono: ";
    cin.getline(telefono, 20);

    cout << "Email: ";
    cin.getline(email, 50);

    empleado.setIdEmpleado(idEmpleado);

    empleado.setCuit(cuit);
    empleado.setNombre(nombre);
    empleado.setApellido(apellido);
    empleado.setTelefono(telefono);
    empleado.setEmail(email);

    empleado.setEstado(true);

    return empleado;
}

void EmpleadoManager::guardarEmpleado(){

    Empleado empleado = crearEmpleado();

    if(_archivoEmpleados.guardar(empleado)){
        cout << "Empleado guardado correctamente." << endl;
    }
    else{
        cout << "Error al guardar el empleado." << endl;
    }
}

void EmpleadoManager::listarEmpleados(){

    int cantidadRegistros = _archivoEmpleados.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay empleados cargados." << endl;
        return;
    }

    for(int i = 1; i <= cantidadRegistros; i++){

        Empleado empleado = _archivoEmpleados.leer(i);

        if(empleado.getEstado()){
            mostrarEmpleado(empleado);
            cout << endl;
        }
    }
}

void EmpleadoManager::mostrarEmpleado(Empleado &reg){

    cout << "==================================" << endl;
    cout << "ID Empleado: " << reg.getIdEmpleado() << endl;
    cout << "CUIT: " << reg.getCuit() << endl;
    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "Apellido: " << reg.getApellido() << endl;
    cout << "Telefono: " << reg.getTelefono() << endl;
    cout << "Email: " << reg.getEmail() << endl;
    cout << "==================================" << endl;
}

void EmpleadoManager::modificarEmpleado(){

    int idEmpleado;

    cout << "Ingrese el ID del empleado a modificar: ";
    cin >> idEmpleado;

    int pos = _archivoEmpleados.buscar(idEmpleado);

    if(pos == -1){
        cout << "No existe un empleado activo con ese ID." << endl;
        return;
    }

    Empleado empleadoActual = _archivoEmpleados.leer(idEmpleado);

    cout << "Empleado actual:" << endl;
    mostrarEmpleado(empleadoActual);

    cout << "Ingrese los nuevos datos del empleado." << endl;

    Empleado empleadoModificado = crearEmpleado();
    empleadoModificado.setIdEmpleado(idEmpleado);

    if(_archivoEmpleados.borrarRegistro(idEmpleado) && _archivoEmpleados.guardar(empleadoModificado)){
        cout << "Empleado modificado correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar el empleado." << endl;
    }
}

#include <cstring>

void EmpleadoManager::ordenarEmpleados(Empleado vEmpleados[], int cantidad){

    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            if(strcmp(vEmpleados[j].getApellido(),
                      vEmpleados[j + 1].getApellido()) > 0){

                Empleado aux = vEmpleados[j];
                vEmpleados[j] = vEmpleados[j + 1];
                vEmpleados[j + 1] = aux;
            }
        }
    }
}

void EmpleadoManager::mostrarEmpleadosOrdenados(){

    int cantidadRegistros = _archivoEmpleados.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay empleados cargados." << endl;
        return;
    }

    Empleado *empleados = new Empleado[cantidadRegistros];

    if(empleados == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadActivos = 0;

    for(int i = 1; i <= cantidadRegistros; i++){

        Empleado empleado = _archivoEmpleados.leer(i);

        if(empleado.getEstado()){
            empleados[cantidadActivos] = empleado;
            cantidadActivos++;
        }
    }

    ordenarEmpleados(empleados, cantidadActivos);

    for(int i = 0; i < cantidadActivos; i++){
        mostrarEmpleado(empleados[i]);
        cout << endl;
    }

    delete[] empleados;
}
