#include "soundengine.h"

SoundEngine SoundEngine::SoundManager;

#define NUM_SOUNDS 2

struct sound_struct {
    Uint8 *data;
    Uint32 dpos;
    Uint32 dlen;
} sounds[NUM_SOUNDS];


Mix_Music* SoundEngine::_music;

SoundEngine::SoundEngine()
{
    SoundEngine::_music = NULL;
}

SoundEngine::~SoundEngine() {

}

bool SoundEngine::OnInit() {
    /* We're going to be requesting certain things from our audio
         device, so we set them up beforehand */
    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16; /* 16-bit stereo */
    int audio_channels = 2;
    int audio_buffers = 4096;

    /* This is where we open up our audio device.  Mix_OpenAudio takes
         as its parameters the audio format we'd /like/ to have. */
    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) == -1) {
        return false;
    }
    return true;
}

void SoundEngine::OnCleanup() {
    Mix_CloseAudio();
}

void SoundEngine::MusicDone() {
    Mix_HaltMusic();
    Mix_FreeMusic(_music);
    _music = NULL;
}

void SoundEngine::PlayMusic(char *file, int loop) {
    _music = Mix_LoadMUS(file);

    if (_music == NULL) {
        char* error = Mix_GetError();
        printf(error);
        return;
    }
    Mix_PlayMusic(_music, loop);
}
