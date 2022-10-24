#ifndef GENERO_DEFINED
#define GENERO_DEFINED
#include <string>
#include "Artista.h"
using namespace std;

class Genero{
    private:
        string gen;
        Artista artistas[4];
    public:
        Genero();
        Genero(string gen);
        string getGen();
        void setGen(string gen);
        void agregarArtista(Artista artista, int pos);      
        void imprimirArtistas();  
};
#endif
