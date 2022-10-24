// Jennifer Avendaño Sánchez A01656951
// Julia Pasten Da Silva A01660665
#include <iostream>
#include <fstream>
#include <vector>
#ifndef _video_
#define _video_
#include "Video.h"
#endif

using namespace std;
//Peliculas
void cargarPelis(vector<Video> &);
//Episodio
void cargarSeries(vector<Video> &);
//Otras
void filVidDur(vector<Video>& vec);
void filVidGen(vector<Video>& vec);
void filVidCal(vector<Video>& vec);
void filVidSin(vector<Video>& vec);
void filEpi(vector<Video>& vec);
void mosVidS(vector<Video>& vec);
void calVids(vector<Video>& vec);
void mosVidP(vector<Video>& vec);
void calVidP(vector<Video>& vec);

int main(){
    vector <Video> series;
    cargarSeries(series);
    vector <Video> peliculas;
    cargarPelis(peliculas);

    int tam =series.size();
    for (int i=0;i<tam;i++){
        if(series[i].getGenero()!= series[i+1].getGenero()){
            std::cout<< series[i].getGenero()<<std::endl;
        }
    }

    // Qué hacer
    string hacer;   
    cout << "¿Qué quieres hacer?" << endl;
    cout << "a. Ver peliculas o series" <<endl;
    cout << "b. Calificar peliculas o series" <<endl;
    cout << "c. Salir" <<endl;
    cin >> hacer;
    cout << "------" <<endl;
    while(hacer != "c"){
        if (hacer=="a"){
            // Busca pelicula o serie
            string buscar; 
            cout << "¿Qué quieres ver?" << endl;
            cout << "a. Películas" <<endl;
            cout << "b. Series" <<endl;
            cin >> buscar;
            cout << "------" <<endl;
            if (buscar=="a"){
                // Busca por un filtro
                string filtro;  
                cout << "Filtar en orden por:" << endl;
                cout << "a. Duración" <<endl;
                cout << "b. Género" <<endl;
                cout << "c. Calificación" <<endl;
                cout << "d. Sin orden" <<endl;
                cin >> filtro;
                cout << "------" <<endl;
                if (filtro=="a"){filVidDur(peliculas);}
                else if (filtro=="b"){filVidGen(peliculas);}
                else if (filtro=="c"){filVidCal(peliculas);}
                else if (filtro=="d"){filVidSin(peliculas);}
                else{cout<<"Valor inválido, reingrese valor"<<endl;}
            }
            else if(buscar=="b"){
                // Busca por un filtro
                mosVidS(series);
                filEpi(series);
            }  
            cout<<endl; 
            cout << "¿Qué quieres hacer?" << endl;
            cout << "a. Ver peliculas o series" <<endl;
            cout << "b. Calificar peliculas o series" <<endl;
            cout << "c. Salir" <<endl;
            cin >> hacer;
            cout << "------" <<endl;

        }
        else if(hacer=="b") {
            // Busca pelicula o serie
            string buscar;  
            cout << "¿Qué quieres calificar?" << endl;
            cout << "a. Películas" <<endl;
            cout << "b. Series" <<endl;
            cout << "------" <<endl;
            cin >> buscar;
            if (buscar=="a"){
                mosVidP(peliculas);
                calVidP(peliculas);
            }
            else if(buscar=="b"){
                mosVidS(series);
                calVids(series);
            }
            cout<<endl;
            cout << "¿Qué quieres hacer?" << endl;
            cout << "a. Ver peliculas o series" <<endl;
            cout << "b. Calificar peliculas o series" <<endl;
            cout << "c. Salir" <<endl;
            cin >> hacer;
            cout << "------" <<endl;
        }
    }    
    if(hacer=="c"){
        cout<<"byee"<<endl;
    }
}

