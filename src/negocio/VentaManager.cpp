#include <iostream>
#include "../modelos/Venta.h"
#include "VentaManager.h"
#include "../archivos/ArchivoDetalleVenta.h"
#include "../archivos/ArchivoEquipo.h"
#include "../archivos/ArchivoTipoMarca.h"
#include "../archivos/ArchivoTipoEquipo.h"


using namespace std;

VentaManager::VentaManager()
   : _archivoVentas(), _archivoEquipos(), _archivoDetalleVentas(){}

// Crea una nueva venta solicitando los datos principales por teclado.

// VALIDACIONES:
// - Genera automáticamente el ID de venta.
// - Valida que el ID del cliente sea numérico y positivo.
// - Valida que el ID del empleado sea numérico y positivo.
// - Valida que la fecha ingresada sea correcta.
Venta VentaManager::crearVenta(){

    Venta venta;

    int idVenta;
    int idCliente;
    int idEmpleado;
    int dia, mes, anio;

    // Genera automáticamente el ID de la nueva venta.
    idVenta = _archivoVentas.getCantidadRegistros() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    // VALIDACIÓN:
    // Solicita IDs válidos para cliente y empleado.
    validador.leerEnteroPositivo(idCliente, "ID Cliente: ");
    validador.leerEnteroPositivo(idEmpleado, "ID Empleado: ");

    // VALIDACIÓN:
    // Solicita una fecha válida.
    do{
        validador.leerEnteroPositivo(dia, "Dia: ");
        validador.leerEnteroPositivo(mes, "Mes: ");
        validador.leerEnteroPositivo(anio, "Anio: ");

        if(dia <= 0 || dia > 31 || mes <= 0 || mes > 12 || anio <= 0){
            cout << "Fecha invalida. Ingrese nuevamente." << endl;
        }

    }while(dia <= 0 || dia > 31 || mes <= 0 || mes > 12 || anio <= 0);

    Fecha fecha(dia, mes, anio);

    // Se cargan los datos principales de la venta.
    venta.setIdVenta(idVenta);
    venta.setIdCliente(idCliente);
    venta.setIdEmpleado(idEmpleado);
    venta.setFecha(fecha);
    venta.setImporteTotal(0);
    venta.setEstado(true);

    return venta;
}

// Registra una venta completa.
// Primero crea la venta principal y luego permite cargar uno o más equipos
// como detalles de venta.

// VALIDACIONES:
// - Valida que la cantidad de equipos a vender sea positiva.
// - Verifica que se pueda reservar memoria para los detalles.
// - Valida que cada equipo exista.
// - Valida que la cantidad vendida sea positiva.
// - Verifica que haya stock suficiente.
// - Actualiza el stock de cada equipo vendido.
// - Guarda la venta y sus detalles.
void VentaManager::guardarVenta(){

    Venta venta = crearVenta();

    int cantidadEquipos;

    // VALIDACIÓN:
    // Solicita una cantidad válida de equipos a agregar.
    validador.leerEnteroPositivo(cantidadEquipos,
                                 "Cantidad de equipos a agregar a la venta: ");

    DetalleVenta *detalles = new DetalleVenta[cantidadEquipos];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
        return;
    }

    double importeTotal = 0;
    int cantidadCargados = 0;

    // Carga cada equipo incluido en la venta.
    for(int i = 0; i < cantidadEquipos; i++){

        bool equipoValido = false;

        while(!equipoValido){

            int idEquipo;
            int cantidad;

            cout << "-- Equipo " << i + 1 << " --" << endl;

            // VALIDACIÓN:
            // Solicita un ID de equipo válido.
            validador.leerEnteroPositivo(idEquipo, "ID Equipo: ");

            Equipo equipo = _archivoEquipos.leer(idEquipo);

            if(equipo.getIdEquipo() == 0 || !equipo.getEstado()){
                cout << "No existe un equipo activo con ese ID. Ingrese otro." << endl;
                continue;
            }

            // VALIDACIÓN:
            // Solicita una cantidad válida.
            validador.leerEnteroPositivo(cantidad, "Cantidad: ");

            if(cantidad > equipo.getStock()){
                cout << "Sin stock suficiente. Stock disponible: "
                     << equipo.getStock() << endl;
                continue;
            }

            int idDetalle = _archivoDetalleVentas.getCantidadRegistros() + 1 + cantidadCargados;
            float precioUnitario = equipo.getPrecioUnitario();
            float subtotal = precioUnitario * cantidad;

            // Se cargan los datos del detalle de venta.
            detalles[cantidadCargados].setIdDetalleVenta(idDetalle);
            detalles[cantidadCargados].setIdVenta(venta.getIdVenta());
            detalles[cantidadCargados].setIdEquipo(idEquipo);
            detalles[cantidadCargados].setCantidad(cantidad);
            detalles[cantidadCargados].setPrecioUnitario(precioUnitario);
            detalles[cantidadCargados].setSubtotal(subtotal);
            detalles[cantidadCargados].setEstado(true);

            // Se descuenta el stock del equipo vendido.
            equipo.setStock(equipo.getStock() - cantidad);
            _archivoEquipos.modificar(equipo);

            importeTotal += subtotal;
            cantidadCargados++;

            equipoValido = true;
        }
    }

    if(cantidadCargados == 0){
        cout << "No se pudo registrar ningun equipo. Venta cancelada." << endl;
        delete[] detalles;
        consola.pausar();
        return;
    }

    venta.setImporteTotal(importeTotal);

    // Guarda la venta principal y luego sus detalles.
    if(_archivoVentas.guardar(venta)){

        for(int i = 0; i < cantidadCargados; i++){
            _archivoDetalleVentas.guardar(detalles[i]);
        }

        cout << "Venta guardada correctamente." << endl;
        cout << "Importe total: $" << importeTotal << endl;
    }
    else{
        cout << "Error al guardar la venta." << endl;
    }

    delete[] detalles;
    consola.pausar();
}

