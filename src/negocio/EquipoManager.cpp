#include <iostream>
#include <cstring>
#include "../modelos/Equipo.h"
#include "EquipoManager.h"
using namespace std;

EquipoManager::EquipoManager()
   : _archivoEquipos(){
}

Equipo EquipoManager::crearEquipo(){

    Equipo equipo;

    int idEquipo;
    int idTipoEquipo;
    int idTipoMarca;
    int stock;
    float precioUnitario;
    char descripcion[30];

   idEquipo = _archivoEquipos.getCantidadEquipos() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    cout << "ID Tipo Equipo: ";
    cin >> idTipoEquipo;

    cout << "ID Tipo Marca: ";
    cin >> idTipoMarca;

    cin.ignore();

    cout << "Descripcion: ";
    cin.getline(descripcion, 30);

    cout << "Stock: ";
    cin >> stock;

    cout << "Precio Unitario: ";
    cin >> precioUnitario;

    equipo.setIdEquipo(idEquipo);
    equipo.setIdTipoEquipo(idTipoEquipo);
    equipo.setIdTipoMarca(idTipoMarca);
    equipo.setDescripcion(descripcion);
    equipo.setStock(stock);
    equipo.setPrecioUnitario(precioUnitario);
    equipo.setEstado(true);

    return equipo;
}

void EquipoManager::guardarEquipo(){

    Equipo equipo = crearEquipo();

    if(_archivoEquipos.guardar(equipo)){
        cout << "Equipo guardado correctamente." << endl;
    }
    else{
        cout << "Error al guardar el equipo." << endl;
    }
}

void EquipoManager::listarEquipos(){

    int cantidadEquipos = _archivoEquipos.getCantidadEquipos();

    if(cantidadEquipos == 0){
        cout << "No hay equipos cargados." << endl;
        return;
    }

    for(int i = 1; i <= cantidadEquipos; i++){

        Equipo equipo = _archivoEquipos.leer(i);

        if(equipo.getEstado()){
            mostrarEquipo(equipo);
            cout << endl;
        }
    }
}

void EquipoManager::mostrarEquipo(Equipo &reg){

    cout << "==================================" << endl;
    cout << "ID Equipo: " << reg.getIdEquipo() << endl;
    cout << "ID Tipo Equipo: " << reg.getIdTipoEquipo() << endl;
    cout << "ID Tipo Marca: " << reg.getIdTipoMarca() << endl;
    cout << "Descripcion: " << reg.getDescripcion() << endl;
    cout << "Stock: " << reg.getStock() << endl;
    cout << "Precio Unitario: $" << reg.getPrecioUnitario() << endl;
    cout << "==================================" << endl;
}
void EquipoManager::modificarEquipo(){

    int idEquipo;

    cout << "Ingrese el ID del equipo a modificar: ";
    cin >> idEquipo;

    int pos = _archivoEquipos.getPosicion(idEquipo);

    if(pos == -1){
        cout << "No existe un equipo activo con ese ID." << endl;
        return;
    }

    Equipo equipoActual = _archivoEquipos.leer(idEquipo);

    cout << "Equipo actual:" << endl;
    mostrarEquipo(equipoActual);

    cout << "Ingrese los nuevos datos del equipo." << endl;

    Equipo equipoModificado = crearEquipo();
    equipoModificado.setIdEquipo(idEquipo);

    if(_archivoEquipos.borrarRegistro(idEquipo) &&
       _archivoEquipos.guardar(equipoModificado)){

        cout << "Equipo modificado correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar el equipo." << endl;
    }
}

void EquipoManager::ordenarEquipos(Equipo vEquipos[], int cantidad){

    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            if(strcmp(vEquipos[j].getDescripcion(),
                      vEquipos[j + 1].getDescripcion()) > 0){

                Equipo aux = vEquipos[j];
                vEquipos[j] = vEquipos[j + 1];
                vEquipos[j + 1] = aux;
            }
        }
    }
}

void EquipoManager::mostrarEquiposOrdenados(){

    int cantidadEquipos = _archivoEquipos.getCantidadEquipos();

    if(cantidadEquipos == 0){
        cout << "No hay equipos cargados." << endl;
        return;
    }

    Equipo *equipos = new Equipo[cantidadEquipos];

    if(equipos == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadActivos = 0;

    for(int i = 1; i <= cantidadEquipos; i++){

        Equipo equipo = _archivoEquipos.leer(i);

        if(equipo.getEstado()){
            equipos[cantidadActivos] = equipo;
            cantidadActivos++;
        }
    }

    ordenarEquipos(equipos, cantidadActivos);

    for(int i = 0; i < cantidadActivos; i++){
        mostrarEquipo(equipos[i]);
        cout << endl;
    }

    delete[] equipos;
}
void EquipoManager::eliminarEquipo(){
    int idEliminado;
    char confirmar;

    cout << "Ingrese el ID del equipo a eliminar: ";
    cin >> idEliminado;

    Equipo equipo = _archivoEquipos.leer(idEliminado);

    if(equipo.getEstado() == false){
        cout << "Equipo no encontrado." << endl;
        return;
    }

    mostrarEquipo(equipo);

    cout << "Eliminar? (s/n): ";
    cin >> confirmar;

    if(confirmar == 's' || confirmar == 'S'){
        if(_archivoEquipos.borrarRegistro(idEliminado)){
            cout << "Equipo eliminado con exito." << endl;
        }
        else{
            cout << "No se pudo eliminar el equipo." << endl;
        }
    }
}
