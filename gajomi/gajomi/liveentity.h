#ifndef LIVEENTITY_H
#define LIVEENTITY_H

#include "entity.h"

class LiveEntity: public Entity
{
private:
    double _life;
    bool _dead;

public:
    LiveEntity();
    virtual ~LiveEntity();

    bool        isDead();
    void        reduceLifeByPercentage(double perc);
    virtual void        reborn();
    double      currentLife();
};

#endif // LIVEENTITY_H
