#ifndef DURATA_H
#define DURATA_H

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

    friend std::ostream &operator<<(std::ostream& out,const Durata& durata){

        out<<"ore: "<<durata.ore<<", "<<" minute: "<<durata.minute<<" secunde: "<<durata.secunde<<"\n";

        return out;

    }

};

#endif // DURATA_H
