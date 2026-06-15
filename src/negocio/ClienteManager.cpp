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
    char calle[50];
    int altura;
    char piso[10];
    char departamento[10];
    char localidad[50];
    char codigoPostal[20];
    char provincia[50];

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

    cout << "Codigo Postal: ";
    cin.getline(codigoPostal, 20);

    cout << "Provincia: ";
    cin.getline(provincia, 50);

    cliente.setIdCliente(idCliente);
    cliente.setTipoCliente(tipoCliente);
    cliente.setCuit(cuit);
    cliente.setNombre(nombre);
    cliente.setApellido(apellido);
    cliente.setTelefono(telefono);
    cliente.setEmail(email);
    cliente.setEstado(true);

    direccion.setCalle(calle);
    direccion.setAltura(altura);
    direccion.setPiso(piso);
    direccion.setDepartamento(departamento);
    direccion.setLocalidad(localidad);
    direccion.setCodigoPostal(codigoPostal);
    direccion.setProvincia(provincia);
    direccion.setEstado(true);

    cliente.setDireccion(direccion);

    system("pause");
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
    system("pause");
}
void ClienteManager::consultarPorId(){

    int idCliente;
    Cliente cliente;

    while(true){

        cout << "Ingrese el ID del cliente: ";
        cin >> idCliente;

        if(idCliente == 0){
            return;
        }

        cliente = _archivoClientes.leer(idCliente);

        if(cliente.getEstado()){
            mostrarCliente(cliente);
            return;
        }

        cout << "Cliente no encontrado. Intente nuevamente." << endl;
    }
    system("pause");
}

void ClienteManager::consultarPorCuit(){

    long long cuit;
    int pos;
    Cliente cliente;

    while(true){

        cout << "Ingrese el CUIT del cliente: ";
        cin >> cuit;

        if(cuit == 0){
            return;
        }

        pos = _archivoClientes.buscarPorCuit(cuit);

        if(pos != -1){
            cliente = _archivoClientes.leerPorPosicion(pos);
            mostrarCliente(cliente);
            return;
        }

        cout << "Cliente no encontrado. Intente nuevamente." << endl;
    }
    system("pause");
}

void ClienteManager::consultarPorApellido(){

    char apellido[30];
    Cliente cliente;
    bool encontro = false;
    int cantidad = _archivoClientes.getCantidadRegistros();

    cin.ignore();

    cout << "Ingrese el apellido a buscar: ";
    cin.getline(apellido, 30);

    for(int i = 0; i < cantidad; i++){

        cliente = _archivoClientes.leerPorPosicion(i);

        if(cliente.getEstado() && strcmp(cliente.getApellido(), apellido) == 0){
            mostrarCliente(cliente);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron clientes con ese apellido." << endl;
    }
    system("pause");
}

void ClienteManager::consultarPorTipo(){

    int tipoCliente;
    Cliente cliente;
    bool encontro = false;
    int cantidad = _archivoClientes.getCantidadRegistros();

    do{
        cout << "Ingrese tipo de cliente (1-Particular / 2-Empresa / 0-Volver): ";
        cin >> tipoCliente;

        if(tipoCliente == 0){
            return;
        }

        if(tipoCliente != 1 && tipoCliente != 2){
            cout << "Tipo invalido." << endl;
        }

    }while(tipoCliente != 1 && tipoCliente != 2);

    for(int i = 0; i < cantidad; i++){

        cliente = _archivoClientes.leerPorPosicion(i);

        if(cliente.getEstado() && cliente.getTipoCliente() == tipoCliente){
            mostrarCliente(cliente);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron clientes de ese tipo." << endl;
    }
    system("pause");
}


void ClienteManager::listarClientes(){
    int cantidad = _archivoClientes.getCantidadRegistros();
    bool hayClientes = false;
    if (cantidad == 0){
        cout << "No hay clientes cargados." << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++){
        Cliente cliente = _archivoClientes.leerPorPosicion(i);

        if (cliente.getEstado()){
            mostrarCliente(cliente);
            hayClientes = true;
        }
    }

    if(!hayClientes && cantidad > 0){
        cout << "No hay clientes activos." << endl;
        }
    system("pause");
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
    cout << "Tipo Cliente: " << reg.getTipoCliente() << endl;

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
    cout << "==================================" << endl;
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

    int opcion;

    cout << endl;
    cout << "Que dato desea modificar?" << endl;
    cout << "1. CUIT" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Apellido" << endl;
    cout << "4. Telefono" << endl;
    cout << "5. Email" << endl;
    cout << "6. Direccion" << endl;
    cout << "7. Tipo de cliente" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch(opcion){

    case 1:{
        long long cuit;
        cout << "Ingrese nuevo CUIT: ";
        cin >> cuit;
        clienteActual.setCuit(cuit);
        break;
    }

    case 2:{
        char nombre[30];
        cout << "Ingrese nuevo nombre: ";
        cin.ignore();
        cin.getline(nombre, 30);
        clienteActual.setNombre(nombre);
        break;
    }

    case 3:{
        char apellido[30];
        cout << "Ingrese nuevo apellido: ";
        cin.ignore();
        cin.getline(apellido, 30);
        clienteActual.setApellido(apellido);
        break;
    }

    case 4:{
        char telefono[20];
        cout << "Ingrese nuevo telefono: ";
        cin.ignore();
        cin.getline(telefono, 20);
        clienteActual.setTelefono(telefono);
        break;
    }

    case 5:{
        char email[50];
        cout << "Ingrese nuevo email: ";
        cin.ignore();
        cin.getline(email, 50);
        clienteActual.setEmail(email);
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
        clienteActual.setDireccion(direccionNueva);
        break;
    }

    case 7:{
        int tipoCliente;
        cout << "Ingrese nuevo tipo de cliente: ";
        cin >> tipoCliente;
        clienteActual.setTipoCliente(tipoCliente);
        break;
    }

    case 0:
        cout << "Modificacion cancelada." << endl;
        system("pause");
        return;

    default:
        cout << "Opcion invalida." << endl;
        system("pause");
        return;
    }

    char confirmar;

    cout << endl;
    cout << "Desea confirmar los cambios? (S/N): ";
    cin >> confirmar;

     if(confirmar != 'S' && confirmar != 's'){
        cout << "Modificacion cancelada." << endl;
        system("pause");
        return;
     }

    if (_archivoClientes.borrarRegistro(idCliente) && _archivoClientes.guardar(clienteActual)){
        cout << "Cliente modificado correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar el cliente." << endl;
    }

    system("pause");
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
    system("pause");
}


void ClienteManager::eliminarCliente(){
    int idEliminado;
    char confirmar;

    cout << "Ingrese el ID del cliente a eliminar: ";
    cin >> idEliminado;

    Cliente cliente = _archivoClientes.leer(idEliminado);

    if(cliente.getEstado() == false){
        cout << "Cliente no encontrado." << endl;
        return;
    }

    mostrarCliente(cliente);

    cout << "Eliminar? (s/n): ";
    cin >> confirmar;

    if(confirmar == 's' || confirmar == 'S'){
        if(_archivoClientes.borrarRegistro(idEliminado)){
            cout << "Cliente eliminado con exito." << endl;
        }
        else{
            cout << "No se pudo eliminar el cliente." << endl;
        }
    }
    system("pause");
}

