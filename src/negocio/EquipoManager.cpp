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
        consola.pausar();
    }
    else{
        cout << "Error al guardar el equipo." << endl;
        consola.pausar();
    }
}

void EquipoManager::consultarPorId(){

    int idEquipo;
    Equipo equipo;

    while(true){
        cout << "Ingrese el ID del equipo: ";
        cin >> idEquipo;
        }

        equipo = _archivoEquipos.leer(idEquipo);

        if(equipo.getEstado()){
            mostrarEquipo(equipo);
            return;
        }

        cout << "Equipo no encontrado. Intente nuevamente." << endl;
        consola.pausar();
    }
}

void EquipoManager::consultarPorTipo(){

    int idTipoEquipo;
    Equipo equipo;
    bool encontro = false;
    int cantidad = _archivoEquipos.getCantidadEquipos();

    cout << "Ingrese ID tipo de equipo: ";
    cin >> idTipoEquipo;

    for(int i = 0; i < cantidad; i++){
        equipo = _archivoEquipos.leerPorPosicion(i);

        if(equipo.getEstado() && equipo.getIdTipoEquipo() == idTipoEquipo){
            mostrarEquipo(equipo);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron equipos de ese tipo." << endl;
        consola.pausar();
    }
}

void EquipoManager::consultarPorMarca(){

    int idTipoMarca;
    Equipo equipo;
    bool encontro = false;
    int cantidad = _archivoEquipos.getCantidadEquipos();

    cout << "Ingrese ID marca: ";
    cin >> idTipoMarca;

    for(int i = 0; i < cantidad; i++){
        equipo = _archivoEquipos.leerPorPosicion(i);

        if(equipo.getEstado() && equipo.getIdTipoMarca() == idTipoMarca){
            mostrarEquipo(equipo);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron equipos de esa marca." << endl;
        consola.pausar();
    }
}

void EquipoManager::consultarPorPrecio(){

    float precioMin, precioMax;
    Equipo equipo;
    bool encontro = false;
    int cantidad = _archivoEquipos.getCantidadEquipos();

    cout << "Ingrese precio minimo: ";
    cin >> precioMin;

    cout << "Ingrese precio maximo: ";
    cin >> precioMax;

    for(int i = 0; i < cantidad; i++){
        equipo = _archivoEquipos.leerPorPosicion(i);

        if(equipo.getEstado() &&
           equipo.getPrecioUnitario() >= precioMin &&
           equipo.getPrecioUnitario() <= precioMax){

            mostrarEquipo(equipo);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron equipos en ese rango de precio." << endl;
        consola.pausar();
    }
}

void EquipoManager::consultarPorStock(){

    Equipo equipo;
    bool encontro = false;
    int cantidad = _archivoEquipos.getCantidadEquipos();

    for(int i = 0; i < cantidad; i++){
        equipo = _archivoEquipos.leerPorPosicion(i);

        if(equipo.getEstado() && equipo.getStock() > 0){
            mostrarEquipo(equipo);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No hay equipos con stock disponible." << endl;
        consola.pausar();
    }
}

void EquipoManager::listarEquipos(){

    int cantidadEquipos = _archivoEquipos.getCantidadEquipos();

    if(cantidadEquipos == 0){
        cout << "No hay equipos cargados." << endl;
        consola.pausar();
        return;
    }

    for(int i = 1; i < cantidadEquipos; i++){

        Equipo equipo = _archivoEquipos.leer(i);

        if(equipo.getEstado()){
            mostrarEquipo(equipo);
            cout << endl;
        }
    }
    consola.pausar();
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
        consola.pausar();
        return;
    }

    Equipo equipoActual = _archivoEquipos.leer(idEquipo);

    cout << "Equipo actual:" << endl;
    mostrarEquipo(equipoActual);

    int opcion;

    cout << endl;
    cout << "Que dato desea modificar?" << endl;
    cout << "1. Tipo de equipo" << endl;
    cout << "2. Marca" << endl;
    cout << "3. Descripcion" << endl;
    cout << "4. Stock" << endl;
    cout << "5. Precio unitario" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch(opcion){

    case 1:{
        int idTipoEquipo;
        cout << "Ingrese nuevo tipo de equipo: ";
        cin >> idTipoEquipo;
        equipoActual.setIdTipoEquipo(idTipoEquipo);
        break;
    }

    case 2:{
        int idTipoMarca;
        cout << "Ingrese nueva marca: ";
        cin >> idTipoMarca;
        equipoActual.setIdTipoMarca(idTipoMarca);
        break;
    }

    case 3:{
        char descripcion[30];
        cout << "Ingrese nueva descripcion: ";
        cin.ignore();
        cin.getline(descripcion, 30);
        equipoActual.setDescripcion(descripcion);
        break;
    }

    case 4:{
        int stock;
        cout << "Ingrese nuevo stock: ";
        cin >> stock;
        equipoActual.setStock(stock);
        break;
    }

    case 5:{
        float precioUnitario;
        cout << "Ingrese nuevo precio unitario: ";
        cin >> precioUnitario;
        equipoActual.setPrecioUnitario(precioUnitario);
        break;
    }

    case 0:
        cout << "Modificacion cancelada." << endl;
        //system("pause");
        consola.pausar();
        return;

    default:
        cout << "Opcion invalida." << endl;
        //system("pause");
        consola.pausar();
        return;
    }

    char confirmar;

    cout << endl;
    cout << "Desea confirmar los cambios? (S/N): ";
    cin >> confirmar;

    if(confirmar != 'S' && confirmar != 's'){
       cout << "Modificacion cancelada por el usuario." << endl;
       //system("pause");
       consola.pausar();
       return;
       }

    if(_archivoEquipos.modificar(equipoActual)){
        cout << "Equipo modificado correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar el equipo." << endl;
    }

    //system("pause");
    consola.pausar();
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
        consola.pausar();
        return;
    }

    Equipo *equipos = new Equipo[cantidadEquipos];

    if(equipos == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
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
        consola.pausar();
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
    consola.pausar();
}
