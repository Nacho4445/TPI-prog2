#include "archivos/ArchivoTipoEquipo.h"

ArchivoTipoEquipo::ArchivoTipoEquipo() {
    _ruta = "datos/tiposEquipos.dat";
}

int ArchivoTipoEquipo::getCantidadTipos() {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);
    int cantidadBytes = ftell(pArchivo);

    fclose(pArchivo);

    return cantidadBytes / sizeof(TipoEquipo);
}

bool ArchivoTipoEquipo::guardar(TipoEquipo tipo) {
    FILE* pArchivo = fopen(_ruta.c_str(), "ab");

    if (pArchivo == nullptr) {
        return false;
    }

    bool pudoGuardar = fwrite(&tipo, sizeof(TipoEquipo), 1, pArchivo);

    fclose(pArchivo);

    return pudoGuardar;
}

int ArchivoTipoEquipo::getPosicion(int idTipoEquipo) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return -1;
    }

    TipoEquipo tipo;
    int posicion = 0;

    while (fread(&tipo, sizeof(TipoEquipo), 1, pArchivo) == 1) {

        if (tipo.getIdTipoEquipo() == idTipoEquipo && tipo.getEstado()) {
            fclose(pArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(pArchivo);
    return -1;
}

TipoEquipo ArchivoTipoEquipo::leer(int idTipoEquipo) {
    TipoEquipo tipo;

    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return tipo;
    }

    while (fread(&tipo, sizeof(TipoEquipo), 1, pArchivo) == 1) {

        if (tipo.getIdTipoEquipo() == idTipoEquipo && tipo.getEstado()) {
            fclose(pArchivo);
            return tipo;
        }
    }

    fclose(pArchivo);
    return TipoEquipo();
}

TipoEquipo ArchivoTipoEquipo::leerPorPosicion(int posicion){

    TipoEquipo reg;

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return reg;
    }

    fseek(p, posicion * sizeof(TipoEquipo), SEEK_SET);

    fread(&reg, sizeof(TipoEquipo), 1, p);

    fclose(p);

    return reg;
}

int ArchivoTipoEquipo::generarNuevoId(){

    FILE *pArchivo = fopen(_ruta.c_str(), "rb");

    if(pArchivo == nullptr){
        return 1;
    }

    TipoEquipo tipo;
    int maxId = 0;

    while(fread(&tipo, sizeof(TipoEquipo), 1, pArchivo) == 1){

        if(tipo.getIdTipoEquipo() > maxId){
            maxId = tipo.getIdTipoEquipo();
        }
    }

    fclose(pArchivo);

    return maxId + 1;
}

bool ArchivoTipoEquipo::borrarRegistro(int idTipoEquipo) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb+");

    if (pArchivo == nullptr) {
        return false;
    }

    TipoEquipo tipo;

    while (fread(&tipo, sizeof(TipoEquipo), 1, pArchivo) == 1) {

        if (tipo.getIdTipoEquipo() == idTipoEquipo && tipo.getEstado()) {

            tipo.setEstado(false);

            fseek(pArchivo, -(long)sizeof(TipoEquipo), SEEK_CUR);

            bool pudoModificar = fwrite(&tipo, sizeof(TipoEquipo), 1, pArchivo);

            fclose(pArchivo);
            return pudoModificar;
        }
    }

    fclose(pArchivo);
    return false;
}

void ArchivoTipoEquipo::vaciar() {
    FILE* pArchivo = fopen(_ruta.c_str(), "wb");

    if (pArchivo != nullptr) {
        fclose(pArchivo);
    }
}

bool ArchivoTipoEquipo::exportarDatosCSV(FILE *pBinario, FILE *pCSV) {
    // cabecera
    fprintf(pCSV, "ID Tipo Equipo, Descripcion, Estado\n");

    TipoEquipo reg;

    while (fread(&reg, sizeof(TipoEquipo), 1, pBinario) == 1) {
        fprintf(pCSV, "%d,%s,%s\n",
            reg.getIdTipoEquipo(),
            reg.getDescripcion(),
            reg.getEstado() ? "activo" : "inactivo");
    }
    return true;
}
