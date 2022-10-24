#include "habitacion.h"

Habitacion::Habitacion(){
    nombre="Sin nombre";
    apmaterno="Sin apellido";
    appaterno="Sin apellido";
}
Habitacion::Habitacion(string nombre,string apmaterno,string appaterno){
    this->nombre=nombre;
    this->apmaterno=apmaterno;
    this->appaterno=appaterno;
}
void Habitacion::setNombre(string nombre){
    this->nombre=nombre;
}
void Habitacion::setMaterno(string apmaterno){
    this->apmaterno=apmaterno;
}
void Habitacion::setPaterno(string appaterno){
    this->appaterno=appaterno;
}

string Habitacion::getNombre(){
    return nombre;
}
string Habitacion::getMaterno(){
    return apmaterno;
}
string Habitacion::getPaterno(){
    return appaterno;
}
