#include "app.h"

App::App()
{
}

bool App::OnInit() {
    _engine.OnInit();

    if(_cannon.OnLoad("./images/cannon.png", 80, 64, 8) == false) {
        return false;
    }
    _ufo.OnInit();
    _ufo.X = 200;
    _ufo.Y = 120;
    _cannon.Y = 550;
    _cannon.X = 500;
    _engine.AddEntity(&_ufo);
    _engine.SetPlayer(&_cannon);
    _ufo.SetTarget(&_cannon.X, &_cannon.Y);
    _cannon.SetTarget(&_ufo.X, &_ufo.Y);
    return true;
}

void App::OnExecute() {
    if (!OnInit()) {
        return;
    }

    _engine.OnExecute();
}
