#include "archivos/ArchivoEquipo.h"

ArchivoEquipo::ArchivoEquipo() {
    _ruta = "datos/equipos.dat";
}

int ArchivoEquipo::getCantidadEquipos() {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);
    int cantidadBytes = ftell(pArchivo);

    fclose(pArchivo);

    return cantidadBytes / sizeof(Equipo);
}

bool ArchivoEquipo::guardar(Equipo equipo) {
    FILE* pArchivo = fopen(_ruta.c_str(), "ab");

    if (pArchivo == nullptr) {
        return false;
    }

    bool pudoGuardar = fwrite(&equipo, sizeof(Equipo), 1, pArchivo);

    fclose(pArchivo);

    return pudoGuardar;
}

int ArchivoEquipo::getPosicion(int idEquipo) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return -1;
    }

    Equipo equipo;
    int posicion = 0;

    while (fread(&equipo, sizeof(Equipo), 1, pArchivo) == 1) {

        if (equipo.getIdEquipo() == idEquipo && equipo.getEstado()) {
            fclose(pArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(pArchivo);

    return -1;
}

Equipo ArchivoEquipo::leer(int idEquipo) {
    Equipo equipo;

    FILE* pArchivo = fopen(_ruta.c_str(), "rb");

    if (pArchivo == nullptr) {
        return equipo;
    }

    while (fread(&equipo, sizeof(Equipo), 1, pArchivo) == 1) {

        if (equipo.getIdEquipo() == idEquipo && equipo.getEstado()) {
            fclose(pArchivo);
            return equipo;
        }
    }

    fclose(pArchivo);

    return Equipo();
}

Equipo ArchivoEquipo::leerPorPosicion(int posicion){

    Equipo equipo;

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return equipo;
    }

    fseek(p, posicion * sizeof(Equipo), SEEK_SET);

    fread(&equipo, sizeof(Equipo), 1, p);

    fclose(p);

    return equipo;
}

bool ArchivoEquipo::modificar(Equipo equipo) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb+");

    if (pArchivo == nullptr) {
        return false;
    }

    Equipo aux;

    while (fread(&aux, sizeof(Equipo), 1, pArchivo) == 1) {

        if (aux.getIdEquipo() == equipo.getIdEquipo() && aux.getEstado()) {

            fseek(pArchivo, -sizeof(Equipo), SEEK_CUR);

            bool pudoModificar = fwrite(&equipo, sizeof(Equipo), 1, pArchivo);

            fclose(pArchivo);
            return pudoModificar;
        }
    }

    fclose(pArchivo);
    return false;
}

bool ArchivoEquipo::borrarRegistro(int idEquipo) {
    FILE* pArchivo = fopen(_ruta.c_str(), "rb+");

    if (pArchivo == nullptr) {
        return false;
    }

    Equipo equipo;

    while (fread(&equipo, sizeof(Equipo), 1, pArchivo) == 1) {

        if (equipo.getIdEquipo() == idEquipo && equipo.getEstado()) {

            equipo.setEstado(false);

            fseek(pArchivo, -sizeof(Equipo), SEEK_CUR);

            bool pudoModificar = fwrite(&equipo, sizeof(Equipo), 1, pArchivo);

            fclose(pArchivo);
            return pudoModificar;
        }
    }

    fclose(pArchivo);

    return false;
}

void ArchivoEquipo::vaciar() {
    FILE* pArchivo = fopen(_ruta.c_str(), "wb");

    if (pArchivo != nullptr) {
        fclose(pArchivo);
    }
}
