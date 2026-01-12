#ifndef EPISOD_H
#define EPISOD_H

#include "BaseVideo.h"
#include "Durata.h"
#include <ctime>

class Episod: public BaseVideo{

    private:
        Durata* durata;


        void afisare(std::ostream& out) const override{

            BaseVideo::afisare(out);

            out<<*durata;


        }


        void citire(std::istream& in) override{

            BaseVideo::citire(in);

            Durata* durata= new Durata();

            in>>*durata;

            this->durata= durata;


        }

    public:
        
        Episod():BaseVideo(),durata(nullptr){}

        Episod(const char* denumire, std::list<std::string> cast, const char* genre, const char* descriere,Durata* durata):BaseVideo(denumire,cast,genre,descriere){

            this->durata=new Durata(*durata);

        }
        
        
    ~Episod(){

        delete durata;

    }

        Episod(const Episod& other):BaseVideo(other.denumire,other.cast,other.genre,other.descriere){

            Durata* durata=  new Durata(*other.durata);

            this->durata=durata;

        }



};

class Clock{

    private:
        Clock(){}

        Clock(Clock& other)= delete;

        Clock& operator=(Clock& other)=delete;

    public:
    
    static Clock& getInstance(){

        static Clock clock;
        return clock;

    }

    std::time_t now(){

        return std::time(nullptr);

    }

    

};


#endif // EPISOD_H
