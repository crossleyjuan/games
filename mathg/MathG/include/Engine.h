#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"

#define SDL_main main

class Engine
{
    public:
        Engine();
        virtual ~Engine();

        bool init();
        void cleanup();

    protected:
    private:
        SDL_Surface* _surfDisplay;
};

#endif // ENGINE_H
