#include "app.h"

App::App()
{
}

bool App::OnInit() {
    _engine.OnInit();

    if(_player.OnLoad("./images/yoshi.png", 64, 64, 8) == false) {
        return false;
    }
    _ufo.OnInit();
    _ufo.X = 200;
    _ufo.Y = 100;
    _player.Y = 550;
    _player.X = 500;
    _engine.AddEntity(&_ufo);
    _engine.SetPlayer(&_player);
    _ufo.SetTarget(&_player.X, &_player.Y);

    return true;
}

void App::OnExecute() {
    if (!OnInit()) {
        return;
    }

    _engine.OnExecute();
}
