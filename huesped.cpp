#include "huesped.h"
#include <iostream>


Huesped::Huesped(string check, double precio){
    this->check=check;
    this->precio=precio;
    this->clave=clave;
}
void Huesped::setCheck(string check){
    this->check=check;
}
void Huesped::setPrecio(double precio){
    this->precio=precio;
}

string Huesped::getCheck(){
    return check;
}
double Huesped::getPrecio(){
    return precio;
}

void Huesped::agregarOcupacion(Habitacion habitacion,int pos){
    habitaciones[pos]=habitacion;
}

void Hotel::imprimirOcupacion(){
    cout<<"-----Hotel "<<clave<<"------"<<endl;
    for(int i=0;i<100;i++){
        if(habitaciones[i].getNombre()=="Si nombre"){
            cout<<(i+1)<<" .- Habitación vacia"<<<<endl;
        }else{
            cout<<(i+1)<<" .- Habitación con adeud $1200"<<<<endl;
        }
        
    }
}