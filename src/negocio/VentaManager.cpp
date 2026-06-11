#include <iostream>
#include "../modelos/Venta.h"
#include "VentaManager.h"
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

        int idEquipo;
        int cantidad;

        cout << "-- Equipo " << i + 1 << " --" << endl;
        cout << "ID Equipo: ";
        cin >> idEquipo;

        Equipo equipo = _archivoEquipos.leer(idEquipo);

        if(equipo.getIdEquipo() == 0){
            cout << "No existe un equipo activo con ese ID." << endl;
            continue;
        }

        cout << "Cantidad: ";
        cin >> cantidad;

        if(cantidad <= 0){
            cout << "La cantidad debe ser mayor a cero." << endl;
            continue;
        }

        if(cantidad > equipo.getStock()){
            cout << "Sin stock suficiente. Stock disponible: " << equipo.getStock() << endl;
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


void VentaManager::consultarPorId(){

    int idVenta;
    Venta venta;

    while(true){
        cout << "Ingrese el ID de la venta (0 para volver): ";
        cin >> idVenta;

        if(idVenta == 0){
            return;
        }

        venta = _archivoVentas.leer(idVenta);

        if(venta.getEstado()){
            mostrarVenta(venta);
            return;
        }

        cout << "Venta no encontrada. Intente nuevamente." << endl;
    }
}

void VentaManager::consultarPorCliente(){

    int idCliente;
    Venta venta;
    bool encontro = false;
    int cantidad = _archivoVentas.getCantidadRegistros();

    cout << "Ingrese ID del cliente: ";
    cin >> idCliente;

    for(int i = 0; i < cantidad; i++){
        venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado() && venta.getIdCliente() == idCliente){
            mostrarVenta(venta);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para ese cliente." << endl;
    }
}

void VentaManager::consultarPorEmpleado(){

    int idEmpleado;
    Venta venta;
    bool encontro = false;
    int cantidad = _archivoVentas.getCantidadRegistros();

    cout << "Ingrese ID del empleado: ";
    cin >> idEmpleado;

    for(int i = 0; i < cantidad; i++){
        venta = _archivoVentas.leerPorPosicion(i);

        if(venta.getEstado() && venta.getIdEmpleado() == idEmpleado){
            mostrarVenta(venta);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para ese empleado." << endl;
    }
}

void VentaManager::consultarPorFecha(){

    int dia, mes, anio;
    Venta venta;
    bool encontro = false;
    int cantidad = _archivoVentas.getCantidadRegistros();

    cout << "Dia: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Anio: ";
    cin >> anio;

    for(int i = 0; i < cantidad; i++){
        venta = _archivoVentas.leerPorPosicion(i);

        Fecha fecha = venta.getFecha();

        if(venta.getEstado() &&
           fecha.getDia() == dia &&
           fecha.getMes() == mes &&
           fecha.getAnio() == anio){

            mostrarVenta(venta);
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas en esa fecha." << endl;
    }
}

void VentaManager::consultarPorEquipo(){

    int idEquipo;
    bool encontro = false;

    ArchivoDetalleVenta archivoDetalles;

    int cantidadDetalles = archivoDetalles.getCantidadRegistros();

    cout << "Ingrese ID del equipo vendido: ";
    cin >> idEquipo;

    for(int i = 0; i < cantidadDetalles; i++){

        DetalleVenta detalle = archivoDetalles.leerPorPosicion(i);

        if(detalle.getEstado() && detalle.getIdEquipo() == idEquipo){

            Venta venta = _archivoVentas.leer(detalle.getIdVenta());

            if(venta.getEstado()){
                mostrarVenta(venta);
                cout << endl;
                encontro = true;
            }
        }
    }

    if(!encontro){
        cout << "No se encontraron ventas para ese equipo." << endl;
    }
}

void VentaManager::listarVentas(){

    int cantidadRegistros = _archivoVentas.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay ventas cargadas." << endl;
        return;
    }

    for(int i = 1; i <= cantidadRegistros; i++){

        Venta venta = _archivoVentas.leer(i);

        if(venta.getEstado()){
            mostrarVenta(venta);
            cout << endl;
        }
    }
}

void VentaManager::mostrarVenta(Venta &reg){

    cout << "==================================" << endl;
    cout << "ID Venta: " << reg.getIdVenta() << endl;
    cout << "ID Cliente: " << reg.getIdCliente() << endl;
    cout << "ID Empleado: " << reg.getIdEmpleado() << endl;
    cout << "Fecha: " << reg.getFecha().toString() << endl;
    cout << "Importe Total: $" << reg.getImporteTotal() << endl;
    cout << "==================================" << endl;
}

void VentaManager::modificarVenta(){

    int idVenta;

    cout << "Ingrese el ID de la venta a modificar: ";
    cin >> idVenta;

    int pos = _archivoVentas.buscar(idVenta);

    if(pos == -1){
        cout << "No existe una venta activa con ese ID." << endl;
        return;
    }

    Venta ventaActual = _archivoVentas.leer(idVenta);

    cout << "Venta actual:" << endl;
    mostrarVenta(ventaActual);

    cout << "Ingrese los nuevos datos de la venta." << endl;

    Venta ventaModificada = crearVenta();
    ventaModificada.setIdVenta(idVenta);

    if(_archivoVentas.borrarRegistro(idVenta) &&
       _archivoVentas.guardar(ventaModificada)){

        cout << "Venta modificada correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar la venta." << endl;
    }
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

    for(int i = 1; i <= cantidadRegistros; i++){

        Venta venta = _archivoVentas.leer(i);

        if(venta.getEstado()){
            ventas[cantidadActivas] = venta;
            cantidadActivas++;
        }
    }

    ordenarVentas(ventas, cantidadActivas);

    for(int i = 0; i < cantidadActivas; i++){
        mostrarVenta(ventas[i]);
        cout << endl;
    }

    delete[] ventas;
}

void VentaManager::eliminarVenta(){

    int idVenta;

    cout << "Ingrese el ID de la venta a eliminar: ";
    cin >> idVenta;

    if(_archivoVentas.borrarRegistro(idVenta)){
        cout << "Venta eliminada correctamente." << endl;
    }
    else{
        cout << "No existe una venta activa con ese ID." << endl;
    }
}
