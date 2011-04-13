#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "gameengine_global.h"

class Player : public Entity {
    public:
        Player();

        bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(Entity* Entity);

        bool OnMapCollision();
};

#endif // PLAYER_H
