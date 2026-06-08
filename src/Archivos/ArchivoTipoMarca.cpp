#include "Archivos/ArchivoTipoMarca.h"

ArchivoTipoMarca::ArchivoTipoMarca() {
    _ruta = "tiposMarcas.dat";
}

int ArchivoTipoMarca::getCantidadTipos() {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);
    int cantidadBytes = ftell(pArchivo);

    fclose(pArchivo);

    return cantidadBytes / sizeof(TipoMarca);
}

bool ArchivoTipoMarca::guardar(TipoMarca tipo) {
    FILE* pArchivo = fopen(_ruta.c_str(), "ab");

    if (pArchivo == nullptr) {
        return false;
    }

    bool pudoGuardar = fwrite(&tipo, sizeof(TipoMarca), 1, pArchivo);

    fclose(pArchivo);

    return pudoGuardar;
}

int ArchivoTipoMarca::getPosicion(int idTipoMarca) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return -1;
    }

    TipoMarca tipo;
    int posicion = 0;

    while (fread(&tipo, sizeof(TipoMarca), 1, pArchivo) == 1) {

        if (tipo.getIdTipoMarca() == idTipoMarca && tipo.getEstado()) {
            fclose(pArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(pArchivo);
    return -1;
}

TipoMarca ArchivoTipoMarca::leer(int idTipoMarca) {
    TipoMarca tipo;

    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return tipo;
    }

    while (fread(&tipo, sizeof(TipoMarca), 1, pArchivo) == 1) {

        if (tipo.getIdTipoMarca() == idTipoMarca && tipo.getEstado()) {
            fclose(pArchivo);
            return tipo;
        }
    }

    fclose(pArchivo);
    return TipoMarca();
}

bool ArchivoTipoMarca::borrarRegistro(int idTipoMarca) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb+");

    if (pArchivo == nullptr) {
        return false;
    }

    TipoMarca tipo;

    while (fread(&tipo, sizeof(TipoMarca), 1, pArchivo) == 1) {

        if (tipo.getIdTipoMarca() == idTipoMarca && tipo.getEstado()) {

            tipo.setEstado(false);

            fseek(pArchivo, -sizeof(TipoMarca), SEEK_CUR);

            bool pudoModificar = fwrite(&tipo, sizeof(TipoMarca), 1, pArchivo);

            fclose(pArchivo);
            return pudoModificar;
        }
    }

    fclose(pArchivo);
    return false;
}

void ArchivoTipoMarca::vaciar() {
    FILE* pArchivo = fopen(_ruta.c_str(), "wb");

    if (pArchivo != nullptr) {
        fclose(pArchivo);
    }
}
