#ifndef ANIMATION_H
#define ANIMATION_H

#include "gameengine_global.h"

class GAMEENGINESHARED_EXPORT Animation
{
private:
    int     FrameInc;
    int     FrameRate; //Milliseconds
    long    OldTime;
    bool    _running;

public:
    int MaxFrames;
    bool    Oscillate;
    bool    Vertical;
    int CurrentFrame;

public:
    Animation();
    Animation(const Animation &orig);
    void OnAnimate();

public:
    void SetFrameRate(int Rate);
    void SetCurrentFrame(int Frame);
    int GetCurrentFrame();
    void Play();
    void Stop();
    bool IsRunning();
};

#endif // ANIMATION_H
