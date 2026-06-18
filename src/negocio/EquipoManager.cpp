#include <iostream>
#include <cstring>
#include "../modelos/Equipo.h"
#include "EquipoManager.h"
using namespace std;

EquipoManager::EquipoManager()
   : _archivoEquipos(){
}

// Crea un nuevo equipo solicitando sus datos por teclado.
// Realiza las validaciones necesarias antes de construir el objeto Equipo.
Equipo EquipoManager::crearEquipo(){

    Equipo equipo;

    int idEquipo;
    int idTipoEquipo;
    int idTipoMarca;
    int stock;
    float precioUnitario;
    char descripcion[30];

    // Genera automáticamente el ID del nuevo equipo.
    idEquipo = _archivoEquipos.getCantidadEquipos() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    // VALIDACIÓN:
    // Permite ingresar el tipo de equipo por nombre.
    // Si no existe, lo crea automáticamente.
    idTipoEquipo = seleccionarTipoEquipo();

    // VALIDACIÓN:
    // Permite ingresar la marca por nombre.
    // Si no existe, la crea automáticamente.
    idTipoMarca = seleccionarMarca();

    // VALIDACIÓN:
    // Verifica que la descripción no esté vacía.
    validador.leerTexto(descripcion, 30, "Descripcion: ");

    // VALIDACIÓN:
    // Verifica que el stock sea un número entero positivo.
    validador.leerEnteroPositivo(stock, "Stock: ");

    // VALIDACIÓN:
    // Verifica que el precio sea un número positivo.
    validador.leerDecimalPositivo(precioUnitario, "Precio Unitario: ");

    // Se cargan los datos validados al objeto Equipo.
    equipo.setIdEquipo(idEquipo);
    equipo.setIdTipoEquipo(idTipoEquipo);
    equipo.setIdTipoMarca(idTipoMarca);
    equipo.setDescripcion(descripcion);
    equipo.setStock(stock);
    equipo.setPrecioUnitario(precioUnitario);
    equipo.setEstado(true);

    return equipo;
}

// Guarda un nuevo equipo en el archivo.

void EquipoManager::guardarEquipo(){

    Equipo equipo = crearEquipo();

    if(_archivoEquipos.guardar(equipo)){
        cout << "Equipo guardado correctamente." << endl;
    }
    else{
        cout << "Error al guardar el equipo." << endl;
    }

    consola.pausar();
}

// Busca y muestra un equipo a partir de su ID.
//
// VALIDACIONES:
// - Solo permite ingresar números.
// - Permite ingresar 0 para cancelar la búsqueda.
// - Verifica que el equipo exista y esté activo.
void EquipoManager::consultarPorId(){

    int idEquipo;

    while(true){

        // Solicita un ID válido o permite cancelar la operación.
        validador.leerEnteroConCero(idEquipo,
                                    "Ingrese el ID del equipo (0 para volver): ");

        if(idEquipo == 0){
            return;
        }

        Equipo equipo = _archivoEquipos.leer(idEquipo);

        // Si el equipo existe, se muestran sus datos.
        if(equipo.getEstado()){
            mostrarEquipo(equipo);
            return;
        }

        cout << "Equipo no encontrado. Intente nuevamente." << endl;
    }
}

