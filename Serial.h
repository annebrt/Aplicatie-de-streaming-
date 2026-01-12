#ifndef SERIAL_H
#define SERIAL_H

#include "BaseVideo.h"
#include "Episod.h"
#include <ostream>

class Serial: public BaseVideo{

    private:
    
        std::list<Episod*> listaEpisoade;


        void afisare(std::ostream &out) const override{

            BaseVideo::afisare(out);

            for (auto episod: listaEpisoade){

                out<<*episod;

            }
            

        }

        

    public:

    Serial():BaseVideo(){}

    Serial(const char* denumire, std::list<std::string> cast, const char* genre, const char* descriere):BaseVideo(denumire,cast,genre,descriere)
        {}

    Serial(const Serial& other):BaseVideo(other){

        for(auto episod:other.listaEpisoade){

            Episod* newEpisod=new Episod(*episod);
            
            this->listaEpisoade.push_back(newEpisod);

        }

    }

    
    

    void adaugaEpisod(Episod* episod){

        this->listaEpisoade.push_back(episod);

    }

    const std::list<Episod*> getList(){

        return listaEpisoade;

    }

    void afisare(std::ostream& os )  {

    }

    ~Serial(){
        for (auto episod:listaEpisoade){

            delete episod;

        }
    }

    Serial& operator=(Serial& other){

        if (this==&other){
            return *this;
        }

        delete [] this->denumire;

        this->denumire= new char[strlen(other.denumire)+1];
        std::strcpy(this->denumire,other.denumire);

        delete [] this->descriere;

        this->descriere=new char[strlen(other.descriere)+1];
        std::strcpy(this->descriere,other.descriere);

        delete [] this->genre;

        this->genre= new char[strlen(other.genre)+1];
        std::strcpy(this->genre,other.genre);

        this->nota=other.nota;
        this->cast=other.cast;
        this->reviewCount=other.reviewCount;

        for (auto episod:this->listaEpisoade){

            delete  episod;

        }
        listaEpisoade.clear();

        for(auto episod:other.listaEpisoade){

            Episod* newEpisod= new Episod(*episod);
            this->listaEpisoade.push_back(newEpisod);

        }

        return *this;
    }   

};


Serial operator+(Serial& serial, Episod* episod){

        Serial aux=  Serial(serial);
        aux.adaugaEpisod(episod);
        return aux;

    }
#endif // SERIAL_H
