#ifndef MISSIL_H
#define MISSIL_H

#include "entity.h"

class Missil: public Entity
{
private:
    float* targetX;
    float* targetY;

public:
    Missil();

    void OnInit();

    virtual void OnLoop();

    void setTarget(float *x, float *y);
};

#endif // MISSIL_H
