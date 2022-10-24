#ifndef Artista_DEFINDED
#define Artista_DEFINDED
#include <string>
using namespace std;

class Artista{
  private:
    string nombre;
    string cancion;
    string estado;
  public:
    Artista();
    Artista(string nombre, string cancion,string estado);
    string getNombre();
    string getCancion();
    string getEstado();
    void setNombre(string nombre);
    void setCancion(string cancion);
    void setEstado(string estado);
};
#endif