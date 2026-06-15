#include <iostream>
#include "negocio/InformeManager.h"
#include "archivos/ArchivoCliente.h"
#include "archivos/ArchivoEmpleado.h"
#include "archivos/ArchivoEquipo.h"
#include "archivos/ArchivoVenta.h"
#include "modelos/RecaudacionAnual.h"
#include "modelos/RecaudacionClientes.h"
#include "modelos/StockEquipos.h"
using namespace std;

void InformeManager::recaudacionXanio(){
    ArchivoVenta repoVentas;
    int cantidadVentas = repoVentas.getCantidadRegistros();
    int anioMin = 9999;
    int anioMax = 0;

    for(int i=0; i<cantidadVentas; i++){
        Venta venta = repoVentas.leerPorPosicion(i);
        if(venta.getEstado()==true){
            int anio = venta.getFecha().getAnio();
                if(anio < anioMin)
                    anioMin = anio;

                if(anio > anioMax)
                    anioMax = anio;

        }
    }

    if (anioMin == 9999) {
        cout << "No hay ventas activas" << endl;
        return;
    }

    FILE *p = fopen("informes/recaudacionAnual.dat", "wb");

    if(p == nullptr){
        cout << "Error de informe..." << endl;
        return;
    }


    for(int anio = anioMin; anio <= anioMax; anio++) {
    float recaudacion = 0;

        for(int i = 0; i < cantidadVentas; i++) {
            Venta venta = repoVentas.leerPorPosicion(i);
            if(venta.getFecha().getAnio() == anio && venta.getEstado()==true) {
                recaudacion += venta.getImporteTotal();
            }
        }
        cout << "------------------------" << endl;
        cout << "Anio: " << anio << endl;
        cout << "Recaudacion: $" << recaudacion << endl;
        cout << "------------------------" << endl;

        RecaudacionAnual reg(recaudacion, anio);
        fwrite(&reg, sizeof(RecaudacionAnual), 1, p);
    }
    fclose(p);
}

void InformeManager::recaudacionXcliente(){
    ArchivoCliente repoClientes;
    int cantidadClientes = repoClientes.getCantidadRegistros();

    float* pClientes = nullptr;
    pClientes = new float[cantidadClientes]{};

    if(pClientes == nullptr){
        cout << "Error de memoria..." << endl;
        return;
    }

    ArchivoVenta repoVentas;
    int cantidadVentas = repoVentas.getCantidadRegistros();

    for(int i=0; i<cantidadVentas; i++){
        Venta venta = repoVentas.leerPorPosicion(i);
        if(venta.getEstado() == true){
            int pos = repoClientes.buscar(venta.getIdCliente());
                if(pos >= 0){
                    pClientes[pos] += venta.getImporteTotal();
                }
            }
        }

    FILE *p = fopen("informes/recaudacionXcliente.dat", "wb");

    if(p == nullptr){
        cout << "Error de informe..." << endl;
        return;
    }

    for(int i = 0; i < cantidadClientes; i++){
        Cliente regCliente = repoClientes.leerPorPosicion(i);

        if(regCliente.getEstado()){
            RecaudacionClientes regRecaudacion(pClientes[i], regCliente);
            fwrite(&regRecaudacion, sizeof(RecaudacionClientes), 1, p);//deberiamos guardar la recaudacion aunque el cliente este eliminado? Si>poner la escritura fuera del if
            cout << "------------------------" << endl;
            cout << "Cliente ID: " << regCliente.getIdCliente() << endl;
            cout << "Recaudacion: $" << pClientes[i] << endl;
            cout << "------------------------" << endl;
        }
    }

    fclose(p);
    delete[] pClientes;
}

void InformeManager::equiposMasVendidos(){

}

void InformeManager::ventasXempleado(){

}

void InformeManager::stockDisponible(){
    Equipo regEquipo;
    ArchivoEquipo repoEquipos;
    bool encontro = false;
    int cantidad = repoEquipos.getCantidadEquipos();


    FILE *p = fopen("informes/stockDisponible.dat", "wb");

    if(p == nullptr){
        cout << "Error de informe..." << endl;
        return;
    }

    for(int i = 0; i < cantidad; i++){
        regEquipo = repoEquipos.leerPorPosicion(i);
        int stock = regEquipo.getStock();
        if(regEquipo.getEstado() && stock > 0){
            cout << "------------------------" << endl;
            cout << "Equipo ID: " << regEquipo.getIdEquipo() << endl;
            cout << "Stock disponible: " << stock << endl;
            cout << "------------------------" << endl;

            StockEquipos regStock(regEquipo, stock);
            fwrite(&regStock, sizeof(StockEquipos), 1, p);

            encontro = true;
        }
    }

    if(!encontro){
        cout << "No hay equipos con stock disponible." << endl;
    }

    fclose(p);

}
