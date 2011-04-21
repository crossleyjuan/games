#ifndef UFO_H
#define UFO_H

#include "enemy.h"

class UFO: public Enemy
{
private:
    float* targetX;
    float* targetY;

public:
    UFO();
    void OnInit();

    virtual bool OnMapCollision();
    virtual bool OnCollision(Entity *Entity);
    void SetTarget(float* x, float* y);
    virtual void OnLoop();

};

#endif // UFO_H
