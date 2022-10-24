#include <vector>

#ifndef _video_
#define _video_
#include "Video.h"
#endif

class Pelicula: public Video{
    std::vector <Video> peliculas;
    public:
    Pelicula(std::string i, std::string n, float d, std::string g, int c): Video(i, n, d, g, c){};
};   
