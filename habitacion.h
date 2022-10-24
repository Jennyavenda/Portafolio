#ifndef HABITACION_DEFINED
#define HABITACION_DEFINED
#include <string>
using namespace std;
class Habitacion{
    private:
        string nombre;
        string apmaterno;
        string appaterno;

    public:
        Habitacion();
        Habitacion(string nombre,string apmaterno,string appaterno);
        void setNombre(string nombre);
        void setMaterno(string apmaterno);
        void setPaterno(string appaterno);
        string getNombre();
        string getMaterno();
        string getPaterno();
};

#endif