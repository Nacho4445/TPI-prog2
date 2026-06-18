#include <iostream>
#include <cstring>
#include "../modelos/Cliente.h"
#include "ClienteManager.h"

using namespace std;


ClienteManager::ClienteManager(): _archivoClientes(){}

// Crea un nuevo cliente solicitando todos sus datos por teclado.
// Realiza las validaciones necesarias antes de construir el objeto Cliente.
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

    // Genera automaticamente el ID del nuevo cliente.
    idCliente = _archivoClientes.getCantidadRegistros() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    int pos;

    // VALIDACION:
    // Solicita el CUIT hasta que sea valido y no exista otro cliente con el mismo.
    do{

        validador.leerCuit(cuit);

        pos = _archivoClientes.buscarPorCuit(cuit);

        if(pos != -1){
            cout << "Ya existe un cliente con ese CUIT. Ingrese otro." << endl;
        }

    }while(pos != -1);

    cin.ignore(1000, '\n');

    // VALIDACION:
    // Se validan los datos personales del cliente.
    validador.leerTexto(nombre, 30, "Nombre: ");
    validador.leerTexto(apellido, 30, "Apellido: ");
    validador.leerTelefono(telefono);
    validador.leerEmail(email);

    // VALIDACION:
    // Solo permite seleccionar un tipo de cliente valido.
    validador.leerTipoCliente(tipoCliente);

    cin.ignore(1000, '\n');

    // VALIDACION:
    // Se validan los datos obligatorios de la direccion.
    validador.leerTexto(calle, 50, "Calle: ");
    validador.leerEnteroPositivo(altura, "Altura: ");

    cin.ignore(1000, '\n');

    // Piso y departamento son datos opcionales.
    cout << "Piso: ";
    cin.getline(piso, 10);

    cout << "Departamento: ";
    cin.getline(departamento, 10);

    // VALIDACION:
    // Se validan los datos obligatorios de la direccion que faltan.
    validador.leerTexto(localidad, 50, "Localidad: ");
    validador.leerTexto(codigoPostal, 20, "Codigo Postal: ");
    validador.leerTexto(provincia, 50, "Provincia: ");

    // Se cargan los datos del cliente.
    cliente.setIdCliente(idCliente);
    cliente.setTipoCliente(tipoCliente);
    cliente.setCuit(cuit);
    cliente.setNombre(nombre);
    cliente.setApellido(apellido);
    cliente.setTelefono(telefono);
    cliente.setEmail(email);
    cliente.setEstado(true);

    // Se cargan los datos de la direccion.
    direccion.setCalle(calle);
    direccion.setAltura(altura);
    direccion.setPiso(piso);
    direccion.setDepartamento(departamento);
    direccion.setLocalidad(localidad);
    direccion.setCodigoPostal(codigoPostal);
    direccion.setProvincia(provincia);
    direccion.setEstado(true);

    // Se asigna la direccion al cliente.
    cliente.setDireccion(direccion);

    return cliente;
}

// Guarda un nuevo cliente en el archivo.
void ClienteManager::guardarCliente(){

    Cliente cliente = crearCliente();

    if(_archivoClientes.guardar(cliente)){
        cout << "Cliente guardado correctamente." << endl;
    }
    else{
        cout << "Error al guardar el cliente." << endl;
    }
}

// Busca y muestra un cliente a partir de su ID.
// VALIDACION:
// - Solo permite ingresar numeros.
// - Permite ingresar 0 para cancelar la busqueda.
// - Verifica que el cliente exista y este activo.
void ClienteManager::consultarPorId(){

    int idCliente;

    while(true){

        // Solicita un ID valido o permite cancelar la operacion.
        validador.leerEnteroConCero(idCliente, "Ingrese el ID del cliente (0 para volver): ");

        if(idCliente == 0){
            return;
        }

        Cliente cliente = _archivoClientes.leer(idCliente);

        // Si el cliente existe, se muestran sus datos.
        if(cliente.getEstado()){
            mostrarCliente(cliente);
            return;
        }

        cout << "Cliente no encontrado." << endl;
    }
}

// Busca y muestra un cliente a partir de su CUIT.
// VALIDACION:
// - Verifica que el CUIT tenga un formato valido.
// - Comprueba que el cliente exista.
void ClienteManager::consultarPorCuit(){

    long long cuit;
    int pos;
    Cliente cliente;

    while(true){

        // Solicita un CUIT valido.
        validador.leerCuit(cuit);

        pos = _archivoClientes.buscarPorCuit(cuit);

        // Si el cliente existe, se muestran sus datos.
        if(pos != -1){
            cliente = _archivoClientes.leerPorPosicion(pos);
            mostrarCliente(cliente);

            cout << endl;
            cout << "Volviendo al menu clientes..." << endl;
            cout << endl;
            return;
        }

        cout << "Cliente no encontrado. Intente nuevamente." << endl;
    }
}

