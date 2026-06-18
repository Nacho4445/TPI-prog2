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
// - Genera automaticamente el ID de venta.
// - Valida que el ID del cliente y empleado sea numerico y positivo.
// - Valida que la fecha sea correcta.
Venta VentaManager::crearVenta(){

    Venta venta;

    int idVenta;
    int idCliente;
    int idEmpleado;
    int dia, mes, anio;

    // Genera automaticamente el ID de la nueva venta.
    idVenta = _archivoVentas.getCantidadRegistros() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    // Valida IDs cliente y empleado.
    validador.leerEnteroPositivo(idCliente, "ID Cliente: ");
    validador.leerEnteroPositivo(idEmpleado, "ID Empleado: ");

    // Valida fecha.
    do{
        validador.leerEnteroPositivo(dia, "Dia: ");
        validador.leerEnteroPositivo(mes, "Mes: ");
        validador.leerEnteroPositivo(anio, "Anio: ");

        if(dia <= 0 || dia > 31 || mes <= 0 || mes > 12 || anio <= 0){
            cout << "Fecha invalida. Ingrese nuevamente." << endl;
        }

    }while(dia <= 0 || dia > 31 || mes <= 0 || mes > 12 || anio <= 0);

    Fecha fecha(dia, mes, anio);

    // Se cargan los datos de la venta.
    venta.setIdVenta(idVenta);
    venta.setIdCliente(idCliente);
    venta.setIdEmpleado(idEmpleado);
    venta.setFecha(fecha);
    venta.setImporteTotal(0);
    venta.setEstado(true);

    return venta;
}

// Registra una venta completa.
// Primero crea la venta principal y luego permite cargar uno o mas equipos (detalles de venta).
// VALIDACIONES:
// - Valida que la cantidad de equipos a vender sea positiva.
// - Verifica que se pueda reservar memoria para los detalles.
// - Valida que cada equipo exista.
// - Verifica que haya stock suficiente.
// - Actualiza el stock de cada equipo vendido.
// - Guarda la venta y sus detalles.
void VentaManager::guardarVenta(){

    Venta venta = crearVenta();

    int cantidadEquipos;

    // Solicita una cantidad valida de equipos a agregar.
    validador.leerEnteroPositivo(cantidadEquipos, "Cantidad de equipos a agregar a la venta: ");

    DetalleVenta *detalles = new DetalleVenta[cantidadEquipos];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
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

            // Solicita un ID de equipo valido.
            validador.leerEnteroPositivo(idEquipo, "ID Equipo: ");

            Equipo equipo = _archivoEquipos.leer(idEquipo);

            if(equipo.getIdEquipo() == 0 || !equipo.getEstado()){
                cout << "No existe un equipo activo con ese ID. Ingrese otro." << endl;
                continue;
            }

            // Solicita una cantidad valida.
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
}

// Muestra los datos completos de una venta (con detalle de equipos vendidos.
void VentaManager::mostrarVenta(Venta &reg, DetalleVenta *detalles){

    cout << endl;
    cout << "ID Venta: " << reg.getIdVenta() << endl;
    cout << "ID Cliente: " << reg.getIdCliente() << endl;
    cout << "ID Empleado: " << reg.getIdEmpleado() << endl;
    cout << "Fecha: " << reg.getFecha().toString() << endl;
    cout << defaultfloat;
    cout.precision(10);
    cout << "Importe Total: $" << reg.getImporteTotal() << endl;
    cout << "Estado: " << (reg.getEstado() ? "Activa" : "Cancelada") << endl;

    int cantidadDetalles = 0;

    // Busca los detalles asociados a la venta.
    _archivoDetalleVentas.leerPorIdVenta(reg.getIdVenta(), detalles, cantidadDetalles);

    if(cantidadDetalles > 0){

        cout << "----------------------------------" << endl;
        cout << "Detalle:" << endl;

        // Muestra cada equipo vendido.
        for(int i = 0; i < cantidadDetalles; i++){

            cout << "  Equipo: ";
            mostrarEquipoDetalle(detalles[i].getIdEquipo());

            cout << defaultfloat;
            cout.precision(10);
            cout << " | Cantidad: " << detalles[i].getCantidad()
                 << " | Precio unit.: $" << detalles[i].getPrecioUnitario()
                 << " | Subtotal: $" << detalles[i].getSubtotal() << endl;
        }
    }
    cout << endl;
    cout << "==================================" << endl;
}

// Muestra todas las ventas activas registradas.
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
        return;
    }

    // Recorre todas las ventas mostrando solo las activas.
    for(int i = 0; i < cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado()){
            mostrarVenta(venta, detalles);
        }
    }

    delete[] detalles;
}

