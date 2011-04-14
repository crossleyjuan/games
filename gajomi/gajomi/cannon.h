#ifndef CANNON_H
#define CANNON_H

#include "entity.h"

class Cannon: public Entity
{
private:
    float* targetX;
    float* targetY;

public:
    Cannon();

    void OnAnimate();

    void SetTarget(float* X, float *Y);
};

#endif // CANNON_H