// Busca y muestra todos los equipos pertenecientes a un tipo determinado.
//
// VALIDACIONES:
// - Verifica que el tipo de equipo exista antes de realizar la búsqueda.
void EquipoManager::consultarPorTipo(){

    // Obtiene el ID correspondiente al tipo de equipo ingresado.
    int idTipoEquipo = buscarTipoEquipo();

    if(idTipoEquipo == 0){
        cout << "No existe ese tipo de equipo." << endl;
        return;
    }

    Equipo equipo;
    bool encontro = false;
    int cantidad = _archivoEquipos.getCantidadEquipos();

    // Recorre todos los equipos buscando coincidencias.
    for(int i = 0; i < cantidad; i++){

        equipo = _archivoEquipos.leerPorPosicion(i);

        if(equipo.getEstado() &&
           equipo.getIdTipoEquipo() == idTipoEquipo){

            mostrarEquipo(equipo);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron equipos de ese tipo." << endl;
    }
}

// Busca y muestra todos los equipos pertenecientes a una marca determinada.
//
// VALIDACIONES:
// - Verifica que la marca exista antes de realizar la búsqueda.
void EquipoManager::consultarPorMarca(){

    // Obtiene el ID correspondiente a la marca ingresada.
    int idTipoMarca = buscarMarca();

    if(idTipoMarca == 0){
        cout << "No existe esa marca." << endl;
        return;
    }

    Equipo equipo;
    bool encontro = false;
    int cantidad = _archivoEquipos.getCantidadEquipos();

    // Recorre todos los equipos buscando coincidencias.
    for(int i = 0; i < cantidad; i++){

        equipo = _archivoEquipos.leerPorPosicion(i);

        if(equipo.getEstado() &&
           equipo.getIdTipoMarca() == idTipoMarca){

            mostrarEquipo(equipo);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron equipos de esa marca." << endl;
    }
}

// Busca y muestra todos los equipos cuyo precio se encuentre
// dentro del rango ingresado por el usuario.
//
// VALIDACIONES:
// - Verifica que ambos precios sean valores positivos.
// - Comprueba que el precio mínimo no sea mayor que el máximo.
void EquipoManager::consultarPorPrecio(){

    float precioMin;
    float precioMax;

    Equipo equipo;
    bool encontro = false;
    int cantidad = _archivoEquipos.getCantidadEquipos();

    // VALIDACIÓN:
    // Solicita un precio mínimo válido.
    validador.leerDecimalPositivo(precioMin, "Ingrese precio minimo: ");

    // VALIDACIÓN:
    // Solicita un precio máximo válido.
    validador.leerDecimalPositivo(precioMax, "Ingrese precio maximo: ");

    // Verifica que el rango ingresado sea correcto.
    while(precioMin > precioMax){

        cout << "El precio minimo no puede ser mayor que el precio maximo." << endl;

        validador.leerDecimalPositivo(precioMin, "Ingrese precio minimo: ");
        validador.leerDecimalPositivo(precioMax, "Ingrese precio maximo: ");
    }

    // Recorre todos los equipos buscando coincidencias.
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
    }
}

// Muestra todos los equipos activos que tienen stock disponible.
//
// VALIDACIÓN:
// - No requiere ingreso de datos.
// - Solo muestra equipos activos con stock mayor a cero.
void EquipoManager::consultarPorStock(){

    Equipo equipo;
    bool encontro = false;
    int cantidad = _archivoEquipos.getCantidadEquipos();

    // Recorre todos los equipos buscando los que tengan stock disponible.
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
// Permite modificar los datos de un equipo existente.
//
// VALIDACIONES:
// - Verifica que el ID ingresado sea válido.
// - Comprueba que el equipo exista.
// - Valida el nuevo dato ingresado según la opción elegida.
// - Permite ingresar tipo y marca por nombre.
// - Solicita confirmación antes de guardar los cambios.
void EquipoManager::modificarEquipo(){

    int idEquipo;

    // VALIDACIÓN:
    // Solicita un ID válido o permite cancelar la operación.
    validador.leerEnteroConCero(idEquipo,
        "Ingrese el ID del equipo a modificar (0 para cancelar): ");

    if(idEquipo == 0){
        cout << "Modificacion cancelada." << endl;
        return;
    }

    int pos = _archivoEquipos.getPosicion(idEquipo);

    if(pos == -1){
        cout << "No existe un equipo activo con ese ID." << endl;
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

    // VALIDACIÓN:
    // Solicita una opción numérica del menú.
    validador.leerEnteroConCero(opcion, "Opcion: ");

    if(opcion == 0){
        cout << "Modificacion cancelada." << endl;
        return;
    }

    if(opcion < 1 || opcion > 5){
        cout << "Opcion invalida." << endl;
        return;
    }

    switch(opcion){

    case 1:{
        // VALIDACIÓN:
        // Permite ingresar el tipo de equipo por nombre.
        // Si no existe, lo crea automáticamente.
        int idTipoEquipo = seleccionarTipoEquipo();

        equipoActual.setIdTipoEquipo(idTipoEquipo);
        break;
    }

    case 2:{
        // VALIDACIÓN:
        // Permite ingresar la marca por nombre.
        // Si no existe, la crea automáticamente.
        int idTipoMarca = seleccionarMarca();

        equipoActual.setIdTipoMarca(idTipoMarca);
        break;
    }

    case 3:{
        char descripcion[30];

        cin.ignore(1000, '\n');

        // VALIDACIÓN:
        // Verifica que la descripción no esté vacía.
        validador.leerTexto(descripcion, 30, "Ingrese nueva descripcion: ");

        equipoActual.setDescripcion(descripcion);
        break;
    }

    case 4:{
        int stock;

        // VALIDACIÓN:
        // Verifica que el stock sea un número entero positivo.
        validador.leerEnteroPositivo(stock, "Ingrese nuevo stock: ");

        equipoActual.setStock(stock);
        break;
    }

    case 5:{
        float precioUnitario;

        // VALIDACIÓN:
        // Verifica que el precio sea un número positivo.
        validador.leerDecimalPositivo(precioUnitario,
                                      "Ingrese nuevo precio unitario: ");

        equipoActual.setPrecioUnitario(precioUnitario);
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
        cout << "Modificacion cancelada por el usuario." << endl;
        return;
    }

    if(_archivoEquipos.modificar(equipoActual)){
        cout << "Equipo modificado correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar el equipo." << endl;
    }

    consola.pausar();
}
// Ordena un vector de equipos por precio unitario de menor a mayor.
// Se utiliza para generar los listados ordenados.
void EquipoManager::ordenarEquipos(Equipo vEquipos[], int cantidad){

    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            if(vEquipos[j].getPrecioUnitario() >
               vEquipos[j + 1].getPrecioUnitario()){

                Equipo aux = vEquipos[j];
                vEquipos[j] = vEquipos[j + 1];
                vEquipos[j + 1] = aux;
            }
        }
    }
}

// Muestra todos los equipos activos ordenados según el criterio
// definido en la función ordenarEquipos().
//
// VALIDACIONES:
// - Verifica que existan equipos cargados.
// - Comprueba que se haya podido reservar memoria dinámica.
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

    // Carga únicamente los equipos activos.
    for(int i = 1; i <= cantidadEquipos; i++){

        Equipo equipo = _archivoEquipos.leer(i);

        if(equipo.getEstado()){
            equipos[cantidadActivos] = equipo;
            cantidadActivos++;
        }
    }

    // Ordena el vector de equipos.
    ordenarEquipos(equipos, cantidadActivos);

    // Muestra los equipos ordenados.
    for(int i = 0; i < cantidadActivos; i++){
        mostrarEquipo(equipos[i]);
        cout << endl;
    }

    delete[] equipos;
}
// Da de baja un equipo del sistema.
//
// VALIDACIONES:
// - Verifica que el ID ingresado sea válido.
// - Comprueba que el equipo exista y se encuentre activo.
// - Solicita confirmación antes de realizar la baja.
void EquipoManager::eliminarEquipo(){

    int idEliminado;

    // VALIDACIÓN:
    // Solicita un ID válido o permite cancelar la operación.
    validador.leerEnteroConCero(idEliminado,
        "Ingrese el ID del equipo a dar de baja (0 para cancelar): ");

    if(idEliminado == 0){
        cout << "Operacion cancelada." << endl;
        return;
    }

    Equipo equipo = _archivoEquipos.leer(idEliminado);

    if(!equipo.getEstado()){
        cout << "Equipo no encontrado." << endl;
        consola.pausar();
        return;
    }

    mostrarEquipo(equipo);

    char confirmar;

    // VALIDACIÓN:
    // Solicita confirmación antes de dar de baja el equipo.
    validador.leerConfirmacion(confirmar);

    if(confirmar == 'S' || confirmar == 's'){

        if(_archivoEquipos.borrarRegistro(idEliminado)){
            cout << "Equipo dado de baja con exito." << endl;
        }
        else{
            cout << "No se pudo dar de baja el equipo." << endl;
        }
    }
    else{
        cout << "Operacion cancelada por el usuario." << endl;
    }

    consola.pausar();
}

// Permite seleccionar un tipo de equipo.
//
// Si el tipo ingresado ya existe, devuelve su ID.
// En caso contrario, crea un nuevo tipo y devuelve el ID generado.
//
// VALIDACIONES:
// - Verifica que la descripción ingresada no esté vacía.
int EquipoManager::seleccionarTipoEquipo(){

    char descripcion[30];

    // VALIDACIÓN:
    // Solicita un tipo de equipo válido.
    validador.leerTexto(descripcion, 30, "Tipo de equipo: ");

    int cantidad = _archivoTipoEquipos.getCantidadTipos();

    // Busca si el tipo ya existe.
    for(int i = 0; i < cantidad; i++){

        TipoEquipo tipo = _archivoTipoEquipos.leerPorPosicion(i);

        if(tipo.getEstado() &&
           strcmp(tipo.getDescripcion(), descripcion) == 0){

            return tipo.getIdTipoEquipo();
        }
    }

    // Si no existe, genera un nuevo ID y crea el tipo.
    int nuevoId = _archivoTipoEquipos.generarNuevoId();

    TipoEquipo nuevoTipo(nuevoId, descripcion, true);

    if(_archivoTipoEquipos.guardar(nuevoTipo)){
        cout << "Tipo de equipo nuevo creado con ID " << nuevoId << endl;
        return nuevoId;
    }

    return 0;
}

// Permite seleccionar una marca.
//
// Si la marca ingresada ya existe, devuelve su ID.
// En caso contrario, crea una nueva marca y devuelve el ID generado.
//
// VALIDACIONES:
// - Verifica que la descripción ingresada no esté vacía.
int EquipoManager::seleccionarMarca(){

    char descripcion[30];

    // VALIDACIÓN:
    // Solicita una marca válida.
    validador.leerTexto(descripcion, 30, "Marca: ");

    int cantidad = _archivoTipoMarcas.getCantidadTipos();

    // Busca si la marca ya existe.
    for(int i = 0; i < cantidad; i++){

        TipoMarca marca = _archivoTipoMarcas.leerPorPosicion(i);

        if(marca.getEstado() &&
           strcmp(marca.getDescripcion(), descripcion) == 0){

            return marca.getIdTipoMarca();
        }
    }

    // Si no existe, genera un nuevo ID y crea la marca.
    int nuevoId = _archivoTipoMarcas.generarNuevoId();

    TipoMarca nuevaMarca(nuevoId, descripcion, true);

    if(_archivoTipoMarcas.guardar(nuevaMarca)){
        cout << "Marca nueva creada con ID " << nuevoId << endl;
        return nuevoId;
    }

    return 0;
}

// Busca un tipo de equipo por su descripción.
//
// Devuelve el ID del tipo de equipo si existe.
// Si no existe, devuelve 0.
//
// VALIDACIONES:
// - Verifica que la descripción ingresada no esté vacía.
int EquipoManager::buscarTipoEquipo(){

    char descripcion[30];

    // VALIDACIÓN:
    // Solicita un tipo de equipo válido.
    validador.leerTexto(descripcion, 30, "Ingrese el tipo de equipo: ");

    int cantidad = _archivoTipoEquipos.getCantidadTipos();

    // Recorre los tipos de equipo buscando una coincidencia.
    for(int i = 0; i < cantidad; i++){

        TipoEquipo tipo = _archivoTipoEquipos.leerPorPosicion(i);

        if(tipo.getEstado() &&
           strcmp(tipo.getDescripcion(), descripcion) == 0){

            return tipo.getIdTipoEquipo();
        }
    }

    return 0;
}
// Busca una marca por su descripción.
//
// Devuelve el ID de la marca si existe.
// Si no existe, devuelve 0.
//
// VALIDACIONES:
// - Verifica que la descripción ingresada no esté vacía.
int EquipoManager::buscarMarca(){

    char descripcion[30];

    // VALIDACIÓN:
    // Solicita una marca válida.
    validador.leerTexto(descripcion, 30, "Ingrese la marca: ");

    int cantidad = _archivoTipoMarcas.getCantidadTipos();

    // Recorre las marcas buscando una coincidencia.
    for(int i = 0; i < cantidad; i++){

        TipoMarca marca = _archivoTipoMarcas.leerPorPosicion(i);

        if(marca.getEstado() &&
           strcmp(marca.getDescripcion(), descripcion) == 0){

            return marca.getIdTipoMarca();
        }
    }

    return 0;
}

// Ordena un vector de equipos por tipo de equipo (ID).
void EquipoManager::ordenarEquiposPorTipo(Equipo vEquipos[], int cantidad){

    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            if(vEquipos[j].getIdTipoEquipo() >
               vEquipos[j + 1].getIdTipoEquipo()){

                Equipo aux = vEquipos[j];
                vEquipos[j] = vEquipos[j + 1];
                vEquipos[j + 1] = aux;
            }
        }
    }
}

