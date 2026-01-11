#ifndef BASECONT_H
#define BASECONT_H

#include <list> 
#include "BaseVideo.h"


class BaseCont{

    protected: 

        std::list<char*> preferinte; 
        std::list<BaseVideo*> istoric;
        int puncte;

        public: BaseCont(const std::list<char*> preferinte){

            this->preferinte=preferinte;

        }

};

#endif // BASECONT_H
