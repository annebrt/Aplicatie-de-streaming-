#ifndef EPISOD_H
#define EPISOD_H

#include "BaseVideo.h"
#include "Durata.h"

class Episod: public BaseVideo{

    private:
        Durata* durata;


        void afisare(std::ostream& out) const override{

            BaseVideo::afisare(out);

            out<<*durata;


        }

    public:

        Episod(const char* denumire, std::list<std::string> cast, const char* genre, const char* descriere,Durata* durata):BaseVideo(denumire,cast,genre,descriere),durata(durata){}
        
        



};

#endif // EPISOD_H
