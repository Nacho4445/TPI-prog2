#include <iostream>
#include "negocio/InformeManager.h"
#include "archivos/ArchivoCliente.h"
#include "archivos/ArchivoEmpleado.h"
#include "archivos/ArchivoEquipo.h"
#include "archivos/ArchivoVenta.h"
#include "modelos/RecaudacionAnual.h"
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

        cout << "Anio: " << anio
             << " - Recaudacion: $" << recaudacion << endl;
        RecaudacionAnual reg(recaudacion, anio);
        fwrite(&reg, sizeof(RecaudacionAnual), 1, p);
    }
    fclose(p);
}

void InformeManager::recaudacionXcliente(){

}

void InformeManager::equiposMasVendidos(){

}

void InformeManager::ventasXempleado(){

}

void InformeManager::stockDisponible(){

}
