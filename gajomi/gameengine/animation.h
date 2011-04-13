#ifndef ANIMATION_H
#define ANIMATION_H

#include "gameengine_global.h"

class GAMEENGINESHARED_EXPORT Animation
{
private:
    int CurrentFrame;
    int     FrameInc;
    int     FrameRate; //Milliseconds
    long    OldTime;

public:
    int MaxFrames;
    bool    Oscillate;
    bool    Vertical;

public:
    Animation();
    void OnAnimate();

public:
    void SetFrameRate(int Rate);
    void SetCurrentFrame(int Frame);
    int GetCurrentFrame();
};

#endif // ANIMATION_H
