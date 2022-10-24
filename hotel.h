#ifndef HOTEL_DEFINED
#define HOTEL_DEFINED
#include <string>
#include "habitacion.h"
using namespace std;

class Hotel{
    private:
        string clave;
        Habitacion habitaciones[100];
    
    public: 
        Hotel(string clave);
        void agregarHabitacion(Habitacion habitacion,int pos);
        void imprimirHabitaciones();
};

#endif