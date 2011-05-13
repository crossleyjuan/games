#ifndef UFO_H
#define UFO_H

#include "enemy.h"
#include "sound.h"

class UFO: public Enemy
{
private:
    float* targetX;
    float* targetY;
    bool    _isOnGround;
    Sound* _explosionSound;

public:
    UFO();
    bool OnInit();

    virtual bool OnMapCollision();
    virtual bool OnCollision(Entity *Entity);
    void SetTarget(float* x, float* y);
    virtual void OnLoop();
    virtual void reborn();
};

#endif // UFO_H
