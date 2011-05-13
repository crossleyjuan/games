#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <SDL.h>

class DrawableObject {
public:
    virtual bool OnInit() = 0;
    virtual void OnRender(SDL_Surface* display) = 0;
    virtual void OnCleanup() = 0;
};

#endif // DRAWABLEOBJECT_H
