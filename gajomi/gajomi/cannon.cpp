#include "cannon.h"

Cannon::Cannon()
{
}

void Cannon::OnAnimate() {
    Anim_Control.SetCurrentFrame(0);
}

void Cannon::SetTarget(float *X, float *Y) {
    this->targetX = X;
    this->targetY = Y;
}