// Cancela una venta, devuelve al stock las cantidades vendidas de cada equipo incluido en el detalle.
// VALIDACIONES:
// - Verifica que el ID ingresado sea valido.
// - Comprueba que la venta exista y este activa.
// - Verifica que se pueda reservar memoria para los detalles.
// - Solicita confirmacion antes de cancelar.
// - Solo devuelve stock de equipos activos.
void VentaManager::cancelarVenta(){

    int idVenta;
    char confirmar;
    Venta venta;

    // Solicita un ID valido o permite cancelar.
    validador.leerEnteroConCero(idVenta, "Ingrese el ID de la venta a cancelar (0 para volver): ");

    if(idVenta == 0){
        cout << "Cancelacion anulada." << endl;
        return;
    }

    venta = _archivoVentas.leer(idVenta);

    if(!venta.getEstado()){
        cout << "Venta no encontrada o ya cancelada." << endl;
        return;
    }

    int cantidadRegistrosDetalle = _archivoDetalleVentas.getCantidadRegistros();

    DetalleVenta *detalles = new DetalleVenta[cantidadRegistrosDetalle];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadDetalles = 0;

    _archivoDetalleVentas.leerPorIdVenta(idVenta, detalles, cantidadDetalles);

    cout << "Venta encontrada:" << endl;
    mostrarVenta(venta, detalles);

    // Solicita confirmacion antes de cancelar.
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
}

// Ordena por ID de venta con ordenamiento burbuja.
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
// - Comprueba que se pueda reservar memoria para ventas y detalles.
// - Solo muestra ventas activas.
void VentaManager::mostrarVentasOrdenadas(){

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        return;
    }

    Venta *ventas = new Venta[cantidadRegistros];

    if(ventas == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadActivas = 0;

    // Carga solo las ventas activas.
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
        return;
    }

    // Muestra las ventas ordenadas.
    cout << defaultfloat;
    cout.precision(10);
    for(int i = 0; i < cantidadActivas; i++){
        mostrarVenta(ventas[i], detalles);
    }

    delete[] ventas;
    delete[] detalles;
}

// Busca y muestra una venta segun su ID.
// VALIDACIONES:
// - Verifica que el ID sea valido.
// - Comprueba que la venta exista.
// - Verifica que se pueda reservar memoria para los detalles.
void VentaManager::consultarPorId(){

    int idVenta;

    // Solicita un ID de venta valido.
    validador.leerEnteroPositivo(idVenta, "Ingrese el ID de la venta: ");

    Venta venta = _archivoVentas.leerIncluyendoCanceladas(idVenta);

    if(venta.getIdVenta() == 0){
        cout << "No existe una venta con ese ID." << endl;
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();

    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    int cantidadEncontrada = 0;

    // Obtiene el detalle correspondiente a la venta.
    _archivoDetalleVentas.leerPorIdVenta(idVenta, detalles, cantidadEncontrada);

    mostrarVenta(venta, detalles);

    delete[] detalles;
}

// Busca y muestra todas las ventas asociadas a un cliente.
// VALIDACIONES:
// - Verifica que el ID del cliente ingresado sea valido.
// - Verifica que existan ventas cargadas.
// - Comprueba que se pueda reservar memoria para los detalles.
// - Solo muestra ventas activas.
void VentaManager::consultarPorCliente(){

    int idCliente;

    // Solicita un ID de cliente valido.
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
        return;
    }

    bool encontro = false;

    // Recorre las ventas buscando las asociadas al cliente indicado.
    for(int i = 0; i < cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado() && venta.getIdCliente() == idCliente){
            mostrarVenta(venta, detalles);
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para ese cliente." << endl;
    }

    delete[] detalles;
}

// Busca y muestra todas las ventas realizadas por un empleado.
// VALIDACIONES:
// - Verifica que el ID del empleado ingresado sea valido.
// - Verifica que existan ventas cargadas.
// - Comprueba que se pueda reservar memoria para los detalles.
// - Solo muestra ventas activas.
void VentaManager::consultarPorEmpleado(){

    int idEmpleado;

    // Solicita un ID de empleado valido.
    validador.leerEnteroPositivo(idEmpleado, "Ingrese el ID del empleado: ");

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    bool encontro = false;

    // Recorre las ventas buscando las asociadas al empleado indicado.
    for(int i = 0; i < cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado() && venta.getIdEmpleado() == idEmpleado){
            mostrarVenta(venta, detalles);
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para ese empleado." << endl;
    }

    delete[] detalles;
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
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
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
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para esa fecha." << endl;
    }

    delete[] detalles;
}

// Busca y muestra todas las ventas que incluyan un equipo determinado.
// VALIDACIONES:
// - Verifica que el ID del equipo ingresado sea valido.
// - Verifica que existan ventas cargadas.
// - Comprueba que se pueda reservar memoria para los detalles.
// - Solo muestra ventas activas.
void VentaManager::consultarPorEquipo(){

    int idEquipo;

    // Solicita un ID de equipo valido.
    validador.leerEnteroPositivo(idEquipo, "Ingrese el ID del equipo: ");

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        return;
    }

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
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
}

// Devuelve la descripcion correspondiente a una marca.
const char* VentaManager::obtenerNombreMarca(int idMarca){

    TipoMarca marca = _archivoTipoMarcas.leer(idMarca);

    if(marca.getIdTipoMarca() == 0){
        return "Marca no encontrada";
    }

    return marca.getDescripcion();
}

// Devuelve la descripcion correspondiente a un tipo de equipo.

const char* VentaManager::obtenerNombreTipoEquipo(int idTipoEquipo){

    TipoEquipo tipo = _archivoTipoEquipos.leer(idTipoEquipo);

    if(tipo.getIdTipoEquipo() == 0){
        return "Tipo no encontrado";
    }

    return tipo.getDescripcion();
}

// Muestra la informacion resumida de un equipo perteneciente al detalle de una venta.
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