// Ordena un vector de equipos por marca (ID).
void EquipoManager::ordenarEquiposPorMarca(Equipo vEquipos[], int cantidad){

    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            if(vEquipos[j].getIdTipoMarca() >
               vEquipos[j + 1].getIdTipoMarca()){

                Equipo aux = vEquipos[j];
                vEquipos[j] = vEquipos[j + 1];
                vEquipos[j + 1] = aux;
            }
        }
    }
}
// Ordena un vector de equipos por precio unitario de menor a mayor.

void EquipoManager::ordenarEquiposPorPrecioAsc(Equipo vEquipos[], int cantidad){

    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            if(vEquipos[j].getPrecioUnitario() >
               vEquipos[j + 1].getPrecioUnitario()){

                Equipo aux = vEquipos[j];
                vEquipos[j] = vEquipos[j + 1];
                vEquipos[j + 1] = aux;
            }
        }
    }
}

// Ordena un vector de equipos por precio unitario de mayor a menor.

void EquipoManager::ordenarEquiposPorPrecioDesc(Equipo vEquipos[], int cantidad){

    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            if(vEquipos[j].getPrecioUnitario() <
               vEquipos[j + 1].getPrecioUnitario()){

                Equipo aux = vEquipos[j];
                vEquipos[j] = vEquipos[j + 1];
                vEquipos[j + 1] = aux;
            }
        }
    }
}

