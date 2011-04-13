#include "enemy.h"

Enemy::Enemy()
{
    Type =  ENTITY_TYPE_GENERIC;

    MaxSpeedX = 3;
    MaxSpeedY = 3;

    CanJump = false;
}
