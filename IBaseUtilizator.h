#ifndef IBASEUTILIZATOR_H
#define IBASEUTILIZATOR_H

#include "BaseVideo.h"

class IBaseUtilizator{

    virtual void rateVideo(const BaseVideo* video, int nota)=0;
    virtual void upgradeAccount();
    virtual void watchVideo(const BaseVideo* video);

};

#endif // IBASEUTILIZATOR_H
