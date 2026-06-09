#include <iostream>
#include <cstring>
#include "../modelos/Cliente.h"
#include "ClienteManager.h"

using namespace std;


ClienteManager::ClienteManager(): _archivoClientes(){}

Cliente ClienteManager::crearCliente(){
    Cliente cliente;
    Direccion direccion;

    int idCliente;
    int tipoCliente;
    long long cuit;

    char nombre[30];
    char apellido[30];
    char telefono[20];
    char email[50];

    idCliente = _archivoClientes.getCantidadRegistros() + 1;

    cout<<"Ingrese los siguientes datos:"<<endl;

    do{
        cout << "CUIT: ";
        cin >> cuit;

        if(_archivoClientes.buscarPorCuit(cuit) != -1){
            cout << "Ya existe un cliente con ese CUIT. Ingrese otro." << endl;
        }

    }while(_archivoClientes.buscarPorCuit(cuit) != -1);

    cin.ignore();

    cout << "Nombre: ";
    cin.getline(nombre, 30);

    cout << "Apellido: ";
    cin.getline(apellido, 30);

    cout << "Telefono: ";
    cin.getline(telefono, 20);

    cout << "Email: ";
    cin.getline(email, 50);

    cout << "Tipo Cliente (1-Particular / 2-Empresa): ";
    cin >> tipoCliente;


    cliente.setIdCliente(idCliente);
    cliente.setTipoCliente(tipoCliente);
    cliente.setCuit(cuit);
    cliente.setNombre(nombre);
    cliente.setApellido(apellido);
    cliente.setTelefono(telefono);
    cliente.setEmail(email);
    cliente.setEstado(true);

    return cliente;
}

void ClienteManager::guardarCliente(){

    Cliente cliente = crearCliente();

    if(_archivoClientes.guardar(cliente)){
        cout << "Cliente guardado correctamente." << endl;
    }
    else{
        cout << "Error al guardar el cliente." << endl;
    }

}

void ClienteManager::listarClientes(){
    int cantidad = _archivoClientes.getCantidadRegistros();

    if (cantidad == 0){
        cout << "No hay clientes cargados." << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++){
        Cliente cliente = _archivoClientes.leerPorPosicion(i);

        if (cliente.getEstado()){
            mostrarCliente(cliente);
        }
    }
}


void ClienteManager::mostrarCliente(Cliente &reg){
    Direccion direccion = reg.getDireccion();

    cout << "=================================="<< endl;
    cout << "ID Cliente: " << reg.getIdCliente() << endl;
    cout << "CUIT: " << reg.getCuit() << endl;
    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "Apellido: " << reg.getApellido() << endl;
    cout << "Telefono: " << reg.getTelefono() << endl;
    cout << "Email: " << reg.getEmail() << endl;
    cout << "Tipo Cliente: " << reg.getTipoCliente();
    cout << "==================================" << endl;

    if (reg.getTipoCliente() == 1){
        cout << " - Particular" << endl;
    }
    else if (reg.getTipoCliente() == 2){
        cout << " - Empresa" << endl;
    }
    else{
        cout << endl;
    }

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
    cout << "------------------------" << endl;
}

void ClienteManager::modificarCliente(){
    int idCliente;

    cout << "Ingrese el ID del cliente a modificar: ";
    cin >> idCliente;

    int pos = _archivoClientes.buscar(idCliente);

    if (pos == -1){
        cout << "No existe un cliente activo con ese ID." << endl;
        return;
    }

    Cliente clienteActual = _archivoClientes.leer(idCliente);

    cout << "Cliente actual:" << endl;
    mostrarCliente(clienteActual);

    cout << "Ingrese los nuevos datos del cliente." << endl;
    Cliente clienteModificado = crearCliente();
    clienteModificado.setIdCliente(idCliente);

    if (_archivoClientes.borrarRegistro(idCliente) && _archivoClientes.guardar(clienteModificado)){
        cout << "Cliente modificado correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar el cliente." << endl;
    }
}

void ClienteManager::ordenarClientes(Cliente *vClientes, int cantidad){
    for (int i = 0; i < cantidad - 1; i++){
        for (int j = 0; j < cantidad - i - 1; j++){
            if (strcmp(vClientes[j].getApellido(), vClientes[j + 1].getApellido()) > 0){
                Cliente aux = vClientes[j];
                vClientes[j] = vClientes[j + 1];
                vClientes[j + 1] = aux;
            }
        }
    }
}

void ClienteManager::mostrarClientesOrdenados(){
    int cantidadRegistros = _archivoClientes.getCantidadRegistros();

    if (cantidadRegistros == 0){
        cout << "No hay clientes cargados." << endl;
        return;
    }

    Cliente *vClientes = new Cliente[cantidadRegistros];

    if (vClientes == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadActivos = 0;

    for (int i = 0; i < cantidadRegistros; i++){
        Cliente cliente = _archivoClientes.leerPorPosicion(i);

        if (cliente.getEstado()){
            vClientes[cantidadActivos] = cliente;
            cantidadActivos++;
        }
    }

    ordenarClientes(vClientes, cantidadActivos);

    for (int i = 0; i < cantidadActivos; i++){
        mostrarCliente(vClientes[i]);
    }

    delete [] vClientes;
}
