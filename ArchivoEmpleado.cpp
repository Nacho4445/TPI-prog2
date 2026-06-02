#include <iostream>
#include "ArchivoEmpleado.h"

ArchivoEmpleado::ArchivoEmpleado(){
  ruta = "empleados.dat";
}

ArchivoEmpleado::ArchivoEmpleado(std::string _ruta){
  ruta = _ruta;
}

int ArchivoEmpleado::getCantidadRegistros(){
  FILE *p = fopen(ruta.c_str(), "rb");

  if (p == NULL){
    return 0;
  }

  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);

  return bytes / sizeof(Empleado);
}

bool ArchivoEmpleado::guardar(Empleado reg){
  FILE *p = fopen(ruta.c_str(), "ab");

  if (p == NULL){
    return false;
  }

  bool pudoEscribir = fwrite(&reg, sizeof(Empleado), 1, p);
  fclose(p);
  return pudoEscribir;
}

int ArchivoEmpleado::buscar(int id){
  FILE *p = fopen(ruta.c_str(), "rb");
  if (p == NULL) return -1;

  Empleado aux;
  int numReg = 0;

  while (fread(&aux, sizeof(Empleado), 1, p) == 1) {
    if (aux.getIdEmpleado() == id && aux.getEstado() == true) {
      fclose(p);
      return numReg;
    }
    numReg++;
  }

  fclose(p);
  return -1;
}

Empleado ArchivoEmpleado::leer(int id){
  Empleado aux;

  int pos = buscar(id);

  if (pos == -1){
        return aux;
  }

  FILE *p = fopen(ruta.c_str(), "rb");
  if (p == NULL){
    return aux;
  }

  fseek(p, pos * sizeof(Empleado), SEEK_SET);
  fread(&aux, sizeof(Empleado), 1, p);

  fclose(p);
  return aux;
}

bool ArchivoEmpleado::borrarRegistro(int id){
  Empleado aux;

  int pos = buscar(id);

  if (pos == -1){
    return false;
  }

  FILE *p = fopen(ruta.c_str(), "rb+");
  if (p == NULL){
    return false;
  }

  fseek(p, pos * sizeof(Empleado), SEEK_SET);
  fread(&aux, sizeof(Empleado), 1, p);
  aux.setEstado(false);

  fseek(p, pos * sizeof(Empleado), SEEK_SET);
  bool pudoEscribir = fwrite(&aux, sizeof(Empleado), 1, p);

  fclose(p);
  return pudoEscribir;
}

void ArchivoEmpleado::vaciar(){
  FILE *p = fopen(ruta.c_str(), "wb");
  if (p == NULL){
    return ;
  }
  fclose(p);
}
