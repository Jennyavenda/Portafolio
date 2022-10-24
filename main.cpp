#include <iostream>
#include "Playlist.h"
#include "Genero.h"
#include "Artista.h"

using namespace std;

int main(){
    // CREACIÓN DE GENEROS
    Genero popes("Pop en español");
    Genero reg("Reggaeton");
    Genero popin("Pop en ingles");

    // CANCIONES POP ESPAÑOL
    Artista tor("Dorian","La Tormenta de Arena","vivo");
    Artista viv("Maná","Vivir Sin Aire","vivo");
    Artista dej("Chayanne","Dejaría todo","vivo");
    Artista cul("Luis Miguel","Culpable O No","vivo");
    // CANCIONES POP INGLES
    Artista red("Childdish Gambino","Redbone","vivo");
    Artista hel("Disclosure & London Grammar","Help Me Lose My Mind","vivo");
    Artista sme("Nirvana","Smells Like Teen Spirit","vivo");
    Artista wan("Arctic Monkeys","Do I Wanna Know?","vivo");
    // CANCIONES REGGAETON
    Artista play("Zion & Lennox","La player","vivo");
    Artista est("Jhay Cortez","Está deja","vivo");
    Artista todo("Rauw Alejandro","Todo de ti","vivo");
    Artista gust("Wisin & Yandel","Algo me gusta de ti","vivo");

    // AGREGA A GENERO POP ESPAÑOL
    popes.agregarArtista(tor,0);
    popes.agregarArtista(viv,1);
    popes.agregarArtista(dej,2);
    popes.agregarArtista(cul,3);
    // AGREGA A GENERO POP INGLES
    popin.agregarArtista(red,0);
    popin.agregarArtista(hel,1);
    popin.agregarArtista(sme,2);
    popin.agregarArtista(wan,3);
    // AGREGA A GENERO REGGAETON
    reg.agregarArtista(play,0);
    reg.agregarArtista(est,1);
    reg.agregarArtista(todo,2);
    reg.agregarArtista(gust,3);

    Playlist playlist("Playlist");
    playlist.agregarArtista(tor,0);
    playlist.agregarArtista(viv,1);
    playlist.agregarArtista(dej,2);
    playlist.agregarArtista(cul,3);
    playlist.agregarArtista(red,5);
    playlist.agregarArtista(hel,6);
    playlist.agregarArtista(sme,7);
    playlist.agregarArtista(wan,8);
    playlist.agregarArtista(play,9);
    playlist.agregarArtista(est,10);
    playlist.agregarArtista(todo,11);
    playlist.agregarArtista(gust,12);

    
    int respuesta;
    cout<<"¿Qué quieres que haga?"<<endl<<"1. Ver playlist"<<endl<<"2. Ver los géneros"<<endl<<"3. Sustituir una canción"<<endl<<"4. Salir"<<endl<<"----- "; 
    cin>>respuesta;

    // CICLO
    while(respuesta != 4){
        if (respuesta==1){
            playlist.imprimirArtistas();
        }
        else if(respuesta==2){
            cout<<"Escoge el género que deseas ver"<<endl<<"1. Reggaeton"<<endl<<"2. Pop en ingles"<<endl<<"3. Pop en español"<<endl<<"--- ";
            int selecGen;
            cin>>selecGen;
            if (selecGen==1){
                reg.imprimirArtistas();
            }else if(selecGen==2){
                popin.imprimirArtistas();
            }else{
                popes.imprimirArtistas();
            }
        }
        else if(respuesta==3){
            int gencambio;
            int posnueva;
            string nombren;
            string canciónn;
            string estadon;
            cout<<"Escoge el género que deseas cambiar la canción:"<<endl<<"1. Reggaeton"<<endl<<"2. Pop en ingles"<<endl<<"3. Pop en español"<<endl<<"--- ";
            cin>>gencambio;
            if (gencambio==1){
                reg.imprimirArtistas();
            }else if(gencambio==2){
                popin.imprimirArtistas();
            }else{
                popes.imprimirArtistas();
            }
            cout<<"Escoge la posición de la canción que deseas sustituir:"<<endl<<"-- ";
            cin>>posnueva;
            
            cout<<"¿Quién es el artista de tu nueva canción?"<<endl<<"-- ";
            cin>>nombren;
            cout<<"¿Cómo se llama tu nueva canción?"<<endl<<"-- ";
            cin>>canciónn;
            cout<<"¿El nuevo artitas está vivo o muerto?"<<endl<<"-- ";
            cin>>estadon;
            if (gencambio==1){
                Artista nuev(nombren, canciónn, estadon);
                reg.agregarArtista(nuev,posnueva-1);
                reg.imprimirArtistas();
            }else if(gencambio==2){
                Artista nuev(nombren, canciónn, estadon);
                popin.agregarArtista(nuev,posnueva-1);
                popin.imprimirArtistas();
            }else{
                Artista nuev(nombren, canciónn,estadon);
                popes.agregarArtista(nuev,posnueva-1);
                popes.imprimirArtistas();
            }
        }
        cout<<endl<<"¿Qué quieres que haga?"<<endl<<"1. Ver playlist"<<endl<<"2. Ver los géneros"<<endl<<"3. Sustituir una canción"<<endl<<"4. Salir"<<endl<<"----- ";  
        cin>>respuesta;
    }
    cout<<"Un placer ayudarte :)"<<endl;

    return 0;
}