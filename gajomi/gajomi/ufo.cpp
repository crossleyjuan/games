#include "ufo.h"

UFO::UFO()
{
    targetX = NULL;
    targetY = NULL;
}

void UFO::OnInit() {
    OnLoad("./images/ufo.png", 300, 72, 0);
    Type =  ENTITY_TYPE_GENERIC;
    Flags = ENTITY_FLAG_MAPONLY ; // | ENTITY_FLAG_GRAVITY

    MaxSpeedX = 2;
    MaxSpeedY = 0.001;

    MoveLeft = true;
}

void UFO::OnLoop() {
    /*
    if (targetX == NULL) return;

    float pointX = this->X + (this->Width / 2);
    float pointY = this->Y + this->Height;

    if ((this->X + this->Width - (pointY / 2)) > *targetX) {
        MoveLeft = true;
        MoveRight = false;
    }
    if ((this->X + (pointY / 2)) < *targetX) {
//    if ((pointX < (*targetX - (pointY * 0.2)))) {
        MoveRight = true;
        MoveLeft = false;
    }
    */
/*
    if ((this->X + (this->Width / 2)) > *targetX) {
        MoveLeft = true;
        MoveRight = false;
    }
    if ((this->X + (this->Width / 2)) < *targetX) {
        MoveRight = true;
        MoveLeft = false;
    }
    */
    Enemy::OnLoop();
}

bool UFO::OnMapCollision() {
    StopMove();
    if (MoveLeft) {
        MoveRight = true;
        MoveLeft = false;
    } else {
        MoveRight = false;
        MoveLeft = true;
    }
}

void UFO::SetTarget(float *x, float *y) {
    this->targetX = x;
    this->targetY = y;
}
