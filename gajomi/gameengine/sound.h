#ifndef SOUND_H
#define SOUND_H

#include "gameengine_global.h"
#include <SDL.h>
#include <SDL_mixer.h>

class GAMEENGINESHARED_EXPORT Sound
{
private:
    Mix_Chunk* _chunk;
public:
    Sound(char* file);

    ~Sound();

    void Play();
};

#endif // SOUND_H
