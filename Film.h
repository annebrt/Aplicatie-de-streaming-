#ifndef FILM_H
#define FILM_H

#include "BaseVideo.h"
#include "Durata.h"
#include <ostream>

class Film: public BaseVideo{

    private:

        
        Durata* durata; 
        int buget;
    
    public: 

        Film(const char* denumire, std::list<std::string> cast, const char* genre, const char* descriere, Durata* durata, int buget):BaseVideo(denumire,cast,genre,descriere)
            ,durata(durata),buget(buget){}

        ~Film(){
            delete  durata;
        }

    void afisare(std::ostream& out) {


    }
    
};

#endif // FILM_H
