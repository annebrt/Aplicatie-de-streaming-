#ifndef CLIENT_H
#define CLIENT_H

#include "BaseUtilizator.h"
#include "Data.h"
#include "BaseCont.h"
#include <cstring>
#include "IBaseUtilizator.h"
#include "ContPremium.h"
#include "ContStandard.h"

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
        this->nume = new char[std::strlen(nume)+1];
        std::strcpy(this->nume,nume);
        return *this;
    }

      ClientBuilder& Prenume( char *prenume)
    {
        this->prenume = new char[std::strlen(prenume)+1];
        std::strcpy(this->prenume,prenume);
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

    ~ClientBuilder()= default;

};


class Client : public BaseUtilizator
{

private:
     Data *dataNastere;
     BaseCont *cont;
     char *email;
     char *telefon;

public:

    Client(): BaseUtilizator(),dataNastere(nullptr),cont(nullptr),email(nullptr),telefon(nullptr){}

    Client(const char *nume, const char *prenume, Data *dataNastere,  BaseCont* cont, const char* email, const char* telefon) :
    BaseUtilizator(nume, prenume), dataNastere(dataNastere),cont(cont)
    { 

        this->email= new char[std::strlen(email)+1];
        std::strcpy(this->email,email);

        this->telefon= new char[std::strlen(telefon)+1];
        std::strcpy(this->telefon,telefon);

    }

    const char* getTelefon() const{
        return this->telefon;
    }

    static ClientBuilder builder(){
        
        return ClientBuilder();
    }

    ~Client(){

        delete dataNastere;
        delete []email;
        delete []telefon;
        delete cont;

    }

    void rateVideo( BaseVideo* video, int nota) override{

        int oldNota= video->getNota();
        int oldReviewCount= video->getReviewCount();

        int newNota= (nota+oldNota*oldReviewCount)/(oldReviewCount+1);

        video->setNota(newNota);
        video->setReviewCount(oldReviewCount+1);

    }

    void upgradeAccount() override{

        BaseCont* cont= this->cont;

        if (dynamic_cast<const ContStandard*>(cont)){

            ContPremium* newAccount= new ContPremium(cont->getPreferinte());
            newAccount->setIstoric(cont->getIstoric());

            this->cont=newAccount;

            delete cont;

        }else{
            std::cout<<"Contul este deja premium";
            return;
        }

    }

    void watchVideo( const BaseVideo* video) override{

        BaseCont* cont= this->cont;
        std::list<const BaseVideo*> istoric= cont->getIstoric();

        istoric.push_back(video);

        cont->setIstoric(istoric);

    }

    const BaseCont* getCont() const  {

        return this->cont;

    }

};


Client* ClientBuilder::build() {


    Client* c= new Client(
        nume,
        prenume,
        dataNastere,
        cont,
        email,
        telefon
    );

    nume=prenume=email=telefon=nullptr;
    cont=nullptr;
    dataNastere=nullptr;

    return c;

}



#endif // CLIENT_H