/* Muestra por pantalla los datos completos de una venta,
 incluyendo sus datos principales y el detalle de equipos vendidos.*/

void VentaManager::mostrarVenta(Venta &reg, DetalleVenta *detalles){

    cout << "==================================" << endl;
    cout << "ID Venta: " << reg.getIdVenta() << endl;
    cout << "ID Cliente: " << reg.getIdCliente() << endl;
    cout << "ID Empleado: " << reg.getIdEmpleado() << endl;
    cout << "Fecha: " << reg.getFecha().toString() << endl;
    cout << "Importe Total: $" << reg.getImporteTotal() << endl;
    cout << "Estado: " << (reg.getEstado() ? "Activa" : "Cancelada") << endl;

    int cantidadDetalles = 0;

    // Busca los detalles asociados a la venta.
    _archivoDetalleVentas.leerPorIdVenta(reg.getIdVenta(), detalles, cantidadDetalles);

    if(cantidadDetalles > 0){

        cout << "----------------------------------" << endl;
        cout << "Detalle:" << endl;

        // Muestra cada equipo vendido dentro de la venta.
        for(int i = 0; i < cantidadDetalles; i++){

            cout << "  Equipo: ";
            mostrarEquipoDetalle(detalles[i].getIdEquipo());

            cout << " | Cantidad: " << detalles[i].getCantidad()
                 << " | Precio unit.: $" << detalles[i].getPrecioUnitario()
                 << " | Subtotal: $" << detalles[i].getSubtotal() << endl;
        }
    }

    cout << "==================================" << endl;
}

// Muestra todas las ventas activas registradas en el sistema.

// VALIDACIONES:
// - Verifica que existan ventas cargadas.
// - Comprueba que se pueda reservar memoria para los detalles.
// - Solo muestra ventas activas.
void VentaManager::listarVentas(){

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        consola.pausar();
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();

    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
        return;
    }

    // Recorre todas las ventas mostrando únicamente las activas.
    for(int i = 0; i < cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado()){
            mostrarVenta(venta, detalles);
            cout << endl;
        }
    }

    delete[] detalles;
    consola.pausar();
}

// Cancela una venta existente.
// Al cancelar la venta, devuelve al stock las cantidades vendidas de cada equipo incluido en el detalle.

