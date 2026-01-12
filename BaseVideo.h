#ifndef BASEVIDEO_H
#define BASEVIDEO_H

#include <string>
#include <cstring>
#include <list>
#include <ostream>


class BaseVideo{

protected:

    
    
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

    virtual void citire(std::istream& in) {

        std::string actor;

        char buffer[256];

        delete []denumire;

        std::cout<<"denumire: ";
        in>> buffer;

        this->denumire= new char[std::strlen(buffer)+1];
        std::strcpy(this->denumire,buffer);

        


        std::cout<<"genre: ";
        in>> buffer;

        delete [] genre;

        this->genre= new char[std::strlen(buffer)+1];
        std::strcpy(this->genre,buffer);



        std::cout<<"descriere: ";
        in>>buffer;

        delete []descriere;

        this->descriere= new char[std::strlen(buffer)+1];
        std::strcpy(this->descriere,buffer);

        
        std::cout<<"cast: ";

        cast.clear();

        while(true){

            std::cout<<"introdu nume actor: ";
            in>>actor;

            if (actor=="STOP"){

                break;

            }

            this->cast.push_back(actor);

        }

    }

public:

    BaseVideo(){
        this->denumire= nullptr;
        this->genre= nullptr;
        this->descriere= nullptr;
    }

    BaseVideo(const char* denumire){

        this->denumire= new char[std::strlen(denumire)+1];
        std::strcpy(this->denumire,denumire);

        this-> genre= nullptr;
        this -> descriere= nullptr;

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

    BaseVideo(const BaseVideo& other) {
    nota = other.nota;
    reviewCount = other.reviewCount;
    cast = other.cast;

    if (other.denumire) {
        denumire = new char[strlen(other.denumire) + 1];
        strcpy(denumire, other.denumire);
    } else {
        denumire = nullptr;
    }

    if (other.genre) {
        genre = new char[strlen(other.genre) + 1];
        strcpy(genre, other.genre);
    } else {
        genre = nullptr;
    }

    if (other.descriere) {
        descriere = new char[strlen(other.descriere) + 1];
        strcpy(descriere, other.descriere);
    } else {
        descriere = nullptr;
    }
}



    virtual ~BaseVideo(){

        delete [] denumire;
        delete [] descriere;
        delete [] genre;

    }
    


    const char* getDenumire() const{
        return this->denumire;
    }

    int getNota() const {
        return this->nota;
    } 

    int getReviewCount() const{
        return this->reviewCount;
    }

    const std::list<std::string>& getCast() const{
        return this->cast;
    }

    const char* getGenre() const{
        return this->genre;
    }

    const char* getDescriere() const {
        return this->descriere;
    }

    void setNota(int nota) {

        this->nota=nota;

    }

    void setReviewCount(int reviewCount){
        this->reviewCount=reviewCount;
    }

    friend std::ostream &operator<<(std::ostream &out, const BaseVideo &video){

        video.afisare(out);
        return out;

    }

    friend std::istream &operator>>(std::istream &in, BaseVideo &video){

        video.citire(in);
        return in;

    }



    

};



#endif // BASEVIDEO_H

