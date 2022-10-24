#include <vector>

#ifndef _video_
#define _video_
#include "Video.h"
#endif

class Episodio: public Video{
    public:
    Episodio(std::string i, std::string n, float d, std::string g, int c): Video(i, n, d, g, c){};
};