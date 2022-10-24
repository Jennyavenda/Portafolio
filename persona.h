class Persona{
  private:
    string first_name,last_name, gender, dob, email, city, state;
    int id, phone, zip;
  public:
      Persona(int id = 0, string fname = "", string lname = "", string gender = "", string dob = "", int phone = 0, string email = "", int zip = 0, string city = "", string state = ""){
        this->id = id;
        this->first_name = fname;
        this->last_name = lname;
        this->gender = gender;
        this->dob = dob;
        this->phone = phone;
        this->email = email;
        this->zip = zip;
        this->city = city;
        this->state = state;
      }

    string getCiudad(){
      return city;
    }

    int getZip(){
      return zip;
    }

    int getId(){
      return id;
    }
    
    bool operator==(const string & last_name){
      return (this->last_name == last_name);
    }

    bool operator<(const Persona & persona){
      return (this-> zip < persona.zip);
    }

    /*
    bool operator<(const string & last_name){
      return (this-> last_name < last_name);
    }
    */

    bool operator>(const string & last_name){
      return (this-> last_name > last_name);
    }

    /*
    bool operator>(const string & last_name){
      return (this-> last_name > last_name);
    }
    */

    string getLastName(){
      return last_name;
    }

/*
Agrega las sobre cargas de operadores necesarias en la clase Persona.
*/   
    friend ostream & operator<<(ostream &, const Persona &);



    

};

ostream & operator<<(ostream & salida, const Persona & persona){
  salida << persona.id << "|" << persona.first_name << "|" << persona.last_name << "|" << persona.gender << "|" << persona.dob << "|" << persona.phone << "|" << persona.email << "|" << persona.zip << "|" << persona.city << "|" << persona.state << endl;
  return salida;
}