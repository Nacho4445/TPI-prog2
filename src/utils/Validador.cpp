#include "utils/Validador.h"
#include <iostream>
#include <cstring>

using namespace std;

// Verifica que una cadena contenga unicamente numeros.
bool Validador::esNumero(const char texto[]){

    if(strlen(texto) == 0){
        return false;
    }

    for(int i = 0; texto[i] != '\0'; i++){
        if(texto[i] < '0' || texto[i] > '9'){
            return false;
        }
    }

    return true;
}

// Verifica que un texto no este vacio.
bool Validador::textoNoVacio(const char texto[]){
    return strlen(texto) > 0;
}

// Valida que el CUIT tenga 11 digitos numericos.
bool Validador::cuitValido(const char texto[]){
    return strlen(texto) == 11 && esNumero(texto);
}

// Valida que el telefono tenga al menos 6 digitos.
bool Validador::telefonoValido(const char texto[]){
    return strlen(texto) >= 6 && esNumero(texto);
}

// Valida que el email contenga '@' y '.'
bool Validador::emailValido(const char texto[]){

    bool tieneArroba = false;
    bool tienePunto = false;

    for(int i = 0; texto[i] != '\0'; i++){

        if(texto[i] == '@'){
            tieneArroba = true;
        }

        if(texto[i] == '.'){
            tienePunto = true;
        }
    }

    return textoNoVacio(texto) && tieneArroba && tienePunto;
}

// Verifica que el texto represente un entero mayor que cero.
bool Validador::enteroPositivo(const char texto[]){

    if(!esNumero(texto)){
        return false;
    }

    return convertirEntero(texto) > 0;
}

// Verifica que el texto represente un numero decimal positivo.
bool Validador::decimalPositivo(const char texto[]){

    if(strlen(texto) == 0){
        return false;
    }

    int cantidadPuntos = 0;

    for(int i = 0; texto[i] != '\0'; i++){

        if(texto[i] == '.'){
            cantidadPuntos++;
        }
        else if(texto[i] < '0' || texto[i] > '9'){
            return false;
        }
    }

    if(cantidadPuntos > 1){
        return false;
    }

    return convertirFloat(texto) > 0;
}

// Verifica que la opcion ingresada sea S o N.
bool Validador::opcionSN(char opcion){
    return opcion == 'S' || opcion == 's' ||
           opcion == 'N' || opcion == 'n';
}

// Convierte un texto numerico a entero.
int Validador::convertirEntero(const char texto[]){

    int numero = 0;

    for(int i = 0; texto[i] != '\0'; i++){
        numero = numero * 10 + (texto[i] - '0');
    }

    return numero;
}

// Convierte un texto numerico a long long.
long long Validador::convertirLongLong(const char texto[]){

    long long numero = 0;

    for(int i = 0; texto[i] != '\0'; i++){
        numero = numero * 10 + (texto[i] - '0');
    }

    return numero;
}

// Convierte un texto numerico con decimales a float.
float Validador::convertirFloat(const char texto[]){

    float numero = 0;
    float decimal = 0.1f;
    bool despuesDelPunto = false;

    for(int i = 0; texto[i] != '\0'; i++){

        if(texto[i] == '.'){
            despuesDelPunto = true;
        }
        else{

            if(!despuesDelPunto){
                numero = numero * 10 + (texto[i] - '0');
            }
            else{
                numero += (texto[i] - '0') * decimal;
                decimal /= 10;
            }
        }
    }

    return numero;
}

// Solicita un texto y verifica que no este vacio.
void Validador::leerTexto(char texto[], int tamanio, const char mensaje[]){

    do{

        cout << mensaje;
        cin.getline(texto, tamanio);

        if(!textoNoVacio(texto)){
            cout << "El campo no puede estar vacio." << endl;
        }

    }while(!textoNoVacio(texto));
}

// Solicita un entero mayor que cero.
void Validador::leerEnteroPositivo(int &numero, const char mensaje[]){

    char texto[20];

    do{

        cout << mensaje;
        cin >> texto;

        if(!enteroPositivo(texto)){
            cout << "Debe ingresar un numero entero mayor a cero." << endl;
        }

    }while(!enteroPositivo(texto));

    numero = convertirEntero(texto);
}

// Solicita un entero permitiendo el valor cero.
void Validador::leerEnteroConCero(int &numero, const char mensaje[]){

    char texto[20];
    bool valido;

    do{

        valido = true;

        cout << mensaje;
        cin.getline(texto, 20);

        if(strlen(texto) == 0){
            valido = false;
        }

        for(int i = 0; texto[i] != '\0'; i++){

            if(texto[i] < '0' || texto[i] > '9'){
                valido = false;
                break;
            }
        }

        if(valido){

            numero = convertirEntero(texto);

            if(numero < 0){
                valido = false;
            }
        }

        if(!valido){
            cout << "Ingrese un numero valido." << endl;
        }

    }while(!valido);
}

// Solicita un numero decimal mayor que cero.
void Validador::leerDecimalPositivo(float &numero, const char mensaje[]){

    char texto[30];

    do{

        cout << mensaje;
        cin >> texto;

        if(!decimalPositivo(texto)){
            cout << "Debe ingresar un numero mayor a cero." << endl;
        }

    }while(!decimalPositivo(texto));

    numero = convertirFloat(texto);
}

// Solicita y valida un CUIT.
void Validador::leerCuit(long long &cuit){

    char texto[20];

    do{

        cout << "CUIT: ";
        cin >> texto;

        if(!cuitValido(texto)){
            cout << "CUIT invalido. Debe contener 11 numeros." << endl;
        }

    }while(!cuitValido(texto));

    cuit = convertirLongLong(texto);
}

// Solicita y valida un telefono.
void Validador::leerTelefono(char telefono[]){

    do{

        cout << "Telefono: ";
        cin >> telefono;

        if(!telefonoValido(telefono)){
            cout << "Telefono invalido. Use solo numeros." << endl;
        }

    }while(!telefonoValido(telefono));
}

// Solicita y valida un email.
void Validador::leerEmail(char email[]){

    do{

        cout << "Email: ";
        cin >> email;

        if(!emailValido(email)){
            cout << "Email invalido." << endl;
        }

    }while(!emailValido(email));
}

// Solicita una confirmacion S o N.
void Validador::leerConfirmacion(char &opcion){

    do{

        cout << "Desea confirmar los cambios? (S/N): ";
        cin >> opcion;

        if(!opcionSN(opcion)){
            cout << "Ingrese S o N." << endl;
        }

    }while(!opcionSN(opcion));
}

// Solicita y valida el tipo de cliente.
void Validador::leerTipoCliente(int &tipo){

    char texto[5];

    do{

        cout << "Ingrese tipo de cliente (1-Particular / 2-Empresa): ";
        cin >> texto;

        if(!esNumero(texto) ||
           (convertirEntero(texto) != 1 && convertirEntero(texto) != 2)){
            cout << "Tipo invalido." << endl;
        }

    }while(!esNumero(texto) ||
           (convertirEntero(texto) != 1 && convertirEntero(texto) != 2));

    tipo = convertirEntero(texto);
}
