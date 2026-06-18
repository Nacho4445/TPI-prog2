#pragma once
class Validador{

public:

    // Validaciones
    bool esNumero(const char texto[]);
    bool textoNoVacio(const char texto[]);
    bool cuitValido(const char texto[]);
    bool telefonoValido(const char texto[]);
    bool emailValido(const char texto[]);
    bool enteroPositivo(const char texto[]);
    bool decimalPositivo(const char texto[]);
    bool opcionSN(char opcion);

    // Conversiones
    int convertirEntero(const char texto[]);
    long long convertirLongLong(const char texto[]);
    float convertirFloat(const char texto[]);

    // Lecturas
    void leerTexto(char texto[], int tamanio, const char mensaje[]);
    void leerEnteroPositivo(int &numero, const char mensaje[]);
    void leerEnteroConCero(int &numero, const char mensaje[]);
    void leerDecimalPositivo(float &numero, const char mensaje[]);
    void leerCuit(long long &cuit);
    void leerTelefono(char telefono[]);
    void leerEmail(char email[]);
    void leerConfirmacion(char &opcion);
    void leerTipoCliente(int &tipo);
    void leerTamanioEntrada(char destino[], int tamanioMax);
};
