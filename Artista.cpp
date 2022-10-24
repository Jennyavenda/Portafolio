#include "Artista.h"

Artista::Artista(){
    nombre="Sin nombre";
    cancion="Sin cancion";
    estado="Sin estado";
}
Artista::Artista(string nombre,string cancion,string estado){
    this->nombre=nombre;
    this->cancion=cancion;
    this->estado=estado;
}
string Artista::getNombre(){
    return nombre;
}
string Artista::getCancion(){
    return cancion;
}
string Artista::getEstado(){
    return estado;
}

void Artista::setNombre(string nombre){
    this->nombre=nombre;
}
void Artista::setCancion(string cancion){
    this->cancion=cancion;
}
void Artista::setEstado(string estado){
    this->estado=estado;
}
