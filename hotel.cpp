#include "hotel.h"
#include <iostream>

Hotel::Hotel(string clave){
    this->clave=clave;
}

void Hotel::agregarHabitacion(Habitacion habitacion,int pos){
    habitaciones[pos]=habitacion;
}
void Hotel::imprimirHabitaciones(){
    cout<<"-----Hotel "<<clave<<"------"<<endl;
    for(int i=0;i<100;i++){
        cout<<(i+1)<<" .- "<<habitaciones[i].getNombre()<<" "<<habitaciones[i].getMaterno()<<" "<<habitaciones[i].getPaterno()<<endl;  
    }
}