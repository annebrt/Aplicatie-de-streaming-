#ifndef CONTSTANDARD_H
#define CONTSTANDARD_H

#include "BaseCont.h"

class ContStandard: public BaseCont{

    private:

        int watchHour=180;
        const static int numarDispozitive = 2;

    public:

        ContStandard(std::list<char*> preferinte):BaseCont(preferinte){
        }
    
    void oferaInformatii() override{
        std::cout<<"cont standard";
    }

    ~ContStandard()=default;

};

#endif // CONTSTANDARD_H
