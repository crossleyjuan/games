#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include "Event.h"
#include "animation.h"
#include "entity.h"
#include "define.h"
#include "area.h"
#include "camera.h"
#include "gameengine_global.h"

#define SDL_main main


enum GRID_TYPE {
    GRID_TYPE_NONE = 0,
    GRID_TYPE_X,
    GRID_TYPE_O
};

class GAMEENGINESHARED_EXPORT Engine : public Event {
private:
    bool _running;

    SDL_Surface*    _surfDisplay;
    SDL_Surface*    _surfBackground;

    Entity* _player;

public:
    static Engine GameEngine;
    // Constructor
    Engine();

    void AddEntity(Entity* ent);
    void RemoveEntity(Entity* ent);
    void SetPlayer(Entity* ent);
    bool loadBackground(char* file);

    bool OnInit();
    void OnEvent(SDL_Event* evt);
    void OnLoop();
    void OnRender();
    void OnCleanUp();

    //Events
    /*
    virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
    */
    void OnExit();

    int OnExecute();
};

#endif  //ENGINE_H
