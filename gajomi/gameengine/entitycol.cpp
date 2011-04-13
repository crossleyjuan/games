#include "entity.h"

std::vector<EntityCol> EntityCol::EntityColList;
std::vector<EntityMapCol> EntityMapCol::EntityMapColList;

EntityCol::EntityCol() {
    this->EntityA = NULL;
    this->EntityB = NULL;
}


EntityMapCol::EntityMapCol() {
    this->EntityA = NULL;
}
