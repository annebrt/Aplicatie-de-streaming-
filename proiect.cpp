#include <iostream>

#include <string>
#include <cstring>
#include <list>

class IVideo{



};

class Durata{

    private:

    int ore;
    int minute;
    int secunde;

    public: Durata(int ore, int minute, int secunde){

        this->ore= ore;
        this->minute= minute;
        this->secunde= secunde;

    }

};



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

};

class Episod: public BaseVideo{

    private:
        Durata* durata;

    public:

        Episod(const char* denumire, std::list<std::string> cast, const char* genre, const char* descriere,Durata* durata):BaseVideo(denumire,cast,genre,descriere),durata(durata){}





};

int BaseVideo::idCounter=0;

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

};

class Serial: public BaseVideo{

    private:

        std::list<Episod*> listaEpisoade;

    public:

    Serial(const char* denumire, std::list<std::string> cast, const char* genre, const char* descriere,const std::list<Episod*> listaEpisoade):BaseVideo(denumire,cast,genre,descriere)
        ,listaEpisoade(listaEpisoade){}

    Serial(const Serial& other):BaseVideo(other),listaEpisoade(other.listaEpisoade){
    }


    friend Serial& operator+(Serial& serial, Episod* episod){

        Serial* aux= new  Serial(serial);
        aux->adaugaEpisod(episod);
        return *aux;

    }

    void adaugaEpisod(Episod* episod){

        this->listaEpisoade.push_back(episod);

    }

    const std::list<Episod*> getList(){

        return listaEpisoade;

    }



};






class Data{

    private:

        int an;
        int luna;
        int zi;


};

class IBaseUtilizator{

    virtual void rateVideo(const BaseVideo* video, int nota)=0;
    virtual void upgradeAccount();
    virtual void watchVideo(const BaseVideo* video);

};

class BaseUtilizator{

    protected:


        const char* nume;
        const char* prenume;


};



class BaseCont{

    protected:

        const std::list<char*> preferinte;
        const std::list<BaseVideo*> istoric;
        int puncte;

};


class Client: public BaseUtilizator{

    private:

    const Data* dataNastere;
    BaseCont* cont;
    const char* email;
    const char* nr_telefon;

};

class Admin:public BaseUtilizator{

    public:

    void deleteVideo(BaseVideo* video){

    }

};



class ContStandard: public BaseCont{

    private:

        int watchHour;
        const static int numarDispozitive = 2;

};

class ContPremium: public BaseCont{

    private:

        std::list<BaseVideo*> downloadList;
        const static int numarDispozitive = 5;

};


int main(){

    std::list<std::string> cast1= {"anne_brt"};

    Durata* durata1= new Durata(1,20,10);
    Episod* episod1= new Episod("ana are mere",cast1,"drama","un film dragut",durata1);

    std::list<Episod*> lista;
    lista.push_back(episod1);

    BaseVideo* video1= new Film("ana are mere",cast1,"drama","un film dragut",durata1,200000);
    BaseVideo* video2= new Film("ana are mere",cast1,"drama","un film dragut",durata1,200000);
    BaseVideo* video3= new Film("ana are mere",cast1,"drama","un film dragut",durata1,200000);


    std::cout<<video1->getId();
    std::cout<<video2->getId();
    std::cout<<video3->getId();

    Serial serial1("ana are mere",cast1,"drama","un film dragut",lista);

    Serial serial2= serial1+episod1;

    std::cout<<serial2.getList().size();



    return 0;

}