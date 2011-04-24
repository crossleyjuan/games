#ifndef CANNON_H
#define CANNON_H

#include "liveentity.h"

class Cannon: public LiveEntity
{
private:
    float* targetX;
    float* targetY;
    int current;

public:
    Cannon();

    void OnLoop();

    void SetTarget(float* X, float *Y);
};

#endif // CANNON_H
