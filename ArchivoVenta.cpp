#include <iostream>
#include <cstdio>
#include "ArchivoVenta.h"

ArchivoVenta::ArchivoVenta() {
    ruta = "ventas.dat";
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

bool ArchivoVenta::borrarRegistro(int id) {
    int pos = buscar(id);

    if (pos == -1) {
        return false;
    }

    FILE *p = fopen(ruta.c_str(), "rb+");
    if (p == NULL) {
        return false;
    }

    Venta aux;
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fread(&aux, sizeof(Venta), 1, p);

    aux.setEstado(false); // Baja lógica

    fseek(p, pos * sizeof(Venta), SEEK_SET);
    bool pudoEscribir = fwrite(&aux, sizeof(Venta), 1, p);

    fclose(p);
    return pudoEscribir;
}

void ArchivoVenta::vaciar() {
    FILE *p = fopen(ruta.c_str(), "wb");
    if (p != NULL) {
        fclose(p);
    }
}
