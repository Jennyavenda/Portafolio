#include <iostream>
#include "habitacion.h"
#include "hotel.h"
#include "huesped.h"

using namespace std;

int main(){

    Habitacion h1("Julia","González","Flores");
    Habitacion h2("Leo","Flores","Sanchez");
    Habitacion h3("Polo","López","López");
    Habitacion h4("Luis","Escutia","Peralta");

    Hotel hotel("Habitaciones");
    hotel.agregarHabitacion(h1,0);
    hotel.agregarHabitacion(h2,1);
    hotel.agregarHabitacion(h3,2);
    hotel.agregarHabitacion(h4,3);
    hotel.imprimirHabitaciones();

    Huesped huesped("Ocupación");
    huesped.agregarOcupacion(h1,0);
    huesped.agregarOcupacion(h2,1);
    huesped.agregarOcupacion(h3,2);
    huesped.agregarOcupacion(h4,3);
    huesped.imprimirOcupacion();


    return 0;
}