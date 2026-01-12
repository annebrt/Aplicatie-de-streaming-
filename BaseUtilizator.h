#ifndef BASEUTILIZATOR_H
#define BASEUTILIZATOR_H

#include <string>
#include <cstring>
#include <cstdlib>
#include "IBaseUtilizator.h"

class BaseUtilizator:public IBaseUtilizator{

    protected:

        static int idCounter;

        const int id= idCounter++;
        char* nume;
        char* prenume;

    public:

        BaseUtilizator():nume(nullptr),prenume(nullptr){}

        BaseUtilizator(const char* nume, const char* prenume){

            this->nume= new char[std::strlen(nume)+1];
            std::strcpy(this->nume,nume);

            this->prenume= new char[std::strlen(prenume)+1];
            std::strcpy(this->prenume,prenume);


        }
    
    const char* getNume() const{
        return this->nume;
    }

    const char* getPrenume() const{
        return this->nume;
    }

    virtual ~BaseUtilizator(){

        delete []nume;
        delete []prenume;

    }


};

#endif // BASEUTILIZATOR_H
