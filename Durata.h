#ifndef DURATA_H
#define DURATA_H

class Durata{

    private:

    int ore;
    int minute;
    int secunde;

    public: 

        Durata(){}
        
        Durata(int ore, int minute, int secunde){

        this->ore= ore;
        this->minute= minute;
        this->secunde= secunde;

    }

    Durata(const Durata& other){

        this->ore=other.ore;
        this->minute=other.minute;
        this->secunde=other.secunde;

    }

    friend std::ostream &operator<<(std::ostream& out,const Durata& durata){

        out<<"ore: "<<durata.ore<<", "<<" minute: "<<durata.minute<<" secunde: "<<durata.secunde<<"\n";

        return out;

    }

    friend std::istream &operator>>(std::istream& in, Durata& durata){

        int ore;
        int minute;
        int secunde;

        std::cout<<"ore: ";
        in>>ore;
        std::cout<<",  minute: ";
        in>>minute;
        std::cout<<" secunde: ";
        in>>secunde;

        durata.ore= ore;
        durata.minute= minute;
        durata.secunde=secunde;

        return in;

    }

    ~Durata()=default;

};

#endif // DURATA_H