void cargarSeries(vector<Video>& ve){
    string myEpi; 
    ifstream MyReadEpi("Episodios.txt");
    while (getline(MyReadEpi, myEpi)){
        //Separación del texto
        std::string id = myEpi.substr(0, myEpi.find("-"));
        myEpi = myEpi.substr(myEpi.find("-")+1, myEpi.length());
        std::string nombre = myEpi.substr(0, myEpi.find("-"));
        float duracion = std::stof(myEpi.substr(myEpi.find("-")+1, myEpi.find("-")+1));
        myEpi = myEpi.substr(myEpi.find("-",myEpi.find("-")+2)+1, myEpi.length());
        std::string genero = myEpi.substr(0, myEpi.find("-"));
        int calificacion = std::stoi(myEpi.substr(myEpi.find("-")+1,myEpi.length()));
        //Ingreso de valores a Video
        Video video_temp(id, nombre, duracion,genero,calificacion);
        ve.push_back(video_temp);
    }
    MyReadEpi.close();
};
void cargarPelis(vector<Video>& vp){
    string myPeli; 
    ifstream MyReadPeli("Pelicula.txt");
    while (getline(MyReadPeli, myPeli)){
        //Separación del texto
        std::string id = myPeli.substr(0, myPeli.find("-"));
        myPeli = myPeli.substr(myPeli.find("-")+1, myPeli.length());
        std::string nombre = myPeli.substr(0, myPeli.find("-"));
        float duracion = std::stof(myPeli.substr(myPeli.find("-")+1, myPeli.find("-")+1));
        myPeli = myPeli.substr(myPeli.find("-",myPeli.find("-")+2)+1, myPeli.length());
        std::string genero = myPeli.substr(0, myPeli.find("-"));
        int calificacion = std::stoi(myPeli.substr(myPeli.find("-")+1,myPeli.length()));
        //Ingreso de valores a Video
        Video video_temp(id, nombre, duracion,genero,calificacion);
        vp.push_back(video_temp);
    }
    MyReadPeli.close();
};
void filVidDur(vector<Video>& vec){
    float dur;
    std::cout << "Dame la duración que buscas: " << std::endl;
    cin >> dur;
    for(Video v : vec){
        if(v.getDuracion() >= dur){
            v.toStr();
        }
    }
};
void filVidGen(vector<Video>& vec){
    std::cout<< "Estos son los géneros: ";
    std::cout<<std::endl;
    int tam =vec.size();
    for (int i=0;i<tam;i++){
        if(vec[i].getGenero()!= vec[i+1].getGenero()){
            std::cout<< vec[i].getGenero()<<std::endl;
        }
    }
    string gen;
    std::cout << "Dame el género que buscas: " << std::endl;
    cin >> gen;
    for(Video v : vec){
        if(v.getGenero() == gen){
            v.toStr();
        }
    }
};
void filVidCal(vector<Video>& vec){
    int cal;
    std::cout << "Dame la calificación que buscas: " << std::endl;
    cin >> cal;
    for(Video v : vec){
        if(v.getCalificacion() >= cal){
            v.toStr();
        }
    }
};
void filVidSin(vector<Video>& vec){
    for(Video v : vec){
            v.toStr();
    }
};
void filEpi(vector<Video>& vec){
    cout<<endl;
    //Reciber Id de clase
    string idinci;
    cout <<"Dame el Id de la serie cuyos datos quieres filtrar"<<endl;
    cin>>idinci;

    //Filtra
    cout<<endl;
    string filtro;  
    cout << "Filtar en orden por:" << endl;
    cout << "a. Duración" <<endl;
    cout << "b. Género" <<endl;
    cout << "c. Calificación" <<endl;
    cout << "d. Sin orden" <<endl;
    cout << "------" <<endl;
    cin >> filtro;

    if (filtro=="a"){
        float dur;
        std::cout << "Dame la duración que buscas: " << std::endl;
        cin >> dur;
        int tam =vec.size();
        for (int i=0;i<tam;i++){
            if(vec[i].getId().substr(0,3) == idinci & vec[i].getDuracion() >= dur){
                vec[i].toStr();
            }
        }
    }
    else if (filtro=="b"){
        std::cout<< "Estos son los géneros: ";
        std::cout<<std::endl;
        int tam =vec.size();
        for (int i=0;i<tam;i++){
            if(vec[i].getId().substr(0,3) == idinci & vec[i].getGenero()!= vec[i+1].getGenero()){
                std::cout<< vec[i].getGenero()<<std::endl;
            }
        }

        string gen;
        std::cout << "Dame el género que buscas: " << std::endl;
        cin >> gen;
        for (int i=0;i<tam;i++){
            if(vec[i].getId().substr(0,3) == idinci & vec[i].getGenero() >= gen){
                vec[i].toStr();
            }
        }
    }
    else if (filtro=="c"){
        int cal;
        std::cout << "Dame la calificación que buscas: " << std::endl;
        cin >> cal;
        int tam =vec.size();
        for (int i=0;i<tam;i++){
            if(vec[i].getId().substr(0,3) == idinci & vec[i].getCalificacion() >= cal){
                vec[i].toStr();
            }
        }
    }
    else if (filtro=="d"){
        int tam =vec.size();
        for (int i=0;i<tam;i++){
            if(vec[i].getId().substr(0,3) == idinci){
                vec[i].toStr();
            }
        }
    }
    else{cout<<"Valor inválido, reingrese valor"<<endl;}
};
void mosVidS(vector<Video>& vec){
    std::cout<< "Estas son las series: ";
    std::cout<<std::endl;
    int tam =vec.size();
    for (int i=0;i<tam;i++){
        string v =vec[i].getNombre();
        string def;
        def = v.substr(0, v.find(":"));
        if(def!= vec[i+1].getNombre().substr(0, v.find(":"))){
            cout<< v.substr(0, v.find(":"))<<endl<<" su Id es: "<<vec[i].getId().substr(0,3)<<endl;
        }
    }
}
void calVids(vector<Video>& vec){
    cout<<endl;
    //Reciber Id de clase
    string idinci;
    cout <<"Dame el Id de la serie"<<endl;
    cin>>idinci;
    for(Video v : vec){
        int i = 0;
        int vs = vec.size();
        if(vec[i].getId().substr(0,3) == idinci & i <vs){
            v.toStrS();
            i+=1;
        }
    }
    // Da el id del objeto que quiere calificar
    string seleccion;
    cout << "Ingresa el id para calificar:      ";
    cin >> seleccion; 
    int tam =vec.size();
    for (int i=0;i<tam;i++){
        if(vec[i].getId()== seleccion){
            std::cout<< "Id enocntrado, su título es: "<<vec[i].getNombre()<<std::endl;
            //Calificar el id
            int califica;
            cout << "¿Cuál es tu calificación para este título?(en entero):     ";
            cin >> califica;
            vec[i].setCalificacion(califica);
        }
    }
}
void mosVidP(vector<Video>& vec){
    for(Video v: vec){
        v.toStrS();
    }
};
void calVidP(vector<Video>& vec){
    string seleccion;
    cout << "Ingresa el id para calificar:      ";
    cin >> seleccion; 
    int tam =vec.size();
    for (int i=0;i<tam;i++){
        if(vec[i].getId()== seleccion){
            std::cout<< "Id enocntrado, su título es: "<<vec[i].getNombre()<<std::endl;
            //Calificar el id
            int califica;
            cout << "¿Cuál es tu calificación para este título?(en entero):     ";
            cin >> califica;
            vec[i].setCalificacion(califica);
        }
    }
};