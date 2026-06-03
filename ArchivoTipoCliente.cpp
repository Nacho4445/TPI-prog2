#include <iostream>
#include <cstdio>
#include "ArchivoTipoCliente.h"

ArchivoTipoCliente::ArchivoTipoCliente() {
    ruta = "tipos_clientes.dat";
}

ArchivoTipoCliente::ArchivoTipoCliente(std::string _ruta) {
    ruta = _ruta;
}

int ArchivoTipoCliente::getCantidadRegistros() {
    FILE *p = fopen(ruta.c_str(), "rb");

    if (p == NULL) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(TipoCliente);
}

bool ArchivoTipoCliente::guardar(TipoCliente reg) {
    FILE *p = fopen(ruta.c_str(), "ab");

    if (p == NULL) {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(TipoCliente), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoTipoCliente::buscar(int id) {
    FILE *p = fopen(ruta.c_str(), "rb");
    if (p == NULL) return -1;

    TipoCliente aux;
    int numReg = 0;

    while (fread(&aux, sizeof(TipoCliente), 1, p) == 1) {
        if (aux.getIdTipoCliente() == id && aux.getEstado() == true) {
            fclose(p);
            return numReg;
        }
        numReg++;
    }

    fclose(p);
    return -1;
}

TipoCliente ArchivoTipoCliente::leer(int id) {
    TipoCliente aux;

    int pos = buscar(id);

    if (pos == -1) {
        return aux;
    }

    FILE *p = fopen(ruta.c_str(), "rb");
    if (p == NULL) {
        return aux;
    }

    fseek(p, pos * sizeof(TipoCliente), SEEK_SET);
    fread(&aux, sizeof(TipoCliente), 1, p);

    fclose(p);
    return aux;
}

bool ArchivoTipoCliente::borrarRegistro(int id) {
    int pos = buscar(id);

    if (pos == -1) {
        return false;
    }

    FILE *p = fopen(ruta.c_str(), "rb+");
    if (p == NULL) {
        return false;
    }

    TipoCliente aux;
    fseek(p, pos * sizeof(TipoCliente), SEEK_SET);
    fread(&aux, sizeof(TipoCliente), 1, p);

    aux.setEstado(false); // Baja lógica

    fseek(p, pos * sizeof(TipoCliente), SEEK_SET);
    bool pudoEscribir = fwrite(&aux, sizeof(TipoCliente), 1, p);

    fclose(p);
    return pudoEscribir;
}

void ArchivoTipoCliente::vaciar() {
    FILE *p = fopen(ruta.c_str(), "wb");
    if (p != NULL) {
        fclose(p);
    }
}
