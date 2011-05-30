#include "liveentity.h"

LiveEntity::LiveEntity(Life* life)
{
    this->_dead = false;
    _life = life;
    _life->SetValue(100);
}

LiveEntity::~LiveEntity() {
}

bool LiveEntity::isDead() {
    return _dead;
}

void LiveEntity::reduceLifeByPercentage(double perc) {
    _life->SetValue(_life->Value() - perc);
    if (_life->Value() <= 0) {
        _life->SetValue(0);
        _dead = true;
    } else if (_life->Value() > 100) {
        _life->SetValue(100);
        _dead = false;
    }
}

void LiveEntity::reborn() {
    _life->SetValue(100);
    _dead = false;
}

double LiveEntity::currentLife() {
    return _life->Value();
}

