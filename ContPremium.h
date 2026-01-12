#ifndef CONTPREMIUM_H
#define CONTPREMIUM_H

#include <list>
#include "BaseCont.h"

class ContPremium: public BaseCont{

    private: 

        std::list<BaseVideo*> downloadList;
        const static int numarDispozitive = 5;

    public:
        
        ContPremium(std::list<char*> preferinte):BaseCont(preferinte){
        }
    
    
    void oferaInformatii() override{

        std::cout<<"cont premium";

    }

        ~ContPremium()=default;

};

#endif // CONTPREMIUM_H
