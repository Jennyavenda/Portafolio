#include <iostream>
class Video{
    private:
        std::string id;
        std::string nombre;
        float duracion;
        std::string genero;
        int calificacion;
    public:
    Video(std::string i, std::string n, float d, std::string g, int c){
        id = i;
        nombre = n;
        duracion = d;
        genero = g;
        calificacion = c;
    } 
    
    //getters & setters
    std::string getId(){return id;};
    std::string getNombre(){return nombre;};
    float getDuracion(){return duracion;};
    std::string getGenero(){return genero;};
    int getCalificacion(){return calificacion;};
    void setCalificacion(int c){calificacion = c;};

    void toStr(){
        std::cout << "*****************************"  << std::endl;
        std::cout << "El id: " << id << std::endl;
        std::cout << "El nombre: " << nombre << std::endl;
        std::cout << "La duración: " << duracion << std::endl;
        std::cout << "El género: " << genero << std::endl;
        std::cout << "La calificación: " << calificacion << std::endl;
    };   

    void toStrS(){
        std::cout << "*****************************"  << std::endl;
        std::cout << "El id: " << id << std::endl;
        std::cout << "El nombre: " << nombre << std::endl;
        std::cout << "La calificación: " << calificacion << std::endl;
    };  

};
