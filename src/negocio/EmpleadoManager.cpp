#include <iostream>
#include <cstring>
#include "../modelos/Empleado.h"
#include "EmpleadoManager.h"
using namespace std;

EmpleadoManager::EmpleadoManager()
   : _archivoEmpleados(){
}

// Crea un nuevo empleado solicitando todos sus datos por teclado.
// Realiza las validaciones necesarias antes de construir el objeto Empleado.
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

    // Genera automáticamente el ID del nuevo empleado.
    idEmpleado = _archivoEmpleados.getCantidadRegistros() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    // VALIDACIÓN:
    // Solicita el CUIT hasta que sea válido y no exista otro empleado con el mismo.
    do{
        validador.leerCuit(cuit);

        posicion = _archivoEmpleados.buscarPorCuit(cuit);

        if(posicion != -1){
            cout << "Ya existe un empleado con ese CUIT." << endl;
        }

    }while(posicion != -1);

    cin.ignore(1000, '\n');

    // VALIDACIÓN:
    // Se validan los datos personales del empleado.
    validador.leerTexto(nombre, 30, "Nombre: ");
    validador.leerTexto(apellido, 30, "Apellido: ");
    validador.leerTelefono(telefono);
    validador.leerEmail(email);

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

    // Se cargan los datos del empleado.
    empleado.setIdEmpleado(idEmpleado);
    empleado.setCuit(cuit);
    empleado.setNombre(nombre);
    empleado.setApellido(apellido);
    empleado.setTelefono(telefono);
    empleado.setEmail(email);
    empleado.setEstado(true);

    // Se cargan los datos de la dirección.
    direccion.setCalle(calle);
    direccion.setAltura(altura);
    direccion.setPiso(piso);
    direccion.setDepartamento(departamento);
    direccion.setLocalidad(localidad);
    direccion.setCodigoPostal(codigoPostal);
    direccion.setProvincia(provincia);
    direccion.setEstado(true);

    // Se asigna la dirección al empleado.
    empleado.setDireccion(direccion);

    return empleado;
}

// Guarda un nuevo empleado en el archivo.
void EmpleadoManager::guardarEmpleado(){

    Empleado empleado = crearEmpleado();

    if(_archivoEmpleados.guardar(empleado)){
        cout << "Empleado guardado correctamente." << endl;
    }
    else{
        cout << "Error al guardar el empleado." << endl;
    }

    consola.pausar();
}

// Busca y muestra un empleado a partir de su ID.
//
// VALIDACIÓN:
// - Solo permite ingresar números.
// - Permite ingresar 0 para cancelar la búsqueda.
// - Verifica que el empleado exista y esté activo.
void EmpleadoManager::consultarPorId(){

    int idEmpleado;

    while(true){

        // Solicita un ID válido o permite cancelar la operación.
        validador.leerEnteroConCero(idEmpleado,
                                    "Ingrese el ID del empleado (0 para volver): ");

        if(idEmpleado == 0){
            return;
        }

        Empleado empleado = _archivoEmpleados.leer(idEmpleado);

        if(empleado.getEstado()){
            mostrarEmpleado(empleado);
            return;
        }

        cout << "Empleado no encontrado. Intente nuevamente." << endl;
    }
}

// Busca y muestra un empleado a partir de su CUIT.
//
// VALIDACIÓN:
// - Verifica que el CUIT tenga un formato válido.
// - Comprueba que el empleado exista en el sistema.
void EmpleadoManager::consultarPorCuit(){

    long long cuit;
    int pos;
    Empleado empleado;

    while(true){

        // Solicita un CUIT válido.
        validador.leerCuit(cuit);

        pos = _archivoEmpleados.buscarPorCuit(cuit);

        // Si el empleado existe, se muestran sus datos.
        if(pos != -1){
            empleado = _archivoEmpleados.leerPorPosicion(pos);
            mostrarEmpleado(empleado);
            return;
        }

        cout << "Empleado no encontrado. Intente nuevamente." << endl;
    }
}

// Busca y muestra todos los empleados que coincidan con el apellido ingresado.
//
// VALIDACIÓN:
// - Verifica que el apellido ingresado no esté vacío.
void EmpleadoManager::consultarPorApellido(){

    char apellido[30];
    Empleado empleado;
    bool encontro = false;
    int cantidad = _archivoEmpleados.getCantidadRegistros();

    cin.ignore(1000, '\n');

    // Solicita un apellido válido.
    validador.leerTexto(apellido, 30, "Ingrese el apellido a buscar: ");

    // Recorre todos los empleados buscando coincidencias.
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
}

