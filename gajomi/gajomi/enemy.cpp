#include "enemy.h"

Enemy::Enemy() : LiveEntity()
{
    Type =  ENTITY_TYPE_GENERIC;

    MaxSpeedX = 3;
    MaxSpeedY = 3;

    CanJump = false;
}
