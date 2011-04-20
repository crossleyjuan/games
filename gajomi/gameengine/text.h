#ifndef TEXT_H
#define TEXT_H

#include "entity.h"
#include <SDL.h>
#include <SDL_ttf.h>

class GAMEENGINESHARED_EXPORT Text: public Entity
{
public:
    Text(char* text, int x, int y);

    void OnLoop();
};

#endif // TEXT_H
