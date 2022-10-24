//Luis Armando Mandujano Chávez A01655899
//Pablo Ceballos G. A01660148
//Jennifer Avendaño Sánchez A01656951
#include <cstddef>
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#include "persona.h"
#include "lista.h"
#include "hashtablevd.h"

int stringToInt(string s){
  int n = 0;
  stringstream ssn;
  ssn << s;
  ssn >> n;
  return n;
}

//Funcion para leer el archivo .csv y creae el censo en una tabla hash
void censoHash(string &comando){
  int totalDatosArchivo = 0;
  string noLinea;
  ifstream bitacora;

  if(comando == "bitacora.csv"){
    bitacora.open(comando);
    if (bitacora.is_open()){
      while (getline(bitacora, noLinea)){
        totalDatosArchivo++;
      }
    }

    bitacora.close();
  }
  

  string linea1;
  string idS, fNombre, lNombre, genero, nacimiento, telefonoS, email, zipS, ciudad, estado;
  int id, telefono, zip;

  Hashtable<string, LinkedList<Persona> > censo(totalDatosArchivo -1);

  bitacora.open(comando);
  getline(bitacora, linea1);
  for(int i = 0; i < totalDatosArchivo-1; i++){
    getline(bitacora, noLinea);

    idS = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    fNombre = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    lNombre = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    genero = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    nacimiento = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    telefonoS = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    email = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    zipS = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    ciudad = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    estado = noLinea.substr(0, noLinea.length());

    id = stringToInt(idS);
    telefono = stringToInt(telefonoS);
    zip = stringToInt(zipS);

    Persona personita(id, fNombre, lNombre, genero, nacimiento, telefono, email, zip, ciudad, estado);


    if(censo.contains(ciudad)){
      LinkedList<Persona> Pr = censo.get(ciudad);
      Pr.addLast(personita);
      censo.put(ciudad, Pr);
    }
    else{
      LinkedList<Persona> Pr2;
      Pr2.addLast(personita);
      censo.put(ciudad, Pr2);
    }
  }
  censo.print();
  //cout << censo.Size() << endl;
  bitacora.close();
}

void ordenStack(string &comando){
  int totalDatosArchivo = 0;
  string noLinea;
  ifstream bitacora;

  if(comando == "bitacora.csv"){
    bitacora.open(comando);
    if (bitacora.is_open()){
      while (getline(bitacora, noLinea)){
        totalDatosArchivo++;
      }
    }

    bitacora.close();
  
  }  

  Stack<Persona> stack1;
  Stack<Persona> stack2;
  string linea1;
  string idS, fNombre, lNombre, genero, nacimiento, telefonoS, email, zipS, ciudad, estado;
  int id, telefono, zip;

  bitacora.open(comando);
  getline(bitacora, linea1);
  for(int i = 0; i < totalDatosArchivo-1; i++){
    getline(bitacora, noLinea);

    idS = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    fNombre = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    lNombre = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    genero = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    nacimiento = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    telefonoS = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    email = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    zipS = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    ciudad = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    estado = noLinea.substr(0, noLinea.length());

    id = stringToInt(idS);
    telefono = stringToInt(telefonoS);
    zip = stringToInt(zipS);

    Persona personita(id, fNombre, lNombre, genero, nacimiento, telefono, email, zip, ciudad, estado);
    stack1.push(personita);

  }

  bitacora.close();
  

  while(!stack1.is_empty()){
    string temporal = stack1.peek().getLastName();
    Persona tempPersona = stack1.peek();
    stack1.pop();

    while(!stack2.is_empty() && stack2.peek() > temporal){
      stack1.push(stack2.peek());
      stack2.pop();
    }

    stack2.push(tempPersona);
  }

  while(!stack2.is_empty()){
    cout << stack2.peek() << endl;
    stack2.pop();
  }


}

void zipQueue(string &comando){
  int totalDatosArchivo = 0;
  string noLinea;
  ifstream bitacora;

  if(comando == "bitacora.csv"){
    bitacora.open(comando);
    if (bitacora.is_open()){
      while (getline(bitacora, noLinea)){
        totalDatosArchivo++;
      }
    }

    bitacora.close();
  
  }  

  Queue<Persona> zips;
  string linea1;
  string idS, fNombre, lNombre, genero, nacimiento, telefonoS, email, zipS, ciudad, estado;
  int id, telefono, zip;

  bitacora.open(comando);
  getline(bitacora, linea1);
  for(int i = 0; i < totalDatosArchivo-1; i++){
    getline(bitacora, noLinea);

    idS = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    fNombre = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    lNombre = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    genero = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    nacimiento = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    telefonoS = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    email = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    zipS = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    ciudad = noLinea.substr(0, noLinea.find(","));
    noLinea = noLinea.substr(noLinea.find(",")+1, noLinea.length());

    estado = noLinea.substr(0, noLinea.length());

    id = stringToInt(idS);
    telefono = stringToInt(telefonoS);
    zip = stringToInt(zipS);

    Persona personita(id, fNombre, lNombre, genero, nacimiento, telefono, email, zip, ciudad, estado);
    zips.enqueue(personita);

  }

  bitacora.close();
  while(!zips.is_empty()){
    cout << zips.dequeueMin() << endl;
  }

}




int main(int argc, char**argv) {

  system("cls");
  string entrada;
  cout << "Ingrese el nombre del archivo porfavor: " << endl;
  cin >> entrada;
  cout << endl;
  string nombre = entrada;
  system("cls");

  int opcion;
  do{
    cout << "####### MENU PRINCIPAL #######" << endl;
    cout << "Seleccione la opcion que desee realizar" << endl;
    cout << endl;
    cout << "1. Despliega el registro de ciudades junto con sus habitantes" << endl;
    cout << "2. Despliega la lista de habitantes ordenada por apellidos" << endl;
    cout << "3. Despliega la lista de habitantes ordenada zip code de mayor a menor" << endl;
    cin >> opcion;
    cout << endl;

    if(opcion < 1 || opcion > 3){
      cout << "Por favor, seleccione una opcion valida" << endl;
      cout << endl;
    }

    switch(opcion){
      case 1:
        censoHash(nombre);
        break;
      case 2:
        ordenStack(nombre);
        break;
      case 3:
        zipQueue(nombre);
        break;
    }

  }while(opcion < 0 || opcion > 3);

  






  //cout << argv[0] << endl;
  //cout << argv[1] << endl;
  cout << "finito" << endl;  
}
