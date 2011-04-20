#ifndef APP_H
#define APP_H

//#include "player.h"
#include "cannon.h"
#include "engine.h"
#include "ufo.h"
#include "missil.h"
#include "level.h"
#include "text.h"

class App : public Engine
{
public:
    App();
    void OnExecute();
    virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

private:
    bool OnInit();

private:
    //Engine  _engine;
//    Player  _player;
    Cannon  _cannon;
    UFO     _ufo;
    Missil  _missil;
    Text*    _text;

    Level _level;
    int _hits;

    void renderLaunchCode();
};

#endif // APP_H
