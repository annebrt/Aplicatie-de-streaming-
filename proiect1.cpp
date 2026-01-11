#include <iostream>
#include "BaseVideo.h"
#include "IVideo.h"
#include <string>
#include <cstring>
#include "Durata.h"
#include <list>
#include "Episod.h"
#include "Data.h"
#include "BaseUtilizator.h"
#include "BaseCont.h"
#include "Film.h"
#include "Serial.h"
#include "Client.h"
#include "ContStandard.h"

int BaseVideo::idCounter = 0;

int main(){

    std::list<std::string> cast1= {"anne_brt"};

    Durata* durata1= new Durata(1,20,10);
    Episod* episod1= new Episod("ana are mere",cast1,"drama","un film dragut",durata1);
    BaseVideo* episod2= new Episod("ana are mere",cast1,"drama","un film dragut",durata1);

    std::list<Episod*> lista;
    lista.push_back(episod1);

    BaseVideo* video1= new Film("ana are mere",cast1,"drama","un film dragut",durata1,200000);
    BaseVideo* video2= new Film("ana are mere",cast1,"drama","un film dragut",durata1,200000);
    BaseVideo* video3= new Film("ana are mere",cast1,"drama","un film dragut",durata1,200000);
    
    std::cout<<*video1<<std::endl;
    std::cout<<*episod1<<"\n";

    std::cout<<video1->getId();
    std::cout<<video2->getId();
    std::cout<<video3->getId();

    Serial serial1("ana are mere",cast1,"drama","un film dragut",lista);

    Serial serial2= serial1+episod1;

    std::cout<<serial2.getList().size();

    std::list<char*> lista2= {"horror"};

    BaseCont* cont= new ContStandard(lista2);

    Client* client= Client::builder().Cont(cont).DataNastere(nullptr).Nume("manny").Prenume("manny").Email("annebrt@gmail.com").Telefon("07n-amcartela").build();

    std::cout<<client->getTelefon();
    

    return 0;

}
