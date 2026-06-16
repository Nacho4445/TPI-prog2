#include <iostream>
using namespace std;
#include "archivos/ArchivoCliente.h"

ArchivoCliente::ArchivoCliente(){
  ruta = "datos/clientes.dat";
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
    cout << "No se pudo abrir: " << ruta << endl;
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

Cliente ArchivoCliente::leer(int id){
  Cliente aux;

  int pos = buscar(id);

  if (pos == -1){
        return aux;
  }

  FILE *p = fopen(ruta.c_str(), "rb");
  if (p == NULL){
    return aux;
  }

  fseek(p, pos * sizeof(Cliente), SEEK_SET);
  fread(&aux, sizeof(Cliente), 1, p);

  fclose(p);
  return aux;
}

Cliente ArchivoCliente::leerPorPosicion(int posicion){
    Cliente aux;

    FILE *p = fopen(ruta.c_str(), "rb");
    if (p == NULL){
        return aux;
    }

    fseek(p, posicion * sizeof(Cliente), SEEK_SET);
    fread(&aux, sizeof(Cliente), 1, p);

    fclose(p);
    return aux;
}

bool ArchivoCliente::modificar(Cliente cliente){

    int pos = buscar(cliente.getIdCliente());

    if(pos == -1){
        return false;
    }

    FILE *p = fopen(ruta.c_str(), "rb+");

    if(p == NULL){
        return false;
    }

    fseek(p, pos * sizeof(Cliente), SEEK_SET);

    bool escribio = fwrite(&cliente, sizeof(Cliente), 1, p);

    fclose(p);

    return escribio;
}

bool ArchivoCliente::borrarRegistro(int id){
  Cliente aux;

  int pos = buscar(id);

  if (pos == -1){
    return false;
  }

  FILE *p = fopen(ruta.c_str(), "rb+");
  if (p == NULL){
    return false;
  }

  fseek(p, pos * sizeof(Cliente), SEEK_SET);
  fread(&aux, sizeof(Cliente), 1, p);
  aux.setEstado(false);

  fseek(p, pos * sizeof(Cliente), SEEK_SET);
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

int ArchivoCliente::buscarPorCuit(long long cuit){

    Cliente cliente;
    FILE* pFile = fopen(ruta.c_str(), "rb");

    if(pFile == nullptr){
        return -1;
    }

    int pos = 0;

    while(fread(&cliente, sizeof(Cliente), 1, pFile) == 1){

        if(cliente.getEstado() &&
           cliente.getCuit() == cuit){

            fclose(pFile);
            return pos;
        }

        pos++;
    }

    fclose(pFile);
    return -1;
}