// VALIDACIONES:
// - Verifica que el ID ingresado sea válido.
// - Comprueba que la venta exista y esté activa.
// - Verifica que se pueda reservar memoria para los detalles.
// - Solicita confirmación antes de cancelar.
// - Solo devuelve stock de equipos activos.
void VentaManager::cancelarVenta(){

    int idVenta;
    char confirmar;
    Venta venta;

    // VALIDACIÓN:
    // Solicita un ID válido o permite cancelar.
    validador.leerEnteroConCero(idVenta,
                                "Ingrese el ID de la venta a cancelar (0 para volver): ");

    if(idVenta == 0){
        cout << "Cancelacion anulada." << endl;
        return;
    }

    venta = _archivoVentas.leer(idVenta);

    if(!venta.getEstado()){
        cout << "Venta no encontrada o ya cancelada." << endl;
        consola.pausar();
        return;
    }

    int cantidadRegistrosDetalle = _archivoDetalleVentas.getCantidadRegistros();

    DetalleVenta *detalles = new DetalleVenta[cantidadRegistrosDetalle];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
        return;
    }

    int cantidadDetalles = 0;

    _archivoDetalleVentas.leerPorIdVenta(idVenta, detalles, cantidadDetalles);

    cout << "Venta encontrada:" << endl;
    mostrarVenta(venta, detalles);

    // VALIDACIÓN:
    // Solicita confirmación antes de cancelar.
    validador.leerConfirmacion(confirmar);

    if(confirmar == 'N' || confirmar == 'n'){
        cout << "Cancelacion anulada." << endl;
        delete[] detalles;
        consola.pausar();
        return;
    }

    // Devuelve al stock las cantidades vendidas.
    for(int i = 0; i < cantidadDetalles; i++){

        Equipo equipo = _archivoEquipos.leer(detalles[i].getIdEquipo());

        if(equipo.getEstado()){

            equipo.setStock(equipo.getStock() + detalles[i].getCantidad());

            _archivoEquipos.modificar(equipo);
        }
    }

    if(_archivoVentas.cancelarVenta(idVenta)){
        cout << "Venta cancelada correctamente." << endl;
    }
    else{
        cout << "No se pudo cancelar la venta." << endl;
    }

    delete[] detalles;
    consola.pausar();
}

// Ordena un vector de ventas por ID de venta
// utilizando el método de ordenamiento Burbuja.

void VentaManager::ordenarVentas(Venta vVentas[], int cantidad){

    for(int i = 0; i < cantidad - 1; i++){

        for(int j = 0; j < cantidad - i - 1; j++){

            if(vVentas[j].getIdVenta() > vVentas[j + 1].getIdVenta()){

                Venta aux = vVentas[j];
                vVentas[j] = vVentas[j + 1];
                vVentas[j + 1] = aux;
            }
        }
    }
}

// Muestra todas las ventas activas ordenadas por ID.

// VALIDACIONES:
// - Verifica que existan ventas cargadas.
// - Comprueba que se pueda reservar memoria para las ventas.
// - Comprueba que se pueda reservar memoria para los detalles.
// - Solo muestra ventas activas.
void VentaManager::mostrarVentasOrdenadas(){

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        consola.pausar();
        return;
    }

    Venta *ventas = new Venta[cantidadRegistros];

    if(ventas == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
        return;
    }

    int cantidadActivas = 0;

    // Carga únicamente las ventas activas.
    for(int i = 0; i < cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado()){
            ventas[cantidadActivas] = venta;
            cantidadActivas++;
        }
    }

    // Ordena las ventas por ID.
    ordenarVentas(ventas, cantidadActivas);

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        delete[] ventas;
        consola.pausar();
        return;
    }

    // Muestra las ventas ordenadas.
    for(int i = 0; i < cantidadActivas; i++){
        mostrarVenta(ventas[i], detalles);
        cout << endl;
    }

    delete[] ventas;
    delete[] detalles;
    consola.pausar();
}
// Busca y muestra una venta según su ID.

// VALIDACIONES:
// - Verifica que el ID ingresado sea válido.
// - Comprueba que la venta exista.
// - Verifica que se pueda reservar memoria para los detalles.
void VentaManager::consultarPorId(){

    int idVenta;

    // VALIDACIÓN:
    // Solicita un ID de venta válido.
    validador.leerEnteroPositivo(idVenta, "Ingrese el ID de la venta: ");

    Venta venta = _archivoVentas.leerIncluyendoCanceladas(idVenta);

    if(venta.getIdVenta() == 0){
        cout << "No existe una venta con ese ID." << endl;
        consola.pausar();
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();

    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
        return;
    }

    int cantidadEncontrada = 0;

    // Obtiene el detalle correspondiente a la venta.
    _archivoDetalleVentas.leerPorIdVenta(idVenta, detalles, cantidadEncontrada);

    mostrarVenta(venta, detalles);

    delete[] detalles;
    consola.pausar();
}

// Busca y muestra todas las ventas asociadas a un cliente determinado.
//
// VALIDACIONES:
// - Verifica que el ID del cliente ingresado sea válido.
// - Verifica que existan ventas cargadas.
// - Comprueba que se pueda reservar memoria para los detalles.
// - Solo muestra ventas activas.
void VentaManager::consultarPorCliente(){

    int idCliente;

    // VALIDACIÓN:
    // Solicita un ID de cliente válido.
    validador.leerEnteroPositivo(idCliente, "Ingrese el ID del cliente: ");

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        consola.pausar();
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
        return;
    }

    bool encontro = false;

    // Recorre las ventas buscando las asociadas al cliente indicado.
    for(int i = 0; i < cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado() && venta.getIdCliente() == idCliente){
            mostrarVenta(venta, detalles);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para ese cliente." << endl;
    }

    delete[] detalles;
    consola.pausar();
}

