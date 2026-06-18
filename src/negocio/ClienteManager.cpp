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

    // Genera automáticamente el ID del nuevo cliente.
    idCliente = _archivoClientes.getCantidadRegistros() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    int pos;

    // VALIDACIÓN:
    // Solicita el CUIT hasta que sea válido y no exista otro cliente con el mismo.
    do{

        validador.leerCuit(cuit);

        pos = _archivoClientes.buscarPorCuit(cuit);

        if(pos != -1){
            cout << "Ya existe un cliente con ese CUIT. Ingrese otro." << endl;
        }

    }while(pos != -1);

    cin.ignore(1000, '\n');

    // VALIDACIÓN:
    // Se validan los datos personales del cliente.
    validador.leerTexto(nombre, 30, "Nombre: ");
    validador.leerTexto(apellido, 30, "Apellido: ");
    validador.leerTelefono(telefono);
    validador.leerEmail(email);

    // VALIDACIÓN:
    // Solo permite seleccionar un tipo de cliente válido.
    validador.leerTipoCliente(tipoCliente);

    cin.ignore(1000, '\n');

    // VALIDACIÓN:
    // Se validan los datos obligatorios de la dirección.
    validador.leerTexto(calle, 50, "Calle: ");
    validador.leerEnteroPositivo(altura, "Altura: ");

    cin.ignore(1000, '\n');

    // Piso y departamento son datos opcionales.
    cout << "Piso: ";
    cin.getline(piso, 10);

    cout << "Departamento: ";
    cin.getline(departamento, 10);

    // VALIDACIÓN:
    // Se validan los restantes datos obligatorios de la dirección.
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

    // Se cargan los datos de la dirección.
    direccion.setCalle(calle);
    direccion.setAltura(altura);
    direccion.setPiso(piso);
    direccion.setDepartamento(departamento);
    direccion.setLocalidad(localidad);
    direccion.setCodigoPostal(codigoPostal);
    direccion.setProvincia(provincia);
    direccion.setEstado(true);

    // Se asigna la dirección al cliente.
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
//
// VALIDACIÓN:
// - Solo permite ingresar números.
// - Permite ingresar 0 para cancelar la búsqueda.
// - Verifica que el cliente exista y esté activo.
void ClienteManager::consultarPorId(){

    int idCliente;

    while(true){

        // Solicita un ID válido o permite cancelar la operación.
        validador.leerEnteroConCero(idCliente,
                                    "Ingrese el ID del cliente (0 para volver): ");

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
//
// VALIDACIÓN:
// - Verifica que el CUIT tenga un formato válido.
// - Comprueba que el cliente exista en el sistema.
void ClienteManager::consultarPorCuit(){

    long long cuit;
    int pos;
    Cliente cliente;

    while(true){

        // Solicita un CUIT válido.
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
//
// VALIDACIÓN:
// - Verifica que el apellido ingresado no esté vacío.
void ClienteManager::consultarPorApellido(){

    char apellido[30];
    Cliente cliente;
    bool encontro = false;
    int cantidad = _archivoClientes.getCantidadRegistros();

    cin.ignore(1000, '\n');

    // Solicita un apellido válido.
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
//
// VALIDACIÓN:
// - Solo permite ingresar un tipo de cliente válido
//   (1 = Particular, 2 = Empresa).
void ClienteManager::consultarPorTipo(){

    int tipoCliente;
    Cliente cliente;
    bool encontro = false;
    int cantidad = _archivoClientes.getCantidadRegistros();

    // Solicita un tipo de cliente válido.
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

// Muestra por pantalla toda la información correspondiente a un cliente,
// incluyendo sus datos personales y su dirección.
void ClienteManager::mostrarCliente(Cliente &reg){

    Direccion direccion = reg.getDireccion();

    cout << "=================================="<< endl;
    cout << "ID Cliente: " << reg.getIdCliente() << endl;
    cout << "CUIT: " << reg.getCuit() << endl;
    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "Apellido: " << reg.getApellido() << endl;
    cout << "Telefono: " << reg.getTelefono() << endl;
    cout << "Email: " << reg.getEmail() << endl;

    // Muestra el tipo de cliente almacenado y su descripción.
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

    // Muestra la dirección completa del cliente.
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

// Permite modificar los datos de un cliente existente.
//
// VALIDACIONES:
// - Verifica que el ID ingresado sea válido.
// - Comprueba que el cliente exista.
// - Valida el nuevo dato ingresado según la opción elegida.
// - Evita CUIT duplicados.
// - Solicita confirmación antes de guardar los cambios.
void ClienteManager::modificarCliente(){

    int idCliente;

    // VALIDACIÓN:
    // Solicita un ID válido o permite cancelar la operación.
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

    // Muestra el menú de campos disponibles para modificar.
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

    // VALIDACIÓN:
    // Solicita una opción válida del menú.
    validador.leerEnteroConCero(opcion, "Opcion: ");

    if(opcion == 0){
        cout << "Modificacion cancelada." << endl;
        return;
    }

    if(opcion < 1 || opcion > 7){
        cout << "Opcion invalida." << endl;
        return;
    }

    // Según la opción elegida, modifica únicamente ese dato.
    switch(opcion){

        case 1:{
            long long cuit;
            int posEncontrada;

            // VALIDACIÓN:
            // Verifica que el nuevo CUIT sea válido y no pertenezca a otro cliente.
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

            // VALIDACIÓN:
            // Verifica que el nombre no esté vacío.
            validador.leerTexto(nombre, 30, "Ingrese nuevo nombre: ");

            clienteActual.setNombre(nombre);
            break;
        }

        case 3:{
            char apellido[30];

            cin.ignore(1000, '\n');

            // VALIDACIÓN:
            // Verifica que el apellido no esté vacío.
            validador.leerTexto(apellido, 30, "Ingrese nuevo apellido: ");

            clienteActual.setApellido(apellido);
            break;
        }

        case 4:{
            char telefono[20];

            // VALIDACIÓN:
            // Verifica que el teléfono tenga un formato válido.
            validador.leerTelefono(telefono);

            clienteActual.setTelefono(telefono);
            break;
        }

        case 5:{
            char email[50];

            // VALIDACIÓN:
            // Verifica que el email tenga un formato válido.
            validador.leerEmail(email);

            clienteActual.setEmail(email);
            break;
        }

        case 6:{
            char calle[50], piso[10], departamento[10], localidad[50], codigoPostal[20], provincia[50];
            int altura;

            cout << "Ingrese nueva direccion: " << endl;

            cin.ignore(1000, '\n');

            // VALIDACIÓN:
            // Verifica los datos obligatorios de la nueva dirección.
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

            // VALIDACIÓN:
            // Solo permite seleccionar un tipo de cliente válido.
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

    // VALIDACIÓN:
    // Solicita confirmación antes de guardar los cambios realizados.
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

// Ordena un vector de clientes alfabéticamente por apellido

void ClienteManager::ordenarClientes(Cliente *vClientes, int cantidad){

    // Recorre el vector realizando comparaciones e intercambios.
    for (int i = 0; i < cantidad - 1; i++){

        for (int j = 0; j < cantidad - i - 1; j++){

            // Compara los apellidos de dos clientes consecutivos.
            if (strcmp(vClientes[j].getApellido(), vClientes[j + 1].getApellido()) > 0){

                // Intercambia ambos registros.
                Cliente aux = vClientes[j];
                vClientes[j] = vClientes[j + 1];
                vClientes[j + 1] = aux;
            }
        }
    }
}
// Ordena un vector de clientes por tipo de cliente.
// Si dos clientes pertenecen al mismo tipo,
// los ordena alfabéticamente por apellido.
void ClienteManager::ordenarClientesPorTipo(Cliente *vClientes, int cantidad){

    // Recorre el vector realizando comparaciones e intercambios.
    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            // Primero compara el tipo de cliente.
            // Si ambos son del mismo tipo, compara el apellido.
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

                // Intercambia ambos registros.
                Cliente aux = vClientes[j];
                vClientes[j] = vClientes[j + 1];
                vClientes[j + 1] = aux;
            }
        }
    }
}
// Muestra todos los clientes activos ordenados alfabéticamente por apellido.
void ClienteManager::mostrarClientesOrdenados(){

    int cantidadRegistros = _archivoClientes.getCantidadRegistros();

    // Verifica que existan clientes cargados.
    if (cantidadRegistros == 0){
        cout << "No hay clientes cargados." << endl;
        return;
    }

    // Reserva memoria para almacenar los clientes activos.
    Cliente *vClientes = new Cliente[cantidadRegistros];

    if (vClientes == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadActivos = 0;

    // Copia únicamente los clientes activos al vector.
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

    // Libera la memoria reservada dinámicamente.
    delete [] vClientes;
}

// Muestra todos los clientes activos ordenados por tipo de cliente.
// Dentro de cada tipo, los clientes se ordenan alfabéticamente por apellido.
void ClienteManager::mostrarClientesOrdenadosPorTipo(){

    int cantidadRegistros = _archivoClientes.getCantidadRegistros();

    // Verifica que existan clientes cargados.
    if(cantidadRegistros == 0){
        cout << "No hay clientes cargados." << endl;
        return;
    }

    // Reserva memoria para almacenar los clientes activos.
    Cliente *vClientes = new Cliente[cantidadRegistros];

    if(vClientes == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadActivos = 0;

    // Copia únicamente los clientes activos al vector.
    for(int i = 0; i < cantidadRegistros; i++){

        Cliente cliente = _archivoClientes.leerPorPosicion(i);

        if(cliente.getEstado()){
            vClientes[cantidadActivos] = cliente;
            cantidadActivos++;
        }
    }

    // Ordena el vector por tipo de cliente y, en caso de empate,
    // por apellido.
    ordenarClientesPorTipo(vClientes, cantidadActivos);

    // Muestra el listado ordenado.
    for(int i = 0; i < cantidadActivos; i++){
        mostrarCliente(vClientes[i]);
    }

    // Libera la memoria reservada dinámicamente.
    delete[] vClientes;
}
