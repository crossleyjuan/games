#ifndef SURFACE_H
#define SURFACE_H

#include <SDL.h>
#include <SDL_image.h>
#include "gameengine_global.h"

class GAMEENGINESHARED_EXPORT Surface
{
public:
    Surface();

    static bool OnDraw(SDL_Surface* dest, SDL_Surface* source, int x, int y);
    static bool OnDraw(SDL_Surface* dest, SDL_Surface* source, int X, int Y, int X2, int Y2, int W, int H);

    static SDL_Surface* loadImage(char* file);
    static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};

#endif // SURFACE_H
