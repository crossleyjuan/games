#include "enemy.h"

Enemy::Enemy(Life* life) : LiveEntity(life)
{
    Type =  ENTITY_TYPE_GENERIC;

    MaxSpeedX = 3;
    MaxSpeedY = 3;

    CanJump = false;
}
