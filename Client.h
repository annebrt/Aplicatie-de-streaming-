#ifndef CLIENT_H
#define CLIENT_H

#include "BaseUtilizator.h"
#include "Data.h"
#include "BaseCont.h"
#include <cstring>

class Client;

class ClientBuilder
{

private:    
    char* nume= nullptr;
    char* prenume= nullptr;
    Data *dataNastere= nullptr;
    BaseCont *cont= nullptr;
    char *email= nullptr;
    char *telefon= nullptr;

    public:

    ClientBuilder() {}


    
    ClientBuilder& Nume( char *nume)
    {
        this->nume = nume;
        return *this;
    }

      ClientBuilder& Prenume( char *prenume)
    {
        this->prenume = prenume;
        return *this;
    }


    ClientBuilder& DataNastere( Data *dataNastere)
    {
        this->dataNastere = dataNastere;
        return *this;
    }

    ClientBuilder& Cont( BaseCont *cont)
    {
        this->cont = cont;
        return *this;
    }

    ClientBuilder& Email( const char *email)
    {
        this->email= new char[std::strlen(email)+1];
        std::strcpy(this->email,email);
        return *this;
    }

    ClientBuilder& Telefon(const char *telefon)
    {
        this->telefon= new char[std::strlen(telefon)+1];
        std::strcpy(this->telefon,telefon);
        return *this;
    }

    Client* build();

};


class Client : public BaseUtilizator
{

private:
     Data *dataNastere;
     BaseCont *cont;
     char *email;
     char *telefon;

public:
    Client(const char *nume, const char *prenume, Data *dataNastere,  BaseCont* cont, const char* email, const char* telefon) :
    BaseUtilizator(nume, prenume), dataNastere(dataNastere),cont(cont)
    { 

        this->email= new char[std::strlen(email)+1];
        std::strcpy(this->email,email);

        this->telefon= new char[std::strlen(telefon)+1];
        std::strcpy(this->telefon,telefon);

    }

    const char* getTelefon(){
        return this->telefon;
    }

    static ClientBuilder builder(){
        
        return ClientBuilder();
    }
};


Client* ClientBuilder::build() {
    return new Client(
        nume,
        prenume,
        dataNastere,
        cont,
        email,
        telefon
    );
}



#endif // CLIENT_H
