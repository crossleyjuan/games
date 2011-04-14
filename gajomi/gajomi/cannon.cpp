#include "cannon.h"

Cannon::Cannon()
{
}

void Cannon::OnAnimate() {
    Anim_Control.SetCurrentFrame(3);
}

void Cannon::SetTarget(float *X, float *Y) {
    this->targetX = X;
    this->targetY = Y;
}
