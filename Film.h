#ifndef FILM_H
#define FILM_H

#include "BaseVideo.h"
#include "Durata.h"
#include <ostream>

class Film: public BaseVideo{

    private:

        
        Durata* durata; 
        int buget;

    void afisare(std::ostream& out) const override {

        BaseVideo::afisare(out);

        out<<"durata: "<<*durata;
        out<<"buget"<<buget;

    }

    void citire(std::istream& in) override{

        BaseVideo::citire(in);

        int ore, minute,secunde;

        std::cout<<"ore: ";
        in>>ore;
        std::cout<<"minute: ";
        in>>minute;
        std::cout<<"secunde: ";
        in>>secunde;

        std::cout<<"buget: ";
        in>>this->buget;

        delete this->durata;

        Durata* durata= new Durata(ore,minute,secunde);

        this->durata=durata;

    }
    
    public: 

        Film(){
            this->durata=nullptr;
        }

        Film(const char* denumire, std::list<std::string> cast, const char* genre, const char* descriere, Durata* durata, int buget):BaseVideo(denumire,cast,genre,descriere)
            ,buget(buget) {


                this->durata= new Durata(*durata);

            }

        ~Film(){
            delete  durata;
        }

    

    

    
};

#endif // FILM_H
