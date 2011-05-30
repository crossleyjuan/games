#include "cannon.h"
#include "math.h"

Cannon::Cannon(): LiveEntity(new Life())
{
    current = 0;
}

void Cannon::SetTarget(float *X, float *Y) {
    this->targetX = X;
    this->targetY = Y;
}

void Cannon::OnLoop() {
    float b = Y - *targetY;

    float a = X - *targetX;
    float c = sqrt(pow(a, 2) + pow(b, 2));

    float side;
    if (c > a) {
        side = a;
    } else {
        side = c;
    }
    float tang = b / side;
    float angle = atan(tang) * 180 / 3.14159;
    if (angle < 0) {
        angle = (float)180 + (float)angle;
    }
    int frame = (float)angle / (float)10.5;
    //frame++; // this corrects the size of the object, X and Y should be the center of the object and not the top-left
    Anim_Control.SetCurrentFrame(frame);
}
