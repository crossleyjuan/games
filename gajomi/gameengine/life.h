#ifndef LIFE_H
#define LIFE_H

#include "DrawableObject.h"
#include "gameengine_global.h"
#include "SDL.h"

class GAMEENGINESHARED_EXPORT Life : public DrawableObject
{
public:
    Life();

    bool OnInit();
    void OnCleanup();
    void OnRender(SDL_Surface* display);

    int X;
    int Y;
    int Width;
    int Height;
    void SetValue(int);
private:
    int _value;
    int _currentFrame;
    SDL_Surface* surface;
};

#endif // LIFE_H
