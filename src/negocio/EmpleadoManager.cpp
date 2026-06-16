#include <iostream>
#include <cstring>
#include "../modelos/Empleado.h"
#include "EmpleadoManager.h"
using namespace std;

EmpleadoManager::EmpleadoManager()
   : _archivoEmpleados(){
}

Empleado EmpleadoManager::crearEmpleado(){

    Empleado empleado;
    Direccion direccion;

    int idEmpleado;
    long long cuit;
    int posicion;

    char nombre[30];
    char apellido[30];
    char telefono[20];
    char email[50];
    char calle[50];
    int altura;
    char piso[10];
    char departamento[10];
    char localidad[50];
    char codigoPostal[20];
    char provincia[50];

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

    cout << "Calle: ";
    cin.getline(calle, 50);

    cout << "Altura: ";
    cin >> altura;
    cin.ignore();

    cout << "Piso: ";
    cin.getline(piso, 10);

    cout << "Departamento: ";
    cin.getline(departamento, 10);

    cout << "Localidad: ";
    cin.getline(localidad, 50);

    cout << "Codigo Postal: ";
    cin.getline(codigoPostal, 20);

    cout << "Provincia: ";
    cin.getline(provincia, 50);

    empleado.setIdEmpleado(idEmpleado);

    empleado.setCuit(cuit);
    empleado.setNombre(nombre);
    empleado.setApellido(apellido);
    empleado.setTelefono(telefono);
    empleado.setEmail(email);
    empleado.setEstado(true);

    direccion.setCalle(calle);
    direccion.setAltura(altura);
    direccion.setPiso(piso);
    direccion.setDepartamento(departamento);
    direccion.setLocalidad(localidad);
    direccion.setCodigoPostal(codigoPostal);
    direccion.setProvincia(provincia);
    direccion.setEstado(true);

    empleado.setDireccion(direccion);

    //system("pause");
    consola.pausar();

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
    //system("pause");
    consola.pausar();
}

void EmpleadoManager::consultarPorId(){

    int idEmpleado;
    Empleado empleado;

    while(true){

        cout << "Ingrese el ID del empleado: ";
        cin >> idEmpleado;

        if(idEmpleado == 0){
            return;
        }

        empleado = _archivoEmpleados.leer(idEmpleado);

        if(empleado.getEstado()){
            mostrarEmpleado(empleado);
            return;
        }

        cout << "Empleado no encontrado. Intente nuevamente." << endl;
    }
    //system("pause");
    consola.pausar();
}

void EmpleadoManager::consultarPorCuit(){

    long long cuit;
    int pos;
    Empleado empleado;

    while(true){

        cout << "Ingrese el CUIT del empleado: ";
        cin >> cuit;

        if(cuit == 0){
            return;
        }

        pos = _archivoEmpleados.buscarPorCuit(cuit);

        if(pos != -1){
            empleado = _archivoEmpleados.leerPorPosicion(pos);
            mostrarEmpleado(empleado);
            return;
        }

        cout << "Empleado no encontrado. Intente nuevamente." << endl;
    }
    //system("pause");
    consola.pausar();
}

void EmpleadoManager::consultarPorApellido(){

    char apellido[30];
    Empleado empleado;
    bool encontro = false;
    int cantidad = _archivoEmpleados.getCantidadRegistros();

    cin.ignore();

    cout << "Ingrese el apellido a buscar: ";
    cin.getline(apellido, 30);

    for(int i = 0; i < cantidad; i++){

        empleado = _archivoEmpleados.leerPorPosicion(i);

        if(empleado.getEstado() && strcmp(empleado.getApellido(), apellido) == 0){
            mostrarEmpleado(empleado);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron empleados con ese apellido." << endl;
    }
    //system("pause");
    consola.pausar();
}

void EmpleadoManager::listarEmpleados(){

    int cantidadRegistros = _archivoEmpleados.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay empleados cargados." << endl;
        consola.pausar();
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++){

        Empleado empleado = _archivoEmpleados.leer(i);

        if(empleado.getEstado()){
            mostrarEmpleado(empleado);
            cout << endl;
        }
    }
    consola.pausar();
}

