#include "Engine.h"
#include "defs.h"

Engine::Engine()
{
    //ctor
}

Engine::~Engine()
{
    //dtor
}

bool Engine::init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((_surfDisplay = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

}

void Engine::cleanup() {
    SDL_FreeSurface(_surfDisplay);

    SDL_Quit();
}
