#ifndef CAMERA_H
#define CAMERA_H


#include <SDL.h>

#include "Define.h"
#include "gameengine_global.h"

enum {
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};

class GAMEENGINESHARED_EXPORT Camera {
    public:
        static Camera CameraControl;

    private:
        int X;
        int Y;

        float* TargetX;
        float* TargetY;

    public:
        int TargetMode;

    public:
        Camera();

    public:
        void OnMove(int MoveX, int MoveY);

    public:
        int GetX();
        int GetY();

    public:
        void SetPos(int X, int Y);

        void SetTarget(float* X, float* Y);
};

#endif // CAMERA_H

