#include"Fecha.h"

Fecha::Fecha() {
  _dia = 0;
  _mes = 0;
  _anio = 0;
}
 
Fecha::Fecha(int dia, int mes, int anio) {
  _dia = dia;
  _mes = mes;
  _anio = anio;
}
 
int Fecha::getDia() {
  return _dia;
}
 
int Fecha::getMes() {
  return _mes;
}
 
int Fecha::getAnio() {
  return _anio;
}
 
string Fecha::toString() {
  return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}