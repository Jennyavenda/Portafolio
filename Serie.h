#include <vector>
#include "Episodio.h"

class Serie: public Episodio{
    std::vector <Video> series;
    public:
    Serie(std::string i, std::string n, float d, std::string g, int c): Episodio(i, n, d, g, c){};
};