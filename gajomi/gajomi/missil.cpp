#include "missil.h"
#include "fps.h"
#include "engine.h"

#include <math.h>

Missil::Missil()
{
    _fired = false;
}

bool Missil::OnInit() {
    if (!Entity::OnLoad("./images/rocket.png", 16, 30, 1)) {
        return false;
    }
    _explosionSound = new Sound("./sounds/Explosions.wav");
    return true;
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

    float newX = dirX * 250 * FPS::FPSControl.GetSpeedFactor();
    float newY = dirY * 250 * FPS::FPSControl.GetSpeedFactor();
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

bool Missil::OnCollision(Entity *Entity) {
    _fired = false;
    _explosionSound->Play();
    Engine::GameEngine.RemoveEntity(this);
    return true;
}

bool Missil::isFired() {
    return _fired;
}
