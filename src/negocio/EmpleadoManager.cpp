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

    // Genera automaticamente el ID del nuevo empleado.
    idEmpleado = _archivoEmpleados.getCantidadRegistros() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    // VALIDACION:
    // Solicita el CUIT hasta que sea valido y no exista otro empleado con el mismo.
    do{
        validador.leerCuit(cuit);

        posicion = _archivoEmpleados.buscarPorCuit(cuit);

        if(posicion != -1){
            cout << "Ya existe un empleado con ese CUIT." << endl;
        }

    }while(posicion != -1);

    cin.ignore(1000, '\n');

    // VALIDACION:
    // Se validan los datos personales del empleado.
    validador.leerTexto(nombre, 30, "Nombre: ");
    validador.leerTexto(apellido, 30, "Apellido: ");
    validador.leerTelefono(telefono);
    validador.leerEmail(email);

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
    // Se validan los datos obligatorios de la direccion.
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

    // Se cargan los datos de la direccion.
    direccion.setCalle(calle);
    direccion.setAltura(altura);
    direccion.setPiso(piso);
    direccion.setDepartamento(departamento);
    direccion.setLocalidad(localidad);
    direccion.setCodigoPostal(codigoPostal);
    direccion.setProvincia(provincia);
    direccion.setEstado(true);

    // Se asigna la direccion al empleado.
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
}

// Busca y muestra un empleado a partir del ID.
// VALIDACION:
// - Solo permite numeros.
// - Permite 0 para cancelar.
// - Verifica que el empleado exista y este activo.
void EmpleadoManager::consultarPorId(){

    int idEmpleado;

    while(true){

        // Solicita un ID valido o permite cancelar la operacion.
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

// Busca y muestra un empleado a partir del CUIT.
// VALIDACION:
// - Verifica que el CUIT sea valido.
// - Comprueba que el empleado exista.
void EmpleadoManager::consultarPorCuit(){

    long long cuit;
    int pos;
    Empleado empleado;

    while(true){

        // Solicita un CUIT valido.
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
// VALIDACION:
// - Verifica que el apellido ingresado no este vacio.
void EmpleadoManager::consultarPorApellido(){

    char apellido[30];
    Empleado empleado;
    bool encontro = false;
    int cantidad = _archivoEmpleados.getCantidadRegistros();

    // cin.ignore(1000, '\n');

    // Solicita un apellido valido.
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

// Muestra por pantalla toda la informacion de un empleado (datos personales y direccion).
void EmpleadoManager::mostrarEmpleado(Empleado &reg){

    Direccion direccion = reg.getDireccion();

    // Muestra los datos personales del empleado.
    cout << endl;
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
    cout << endl;
    cout << "==================================" << endl;
}

// Permite modificar los datos de un empleado existente.
// VALIDACIONES:
// - Verifica que el ID ingresado sea valido.
// - Comprueba que el empleado exista.
// - Valida el nuevo dato ingresado segun la opcion elegida.
// - Evita CUIT duplicados.
// - Solicita confirmacion antes de guardar los cambios.
void EmpleadoManager::modificarEmpleado(){

    int idEmpleado;

    // VALIDACION:
    // Solicita un ID valido o permite cancelar la operacion.
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

    // Muestra el menu de campos disponibles para modificar.
    cout << endl;
    cout << "Que dato desea modificar?" << endl;
    cout << "1. CUIT" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Apellido" << endl;
    cout << "4. Telefono" << endl;
    cout << "5. Email" << endl;
    cout << "6. Direccion" << endl;
    cout << "0. Cancelar" << endl;

    // Solicita una opcion valida del menu.
    validador.leerEnteroConCero(opcion, "Opcion: ");

    if(opcion == 0){
        cout << "Modificacion cancelada." << endl;
        return;
    }

    if(opcion < 1 || opcion > 6){
        cout << "Opcion invalida." << endl;
        return;
    }

    // Segun la opciun elegida, modifica solo ese dato.
    switch(opcion){

    case 1:{
        long long cuit;
        int posEncontrada;

        // Verifica que el nuevo CUIT sea valido y no pertenezca a otro empleado.
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

        // Verifica que el nombre no este vacío.
        validador.leerTexto(nombre, 30, "Ingrese nuevo nombre: ");

        empleadoActual.setNombre(nombre);
        break;
    }

    case 3:{
        char apellido[30];

        cin.ignore(1000, '\n');

        // Verifica que el apellido no este vacio.
        validador.leerTexto(apellido, 30, "Ingrese nuevo apellido: ");

        empleadoActual.setApellido(apellido);
        break;
    }

    case 4:{
        char telefono[20];

        // Verifica que el telefono tenga un formato valido.
        validador.leerTelefono(telefono);

        empleadoActual.setTelefono(telefono);
        break;
    }

    case 5:{
        char email[50];

        // Verifica que el email tenga un formato valido.
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

        // Verifica los datos obligatorios de la nueva direccion.
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

    // Solicita confirmacion antes de guardar los cambios.
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
}

// Ordena los empleados alfabeticamente por apellido
void EmpleadoManager::ordenarEmpleados(Empleado vEmpleados[], int cantidad){

    // Recorre el vector, compara e intercambia.
    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            // Compara los apellidos de dos empleados consecutivos.
            if(strcmp(vEmpleados[j].getApellido(),
                      vEmpleados[j + 1].getApellido()) > 0){

                // Intercambia registros.
                Empleado aux = vEmpleados[j];
                vEmpleados[j] = vEmpleados[j + 1];
                vEmpleados[j + 1] = aux;
            }
        }
    }
}

// Muestra todos los empleados activos ordenados alfabeticamente por apellido.
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

    // Copia solo los empleados activos al vector.
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

// Baja logica a un empleado existente: No elimina el registro del archivo, solo cambia su estado a false.
// VALIDACIONES:
// - Verifica que el ID ingresado sea valido.
// - Permite ingresar 0 para cancelar.
// - Comprueba que el empleado exista y este activo.
// - Solicita confirmacion antes de realizar la baja.
void EmpleadoManager::darDeBajaEmpleado(){

    int idEmpleado;
    char confirmar;

    // Solicita un ID valido o permite cancelar la operacion.
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

    // Solicita confirmacion antes de dar de baja.
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
