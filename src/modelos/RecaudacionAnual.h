#pragma once
class RecaudacionAnual{
private:
    int anio;
    float recaudacion;

public:
    RecaudacionAnual(float _recaudacion, int _anio);
    int getAnio();
    void setAnio(int _anio);

    float getRecaudacion();
    void setRecaudacion(float _recaudacion);

};
