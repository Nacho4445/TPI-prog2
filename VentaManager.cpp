#include <iostream>
#include "Venta.h"
#include "VentaManager.h"
using namespace std;

VentaManager::VentaManager()
   : _archivoVentas(){}

Venta VentaManager::crearVenta(){

    Venta venta;

    int idVenta;
    int idCliente;
    int idEmpleado;
    int dia, mes, anio;
    double importeTotal;

    idVenta = _archivoVentas.getCantidadRegistros() + 1;

    cout << "Ingrese los siguientes datos:" << endl;

    cout << "ID Cliente: ";
    cin >> idCliente;

    cout << "ID Empleado: ";
    cin >> idEmpleado;

    cout << "Dia: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Anio: ";
    cin >> anio;

    Fecha fecha(dia, mes, anio);

    cout << "Importe total: ";
    cin >> importeTotal;

    venta.setIdVenta(idVenta);
    venta.setIdCliente(idCliente);
    venta.setIdEmpleado(idEmpleado);
    venta.setFecha(fecha);
    venta.setImporteTotal(importeTotal);
    venta.setEstado(true);

    return venta;
}

void VentaManager::guardarVenta(){

    Venta venta = crearVenta();

    if(_archivoVentas.guardar(venta)){
        cout << "Venta guardada correctamente." << endl;
    }
    else{
        cout << "Error al guardar la venta." << endl;
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

void VentaManager::mostrarVenta(const Venta &reg){

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
