#ifndef PLAYLIST_DEFINDED
#define PLAYLIST_DEFINDED
#include <string>
#include "Artista.h"
using namespace std;

class Playlist{
  private:
    string play;
    Artista artistas[13];
  public:
    Playlist(string play);
    void agregarArtista(Artista artista, int pos);
    void imprimirArtistas();
};
#endif