// Busca y muestra todos los clientes que coincidan con el apellido ingresado.
// VALIDACION:
// - Verifica que el apellido ingresado no este vacío.
void ClienteManager::consultarPorApellido(){

    char apellido[30];
    Cliente cliente;
    bool encontro = false;
    int cantidad = _archivoClientes.getCantidadRegistros();

    cin.ignore(1000, '\n');

    // Solicita un apellido valido.
    validador.leerTexto(apellido, 30, "Ingrese el apellido a buscar: ");

    // Recorre todos los clientes buscando coincidencias.
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
}

// Busca y muestra todos los clientes de un tipo determinado.
// VALIDACION:
// - Solo permite ingresar un tipo de cliente valido (1 = Particular, 2 = Empresa).
void ClienteManager::consultarPorTipo(){

    int tipoCliente;
    Cliente cliente;
    bool encontro = false;
    int cantidad = _archivoClientes.getCantidadRegistros();

    // Solicita un tipo de cliente valido.
    validador.leerTipoCliente(tipoCliente);

    // Recorre todos los clientes buscando coincidencias.
    for(int i = 0; i < cantidad; i++){

        cliente = _archivoClientes.leerPorPosicion(i);

        if(cliente.getEstado() &&
           cliente.getTipoCliente() == tipoCliente){

            mostrarCliente(cliente);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron clientes de ese tipo." << endl;
    }
}

// Muestra por pantalla toda la informacion de un cliente (datos personales y su direccion).
void ClienteManager::mostrarCliente(Cliente &reg){

    Direccion direccion = reg.getDireccion();

    cout << endl;
    cout << "ID Cliente: " << reg.getIdCliente() << endl;
    cout << "CUIT: " << reg.getCuit() << endl;
    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "Apellido: " << reg.getApellido() << endl;
    cout << "Telefono: " << reg.getTelefono() << endl;
    cout << "Email: " << reg.getEmail() << endl;

    // Muestra el tipo de cliente y descripcion.
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

    // Muestra la direccion completa del cliente.
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
    cout << endl;
    cout << "==================================" << endl;
}

// Permite modificar los datos de un cliente existente.
// VALIDACIONES:
// - Verifica que el ID sea valido.
// - Comprueba que el cliente exista.
// - Valida el nuevo dato ingresado segun la opcion elegida.
// - Evita CUIT duplicados.
// - Solicita confirmacion antes de guardar los cambios.
void ClienteManager::modificarCliente(){

    int idCliente;

    // VALIDACION:
    // Solicita un ID valido o permite cancelar la operacion.
    validador.leerEnteroConCero(idCliente, "Ingrese el ID del cliente a modificar (0 para cancelar): ");

    if(idCliente == 0){
        cout << "Modificacion cancelada." << endl;
        return;
    }

    // Verifica que exista un cliente activo con ese ID.
    int pos = _archivoClientes.buscar(idCliente);

    if(pos == -1){
        cout << "No existe un cliente activo con ese ID." << endl;
        return;
    }

    // Obtiene el cliente para realizar las modificaciones.
    Cliente clienteActual = _archivoClientes.leer(idCliente);

    cout << "Cliente actual:" << endl;
    mostrarCliente(clienteActual);

    int opcion;

    // Muestra el menu de campos disponibles para modificar.
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

    // VALIDACION:
    // Solicita una opcion valida del menu.
    validador.leerEnteroConCero(opcion, "Opcion: ");

    if(opcion == 0){
        cout << "Modificacion cancelada." << endl;
        return;
    }

    if(opcion < 1 || opcion > 7){
        cout << "Opcion invalida." << endl;
        return;
    }

    // Segun la opcion elegida, modifica solo ese dato.
    switch(opcion){

        case 1:{
            long long cuit;
            int posEncontrada;

            // Verifica que el nuevo CUIT sea valido y unico.
            do{

                validador.leerCuit(cuit);

                posEncontrada = _archivoClientes.buscarPorCuit(cuit);

                if(posEncontrada != -1 && posEncontrada != pos){
                    cout << "Ya existe un cliente con ese CUIT. Ingrese otro." << endl;
                }

            }while(posEncontrada != -1 && posEncontrada != pos);

            clienteActual.setCuit(cuit);
            break;
        }

        case 2:{
            char nombre[30];

            cin.ignore(1000, '\n');

            // Verifica que el nombre no este vacio.
            validador.leerTexto(nombre, 30, "Ingrese nuevo nombre: ");

            clienteActual.setNombre(nombre);
            break;
        }

        case 3:{
            char apellido[30];

            cin.ignore(1000, '\n');

            // Verifica que el apellido no este vacio.
            validador.leerTexto(apellido, 30, "Ingrese nuevo apellido: ");

            clienteActual.setApellido(apellido);
            break;
        }

        case 4:{
            char telefono[20];

            // Verifica que el telefono tenga un formato valido.
            validador.leerTelefono(telefono);

            clienteActual.setTelefono(telefono);
            break;
        }

        case 5:{
            char email[50];

            // Verifica que el email tenga un formato valido.
            validador.leerEmail(email);

            clienteActual.setEmail(email);
            break;
        }

        case 6:{
            char calle[50], piso[10], departamento[10], localidad[50], codigoPostal[20], provincia[50];
            int altura;

            cout << "Ingrese nueva direccion: " << endl;

            cin.ignore(1000, '\n');

            // Verifica los datos obligatorios de la nueva direccion.
            validador.leerTexto(calle, 50, "Calle: ");
            validador.leerEnteroPositivo(altura, "Altura: ");

            cin.ignore(1000, '\n');

            cout << "Piso: ";
            cin.getline(piso, 10);

            cout << "Departamento: ";
            cin.getline(departamento, 10);

            validador.leerTexto(localidad, 50, "Localidad: ");
            validador.leerTexto(codigoPostal, 20, "Codigo postal: ");
            validador.leerTexto(provincia, 50, "Provincia: ");

            Direccion direccionNueva(calle, altura, piso, departamento, localidad, codigoPostal, provincia, true);

            clienteActual.setDireccion(direccionNueva);
            break;
        }

        case 7:{
            int tipoCliente;

            // Solo permite seleccionar un tipo de cliente valido.
            validador.leerTipoCliente(tipoCliente);

            clienteActual.setTipoCliente(tipoCliente);
            break;
        }

        default:
            cout << "Opcion invalida." << endl;
            return;
    }

    char confirmar;

    cout << endl;

    // Solicita confirmacion antes de guardar los cambios.
    validador.leerConfirmacion(confirmar);

    if(confirmar == 'N' || confirmar == 'n'){
        cout << "Modificacion cancelada." << endl;
        return;
    }


    if(_archivoClientes.modificar(clienteActual)){
        cout << "Cliente modificado correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar el cliente." << endl;
    }
}

// Ordena los clientes alfabeticamente por apellido
void ClienteManager::ordenarClientes(Cliente *vClientes, int cantidad){

    // Recorre el vector, compara e intercambia.
    for (int i = 0; i < cantidad - 1; i++){

        for (int j = 0; j < cantidad - i - 1; j++){

            // Compara los apellidos de dos clientes consecutivos.
            if (strcmp(vClientes[j].getApellido(), vClientes[j + 1].getApellido()) > 0){

                // Intercambia registros.
                Cliente aux = vClientes[j];
                vClientes[j] = vClientes[j + 1];
                vClientes[j + 1] = aux;
            }
        }
    }
}

// Ordena los clientes por tipo de cliente.
// Si dos clientes tienen el mismo tipo, los ordena alfabeticamente por apellido.
void ClienteManager::ordenarClientesPorTipo(Cliente *vClientes, int cantidad){

    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            // Primero compara el tipo de cliente y despues compara el apellido (si son del mismo tipo).
            if(
                vClientes[j].getTipoCliente() > vClientes[j + 1].getTipoCliente()
                ||
                (
                    vClientes[j].getTipoCliente() == vClientes[j + 1].getTipoCliente()
                    &&
                    strcmp(vClientes[j].getApellido(),
                           vClientes[j + 1].getApellido()) > 0
                )
            ){

                // Intercambia registros.
                Cliente aux = vClientes[j];
                vClientes[j] = vClientes[j + 1];
                vClientes[j + 1] = aux;
            }
        }
    }
}
// Muestra todos los clientes activos ordenados alfabeticamente por apellido.
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

    // Copia solo los clientes activos al vector.
    for (int i = 0; i < cantidadRegistros; i++){

        Cliente cliente = _archivoClientes.leerPorPosicion(i);

        if (cliente.getEstado()){
            vClientes[cantidadActivos] = cliente;
            cantidadActivos++;
        }
    }

    // Ordena los clientes por apellido.
    ordenarClientes(vClientes, cantidadActivos);

    // Muestra el listado ordenado.
    for (int i = 0; i < cantidadActivos; i++){
        mostrarCliente(vClientes[i]);
    }

    delete [] vClientes;
}

// Muestra todos los clientes activos ordenados por tipo de cliente y apellido.
void ClienteManager::mostrarClientesOrdenadosPorTipo(){

    int cantidadRegistros = _archivoClientes.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay clientes cargados." << endl;
        return;
    }

    Cliente *vClientes = new Cliente[cantidadRegistros];

    if(vClientes == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadActivos = 0;

    // Copia solo los clientes activos al vector.
    for(int i = 0; i < cantidadRegistros; i++){

        Cliente cliente = _archivoClientes.leerPorPosicion(i);

        if(cliente.getEstado()){
            vClientes[cantidadActivos] = cliente;
            cantidadActivos++;
        }
    }

    // Ordena el vector por tipo de cliente y por apellido si hay empate.
    ordenarClientesPorTipo(vClientes, cantidadActivos);

    // Muestra el listado ordenado.
    for(int i = 0; i < cantidadActivos; i++){
        mostrarCliente(vClientes[i]);
    }

    delete[] vClientes;
}
