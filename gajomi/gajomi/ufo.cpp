#include "ufo.h"
#include "gamedefs.h"

UFO::UFO()
{
    targetX = NULL;
    targetY = NULL;
}

void UFO::OnInit() {
    OnLoad("./images/ufo2.png", 300, 72, 11);
    Type =  ENTITY_TYPE_GENERIC;
    Flags = ENTITY_FLAG_NONE ; // | ENTITY_FLAG_GRAVITY

    reborn();
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
    if (Anim_Control.IsRunning() && Anim_Control.CurrentFrame == 9) {
        Anim_Control.Stop();
    }
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

bool UFO::OnCollision(Entity *Entity) {
    reduceLifeByPercentage(DEFAULT_CANNON_MISSIL_POWER);
    Anim_Control.Play();
    if (isDead()) {
        Flags = Flags | ENTITY_FLAG_GRAVITY;

        MaxSpeedX = 5;
        MaxSpeedY = 3;
    }
    return false;
}

void UFO::reborn() {
    MaxSpeedX = 1.5;
    MaxSpeedY = 0;

    MoveLeft = true;
    MoveRight = false;
    Anim_Control.Stop();
    Anim_Control.CurrentFrame = 9;
    LiveEntity::reborn();
}
