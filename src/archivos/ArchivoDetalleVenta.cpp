#include "archivos/ArchivoDetalleVenta.h"

ArchivoDetalleVenta::ArchivoDetalleVenta() {
    _ruta = "datos/detalleVentas.dat";
}

int ArchivoDetalleVenta::getCantidadRegistros() {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);
    int cantidadBytes = ftell(pArchivo);
    fclose(pArchivo);

    return cantidadBytes / sizeof(DetalleVenta);
}

bool ArchivoDetalleVenta::guardar(DetalleVenta detalleVenta) {
    FILE* pArchivo = fopen(_ruta.c_str(), "ab");

    if (pArchivo == nullptr) {
        return false;
    }

    bool pudoGuardar = fwrite(&detalleVenta, sizeof(DetalleVenta), 1, pArchivo);
    fclose(pArchivo);

    return pudoGuardar;
}

DetalleVenta ArchivoDetalleVenta::leer(int idDetalleVenta) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb");
    DetalleVenta detalleVenta;

    if (pArchivo == nullptr) {
        return detalleVenta;
    }

    while (fread(&detalleVenta, sizeof(DetalleVenta), 1, pArchivo) == 1) {
        if (detalleVenta.getIdDetalleVenta() == idDetalleVenta && detalleVenta.getEstado()) {
            fclose(pArchivo);
            return detalleVenta;
        }
    }

    fclose(pArchivo);
    return DetalleVenta();
}

DetalleVenta ArchivoDetalleVenta::leerPorPosicion(int posicion){

    DetalleVenta detalleVenta;

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return detalleVenta;
    }

    fseek(p, posicion * sizeof(DetalleVenta), SEEK_SET);

    fread(&detalleVenta, sizeof(DetalleVenta), 1, p);

    fclose(p);

    return detalleVenta;
}

bool ArchivoDetalleVenta::borrarRegistro(int idDetalleVenta) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb+");
    DetalleVenta detalleVenta;

    if (pArchivo == nullptr) {
        return false;
    }

    while (fread(&detalleVenta, sizeof(DetalleVenta), 1, pArchivo) == 1) {
        if (detalleVenta.getIdDetalleVenta() == idDetalleVenta && detalleVenta.getEstado()) {
            detalleVenta.setEstado(false);

            fseek(pArchivo, -sizeof(DetalleVenta), SEEK_CUR);
            bool pudoModificar = fwrite(&detalleVenta, sizeof(DetalleVenta), 1, pArchivo);

            fclose(pArchivo);
            return pudoModificar;
        }
    }

    fclose(pArchivo);
    return false;
}

void ArchivoDetalleVenta::vaciar() {
    FILE* pArchivo = fopen(_ruta.c_str(), "wb");

    if (pArchivo != nullptr) {
        fclose(pArchivo);
    }
}
