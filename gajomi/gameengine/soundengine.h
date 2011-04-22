#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <SDL_mixer.h>
#include <SDL.h>

class SoundEngine
{
public:
    static SoundEngine SoundManager;
    static Mix_Music* _music;
    static void MusicDone();

    SoundEngine();
    ~SoundEngine();

    bool OnInit();
    void OnCleanup();

    void PlayMusic(char* file, int loop);
};

#endif // SOUNDENGINE_H
