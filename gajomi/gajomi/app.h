#ifndef APP_H
#define APP_H

#include "player.h"
#include "engine.h"
#include "ufo.h"

class App
{
public:
    App();
    void OnExecute();

private:
    bool OnInit();

private:
    Engine  _engine;
    Player  _player;
    UFO     _ufo;
};

#endif // APP_H