// Muestra por pantalla toda la información correspondiente a un empleado,
// incluyendo sus datos personales y su dirección.
void EmpleadoManager::mostrarEmpleado(Empleado &reg){

    Direccion direccion = reg.getDireccion();

    // Muestra los datos personales del empleado.
    cout << "==================================" << endl;
    cout << "ID Empleado: " << reg.getIdEmpleado() << endl;
    cout << "CUIT: " << reg.getCuit() << endl;
    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "Apellido: " << reg.getApellido() << endl;
    cout << "Telefono: " << reg.getTelefono() << endl;
    cout << "Email: " << reg.getEmail() << endl;

    // Muestra la dirección completa del empleado.
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

// Permite modificar los datos de un empleado existente.
//
// VALIDACIONES:
// - Verifica que el ID ingresado sea válido.
// - Comprueba que el empleado exista.
// - Valida el nuevo dato ingresado según la opción elegida.
// - Evita CUIT duplicados.
// - Solicita confirmación antes de guardar los cambios.
void EmpleadoManager::modificarEmpleado(){

    int idEmpleado;

    // VALIDACIÓN:
    // Solicita un ID válido o permite cancelar la operación.
    validador.leerEnteroConCero(idEmpleado,
        "Ingrese el ID del empleado a modificar (0 para cancelar): ");

    if(idEmpleado == 0){
        cout << "Modificacion cancelada." << endl;
        return;
    }

    // Verifica que exista un empleado activo con ese ID.
    int pos = _archivoEmpleados.buscar(idEmpleado);

    if(pos == -1){
        cout << "No existe un empleado activo con ese ID." << endl;
        return;
    }

    // Obtiene el empleado para realizar las modificaciones.
    Empleado empleadoActual = _archivoEmpleados.leer(idEmpleado);

    cout << "Empleado actual:" << endl;
    mostrarEmpleado(empleadoActual);

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
    cout << "0. Cancelar" << endl;

    // VALIDACIÓN:
    // Solicita una opción válida del menú.
    validador.leerEnteroConCero(opcion, "Opcion: ");

    if(opcion == 0){
        cout << "Modificacion cancelada." << endl;
        return;
    }

    if(opcion < 1 || opcion > 6){
        cout << "Opcion invalida." << endl;
        return;
    }

    // Según la opción elegida, modifica únicamente ese dato.
    switch(opcion){

    case 1:{
        long long cuit;
        int posEncontrada;

        // VALIDACIÓN:
        // Verifica que el nuevo CUIT sea válido y no pertenezca a otro empleado.
        do{

            validador.leerCuit(cuit);

            posEncontrada = _archivoEmpleados.buscarPorCuit(cuit);

            if(posEncontrada != -1 && posEncontrada != pos){
                cout << "Ya existe un empleado con ese CUIT. Ingrese otro." << endl;
            }

        }while(posEncontrada != -1 && posEncontrada != pos);

        empleadoActual.setCuit(cuit);
        break;
    }

    case 2:{
        char nombre[30];

        cin.ignore(1000, '\n');

        // VALIDACIÓN:
        // Verifica que el nombre no esté vacío.
        validador.leerTexto(nombre, 30, "Ingrese nuevo nombre: ");

        empleadoActual.setNombre(nombre);
        break;
    }

    case 3:{
        char apellido[30];

        cin.ignore(1000, '\n');

        // VALIDACIÓN:
        // Verifica que el apellido no esté vacío.
        validador.leerTexto(apellido, 30, "Ingrese nuevo apellido: ");

        empleadoActual.setApellido(apellido);
        break;
    }

    case 4:{
        char telefono[20];

        // VALIDACIÓN:
        // Verifica que el teléfono tenga un formato válido.
        validador.leerTelefono(telefono);

        empleadoActual.setTelefono(telefono);
        break;
    }

    case 5:{
        char email[50];

        // VALIDACIÓN:
        // Verifica que el email tenga un formato válido.
        validador.leerEmail(email);

        empleadoActual.setEmail(email);
        break;
    }

    case 6:{
        char calle[50], piso[10], departamento[10];
        char localidad[50], codigoPostal[20], provincia[50];
        int altura;

        cout << "Ingrese nueva direccion:" << endl;

        cin.ignore(1000, '\n');

        // VALIDACIÓN:
        // Verifica los datos obligatorios de la nueva dirección.
        validador.leerTexto(calle, 50, "Calle: ");
        validador.leerEnteroPositivo(altura, "Altura: ");

        cout << "Piso: ";
        cin.getline(piso, 10);

        cout << "Departamento: ";
        cin.getline(departamento, 10);

        validador.leerTexto(localidad, 50, "Localidad: ");
        validador.leerTexto(codigoPostal, 20, "Codigo Postal: ");
        validador.leerTexto(provincia, 50, "Provincia: ");

        Direccion direccionNueva(calle, altura, piso, departamento,
                                 localidad, codigoPostal, provincia, true);

        empleadoActual.setDireccion(direccionNueva);
        break;
    }

    default:
        cout << "Opcion invalida." << endl;
        return;
    }

    char confirmar;

    cout << endl;

    // VALIDACIÓN:
    // Solicita confirmación antes de guardar los cambios.
    validador.leerConfirmacion(confirmar);

    if(confirmar == 'N' || confirmar == 'n'){
        cout << "Modificacion cancelada." << endl;
        return;
    }


    if(_archivoEmpleados.modificar(empleadoActual)){
        cout << "Empleado modificado correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar el empleado." << endl;
    }

    consola.pausar();
}

// Ordena un vector de empleados alfabéticamente por apellido
void EmpleadoManager::ordenarEmpleados(Empleado vEmpleados[], int cantidad){

    // Recorre el vector realizando comparaciones e intercambios.
    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            // Compara los apellidos de dos empleados consecutivos.
            if(strcmp(vEmpleados[j].getApellido(),
                      vEmpleados[j + 1].getApellido()) > 0){

                // Intercambia ambos registros.
                Empleado aux = vEmpleados[j];
                vEmpleados[j] = vEmpleados[j + 1];
                vEmpleados[j + 1] = aux;
            }
        }
    }
}

