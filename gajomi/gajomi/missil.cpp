#include "missil.h"

Missil::Missil()
{
}

void Missil::OnInit() {
}

void Missil::setTarget(float *x, float *y) {
    this->targetX = x;
    this->targetY = y;
}

void Missil::OnLoop() {
    X = *targetX;
    Y = *targetY - 100;
}
