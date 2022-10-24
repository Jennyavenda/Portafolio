#ifndef HUESPED_DEFINED
#define HUESPED_DEFINED
#include <string>
#include "habitacion.h"
using namespace std;

class Huesped{
    private:
        Habitacion habitaciones[100];
        string check;
        string clave;
        double precio;

    public: 
        Huesped(string clave);
        void agregarOcupacion(Habitacion habitacion,int pos);
        void imprimirOcupacion();
        void setCheck(string check);
        void setPrecio(double precio);
        string getCheck();
        double getPrecio();


};

#endif