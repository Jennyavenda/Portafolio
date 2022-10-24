#include <iostream>
#include "Playlist.h"

Playlist::Playlist(string play){
    this->play=play;
}
void Playlist::agregarArtista(Artista artista,int pos){
    artistas[pos]=artista;
}
void Playlist::imprimirArtistas(){
    cout<<"••••• "<<play<<" •••••"<<endl;
    for(int i=0;i<13;i++){
        cout<<(i+1)<<" .- "<<artistas[i].getNombre()<<", "<<artistas[i].getCancion()<<", "<<artistas[i].getEstado()<<endl; 
    }
}