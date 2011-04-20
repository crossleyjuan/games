#ifndef MISSIL_H
#define MISSIL_H

#include "entity.h"

class Missil: public Entity
{
private:
    float* targetX;
    float* targetY;

    float _speedX;
    float _speedY;

    bool _fired;

public:
    Missil();

    void OnInit();

    virtual void OnLoop();
    virtual bool OnCollision(Entity *Entity);

    void Fire();
    bool isFired();

    void SetTarget(float *x, float *y);
};

#endif // MISSIL_H
