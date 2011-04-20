#include "app.h"

App::App()
{
    _text = NULL;
    _hits = 0;
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

    if (!_level.OnInit()) {
        return false;
    }
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

    if (_level.GetLaunchCode() == sym) {
        _missil.X = 500;
        _missil.Y = 520;
        AddEntity(&_missil);
        _missil.Fire();
        _hits++;
        if (_hits > 4) {
            _level.NextLevel();
            _hits = 0;
        } else {
            _level.CreateLaunchCode();
        }
        renderLaunchCode();
    }
}

void App::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {

}

void App::renderLaunchCode() {
    if (_text != NULL) {
        RemoveEntity(_text);
    }
    char* code = (char*)malloc(16);
    memset(code, 0, 16);
    sprintf(code, "Launch Code: %c", _level.GetLaunchCode());

    this->_text = new Text((char*)code, 100, 530);
    AddEntity(_text);
}
