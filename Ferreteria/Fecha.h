#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include<string>
using namespace std;

class Fecha{
private:
    int _dia, _mes, _anio;
 
  public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    int getDia();
    int getMes();
    int getAnio();

    string toString();

};

#endif // FECHA_H_INCLUDED
