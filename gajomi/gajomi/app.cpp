#include "app.h"

App::App()
{
}

bool App::OnInit() {
    Engine::OnInit();

    if (!Engine::loadBackground("./images/background.png")) {
        return false;
    }
    if(_cannon.OnLoad("./images/cannon.png", 64, 80, 17) == false) {
        return false;
    }
    if (!_missil.OnLoad("./images/rocket.png", 16, 30, 1)) {
        return false;
    }
    _ufo.OnInit();
    _ufo.X = 200;
    _ufo.Y = 120;
    _cannon.Y = 550;
    _cannon.X = 500;
    _missil.X = 500;
    _missil.Y = 520;
    AddEntity(&_ufo);
    SetPlayer(&_cannon);
    AddEntity(&_missil);
    _ufo.SetTarget(&_cannon.X, &_cannon.Y);
    _cannon.SetTarget(&_ufo.centerX, &_ufo.centerY);
    _missil.SetTarget(&_ufo.centerX, &_ufo.centerY);
    return true;
}

void App::OnExecute() {
    if (!OnInit()) {
        return;
    }

    Engine::OnExecute();
}

void App::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
    case SDLK_SPACE: {
            _missil.Fire();
            break;
        }
    default: {
        }
    }
}

void App::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {

}
