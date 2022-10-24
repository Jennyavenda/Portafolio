#include <iostream>
#include "Genero.h"

Genero::Genero(string gen){
    this->gen=gen;
}
void Genero::agregarArtista(Artista artista,int pos){
    artistas[pos]=artista;
}
void Genero::imprimirArtistas(){
    cout<<"••••• "<<gen<<" •••••"<<endl;
    for(int i=0;i<4;i++){
        cout<<(i+1)<<" .- "<<artistas[i].getNombre()<<", "<<artistas[i].getCancion()<<", "<<artistas[i].getEstado()<<endl;  
    }
}