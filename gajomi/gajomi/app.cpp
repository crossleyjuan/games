#include "app.h"
#include "soundengine.h"
#include "gamedefs.h"
#include <stdlib.h>

App::App()
{
    _text = NULL;
    _beep = NULL;
}

App::~App() {
    // delete(_beep) is not working
    _beep = 0;
}

bool App::OnInit() {
    Engine::OnInit();

    if (!Engine::loadBackground("./images/background.png")) {
        return false;
    }
    if(_cannon.OnLoad("./images/cannon.png", 64, 80, 17) == false) {
        return false;
    }
    if (!_missil.OnInit()) {
        return false;
    }

    if (!_level.OnInit()) {
        return false;
    }
    _beep = new Sound("./sounds/beep.wav");

    _ufo.OnInit();
    _ufo.X = 200;
    _ufo.Y = 120;
    _cannon.Y = 550;
    _cannon.X = 500;
    AddEntity(&_ufo);
    SetPlayer(&_cannon);
    //AddEntity(&_missil);
    _ufo.SetTarget(&_cannon.X, &_cannon.Y);
    _cannon.SetTarget(&_ufo.centerX, &_ufo.centerY);
    _missil.SetTarget(&_ufo.centerX, &_ufo.centerY);
    renderLaunchCode();

    return true;
}

void App::OnExecute() {
    if (!OnInit()) {
        return;
    }

    Engine::OnExecute();
}

void App::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    if (_missil.isFired()) {
        return;
    }

    if (_ufo.isDead()) {
        return;
    }

    if (_level.GetLaunchCode() == sym) {
        _missil.X = 500;
        _missil.Y = 520;
        AddEntity(&_missil);
        _missil.Fire();
        renderLaunchCode();
    } else {
        _ufo.reduceLifeByPercentage(DEFAULT_RESTORE_LIFE);
        _beep->Play();
    }
}

void App::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {

}

void App::renderLaunchCode() {
    if (_text != NULL) {
        RemoveEntity(_text);
    }
    int current = _level.GetLaunchCode();
    do {
        _level.CreateLaunchCode();
    } while (_level.GetLaunchCode() == current);

    char* code = (char*)malloc(16);
    memset(code, 0, 16);
    sprintf(code, "Launch Code: %c", _level.GetLaunchCode());

    this->_text = new Text((char*)code, 100, 530);
    AddEntity(_text);
}

void App::OnLocalLoop() {
    if (_ufo.isDead() && !_ufo.IsMoving()) {
        _ufo.reborn();
        _level.NextLevel();
        // Increases the maximum life
        _ufo.setMaxLife(_ufo.maxLife() * 1.2);
        renderLaunchCode();
        _ufo.X = 200;
        _ufo.Y = 120;
    }
}
