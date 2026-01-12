#ifndef BASECONT_H
#define BASECONT_H

#include <list> 
#include "BaseVideo.h"


class BaseCont{

    protected: 

        std::list<char*> preferinte; 
        std::list<const BaseVideo*> istoric;
        int puncte;

        public: BaseCont(const std::list<char*> preferinte):puncte(0){

            for(auto preferinta:preferinte){

                char* pref= new char[std::strlen(preferinta)+1];
                std::strcpy(pref,preferinta);
                this->preferinte.push_back(pref);

            }

        }

        const std::list<char*>& getPreferinte() const {
            return this->preferinte;
        }

        const std::list<const BaseVideo*>& getIstoric() const {

            return this->istoric;

        }

        void setIstoric(const std::list<const BaseVideo*>& istoric) {
            this->istoric=istoric;
        }

    
    virtual ~BaseCont(){

        for(auto preferinta:preferinte){
            delete []preferinta;
        }
        preferinte.clear();

    }

    virtual void oferaInformatii()=0; 


};

#endif // BASECONT_H
