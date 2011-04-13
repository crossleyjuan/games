#ifndef FPS_H
#define FPS_H

#include "gameengine_global.h"
#include <SDL.h>

class GAMEENGINESHARED_EXPORT FPS {
    public:
        static FPS FPSControl;

    private:
        int     OldTime;
        int     LastTime;

        float   SpeedFactor;

        int NumFrames;
        int     Frames;

        bool _temp;
    public:
        FPS();

        void    OnLoop();

    public:
        int     GetFPS();

        float   GetSpeedFactor();
};

#endif // FPS_H
