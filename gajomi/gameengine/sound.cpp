#include "sound.h"

Sound::Sound(char* file)
{
    _chunk = Mix_LoadWAV(file);
    if (_chunk == NULL) {
        char* error = Mix_GetError();
        printf(error);
    }
}
/*
void Sound::musicDone() {
    if (_music != NULL) {
        Mix_HaltMusic();
        Mix_FreeMusic(_music);
        _music = NULL;
    }
}

*/
void Sound::Play() {
    if (_chunk == NULL) return;


    if (Mix_PlayChannel(-1, _chunk, 0) == -1) {
        char* error = Mix_GetError();
        printf(error);
    }
    //
    // Mix_PlayMusic(_music, 0);
//    Mix_HookMusicFinished(SoundEngine::musicDone);
}