// Busca y muestra todas las ventas realizadas por un empleado determinado.
//
// VALIDACIONES:
// - Verifica que el ID del empleado ingresado sea válido.
// - Verifica que existan ventas cargadas.
// - Comprueba que se pueda reservar memoria para los detalles.
// - Solo muestra ventas activas.
void VentaManager::consultarPorEmpleado(){

    int idEmpleado;

    // VALIDACIÓN:
    // Solicita un ID de empleado válido.
    validador.leerEnteroPositivo(idEmpleado, "Ingrese el ID del empleado: ");

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        consola.pausar();
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
        return;
    }

    bool encontro = false;

    // Recorre las ventas buscando las asociadas al empleado indicado.
    for(int i = 0; i < cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado() && venta.getIdEmpleado() == idEmpleado){
            mostrarVenta(venta, detalles);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para ese empleado." << endl;
    }

    delete[] detalles;
    consola.pausar();
}

void VentaManager::consultarPorFecha(){

    int dia, mes, anio;

    do{
        cout << "Dia: ";
        cin >> dia;

        cout << "Mes: ";
        cin >> mes;

        cout << "Anio: ";
        cin >> anio;

        if(dia <= 0 || mes <= 0 || mes > 12 || anio <= 0){
            cout << "Fecha invalida. Ingrese nuevamente." << endl;
        }

    }while(dia <= 0 || mes <= 0 || mes > 12 || anio <= 0);

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        consola.pausar();
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
        return;
    }

    bool encontro = false;

    for(int i = 0; i < cantidadRegistros; i++){

       Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado() &&
           venta.getFecha().getDia() == dia &&
           venta.getFecha().getMes() == mes &&
           venta.getFecha().getAnio() == anio){

            mostrarVenta(venta, detalles);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para esa fecha." << endl;
    }

    delete[] detalles;
    consola.pausar();
}

// Busca y muestra todas las ventas en las que se haya vendido
// un equipo determinado.
//
// VALIDACIONES:
// - Verifica que el ID del equipo ingresado sea válido.
// - Verifica que existan ventas cargadas.
// - Comprueba que se pueda reservar memoria para los detalles.
// - Solo muestra ventas activas.
void VentaManager::consultarPorEquipo(){

    int idEquipo;

    // VALIDACIÓN:
    // Solicita un ID de equipo válido.
    validador.leerEnteroPositivo(idEquipo, "Ingrese el ID del equipo: ");

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        consola.pausar();
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        consola.pausar();
        return;
    }

    bool encontro = false;

    // Recorre todas las ventas activas.
    for(int i = 0; i < cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado()){

            int cantidadEncontrados = 0;

            _archivoDetalleVentas.leerPorIdVenta(
                venta.getIdVenta(),
                detalles,
                cantidadEncontrados);

            // Busca el equipo dentro del detalle de la venta.
            for(int j = 0; j < cantidadEncontrados; j++){

                if(detalles[j].getIdEquipo() == idEquipo){

                    mostrarVenta(venta, detalles);
                    cout << endl;
                    encontro = true;
                    break;
                }
            }
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas con ese equipo." << endl;
    }

    delete[] detalles;
    consola.pausar();
}
// Devuelve la descripción correspondiente a una marca.

const char* VentaManager::obtenerNombreMarca(int idMarca){

    TipoMarca marca = _archivoTipoMarcas.leer(idMarca);

    if(marca.getIdTipoMarca() == 0){
        return "Marca no encontrada";
    }

    return marca.getDescripcion();
}

// Devuelve la descripción correspondiente a un tipo de equipo.

const char* VentaManager::obtenerNombreTipoEquipo(int idTipoEquipo){

    TipoEquipo tipo = _archivoTipoEquipos.leer(idTipoEquipo);

    if(tipo.getIdTipoEquipo() == 0){
        return "Tipo no encontrado";
    }

    return tipo.getDescripcion();
}

// Muestra la información resumida de un equipo perteneciente al detalle de una venta.

// VALIDACIONES:
// - Verifica que el equipo exista.
void VentaManager::mostrarEquipoDetalle(int idEquipo){

    Equipo equipo = _archivoEquipos.leer(idEquipo);

    if(equipo.getIdEquipo() == 0){
        cout << "Equipo no encontrado";
        return;
    }

    cout << equipo.getDescripcion()
         << " | Marca: " << obtenerNombreMarca(equipo.getIdTipoMarca())
         << " | Tipo: " << obtenerNombreTipoEquipo(equipo.getIdTipoEquipo());
}
