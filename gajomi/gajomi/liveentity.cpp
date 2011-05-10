#include "liveentity.h"

LiveEntity::LiveEntity()
{
    this->_dead = false;
    this->_life = 100.0;
    this->_maxLife = 100.0;
}

LiveEntity::~LiveEntity() {
}

bool LiveEntity::isDead() {
    return _dead;
}

void LiveEntity::reduceLifeByPercentage(double perc) {
    _life -= perc;
    if (_life <= 0) {
        _life = 0;
        _dead = true;
    }
}

void LiveEntity::reborn() {
    _life = _maxLife;
    _dead = false;
}

double LiveEntity::currentLife() {
    return _life;
}

void LiveEntity::setMaxLife(double life) {
    _maxLife = life;
    _dead = false;
    _life = _maxLife;
}

double LiveEntity::maxLife() {
    return _maxLife;
}
