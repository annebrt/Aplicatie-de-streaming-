#ifndef BASEUTILIZATOR_H
#define BASEUTILIZATOR_H

#include <string>
#include <cstring>
#include <cstdlib>

class BaseUtilizator{

    protected:

        
        char* nume;
        char* prenume;

    public:
        BaseUtilizator(const char* nume, const char* prenume){

            this->nume= new char[std::strlen(nume)+1];
            std::strcpy(this->nume,nume);

            this->prenume= new char[std::strlen(prenume)+1];
            std::strcpy(this->prenume,prenume);


        }


};

#endif // BASEUTILIZATOR_H
