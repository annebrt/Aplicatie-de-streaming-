#ifndef IBASEUTILIZATOR_H
#define IBASEUTILIZATOR_H

#include "BaseVideo.h"

class IBaseUtilizator{

    virtual void rateVideo( BaseVideo* video, int nota)=0;
    virtual void upgradeAccount()=0;
    virtual void watchVideo(const BaseVideo* video)=0;

};

#endif // IBASEUTILIZATOR_H