void EmpleadoManager::mostrarEmpleado(Empleado &reg){
    Direccion direccion = reg.getDireccion();

    cout << "==================================" << endl;
    cout << "ID Empleado: " << reg.getIdEmpleado() << endl;
    cout << "CUIT: " << reg.getCuit() << endl;
    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "Apellido: " << reg.getApellido() << endl;
    cout << "Telefono: " << reg.getTelefono() << endl;
    cout << "Email: " << reg.getEmail() << endl;
    cout << "Direccion: " << direccion.getCalle() << " " << direccion.getAltura();

    if (direccion.getPiso()[0] != '\0'){
        cout << ", Piso " << direccion.getPiso();
    }

    if (direccion.getDepartamento()[0] != '\0'){
        cout << ", Depto " << direccion.getDepartamento();
    }

    cout << endl;
    cout << "Localidad: " << direccion.getLocalidad() << endl;
    cout << "Codigo Postal: " << direccion.getCodigoPostal() << endl;
    cout << "Provincia: " << direccion.getProvincia() << endl;
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

    int opcion;

    cout << endl;
    cout << "Que dato desea modificar?" << endl;
    cout << "1. CUIT" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Apellido" << endl;
    cout << "4. Telefono" << endl;
    cout << "5. Email" << endl;
    cout << "6. Direccion" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch(opcion){

    case 1:{
        long long cuit;
        int posEncontrada;

        do{
           cout << "Ingrese nuevo CUIT: ";
           cin >> cuit;

           posEncontrada = _archivoEmpleados.buscarPorCuit(cuit);

           if(posEncontrada != -1 && posEncontrada != pos){
           cout << "Ya existe un empleado con ese CUIT. Ingrese otro." << endl;
           }

        }while(posEncontrada != -1 && posEncontrada != pos);

        empleadoActual.setCuit(cuit);
    }

    case 2:{
        char nombre[30];
        cout << "Ingrese nuevo nombre: ";
        cin.ignore();
        cin.getline(nombre, 30);
        empleadoActual.setNombre(nombre);
        break;
    }

    case 3:{
        char apellido[30];
        cout << "Ingrese nuevo apellido: ";
        cin.ignore();
        cin.getline(apellido, 30);
        empleadoActual.setApellido(apellido);
        break;
    }

    case 4:{
        char telefono[20];
        cout << "Ingrese nuevo telefono: ";
        cin.ignore();
        cin.getline(telefono, 20);
        empleadoActual.setTelefono(telefono);
        break;
    }

    case 5:{
        char email[50];
        cout << "Ingrese nuevo email: ";
        cin.ignore();
        cin.getline(email, 50);
        empleadoActual.setEmail(email);
        break;
    }

    case 6:{
        char calle[50], piso[10], departamento[10], localidad[50], codigoPostal[20], provincia[50];
        int altura;

        cout << "Ingrese nueva direccion: ";
        cin.ignore();

        cout << "Calle: ";
        cin.getline(calle, 50);

        cout << "Altura: ";
        cin >> altura;
        cin.ignore();

        cout << "Piso: ";
        cin.getline(piso, 10);

        cout << "Departamento: ";
        cin.getline(departamento, 10);

        cout << "Localidad: ";
        cin.getline(localidad, 50);

        cout << "Codigo postal: ";
        cin.getline(codigoPostal, 20);

        cout << "Provincia: ";
        cin.getline(provincia, 50);

        Direccion direccionNueva(calle, altura, piso, departamento, localidad, codigoPostal, provincia, true);
        empleadoActual.setDireccion(direccionNueva);
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
      cout << "Modificacion cancelada." << endl;
      //system("pause");
      consola.pausar();
      return;
     }

     if(_archivoEmpleados.modificar(empleadoActual)){
      cout << "Empleado modificado correctamente." << endl;
      }
     else{
      cout << "No se pudo modificar el empleado." << endl;
      }

    //system("pause");
    consola.pausar();

}

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

    for(int i = 0; i <= cantidadRegistros; i++){

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
    //system("pause");
    consola.pausar();
}

void EmpleadoManager::eliminarEmpleado(){
    int idEliminado;
    char confirmar;

    cout << "Ingrese el ID del empleado a eliminar: ";
    cin >> idEliminado;

    Empleado empleado = _archivoEmpleados.leer(idEliminado);

    if(empleado.getEstado() == false){
        cout << "Empleado no encontrado." << endl;
        return;
    }

    mostrarEmpleado(empleado);

    cout << "Eliminar? (s/n): ";
    cin >> confirmar;

    if(confirmar == 's' || confirmar == 'S'){
        if(_archivoEmpleados.borrarRegistro(idEliminado)){
            cout << "Empleado eliminado con exito." << endl;
        }
        else{
            cout << "No se pudo eliminar el empleado." << endl;
        }
    }
    //system("pause");
    consola.pausar();
}