// Carga en un vector todos los equipos que se encuentran activos.
// Devuelve la cantidad de equipos activos cargados.

int EquipoManager::cargarEquiposActivos(Equipo vEquipos[]){

    int cantidad = _archivoEquipos.getCantidadEquipos();
    int cantidadActivos = 0;

    // Recorre todos los equipos almacenados.
    for(int i = 0; i < cantidad; i++){

        Equipo equipo = _archivoEquipos.leerPorPosicion(i);

        // Copia únicamente los equipos activos al vector.
        if(equipo.getEstado()){
            vEquipos[cantidadActivos] = equipo;
            cantidadActivos++;
        }
    }

    return cantidadActivos;
}

void EquipoManager::mostrarEquiposOrdenadosPorTipo(){

    int cantidad = _archivoEquipos.getCantidadEquipos();

    Equipo *vEquipos = new Equipo[cantidad];

    int cantidadActivos = cargarEquiposActivos(vEquipos);

    ordenarEquiposPorTipo(vEquipos, cantidadActivos);

    ordenarEquiposPorTipo(vEquipos, cantidadActivos);

    for(int i = 0; i < cantidadActivos; i++){
        mostrarEquipo(vEquipos[i]);
        cout << endl;
    }

    delete[] vEquipos;
}

void EquipoManager::mostrarEquiposOrdenadosPorMarca(){
    int cantidad = _archivoEquipos.getCantidadEquipos();

    Equipo *vEquipos = new Equipo[cantidad];

    int cantidadActivos = cargarEquiposActivos(vEquipos);

    ordenarEquiposPorTipo(vEquipos, cantidadActivos);

    for(int i = 0; i < cantidadActivos; i++){
        mostrarEquipo(vEquipos[i]);
        cout << endl;
    }

    delete[] vEquipos;
}

void EquipoManager::mostrarEquiposOrdenadosPorPrecioAsc(){
    int cantidad = _archivoEquipos.getCantidadEquipos();

    Equipo *vEquipos = new Equipo[cantidad];

    int cantidadActivos = cargarEquiposActivos(vEquipos);

    ordenarEquiposPorTipo(vEquipos, cantidadActivos);

    for(int i = 0; i < cantidadActivos; i++){
        mostrarEquipo(vEquipos[i]);
        cout << endl;
    }

    delete[] vEquipos;
}

void EquipoManager::mostrarEquiposOrdenadosPorPrecioDesc(){
    int cantidad = _archivoEquipos.getCantidadEquipos();

    Equipo *vEquipos = new Equipo[cantidad];

    int cantidadActivos = cargarEquiposActivos(vEquipos);

    ordenarEquiposPorTipo(vEquipos, cantidadActivos);


    for(int i = 0; i < cantidadActivos; i++){
        mostrarEquipo(vEquipos[i]);
        cout << endl;
    }

    delete[] vEquipos;
}

