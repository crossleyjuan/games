#include "engine.h"
#include "surface.h"
#include "define.h"
#include "fps.h"
#include "text.h"
#include <SDL_ttf.h>

Engine Engine::GameEngine;

Engine::Engine() {
    _running = false;
    _surfDisplay = NULL;
}

bool Engine::OnInit() {
    _running = true;
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((_surfDisplay = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if(Area::AreaControl.OnLoad("./maps/1.area") == false) {
        return false;
    }

    if (TTF_Init() != 0) {
        return false;
    }

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    return true;
}

void Engine::OnEvent(SDL_Event* evt) {
    Event::OnEvent(evt);
}

void Engine::OnLoop() {
    //_yoshi.OnAnimate();
    FPS::FPSControl.OnLoop();
    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;
        Entity::EntityList[i]->OnLoop();
    }

    //Collision Events
    for(int i = 0;i < EntityCol::EntityColList.size();i++) {
        Entity* EntityA = EntityCol::EntityColList[i].EntityA;
        Entity* EntityB = EntityCol::EntityColList[i].EntityB;

        if(EntityA == NULL || EntityB == NULL) continue;

        if(EntityA->OnCollision(EntityB)) {
            EntityB->OnCollision(EntityA);
        }
    }
    EntityCol::EntityColList.clear();

    //Map Collision Events
    for(int i = 0;i < EntityMapCol::EntityMapColList.size();i++) {
        Entity* EntityA = EntityMapCol::EntityMapColList[i].EntityA;

        if(EntityA == NULL) continue;

        EntityA->OnMapCollision();
    }
    EntityMapCol::EntityMapColList.clear();

}

void Engine::OnRender() {
//    Area::AreaControl.OnRender(_surfDisplay, -Camera::CameraControl.GetX(), -Camera::CameraControl.GetY());
    Surface::OnDraw(_surfDisplay, _surfBackground, 0, 0);
    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;
        Entity::EntityList[i]->OnRender(_surfDisplay);
    }

    SDL_Flip(_surfDisplay);
}

void Engine::OnCleanUp() {
    SDL_FreeSurface(_surfDisplay);
    Area::AreaControl.OnCleanup();

    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;
        Entity::EntityList[i]->OnCleanup();
    }

    Entity::EntityList.clear();
    TTF_Quit();
    SDL_Quit();
}


int Engine::OnExecute() {
    SDL_Event evt;
    while (_running) {
        while(SDL_PollEvent(&evt)) {
            OnEvent(&evt);
        }

        OnLoop();
        OnRender();
    }
}


void Engine::OnExit() {
    _running = false;
}

/*
void Engine::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
    case SDLK_LEFT: {
            _player->MoveLeft = true;
            break;
        }
    case SDLK_RIGHT: {
            _player->MoveRight = true;
            break;
        }

    case SDLK_SPACE: {
            _player->Jump();
            break;
        }
    default: {
        }
    }
}

void Engine::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT: {
            _player->MoveLeft = false;
            break;
        }

        case SDLK_RIGHT: {
            _player->MoveRight = false;
            break;
        }

        default: {
        }
    }
}
*/

void Engine::AddEntity(Entity* ent) {
    Entity::EntityList.push_back(ent);
}

void Engine::RemoveEntity(Entity *ent) {
    std::vector<Entity*>::iterator iter;
    for (iter = Entity::EntityList.begin(); iter != Entity::EntityList.end(); iter++) {
        Entity* current = *iter;
        if (current == ent) {
            break;
        }
    }
    if (iter != Entity::EntityList.end()) {
        Entity::EntityList.erase(iter);
    }
}

void Engine::SetPlayer(Entity* ent) {
    _player = ent;
    AddEntity(_player);


    Camera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    Camera::CameraControl.SetTarget(&_player->X, &_player->Y);
}

bool Engine::loadBackground(char *file) {
    _surfBackground = Surface::loadImage(file);
    if (_surfBackground == NULL) {
        return false;
    } else {
        return true;
    }
}

