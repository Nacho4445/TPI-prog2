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

Venta VentaManager::crearVenta(){

    Venta venta;

    int idVenta;
    int idCliente;
    int idEmpleado;
    int dia, mes, anio;

    idVenta = _archivoVentas.getCantidadRegistros() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    cout << "ID Cliente: ";
    cin >> idCliente;

    cout << "ID Empleado: ";
    cin >> idEmpleado;

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

    Fecha fecha(dia, mes, anio);

    venta.setIdVenta(idVenta);
    venta.setIdCliente(idCliente);
    venta.setIdEmpleado(idEmpleado);
    venta.setFecha(fecha);
    venta.setImporteTotal(0);
    venta.setEstado(true);

    return venta;
}

void VentaManager::guardarVenta(){

    Venta venta = crearVenta();

    int cantidadEquipos;
    cout << "Cantidad de equipos a agregar a la venta: ";
    cin >> cantidadEquipos;

    if(cantidadEquipos <= 0){
        cout << "La cantidad de equipos debe ser mayor a cero." << endl;
        return;
    }

    DetalleVenta *detalles = new DetalleVenta[cantidadEquipos];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        return;
    }

    double importeTotal = 0;
    int cantidadCargados = 0;

    for(int i = 0; i < cantidadEquipos; i++){

        bool equipoValido = false;

        while(!equipoValido){

            int idEquipo;
            int cantidad;

            cout << "-- Equipo " << i + 1 << " --" << endl;
            cout << "ID Equipo: ";
            cin >> idEquipo;

            Equipo equipo = _archivoEquipos.leer(idEquipo);

            if(equipo.getIdEquipo() == 0){
                cout << "No existe un equipo activo con ese ID. Ingrese otro." << endl;
                continue;
            }

            cout << "Cantidad: ";
            cin >> cantidad;

            if(cantidad <= 0){
                cout << "La cantidad debe ser mayor a cero. Ingrese nuevamente." << endl;
                continue;
            }

            if(cantidad > equipo.getStock()){
                cout << "Sin stock suficiente. Stock disponible: "
                     << equipo.getStock() << endl;
                continue;
            }

            int idDetalle = _archivoDetalleVentas.getCantidadRegistros() + 1 + cantidadCargados;
            float precioUnitario = equipo.getPrecioUnitario();
            float subtotal = precioUnitario * cantidad;

            detalles[cantidadCargados].setIdDetalleVenta(idDetalle);
            detalles[cantidadCargados].setIdVenta(venta.getIdVenta());
            detalles[cantidadCargados].setIdEquipo(idEquipo);
            detalles[cantidadCargados].setCantidad(cantidad);
            detalles[cantidadCargados].setPrecioUnitario(precioUnitario);
            detalles[cantidadCargados].setSubtotal(subtotal);
            detalles[cantidadCargados].setEstado(true);

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

void VentaManager::mostrarVenta(Venta &reg, DetalleVenta *detalles){

    cout << "==================================" << endl;
    cout << "ID Venta: " << reg.getIdVenta() << endl;
    cout << "ID Cliente: " << reg.getIdCliente() << endl;
    cout << "ID Empleado: " << reg.getIdEmpleado() << endl;
    cout << "Fecha: " << reg.getFecha().toString() << endl;
    cout << "Importe Total: $" << reg.getImporteTotal() << endl;
    cout << "Estado: " << (reg.getEstado() ? "Activa" : "Cancelada") << endl;

    int cantidadDetalles = 0;
    _archivoDetalleVentas.leerPorIdVenta(reg.getIdVenta(), detalles, cantidadDetalles);

    if(cantidadDetalles > 0){
        cout << "----------------------------------" << endl;
        cout << "Detalle:" << endl;
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

void VentaManager::listarVentas(){

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

    for(int i = 0; i <= cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado()){
            mostrarVenta(venta, detalles);
            cout << endl;
        }
    }

    delete[] detalles;
}

void VentaManager::cancelarVenta(){

    int idVenta;
    char confirmar;
    Venta venta;

    cout << "Ingrese el ID de la venta a cancelar: ";
    cin >> idVenta;

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

    cout << "Cancelar esta venta? (s/n): ";
    cin >> confirmar;

    if(confirmar != 's' && confirmar != 'S'){
        cout << "Cancelacion anulada." << endl;
        delete[] detalles;
        return;
    }

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

    for(int i = 0; i < cantidadRegistros; i++){

        Venta venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado()){
            ventas[cantidadActivas] = venta;
            cantidadActivas++;
        }
    }

    ordenarVentas(ventas, cantidadActivas);

    int cantidadDetalles = _archivoDetalleVentas.getCantidadRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles + 1];

    if(detalles == nullptr){
        cout << "No se pudo reservar memoria." << endl;
        delete[] ventas;
        return;
    }

    for(int i = 0; i < cantidadActivas; i++){
        mostrarVenta(ventas[i], detalles);
        cout << endl;
    }

    delete[] ventas;
    delete[] detalles;
}

void VentaManager::consultarPorId(){

    int idVenta;

    cout << "Ingrese el ID de la venta: ";
    cin >> idVenta;

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

    _archivoDetalleVentas.leerPorIdVenta(idVenta, detalles, cantidadEncontrada);

    mostrarVenta(venta, detalles);

    delete[] detalles;
}
void VentaManager::consultarPorCliente(){

    int idCliente;

    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;

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
}

void VentaManager::consultarPorEmpleado(){

    int idEmpleado;

    cout << "Ingrese el ID del empleado: ";
    cin >> idEmpleado;

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
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para esa fecha." << endl;
    }

    delete[] detalles;
}

void VentaManager::consultarPorEquipo(){

    int idEquipo;

    cout << "Ingrese el ID del equipo: ";
    cin >> idEquipo;

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

        if(venta.getEstado()){

            int cantidadEncontrados = 0;
            _archivoDetalleVentas.leerPorIdVenta(venta.getIdVenta(), detalles, cantidadEncontrados);

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
}

const char* VentaManager::obtenerNombreMarca(int idMarca){
    TipoMarca marca = _archivoTipoMarcas.leer(idMarca);

    if(marca.getIdTipoMarca() == 0){
        return "Marca no encontrada";
    }

    return marca.getDescripcion();
}

const char* VentaManager::obtenerNombreTipoEquipo(int idTipoEquipo){
    TipoEquipo tipo = _archivoTipoEquipos.leer(idTipoEquipo);

    if(tipo.getIdTipoEquipo() == 0){
        return "Tipo no encontrado";
    }

    return tipo.getDescripcion();
}

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
