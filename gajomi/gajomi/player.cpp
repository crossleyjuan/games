#include "player.h"
#include "entity.h"

Player::Player() {
    Type = ENTITY_TYPE_PLAYER;
}

bool Player::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(Entity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

void Player::OnLoop() {
    Entity::OnLoop();
}

void Player::OnRender(SDL_Surface* Surf_Display) {
    Entity::OnRender(Surf_Display);
}

void Player::OnCleanup() {
    Entity::OnCleanup();
}

void Player::OnAnimate() {
    if(SpeedX != 0) {
        Anim_Control.MaxFrames = 8;
    }else{
        Anim_Control.MaxFrames = 0;
    }

    Entity::OnAnimate();
}

bool Player::OnCollision(Entity* Entity) {
    Jump();
    return true;
}

bool Player::OnMapCollision() {

}
