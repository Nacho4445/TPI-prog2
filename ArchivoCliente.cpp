#include <iostream>
#include "ArchivoCliente.h"

ArchivoCliente::ArchivoCliente(){
  ruta = "clientes.dat";
}

ArchivoCliente::ArchivoCliente(std::string _ruta){
  ruta = _ruta;
}

int ArchivoCliente::getCantidadRegistros(){
  FILE *p = fopen(ruta.c_str(), "rb");

  if (p == NULL){
    return 0;
  }

  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);

  return bytes / sizeof(Cliente);
}

bool ArchivoCliente::guardar(Cliente reg){
  FILE *p = fopen(ruta.c_str(), "ab");

  if (p == NULL){
    return false;
  }

  bool pudoEscribir = fwrite(&reg, sizeof(Cliente), 1, p);
  fclose(p);
  return pudoEscribir;
}

int ArchivoCliente::buscar(int id){
  FILE *p = fopen(ruta.c_str(), "rb");
  if (p == NULL) return -1;

  Cliente aux;
  int numReg = 0;

  while (fread(&aux, sizeof(Cliente), 1, p) == 1) {
    if (aux.getIdCliente() == id && aux.getEstado() == true) {
      fclose(p);
      return numReg;
    }
    numReg++;
  }

  fclose(p);
  return -1;
}

Cliente ArchivoCliente::leer(int nroRegistro){
  Cliente aux;
  FILE *p = fopen(ruta.c_str(), "rb");
  if (p == NULL){
    return aux;
  }

  fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
  fread(&aux, sizeof(Cliente), 1, p);
  fclose(p);
  return aux;
}

bool ArchivoCliente::borrarRegistro(int nroRegistro){
  Cliente aux;
  FILE *p = fopen(ruta.c_str(), "rb+");
  if (p == NULL){
    return false;
  }

  fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
  fread(&aux, sizeof(Cliente), 1, p);
  aux.setEstado(false);

  fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
  bool pudoEscribir = fwrite(&aux, sizeof(Cliente), 1, p);

  fclose(p);
  return pudoEscribir;

}

void ArchivoCliente::vaciar(){
  FILE *p = fopen(ruta.c_str(), "wb");
  if (p == NULL){
    return ;
  }
  fclose(p);
}
