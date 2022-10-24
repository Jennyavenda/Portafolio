template <typename K, typename T> /* K key, T value*/
class HashPair
{
public:
  K key;
  T value;
  HashPair(K key, T value)
  {
    this->key = key;
    this->value = value;
  }
  HashPair()
  {
  }
};
template <typename K, typename T>
class Hashtable
{
private:
  int size;
  LinkedList<HashPair<K, T> *> *tabla;
  int fh(K key) const
  {
    hash<K> hasher;
    return hasher(key) % size;
  }

public:
  Hashtable(int size = 20)
  {
    this->size = size;
    tabla = new LinkedList<HashPair<K, T> *>[size];
    for (int i = 0; i < size; i++)
    {
      tabla[i] = LinkedList<HashPair<K, T> *>();
    }
  }

  bool put(K key, T value)
  {
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for (int i = 0; i < lista.size(); i++)
    {
      if (lista.get(i)->key == key)
      {
        indice = i;
      }
    }
    if (indice >= 0)
    { // actualiza 0
      lista.get(indice)->value = value;
    }
    else
    { // agrega nuevo 1
      tabla[posicion].addLast(new HashPair<K, T>(key, value));
    }
    return (indice >= 0) ? 0 : 1;
  }
  // O(n)
  T get(K key) const
  {
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for (int i = 0; i < lista.size(); i++)
    {
      if (lista.get(i)->key == key)
      {
        indice = i;
      }
    }
    if (indice < 0)
      throw -1;
    return lista.get(indice)->value;
  }

  bool contains(K key) const
  {
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for (int i = 0; i < lista.size(); i++)
    {
      if (lista.get(i)->key == key)
      {
        indice = i;
      }
    }

    return (indice < 0) ? 0 : 1;
  }

  T get_or_default(K key, T default_value) const {
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for(int i = 0; i < lista.size(); i++){
      if(lista.get(i)->key == key){
        indice = i;
      }


    }
    if(indice < 0){
      return default_value;
    }
    else{
      return lista.get(indice)->value;
    }
  }

  bool is_empty(){
    int posicion = 0;
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;    
    if(lista.is_empty()){
      return 0;
    }
    else{
      return 1;
    }
  }

  LinkedList<T> keys() const{
    LinkedList<T> llaves;
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < tabla[i].size(); j++)
      {
        llaves.addLast(tabla[i].get(j)->key);
      }
    }
    return llaves;
  }

  bool remove(K key) const{
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for (int i = 0; i < lista.size(); i++){
      if (lista.get(i)->key == key)
      {
        indice = i;
      }
    }
    if(indice < 0){
      return 1;
    }
    else{
      tabla[posicion].remove(indice);
      return 0;
    }   
  }

  int Size() const{
    int contador = 0;
    for (int i = 0; i < size; i++){
      for (int j = 0; j < tabla[i].size(); j++){
        contador++;
      }      

    }
    return contador;    
  }

  void print()
  {
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < tabla[i].size(); j++)
      {
        cout << "k: " << tabla[i].get(j)->key << ":  " << tabla[i].get(j)->value << endl;
      }
    }
  }
};

