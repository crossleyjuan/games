#include "life.h";
#include "surface.h"
#include "camera.h"

Life::Life()
{
    this->_value = 100;
    _currentFrame = 0;
    this->surface = NULL;
    Width = 30;
    Height = 15;
}

bool Life::OnInit() {
    surface = Surface::loadImage("./images/health.png");
    if (surface == NULL) {
        return false;
    }
    return true;
}

void Life::OnCleanup() {
    if(surface) {
        SDL_FreeSurface(surface);
    }

    surface = NULL;
}

void Life::SetValue(int value) {
    _value = value;
    _currentFrame = 10 - (value / 10);
}

int Life::Value() {
    return _value;
}

void Life::OnRender(SDL_Surface *display) {
    Surface::OnDraw(display, surface, X, Y, 0, _currentFrame * Height, Width, Height);
}
