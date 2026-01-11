#ifndef BASEVIDEO_H
#define BASEVIDEO_H

#include <string>
#include <cstring>
#include <list>
#include <ostream>


class BaseVideo{

protected:

    static int idCounter;

    const int id= idCounter++;
    char* denumire;
    int nota=0;
    int reviewCount=0;
    std::list<std::string> cast;
    char* genre;
    char* descriere;


    virtual void afisare(std::ostream &out) const{

        out<<"nota: "<<this->nota<<std::endl;
        out<<"review count: "<<this->reviewCount<<std::endl;
        out<<"denumire: "<<this->denumire<<std::endl;
        out<<"genre: "<<this->genre<<std::endl;
        out<<"descriere: "<<this->genre<<std::endl;
        
        out<<"cast: ";

        for(auto actor: this->cast){

            out<< actor<<", ";

        }


    }

public:

    BaseVideo(){}

    BaseVideo(const char* denumire){

        this->denumire= new char[std::strlen(denumire)+1];
        std::strcpy(this->denumire,denumire);

    }

    BaseVideo(const char* denumire, std::list<std::string> cast, const char* genre, const char* descriere ){

      //  this->id= idCounter++;
        this->cast= cast;

        this->denumire= new char[std::strlen(denumire)+1];
        std::strcpy(this->denumire,denumire);

        this->genre= new char[std::strlen(genre)+1];
        std::strcpy(this->genre,genre);

        this->descriere= new char[std::strlen(descriere)+1];
        std::strcpy(this->descriere,descriere);


    }

    BaseVideo(const BaseVideo& other){

        this->nota= other.nota;
        this->reviewCount=reviewCount;

        this->denumire= new char[std::strlen(other.denumire)+1];
        std::strcpy(this->denumire,other.denumire);

        this->genre= new char[std::strlen(other.genre)+1];
        std::strcpy(this->genre,other.genre);

        this->descriere= new char[std::strlen(other.descriere)+1];
        std::strcpy(this->descriere,other.descriere);

        this->cast=other.cast;


    }


    virtual ~BaseVideo(){

        delete [] denumire;
        delete [] genre; 
        delete [] descriere;

    }

    const int getId(){
        return this->id;
    }

    const char* getDenumire(){
        return this->denumire;
    }

    const int getNota(){
        return this->nota;
    } 

    const int getReviewCount(){
        return this->reviewCount;
    }

    const std::list<std::string> getCast(){
        return this->cast;
    }

    const char* getGenre(){
        return this->genre;
    }

    const char* getDescriere(){
        return this->descriere;
    }

    friend std::ostream &operator<<(std::ostream &out, const BaseVideo &video){

        video.afisare(out);
        return out;

    }

};



#endif // BASEVIDEO_H

