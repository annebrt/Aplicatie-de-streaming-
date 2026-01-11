#ifndef SERIAL_H
#define SERIAL_H

#include "BaseVideo.h"
#include "Episod.h"
#include <ostream>

class Serial: public BaseVideo{

    private:
    
        std::list<Episod*> listaEpisoade;

    public:

    Serial(const char* denumire, std::list<std::string> cast, const char* genre, const char* descriere,const std::list<Episod*> listaEpisoade):BaseVideo(denumire,cast,genre,descriere)
        ,listaEpisoade(listaEpisoade){}

    Serial(const Serial& other):BaseVideo(other),listaEpisoade(other.listaEpisoade){
    }

    


    void adaugaEpisod(Episod* episod){

        this->listaEpisoade.push_back(episod);

    }

    const std::list<Episod*> getList(){

        return listaEpisoade;

    }

    void afisare(std::ostream& os )  {





    }

    

};


Serial& operator+(Serial& serial, Episod* episod){

        Serial* aux= new  Serial(serial);
        aux->adaugaEpisod(episod);
        return *aux;

    }
#endif // SERIAL_H
