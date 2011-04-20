#include "missil.h"
#include "fps.h"
#include <math.h>

Missil::Missil()
{
    _fired = false;
}

void Missil::OnInit() {
}

void Missil::SetTarget(float *x, float *y) {
    this->targetX = x;
    this->targetY = y;
}

void Missil::OnLoop() {
    if (!_fired) return;

    float b = Y - *targetY;

    float a = X - *targetX;
    float c = sqrt(pow(a, 2) + pow(b, 2));

    float hyp;
    if (c > a) {
        hyp = c;
    } else {
        hyp = a;
    }

    float dirX = *targetX - X;
    float dirY = *targetY - Y;

    // Normalize the vector
    dirX = dirX / hyp;
    dirY = dirY / hyp;

    float newX = dirX * 100 * FPS::FPSControl.GetSpeedFactor();
    float newY = dirY * 100 * FPS::FPSControl.GetSpeedFactor();
/*
    AccelX = 1;
    AccelY = tang * (AccelX - X) + Y;

    SpeedX += AccelX * FPS::FPSControl.GetSpeedFactor();
    SpeedY += AccelY * FPS::FPSControl.GetSpeedFactor();

    if(SpeedX > MaxSpeedX)  SpeedX =  MaxSpeedX;
    if(SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
    if(SpeedY > MaxSpeedY)  SpeedY =  MaxSpeedY;
    if(SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;
*/
    OnAnimate();
    OnMove(newX, newY);
}

void Missil::Fire() {
    _fired = true;
}
