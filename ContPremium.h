#ifndef CONTPREMIUM_H
#define CONTPREMIUM_H

#include <list>
#include "BaseCont.h"

class ContPremium: public BaseCont{

    private: 

        std::list<BaseVideo*> downloadList;
        const static int numarDispozitive = 5;

};

#endif // CONTPREMIUM_H