// Muestra todos los empleados activos ordenados alfabéticamente por apellido.
void EmpleadoManager::mostrarEmpleadosOrdenados(){

    int cantidadRegistros = _archivoEmpleados.getCantidadRegistros();

    // Verifica que existan empleados cargados.
    if(cantidadRegistros == 0){
        cout << "No hay empleados cargados." << endl;
        return;
    }

    // Reserva memoria para almacenar los empleados activos.
    Empleado *empleados = new Empleado[cantidadRegistros];

    if(empleados == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadActivos = 0;

    // Copia únicamente los empleados activos al vector.
    for(int i = 0; i < cantidadRegistros; i++){

        Empleado empleado = _archivoEmpleados.leerPorPosicion(i);

        if(empleado.getEstado()){
            empleados[cantidadActivos] = empleado;
            cantidadActivos++;
        }
    }

    // Ordena los empleados por apellido.
    ordenarEmpleados(empleados, cantidadActivos);


    for(int i = 0; i < cantidadActivos; i++){
        mostrarEmpleado(empleados[i]);
        cout << endl;
    }

    delete[] empleados;

    consola.pausar();
}

// Da de baja lógica a un empleado existente.
// No elimina el registro del archivo, solamente cambia su estado a inactivo.
//
// VALIDACIONES:
// - Verifica que el ID ingresado sea válido.
// - Permite ingresar 0 para cancelar.
// - Comprueba que el empleado exista y esté activo.
// - Solicita confirmación antes de realizar la baja.
void EmpleadoManager::darDeBajaEmpleado(){

    int idEmpleado;
    char confirmar;

    // VALIDACIÓN:
    // Solicita un ID válido o permite cancelar la operación.
    validador.leerEnteroConCero(idEmpleado,
                                "Ingrese el ID del empleado a dar de baja (0 para cancelar): ");

    if(idEmpleado == 0){
        cout << "Operacion cancelada." << endl;
        return;
    }

    Empleado empleado = _archivoEmpleados.leer(idEmpleado);

    if(!empleado.getEstado()){
        cout << "Empleado no encontrado." << endl;
        return;
    }

    cout << "Empleado seleccionado:" << endl;
    mostrarEmpleado(empleado);

    cout << endl;

    // VALIDACIÓN:
    // Solicita confirmación antes de dar de baja.
    validador.leerConfirmacion(confirmar);

    if(confirmar == 'N' || confirmar == 'n'){
        cout << "Operacion cancelada." << endl;
        return;
    }

    if(_archivoEmpleados.borrarRegistro(idEmpleado)){
        cout << "Empleado dado de baja correctamente." << endl;
    }
    else{
        cout << "No se pudo dar de baja el empleado." << endl;
    }
}
