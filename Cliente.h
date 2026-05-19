#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <vector>
#include <string>
using namespace std;

class Cliente {
private:
    string cuit;
    string nombre;
    string apellido;
    string telefono;
    string email;
    string direccion;
    int tipoCliente; // 1 = particular, 2 = empresa
public:
    string ingresarCuit();
};

#endif // CLIENTE_H_INCLUDED
