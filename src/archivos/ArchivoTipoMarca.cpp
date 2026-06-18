#include "archivos/ArchivoTipoMarca.h"

ArchivoTipoMarca::ArchivoTipoMarca() {
    _ruta = "datos/tiposMarcas.dat";
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

TipoMarca ArchivoTipoMarca::leerPorPosicion(int posicion){

    TipoMarca reg;

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return reg;
    }

    fseek(p, posicion * sizeof(TipoMarca), SEEK_SET);

    fread(&reg, sizeof(TipoMarca), 1, p);

    fclose(p);

    return reg;
}
int ArchivoTipoMarca::generarNuevoId(){

    FILE *pArchivo = fopen(_ruta.c_str(), "rb");

    if(pArchivo == nullptr){
        return 1;
    }

    TipoMarca tipo;
    int maxId = 0;

    while(fread(&tipo, sizeof(TipoMarca), 1, pArchivo) == 1){

        if(tipo.getIdTipoMarca() > maxId){
            maxId = tipo.getIdTipoMarca();
        }
    }

    fclose(pArchivo);

    return maxId + 1;
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

            fseek(pArchivo, -(long)sizeof(TipoMarca), SEEK_CUR);

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

bool ArchivoTipoMarca::exportarDatosCSV(FILE *pBinario, FILE *pCSV) {
    // cabecera
    fprintf(pCSV, "ID Tipo Marca, Descripcion, Estado\n");

    TipoMarca reg;

    while (fread(&reg, sizeof(TipoMarca), 1, pBinario) == 1) {
        fprintf(pCSV, "%d,%s,%s\n",
            reg.getIdTipoMarca(),
            reg.getDescripcion(),
            reg.getEstado() ? "activo" : "inactivo");
    }
    return true;
}

