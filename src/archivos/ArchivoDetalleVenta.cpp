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

void ArchivoDetalleVenta::leerPorIdVenta(int idVenta, DetalleVenta *detalles, int &cantidad) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb");
    DetalleVenta detalleVenta;
    cantidad = 0;

    if (pArchivo == nullptr) {
        return;
    }

    while (fread(&detalleVenta, sizeof(DetalleVenta), 1, pArchivo) == 1) {
        if (detalleVenta.getIdVenta() == idVenta && detalleVenta.getEstado()) {
            detalles[cantidad] = detalleVenta;
            cantidad++;
        }
    }

    fclose(pArchivo);
}
