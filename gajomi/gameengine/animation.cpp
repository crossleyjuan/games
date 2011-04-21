#include "animation.h"
#include <SDL.h>

Animation::Animation()
{
    CurrentFrame    = 0;
    MaxFrames       = 0;
    FrameInc        = 1;

    FrameRate       = 100; //Milliseconds
    OldTime         = 0;

    Oscillate       = false;
    _running    = true;
}

Animation::Animation(const Animation &orig) {
    this->CurrentFrame = orig.CurrentFrame;
    this->FrameInc = orig.FrameInc;
    this->FrameRate = orig.FrameRate;
    this->MaxFrames = orig.MaxFrames;
    this->OldTime = orig.OldTime;
    this->Oscillate = orig.Oscillate;
    this->Vertical = orig.Vertical;
    this->_running = orig._running;
}

void Animation::OnAnimate() {
    if (!_running) return;

    if(OldTime + FrameRate > SDL_GetTicks()) {
        return;
    }

    OldTime = SDL_GetTicks();

    CurrentFrame += FrameInc;

    if(Oscillate) {
        if (FrameInc > 0) {
            if (CurrentFrame >= MaxFrames -1 ) {
                FrameInc = -FrameInc;
            }
        }else{
            if(CurrentFrame <= 0) {
                FrameInc = -FrameInc;
            }
        }
    }else{
        if (CurrentFrame >= MaxFrames - 1) {
            CurrentFrame = 0;
        }
    }
}

void Animation::SetFrameRate(int Rate) {
    FrameRate = Rate;
}

void Animation::SetCurrentFrame(int Frame) {
    if(Frame < 0 || Frame >= MaxFrames) return;

    CurrentFrame = Frame;
}

int Animation::GetCurrentFrame() {
    return CurrentFrame;
}

void Animation::Play() {
    _running = true;
}

void Animation::Stop() {
    _running = false;
}

bool Animation::IsRunning() {
    return _running;
}
