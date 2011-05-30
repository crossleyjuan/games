#ifndef LIVEENTITY_H
#define LIVEENTITY_H

#include "entity.h"
#include "life.h"

class LiveEntity: public Entity
{
private:
    bool _dead;
protected:
    Life*  _life;

public:
    LiveEntity(Life* life);
    virtual ~LiveEntity();

    bool        isDead();
    void        reduceLifeByPercentage(double perc);
    virtual void        reborn();
    double      currentLife();
};

#endif // LIVEENTITY_H
