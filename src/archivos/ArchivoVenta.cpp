#include <iostream>
#include <cstdio>
#include "archivos/ArchivoVenta.h"

ArchivoVenta::ArchivoVenta() {
    ruta = "datos/ventas.dat";
}

ArchivoVenta::ArchivoVenta(std::string _ruta) {
    ruta = _ruta;
}

int ArchivoVenta::getCantidadRegistros() {
    FILE *p = fopen(ruta.c_str(), "rb");

    if (p == NULL) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Venta);
}

bool ArchivoVenta::guardar(Venta reg) {
    FILE *p = fopen(ruta.c_str(), "ab");

    if (p == NULL) {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoVenta::buscar(int id) {
    FILE *p = fopen(ruta.c_str(), "rb");
    if (p == NULL) return -1;

    Venta aux;
    int numReg = 0;

    while (fread(&aux, sizeof(Venta), 1, p) == 1) {
        if (aux.getIdVenta() == id && aux.getEstado() == true) {
            fclose(p);
            return numReg;
        }
        numReg++;
    }

    fclose(p);
    return -1;
}

int ArchivoVenta::buscarIncluyendoCanceladas(int id){

    FILE *p = fopen(ruta.c_str(), "rb");

    if(p == NULL){
        return -1;
    }

    Venta aux;
    int numReg = 0;

    while(fread(&aux, sizeof(Venta), 1, p) == 1){

        if(aux.getIdVenta() == id){
            fclose(p);
            return numReg;
        }

        numReg++;
    }

    fclose(p);
    return -1;
}

Venta ArchivoVenta::leer(int id) {
    Venta aux;

    int pos = buscar(id);

    if (pos == -1) {
        return aux;
    }

    FILE *p = fopen(ruta.c_str(), "rb");
    if (p == NULL) {
        return aux;
    }

    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fread(&aux, sizeof(Venta), 1, p);

    fclose(p);
    return aux;
}

Venta ArchivoVenta::leerIncluyendoCanceladas(int id){

    Venta aux;

    int pos = buscarIncluyendoCanceladas(id);

    if(pos == -1){
        return aux;
    }

    FILE *p = fopen(ruta.c_str(), "rb");

    if(p == NULL){
        return aux;
    }

    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fread(&aux, sizeof(Venta), 1, p);

    fclose(p);

    return aux;
}

Venta ArchivoVenta::leerPorPosicion(int posicion){

    Venta reg;

    FILE *p = fopen(ruta.c_str(), "rb");

    if(p == NULL){
        return reg;
    }

    fseek(p, posicion * sizeof(Venta), SEEK_SET);

    fread(&reg, sizeof(Venta), 1, p);

    fclose(p);

    return reg;
}

bool ArchivoVenta::cancelarVenta(int idVenta){

    Venta venta;

    int pos = buscar(idVenta);

    if(pos == -1){
        return false;
    }

    FILE *p = fopen(ruta.c_str(), "rb+");

    if(p == NULL){
        return false;
    }

    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fread(&venta, sizeof(Venta), 1, p);

    venta.setEstado(false);

    fseek(p, pos * sizeof(Venta), SEEK_SET);
    bool escribio = fwrite(&venta, sizeof(Venta), 1, p);

    fclose(p);

    return escribio;
}

bool ArchivoVenta::borrarRegistro(int id){

    Venta venta;

    int pos = buscar(id);

    if(pos == -1){
        return false;
    }

    FILE *p = fopen(ruta.c_str(), "rb+");

    if(p == NULL){
        return false;
    }

    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fread(&venta, sizeof(Venta), 1, p);

    venta.setEstado(false);

    fseek(p, pos * sizeof(Venta), SEEK_SET);
    bool escribio = fwrite(&venta, sizeof(Venta), 1, p);

    fclose(p);

    return escribio;
}
void ArchivoVenta::vaciar(){

    FILE *p = fopen(ruta.c_str(), "wb");

    if(p == NULL){
        return;
    }

    fclose(p);
}
